#!/usr/bin/env python3

"""Merge/reduce redundant header comment blocks across the three export views.



Re-runnable normalization pass; run it after the annotate/review passes and before

the validators (rebuild.sh). For every function in decompiled/functions/*.c,

decompiled/firmware_decompiled.c and named/firmware_named.c it:



  1. orders the tagged review blocks canonically (same order in all three views) -

     previously the per-function files prepended [ADDITIONAL SOURCE REVIEW] while the

     monoliths inserted it last, so the same header read in different orders;

  2. drops exact-duplicate content lines inside any single review block;

  3. drops machine-generated [CROSS-ECU / RX8DEFS REVIEW] descriptor lines and

     [MATH AND UNITS REVIEW] affine-encoding lines whose statement the function's own

     [ADDITIONAL SOURCE REVIEW] block already carries (same descriptor address plus

     table name, resp. same signal plus step literal) - the accepted source-review TSVs

     stay the authoritative text; a review block left without content lines is removed.



Function bodies (from the '/* ROM address:' anchor onward) are never touched; the pass

asserts every body still occurs intact in both monoliths. Idempotent: a second run

changes nothing. Re-running any annotate pass may reintroduce a redundant line; run

this pass again (or a full rebuild) to re-normalize.

"""

from pathlib import Path

import csv, json, re, struct

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo



BLOCK = re.compile(r'/\*.*?\*/', re.S)

TAG = re.compile(r'/\*\s*\[([A-Z0-9 /-]+)\]')

ADDR = re.compile(r'0x0*([0-9a-fA-F]{4,8})\b')

ANCHOR = re.compile(r'/\* ROM address: 0x[0-9a-f]{8};')

RANK = {'EXPORT CLEANUP': 0, 'CROSS-ECU / RX8DEFS REVIEW': 1, 'ADDITIONAL SOURCE REVIEW': 2,

        'MATH AND UNITS REVIEW': 3, 'LOOKUP FAMILY RECONSTRUCTION': 4, 'SORT RECORD RECONSTRUCTION': 5,

        'READABILITY RECONSTRUCTION': 6}

CE_DESC = re.compile(r'\*\s*Descriptor 0x0*([0-9a-fA-F]+):\s*(.*?)\s*\(RX8Defs data pointer')

MATH_AFFINE = re.compile(r'\*\s*Affine encoding \((\d+)-bit\):\s*(\S+);\s*decode = raw \* ([-+0-9.eE]+) \+ \(([-+0-9.eE]+)\)')





def normaddr(h): return '%x' % int(h, 16)





def normtxt(s): return re.sub(r'[^a-z0-9]+', ' ', s.lower()).strip()





def tag_of(block):

    m = TAG.match(block)

    return m.group(1) if m else None





def rank_of(tag):

    if tag is None: return len(RANK) + 1

    return RANK.get(tag, len(RANK))





def content_key(line):

    return normtxt(re.sub(r'^\s*(?:/\*|\*)\s?', '', line))





def process_block(block, asr_text, stats):

    """Return the block with redundant content lines removed, or None to drop it."""

    tag = tag_of(block)

    if tag is None: return block

    lines = block.splitlines(keepends=True)

    head, content, tail = lines[0], lines[1:-1], lines[-1]

    asr_addrs = {normaddr(h) for h in ADDR.findall(asr_text)} if asr_text else set()

    asr_norm = normtxt(asr_text) if asr_text else ''

    asr_low = asr_text.lower() if asr_text else ''

    seen = set(); out = []

    for ln in content:

        key = content_key(ln)

        if not key:

            out.append(ln); continue

        if key in seen:

            stats['duplicate_lines_dropped'] += 1; continue

        seen.add(key)

        if tag == 'CROSS-ECU / RX8DEFS REVIEW':

            m = CE_DESC.search(ln)

            if m and normaddr(m.group(1)) in asr_addrs:

                name = normtxt(m.group(2))

                if name and name in asr_norm:

                    stats['cross_ecu_lines_dropped'] += 1; continue

        if tag == 'MATH AND UNITS REVIEW':

            m = MATH_AFFINE.search(ln)

            if m:

                sig, step = normtxt(m.group(2)), m.group(3)

                try:

                    hx = '0x%08x' % struct.unpack('>I', struct.pack('>f', float(step)))[0]

                except (ValueError, OverflowError):

                    hx = None

                if sig in asr_norm and (step.lower() in asr_low or (hx and hx in asr_low)):

                    stats['math_units_lines_dropped'] += 1; continue

        out.append(ln)

    if not out:

        stats['empty_blocks_removed'] += 1

        return None

    return head + ''.join(out) + tail





def transform_head(head, stats):

    """Reorder tagged blocks canonically and drop redundant lines.



    head = leading whitespace + comment blocks separated by whitespace-only gaps.

    """

    matches = list(BLOCK.finditer(head))

    if not matches: return head

    lead = head[:matches[0].start()]

    blocks = [m.group(0) for m in matches]

    gaps = [head[matches[i].end():matches[i + 1].start()] for i in range(len(matches) - 1)]

    gaps.append(head[matches[-1].end():])

    tags = [tag_of(bl) for bl in blocks]

    asr_text = next((bl for bl, t in zip(blocks, tags) if t == 'ADDITIONAL SOURCE REVIEW'), '')

    new_blocks = [process_block(bl, asr_text, stats) if t else bl for bl, t in zip(blocks, tags)]

    keep = [(bl, gp) for bl, gp in zip(new_blocks, gaps) if bl is not None]

    if not keep: return lead + gaps[-1]

    new_blocks, gaps = [x[0] for x in keep], [x[1] for x in keep]

    kept_tags = [tag_of(bl) for bl in new_blocks]

    # stable canonical order: tagged blocks sorted by rank occupy the tagged slots in order

    tagged_slots = [i for i, t in enumerate(kept_tags) if t]

    order = sorted(tagged_slots, key=lambda i: (rank_of(kept_tags[i]), i))

    result = list(new_blocks)

    for slot, bi in zip(tagged_slots, order):

        result[slot] = new_blocks[bi]

    if result != new_blocks: stats['headers_reordered'] += 1

    out = lead

    for bl, gp in zip(result, gaps): out += bl + gp

    return out





def transform_view(text, anchors, stats):

    """Transform each pre-anchor head region of a monolith. anchors = [(anchor_text, pos), ...]."""

    pieces = []; last = 0

    for i, (atext, pos) in enumerate(anchors):

        start = anchors[i - 1][1] if i else 0

        region = text[start:pos]

        matches = list(BLOCK.finditer(region))

        cut = 0

        if matches:

            j = len(matches) - 1

            end_ok = region[matches[j].end():].strip() == ''

            while j > 0 and end_ok and region[matches[j - 1].end():matches[j].start()].strip() == '':

                j -= 1

            if end_ok:

                cand = matches[j].start()

                if region[:cand].strip() != '':

                    cut = cand

        head = region[cut:]

        new_head = transform_head(head, stats)

        pieces.append(text[last:start + cut])

        pieces.append(new_head)

        last = pos

    pieces.append(text[last:])

    return ''.join(pieces)





def main():

    stats = {'duplicate_lines_dropped': 0, 'cross_ecu_lines_dropped': 0, 'math_units_lines_dropped': 0,

             'headers_reordered': 0, 'empty_blocks_removed': 0, 'monoliths_changed': []}

    dec = b / 'decompiled'

    idx = list(csv.DictReader((dec / 'function_index.tsv').open(), delimiter='\t'))

    files_changed = 0

    for r in idx:

        p = dec / r['file']

        t = p.read_text()

        m = ANCHOR.search(t)

        assert m, r['file']

        new = transform_head(t[:m.start()], stats) + t[m.start():]

        if new != t:

            p.write_text(new); files_changed += 1

    for view in ('firmware_decompiled.c', 'named/firmware_named.c'):

        p = dec / view

        t = p.read_text()

        anchors = [(m.group(0), m.start()) for m in ANCHOR.finditer(t)]

        assert len(anchors) == len(idx), view

        new = transform_view(t, anchors, stats)

        if new != t:

            p.write_text(new); stats['monoliths_changed'].append(view)

    stats['function_files_changed'] = files_changed

    mono = (dec / 'firmware_decompiled.c').read_text()

    named = (dec / 'named/firmware_named.c').read_text()

    assert mono == named, 'monoliths diverged'

    for r in idx:

        t = (dec / r['file']).read_text()

        anchor = '/* ROM address: 0x' + r['address'] + ';'

        body = t[t.index(anchor):].strip()

        assert body in mono and body in named, r['address']

    stats['function_bodies_verified_in_both_monoliths'] = len(idx)

    stats['asr_blocks'] = mono.count('[ADDITIONAL SOURCE REVIEW]')

    out = b / 'comment_merge'

    out.mkdir(exist_ok=True)

    vfile = out / 'validation.json'

    # Accumulate application totals across runs; the per-run fields of an already

    # normalized tree are all zero, which doubles as the idempotency proof.

    keys = ('duplicate_lines_dropped', 'cross_ecu_lines_dropped', 'math_units_lines_dropped',

            'headers_reordered', 'empty_blocks_removed', 'function_files_changed')

    prior = {}

    if vfile.exists():

        prior = json.loads(vfile.read_text())

    stats['applied_total'] = {k: prior.get('applied_total', {}).get(k, 0) + stats.get(k, 0) for k in keys}

    stats['monoliths_changed_total'] = sorted(set(prior.get('monoliths_changed_total', [])) | set(stats['monoliths_changed']))

    vfile.write_text(json.dumps(stats, indent=2) + chr(10))

    print(json.dumps(stats, indent=2))





if __name__ == '__main__':

    main()

