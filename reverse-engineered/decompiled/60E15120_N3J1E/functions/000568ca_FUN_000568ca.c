/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x0003: OL Status. Dispatch identifier match; logger meaning is definition-derived.
 */
/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0003_fuel_system_status_ol_cl [high]: dispatch record 0x5f124 -> handler verified in ROM bytes + function_index; diag_ol_status_byte 0x5535e encodes CL/OL per OBD PID 03 (0x10 CL+DFE, 2 CL, 4 OL-not-allowed, 8 OL cold, 1 OL); low byte const 0
 */
/* ROM address: 0x000568ca; body bytes: 38; decompiled */

/* Function candidate recovered from ROM pointer at 5f12c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0003_fuel_system_status_ol_cl(char param_1)

{
  byte bVar2;
  uint uVar1;
  
  bVar2 = diag_ol_status_byte();
  uVar1 = diag_ol_status_low_byte();
  diag_append_u16_be((int)param_1,(uVar1 & 0xff) + (uint)bVar2 * 0x100);
  return;
}


