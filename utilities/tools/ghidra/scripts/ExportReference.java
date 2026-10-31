import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;
public class ExportReference extends GhidraScript {
 public void run() throws Exception {
  File out=new File(getScriptArgs()[0]); out.mkdirs();
  println("REFERENCE LANGUAGE: "+currentProgram.getLanguageID());
  for(MemoryBlock b:currentProgram.getMemory().getBlocks()) println("BLOCK "+b.getName()+" "+b.getStart()+" "+b.getSize());
  try(PrintWriter w=new PrintWriter(new File(out,"reference_functions.tsv"))) {
   w.println("address\tname\tsize\tcontiguous\tbytes");
   for(Function f:currentProgram.getFunctionManager().getFunctions(true)) {
    if(f.getEntryPoint().getOffset()>=0x80000) continue;
    long n=f.getBody().getNumAddresses();
    boolean contiguous=f.getBody().getNumAddressRanges()==1;
    StringBuilder hex=new StringBuilder();
    if(contiguous && n<65536) { byte[] bytes=new byte[(int)n]; currentProgram.getMemory().getBytes(f.getBody().getMinAddress(),bytes); for(byte b:bytes) hex.append(String.format("%02x",b&255)); }
    w.println(f.getEntryPoint()+"\t"+f.getName()+"\t"+n+"\t"+contiguous+"\t"+hex);
   }
  }
 }
}
