/* ROM address: 0x00067904; body bytes: 98; decompiled */

/* Function candidate recovered from ROM pointer at 67524 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined4 FUN_00067904(char param_1,char *param_2,short param_3)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    FUN_000688c8(8,param_2,(int)param_3);
    DAT_ffffd984 = DAT_ffffd984 + param_3;
    uVar1 = FUN_000694fa();
  }
  else {
    if (param_1 == '\x02') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    uVar1 = FUN_00066ece(8,(int)*param_2,uVar1);
  }
  return uVar1;
}


