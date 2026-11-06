/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pidff42_rom_id_bytes_ff8 [high]: dispatch record 0x5f580 -> handler verified in ROM bytes + function_index; appends ROM bytes at 0xff8,0xff9,0xffa (via mov.w literals)
 */
/* ROM address: 0x0005792e; body bytes: 32; decompiled */

/* Function candidate recovered from ROM pointer at 5f588 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pidff42_rom_id_bytes_ff8(undefined4 param_1)

{
  diag_append_u8(param_1,0x27);
  diag_append_u8(param_1,0xffffff97);
  diag_append_u8(param_1,0x20);
  return;
}


