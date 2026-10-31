#!/usr/bin/env python3
"""Check artifact consistency and instruction bytes, not semantic equivalence."""
from pathlib import Path
import csv, hashlib, json
base=Path(__file__).resolve().parents[1]
info=json.loads((base/'metadata/input.json').read_text())
rom=Path(info['file']).read_bytes()
assert len(rom)==info['size']
assert hashlib.sha256(rom).hexdigest()==info['sha256']
def rows(path): return list(csv.DictReader(path.open(),delimiter='\t'))
index=rows(base/'decompiled/function_index.tsv')
summary=json.loads((base/'decompiled/analysis_summary.json').read_text())
assert len(index)==summary['functions']
assert len({r['address'] for r in index})==len(index)
assert {r['file'] for r in index}=={'functions/'+p.name for p in (base/'decompiled/functions').glob('*.c')}
assert sum(r['status']=='failed' for r in index)==summary['failed']
assert sum(r['status']=='decompiled_with_warnings' for r in index)==summary['with_warnings']
for row in index:
 text=(base/'decompiled'/row['file']).read_text()
 assert '0x'+row['address'] in text
covered=set();instructions=0
for line in (base/'decompiled/firmware_disassembly.asm').read_text().splitlines():
 addr,raw,_=line.split(None,2);addr=int(addr,16);raw=bytes.fromhex(raw)
 assert len(raw)==2, 'Unexpected non-SH2 instruction width'
 assert addr % 2 == 0, 'Unaligned instruction'
 assert rom[addr:addr+len(raw)]==raw
 covered.update(range(addr,addr+len(raw)));instructions+=1
assert len(covered)==summary['instruction_bytes']
ref={r['address']:r for r in rows(base/'metadata/reference_functions.tsv')}
for r in rows(base/'metadata/matched_functions.tsv'):
 a=int(r['address'],16);raw=bytes.fromhex(ref[r['reference_address']]['bytes'])
 assert rom[a:a+len(raw)]==raw
 assert rom.find(raw)==a and rom.find(raw,a+1)==-1
result={'input_sha256_verified':True,'function_files_verified':len(index),'instructions_byte_verified':instructions,'instruction_bytes_verified':len(covered),'exact_reference_matches_verified':len(rows(base/'metadata/matched_functions.tsv')),'semantic_equivalence_verified':False}
(base/'metadata/validation.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))
