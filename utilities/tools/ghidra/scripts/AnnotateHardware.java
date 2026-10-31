import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.CommentType;
import java.nio.file.*;
public class AnnotateHardware extends GhidraScript {
 public void run() throws Exception {
  int n=0;
  for(String line:Files.readAllLines(Path.of(getScriptArgs()[0],"firmware_annotations.tsv"))) {
   if(line.startsWith("address\t") || line.isBlank())continue;
   String[] fields=line.split("\t",2);var a=toAddr(Long.parseLong(fields[0],16));
   if(getFunctionAt(a)==null)throw new Exception("Missing expected function "+a);
   String old=currentProgram.getListing().getComment(CommentType.PLATE,a);
   if(old==null)old="";
   String marker="\n\n[WIRING REVIEW 2026-09-08]\n";
   int prior=old.indexOf(marker);if(prior>=0)old=old.substring(0,prior);
   setPlateComment(a,old+marker+fields[1]);n++;
  }
  println("Annotated "+n+" functions with wiring evidence and uncertainty");
 }
}
