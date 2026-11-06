/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pidff43_rom_id_bytes_ffb [high]: dispatch record 0x5f58c -> handler verified in ROM bytes + function_index; appends ROM bytes at 0xffb,0xffc,0xffd
 */
/* ROM address: 0x0005794e; body bytes: 32; decompiled */

/* Function candidate recovered from ROM pointer at 5f594 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pidff43_rom_id_bytes_ffb(undefined4 param_1)

{
  diag_append_u8(param_1,0x22);
  diag_append_u8(param_1,0xffffff93);
  diag_append_u8(param_1,0x6d);
  return;
}


