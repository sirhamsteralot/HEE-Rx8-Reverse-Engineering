/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0047_ram_ad5e_pedal [medium]: dispatch record 0x5f28c -> handler verified in ROM bytes + function_index; 0x5578a: DAT_ffffad5e decode(7.63e-05)*20*0.392157
 */
/* ROM address: 0x00056bc6; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f294 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0047_ram_ad5e_pedal(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_ad5e();
  diag_append_u8((int)param_1,uVar1);
  return;
}


