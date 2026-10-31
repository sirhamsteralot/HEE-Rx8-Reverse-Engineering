import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
public class ExportTarget extends GhidraScript {
 public void run() throws Exception {
  File out=new File(getScriptArgs()[0]);out.mkdirs();File funcs=new File(out,"functions");funcs.mkdirs();
  File dasm=new File(getScriptArgs().length>1?getScriptArgs()[1]:getScriptArgs()[0]);dasm.mkdirs(); // disassembly outputs
  for(File old:funcs.listFiles()) if(old.getName().matches("[0-9a-f]{8}_.*\\.c")) Files.delete(old.toPath());
  DecompInterface decomp=new DecompInterface();DecompileOptions options=new DecompileOptions();options.grabFromProgram(currentProgram);decomp.setOptions(options);decomp.openProgram(currentProgram);
  int count=0,ok=0,failed=0,warnings=0;AddressSet covered=new AddressSet();AddressSet functionBodies=new AddressSet();
  try(PrintWriter all=new PrintWriter(new File(out,"firmware_decompiled.c"));PrintWriter index=new PrintWriter(new File(out,"function_index.tsv"));PrintWriter calls=new PrintWriter(new File(out,"callgraph.tsv"));PrintWriter bad=new PrintWriter(new File(dasm,"decompiler_issues.tsv"));PrintWriter asm=new PrintWriter(new File(dasm,"firmware_disassembly.asm"));PrintWriter sym=new PrintWriter(new File(out,"symbols.tsv"))) {
   all.println("/* Decompiled from 60E15120_N3J1E.bin using Ghidra.\n * Analysis C: not original source and not a buildable replacement firmware.\n * ref_ names are inferred from unique exact-byte matches to 60E0FC00.\n * CAL_ labels come from local RX8Defs; see metadata and README.\n */\n");
   index.println("address\tname\tbody_bytes\tstatus\tfile");calls.println("caller\tcallee\tcallee_name");bad.println("address\tname\tissue");sym.println("address\tname\ttype\tsource");
   for(Symbol s:currentProgram.getSymbolTable().getAllSymbols(true)) sym.println(s.getAddress()+"\t"+s.getName()+"\t"+s.getSymbolType()+"\t"+s.getSource());
   for(Instruction ins:currentProgram.getListing().getInstructions(true)) {
    if(ins.getAddress().getOffset()>=0x80000)continue;
    covered.add(ins.getMinAddress(),ins.getMaxAddress());StringBuilder h=new StringBuilder();for(byte b:ins.getBytes())h.append(String.format("%02x",b&255));
    asm.println(ins.getAddress()+"  "+h+"  "+ins);
   }
   for(Function f:currentProgram.getFunctionManager().getFunctions(true)) {
    monitor.checkCancelled();if(f.getEntryPoint().getOffset()>=0x80000)continue;
    count++;functionBodies.add(f.getBody());String addr=f.getEntryPoint().toString();String filename=addr+"_"+f.getName().replaceAll("[^a-zA-Z0-9_]","_")+".c";
    DecompileResults res=decomp.decompileFunction(f,45,monitor);String code;String status;
    if(res.decompileCompleted() && res.getDecompiledFunction()!=null) {
     code=res.getDecompiledFunction().getC();ok++;status="decompiled";
     if(code.contains("WARNING") || !res.getErrorMessage().isBlank()){warnings++;status="decompiled_with_warnings";bad.println(addr+"\t"+f.getName()+"\t"+res.getErrorMessage().replaceAll("[\\r\\n\\t]"," ")+"; inspect WARNING comments in C");}
    } else {failed++;status="failed";code="/* DECOMPILATION FAILED: "+res.getErrorMessage().replace("*/","* /")+" */\n";bad.println(addr+"\t"+f.getName()+"\t"+res.getErrorMessage().replaceAll("[\\r\\n\\t]"," "));}
    String head="/* ROM address: 0x"+addr+"; body bytes: "+f.getBody().getNumAddresses()+"; "+status+" */\n";
    Files.writeString(new File(funcs,filename).toPath(),head+code+"\n");all.println(head+code);index.println(addr+"\t"+f.getName()+"\t"+f.getBody().getNumAddresses()+"\t"+status+"\tfunctions/"+filename);
    for(Function callee:f.getCalledFunctions(monitor))calls.println(addr+"\t"+callee.getEntryPoint()+"\t"+callee.getName());
    if(count%250==0)println("Exported "+count+" functions");
   }
  } finally {decomp.dispose();}
  AddressSet unknown=new AddressSet(toAddr(0),toAddr(0x7ffff));unknown=unknown.subtract(covered);
  try(PrintWriter w=new PrintWriter(new File(dasm,"non_instruction_ranges.tsv"))){w.println("start\tend\tbytes");for(AddressRange r:unknown)w.println(r.getMinAddress()+"\t"+r.getMaxAddress()+"\t"+r.getLength());}
  String report="{\n  \"functions\": "+count+",\n  \"decompiled\": "+ok+",\n  \"failed\": "+failed+",\n  \"with_warnings\": "+warnings+",\n  \"instruction_bytes\": "+covered.getNumAddresses()+",\n  \"function_body_bytes\": "+functionBodies.getNumAddresses()+",\n  \"rom_bytes\": 524288\n}\n";
  Files.writeString(new File(out,"analysis_summary.json").toPath(),report);println(report);
 }
}
