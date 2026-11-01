/* ROM address: 0x00057edc; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5fcfc and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pidc124_diag_status_bits(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_status_bit_pack();
  diag_append_u8((int)param_1,uVar1);
  return;
}


