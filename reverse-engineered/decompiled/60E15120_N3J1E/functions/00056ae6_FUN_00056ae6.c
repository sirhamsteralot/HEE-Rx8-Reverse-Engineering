/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0030_gear_or_vin_byte [high]: dispatch record 0x5f214 -> handler verified in ROM bytes + function_index; 0x55632: 0x61d14 = inferred_ram_8788_ffff8788_ffff8788 u16, clamp 0xff | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x00056ae6; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f21c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0030_gear_or_vin_byte(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_read_gear_byte();
  diag_append_u8((int)param_1,uVar1);
  return;
}


