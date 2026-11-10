/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0200_dtc_count_stored [high]: dispatch record 0x5f2bc -> handler verified in ROM bytes + function_index; ref_faultSomething0x0 0x5fab2: 0x61450(0x80,0) - 0x5f8fa() + 1, clamp 0xff
 */
/* ROM address: 0x00056ca0; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f2c4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0200_dtc_count_stored(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = dtc_count_stored();
  diag_append_u8((int)param_1,uVar1);
  return;
}


