/* ROM address: 0x00057ea8; body bytes: 52; decompiled */

/* Function candidate recovered from ROM pointer at 5fcf0 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pidc117_ram_c1d3_c1d4(undefined4 param_1)

{
  char cVar1;
  char cVar2;
  
  cVar2 = DAT_ffffc244;
  cVar1 = DAT_ffffc243;
  diag_append_u8(param_1,0);
  diag_append_u8(param_1,(int)cVar1);
  diag_append_u8(param_1,(int)cVar2);
  diag_append_u8(param_1,0);
  return;
}


