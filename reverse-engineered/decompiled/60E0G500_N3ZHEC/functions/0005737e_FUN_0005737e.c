/* ROM address: 0x0005737e; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5fa44 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0049_ram_a9c4_pedal(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_a9c4();
  diag_append_u8((int)param_1,uVar1);
  return;
}


