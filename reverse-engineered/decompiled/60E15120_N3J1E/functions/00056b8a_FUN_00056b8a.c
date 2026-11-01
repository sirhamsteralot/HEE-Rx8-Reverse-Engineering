/* [ADDITIONAL SOURCE REVIEW]
 * diag_engine_load [high]: RomRaider PID 0x0043 'Engine Load' handler: encodes engine_load_ffffc0b4 via rx8_encode_u16_affine_saturate (step 0x3b808080 ~ 0.00392) as u16 BE.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x0043: Engine Load. Dispatch identifier match; logger meaning is definition-derived.
 */
/* ROM address: 0x00056b8a; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f270 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0043_engine_load_g_rev(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_load_g_rev();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


