/* ROM address: 0x00056a32; body bytes: 38; decompiled */

/* Function candidate recovered from ROM pointer at 5f1c8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid0015_o2s2_voltage_trim(char param_1)

{
  byte bVar2;
  uint uVar1;
  
  bVar2 = candidate_diag_encode_o2s2();
  uVar1 = candidate_diag_encode_trim_b074();
  diag_append_u16_be((int)param_1,(uVar1 & 0xff) + (uint)bVar2 * 0x100);
  return;
}


