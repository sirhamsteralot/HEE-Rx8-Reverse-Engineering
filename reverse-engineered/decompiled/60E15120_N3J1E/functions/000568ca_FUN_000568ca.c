/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x0003: OL Status. Dispatch identifier match; logger meaning is definition-derived.
 */
/* ROM address: 0x000568ca; body bytes: 38; decompiled */

/* Function candidate recovered from ROM pointer at 5f12c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag_read_ol_status(char param_1)

{
  byte bVar2;
  uint uVar1;
  
  bVar2 = diag_ol_status_byte();
  uVar1 = diag_ol_status_low_byte();
  diag_append_u16_be((int)param_1,(uVar1 & 0xff) + (uint)bVar2 * 0x100);
  return;
}


