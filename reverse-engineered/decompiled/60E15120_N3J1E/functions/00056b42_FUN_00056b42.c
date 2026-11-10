/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid003c_ram_c644_scaled [medium]: dispatch record 0x5f244 -> handler verified in ROM bytes + function_index; 0x5571a: DAT_ffffc644*0.1-40 (fuel-chain cell named in ROADMAP group C)
 */
/* ROM address: 0x00056b42; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f24c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid003c_ram_c644_scaled(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_c644();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


