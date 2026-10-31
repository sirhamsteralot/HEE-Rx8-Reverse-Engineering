import ghidra.app.script.GhidraScript;
import java.io.*;
public class RecoverDispatch extends GhidraScript {
 public void run() throws Exception {
  int n=0;
  try(PrintWriter w=new PrintWriter(new File(getScriptArgs()[0],"diagnostic_dispatch.tsv"))) {
   w.println("record_address\tdescriptor\tflags\ttarget\tnew_function");
   // 99 consecutive 12-byte records, identified in this target ROM.
   for(long row=0x5f10c;row<0x5f5b0;row+=12) {
    long a=Integer.toUnsignedLong(getInt(toAddr(row+8)));boolean made=false;
    if(getFunctionAt(toAddr(a))==null && getFunctionContaining(toAddr(a))==null) {
     disassemble(toAddr(a));if(getInstructionAt(toAddr(a))!=null && createFunction(toAddr(a),null)!=null){made=true;n++;setPlateComment(toAddr(a),"Handler candidate from 12-byte diagnostic dispatch record at "+Long.toHexString(row)+". Table purpose inferred from neighboring code.");}
    }
    w.printf("%08x\t%08x\t%08x\t%08x\t%b\n",row,getInt(toAddr(row)),getInt(toAddr(row+4)),a,made);
   }
  }
  println("Recovered "+n+" dispatch handlers");
 }
}
