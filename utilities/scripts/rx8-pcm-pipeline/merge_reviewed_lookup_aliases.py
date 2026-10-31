#!/usr/bin/env python3
"""Merge curated lookup-table aliases into named/lookup_aliases.tsv (idempotent).

name_lookup_variables.py regenerates named/lookup_aliases.tsv from scratch on a
fresh export, so reviewed table aliases live in
source_review/accepted_lookup_aliases.tsv and are merged in afterwards, before
integrate_reviewed_names.py reads the file. For a token with several rows the
last row wins in the integrator, so appended rows override generated ones.
"""
from pathlib import Path
import csv, json

from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
FIELDS = ['original', 'alias', 'basis', 'evidence']


def read_rows(path):
    with path.open(newline='') as f:
        return list(csv.DictReader(f, delimiter='\t'))


def write_rows(path, rows):
    with path.open('w', newline='') as f:
        w = csv.DictWriter(f, fieldnames=FIELDS, delimiter='\t')
        w.writeheader()
        w.writerows(rows)


def main():
    src = b / 'source_review/accepted_lookup_aliases.tsv'
    dst = b / 'named/lookup_aliases.tsv'
    curated = read_rows(src)
    rows = read_rows(dst)
    pairs = {(r['original'], r['alias']) for r in rows}
    added = 0
    for r in curated:
        if (r['original'], r['alias']) in pairs:
            continue
        rows.append({k: r[k] for k in FIELDS})
        pairs.add((r['original'], r['alias']))
        added += 1
    write_rows(dst, rows)
    print(json.dumps({'curated_rows': len(curated), 'rows_added': added,
                      'lookup_aliases_total': len(rows)}, indent=2))


if __name__ == '__main__':
    main()
