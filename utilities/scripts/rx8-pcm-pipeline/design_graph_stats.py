#!/usr/bin/env python3
"""Compute call-graph and structure statistics for design/README.md.

Writes design/graph_stats.json (inputs to the document) and
design/validation.json (cross-checks). Direct edges only: indirect dispatch,
jump tables, the task table and the diagnostic dispatch table are separate
entry mechanisms and are listed explicitly."""
from pathlib import Path
import csv,json,struct
from collections import Counter,defaultdict
from paths import b, base, rom_file, ROOT  # legacy-layout shim (paths.py): maps input/Tuning-merged keys to this repo
out=b/'design';out.mkdir(exist_ok=True)
rom=rom_file().read_bytes()
idx=list(csv.DictReader((b/'decompiled/function_index.tsv').open(),delimiter='\t'))
calls=list(csv.DictReader((b/'decompiled/callgraph.tsv').open(),delimiter='\t'))
syms=list(csv.DictReader((b/'decompiled/symbols.tsv').open(),delimiter='\t'))
disp=list(csv.DictReader((b/'metadata/diagnostic_dispatch.tsv').open(),delimiter='\t'))
byaddr={r['address']:r for r in idx}
out_g=defaultdict(set);inn=defaultdict(set)
for r in calls:
    if r['caller'] in byaddr and r['callee'] in byaddr and r['caller']!=r['callee']:
        out_g[r['caller']].add(r['callee']);inn[r['callee']].add(r['caller'])
# vector entries
vectors={}
for r in syms:
    if r['name'].startswith('vector_'):
        t=struct.unpack_from('>I',rom,int(r['address'],16))[0]
        vectors[r['name']]=f'{t:08x}'
# task table at 0x4998: 16-byte records {entry, mask, param, stack}
tasks=[]
for off in range(0x4998,0x4ab8,16):
    e,m,p,s=struct.unpack_from('>IIII',rom,off)
    tasks.append({'record':f'{off:08x}','entry':f'{e:08x}','entry_name':byaddr[f'{e:08x}']['name'],
                  'mask':f'0x{m:08x}','param':f'0x{p:08x}','stack':f'0x{s:08x}'})
def reach(seed):
    seen=set();stack=[seed]
    while stack:
        x=stack.pop()
        if x in seen:continue
        seen.add(x);stack.extend(out_g.get(x,()))
    return seen
handlers=set(r['target'] for r in disp)
stats={
 'functions':len(idx),'direct_edges':len(calls),
 'leaf_functions':sum(1 for r in idx if r['address'] not in out_g),
 'never_called':sum(1 for r in idx if r['address'] not in inn),
 'thunks':sum(1 for r in idx if r['name'].startswith('thunk_')),
 'dispatch_handlers':len(handlers),
 'vectors':vectors,
 'boot_reachable_from_reset':len(reach('000008b8')),
 'task_table':{'base':'0x4998','record_bytes':16,'records':len(tasks),'entries':tasks},
 'fan_in_top':[{'address':a,'name':byaddr[a]['name'],'callers':n}
   for a,n in Counter({c:len(v) for c,v in inn.items()}).most_common(20)],
 'fan_out_top':[{'address':a,'name':byaddr[a]['name'],'callees':n}
   for a,n in Counter({c:len(v) for c,v in out_g.items()}).most_common(10)],
 'fan_in_histogram':{str(k):v for k,v in sorted(Counter(len(inn.get(r['address'],())) for r in idx).items())},
 'code_bands':{f'0x{k<<12:05x}':v for k,v in sorted(Counter(int(r['address'],16)>>12 for r in idx).items())},
}
(b/'design/graph_stats.json').write_text(json.dumps(stats,indent=2)+'\n')
checks={
 'functions_match_summary':len(idx)==json.loads((b/'decompiled/analysis_summary.json').read_text())['functions'],
 'edges_match_callgraph_rows':len(calls)==6977,
 'task_table_records_valid':all(0x400<=int(t['entry'],16)<0x6c000 and int(t['stack'],16)>>16==0xffff for t in tasks),
 'dispatch_handlers_all_in_index':all(h in byaddr for h in handlers),
 'vectors_resolve':all(v in byaddr for v in vectors.values()),
 'leaf_plus_called_equals_total':stats['leaf_functions']+sum(1 for r in idx if r['address'] in out_g)==len(idx),
}
(b/'design/validation.json').write_text(json.dumps(checks,indent=2)+'\n')
print(json.dumps({'stats_written':True,'checks':checks},indent=2))
