/* ROM address: 0x0005736a; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5fa38 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0047_ram_ad5e_pedal(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_ad5e();
  diag_append_u8((int)param_1,uVar1);
  return;
}


