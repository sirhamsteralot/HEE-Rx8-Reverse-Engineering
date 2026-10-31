import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.data.*;
import java.nio.file.*;
public class SetupTarget extends GhidraScript {
 public void run() throws Exception {
  Path base=Path.of(getScriptArgs()[0]);
  Memory mem=currentProgram.getMemory();
  MemoryBlock rom=mem.getBlock(toAddr(0));rom.setName("ROM");rom.setRead(true);rom.setWrite(false);rom.setExecute(true);
  MemoryBlock ram=mem.createUninitializedBlock("RAM",toAddr(0xffff6000L),0x8000,false);ram.setRead(true);ram.setWrite(true);
  MemoryBlock io=mem.createUninitializedBlock("IO",toAddr(0xffffe000L),0x2000,false);io.setRead(true);io.setWrite(true);io.setVolatile(true);
  Path regs=base.resolve("reference_project/RX8_6.rep/script_stuff/regs_7055_180.csv");
  for(String line:Files.readAllLines(regs).subList(1,Files.readAllLines(regs).size())) {
   String[] r=line.split(","); long a=Long.decode(r[1]);createLabel(toAddr(a),r[0],true);
  }
  for(String line:Files.readAllLines(base.resolve("metadata/calibration_labels.tsv"))) {
   String[] r=line.split("\t");if(r[0].equals("address"))continue;
   createLabel(toAddr(Long.parseLong(r[0],16)),r[1],true);setEOLComment(toAddr(Long.parseLong(r[0],16)),"Local RX8Defs 60E15120 definition: "+r[2]+"; semantic annotation, not independently validated.");
  }
  createLabel(toAddr(0x2000),"firmware_id",true);
  // Only defined architectural vectors are used; do not scan reserved vector slots as pointers.
  java.util.ArrayList<String> vectors=new java.util.ArrayList<>();vectors.add("Power_Reset,0x0,Power reset");
  vectors.addAll(Files.readAllLines(base.resolve("reference_project/RX8_6.rep/script_stuff/ivt_7055.csv")).subList(1,Files.readAllLines(base.resolve("reference_project/RX8_6.rep/script_stuff/ivt_7055.csv")).size()));
  for(String line:vectors) {
   String[] r=line.split(",");long a=Long.decode(r[1]);long dest=Integer.toUnsignedLong(mem.getInt(toAddr(a)));
   if(dest>=0x80000 || dest%2!=0)continue;
   createData(toAddr(a),new PointerDataType()); createLabel(toAddr(a),"vector_"+r[0],true);
   disassemble(toAddr(dest));if(getFunctionAt(toAddr(dest))==null)createFunction(toAddr(dest),r[0]);
  }
  int seeds=0;
  for(String line:Files.readAllLines(base.resolve("metadata/matched_functions.tsv"))) {
   String[] r=line.split("\t");if(r[0].equals("address"))continue;
   var a=toAddr(Long.parseLong(r[0],16));
   if(getInstructionContaining(a)!=null && getInstructionAt(a)==null)continue;
   disassemble(a);
   if(getFunctionAt(a)==null)createFunction(a,r[1]);
   else if(!r[1].startsWith("FUN_"))getFunctionAt(a).setName(r[1],SourceType.USER_DEFINED);
   setPlateComment(a,"Unique exact-byte match to related 60E0FC00 function at "+r[2]+" ("+r[3]+" bytes). Names prefixed ref_ are inherited hypotheses."); seeds++;
  }
  println("Seeded "+seeds+" matched functions");
 }
}
