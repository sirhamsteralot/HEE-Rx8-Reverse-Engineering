/* ROM address: 0x00057704; body bytes: 52; decompiled */

/* Function candidate recovered from ROM pointer at 5f54c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00057704(undefined4 param_1)

{
  char cVar1;
  char cVar2;
  
  cVar2 = DAT_ffffc1d4;
  cVar1 = DAT_ffffc1d3;
  diag_append_u8(param_1,0);
  diag_append_u8(param_1,(int)cVar1);
  diag_append_u8(param_1,(int)cVar2);
  diag_append_u8(param_1,0);
  return;
}


