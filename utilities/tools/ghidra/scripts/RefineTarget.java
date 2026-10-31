import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.*;
import java.io.*;
public class RefineTarget extends GhidraScript {
 void floats(long addr,String name,int n)throws Exception {
  Function f=getFunctionAt(toAddr(addr));if(f==null)return;
  Parameter[] p=new Parameter[n];for(int i=0;i<n;i++)p[i]=new ParameterImpl("arg"+i,FloatDataType.dataType,currentProgram);
  f.updateFunction("__stdcall",new ReturnParameterImpl(FloatDataType.dataType,currentProgram),Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS,true,SourceType.USER_DEFINED,p);
  f.setName(name,SourceType.USER_DEFINED);
 }
 public void run() throws Exception {
  int found=0;
  try(PrintWriter w=new PrintWriter(new File(getScriptArgs()[0],"recovered_pointer_seeds.tsv"))) {
   w.println("address\tpointer_source\tevidence");
   for(long off=0;off<0x80000;off+=4) {
    long a=Integer.toUnsignedLong(getInt(toAddr(off)));if(a<0x400 || a>=0x6c000 || a%2!=0)continue;
    if(getInstructionContaining(toAddr(a))!=null || getFunctionContaining(toAddr(a))!=null)continue;
    int opcode=Short.toUnsignedInt(getShort(toAddr(a)));
    if(opcode!=0x4f22 && (opcode&0xff0f)!=0x2f06)continue;
    if(disassemble(toAddr(a)) && getInstructionAt(toAddr(a))!=null) {
     Function f=createFunction(toAddr(a),null);
     if(f!=null){found++;w.printf("%08x\t%08x\tROM pointer plus SH register-save prologue; heuristic\n",a,off);setPlateComment(toAddr(a),"Function candidate recovered from ROM pointer at "+Long.toHexString(off)+" and register-save prologue. Heuristic boundary; inspect disassembly.");}
    }
   }
  }
  // Signatures verified against floating-point input/output register use in these routines.
  floats(0x23b0,"rx8_first_order_filter",4);
  floats(0x23dc,"rx8_absolute_difference",2);
  floats(0x23e4,"rx8_max_float",2);
  floats(0x23f4,"rx8_min_float",2);
  floats(0x2404,"rx8_clamp_float",3);
  println("Recovered "+found+" pointer/prologue function candidates");
 }
}
