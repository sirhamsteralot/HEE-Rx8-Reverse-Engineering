/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs service 0x22 identifier 0x1746: Knock Retard. Dispatch identifier match; logger meaning is definition-derived.
 * RX8Defs diagnostic chain suggests RAM 0xffffa734 = knock_retard. Direct C dataflow to handler 0x0005707a; semantic candidate, not a recovered original symbol.
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): knock_retard_ffffa734; decode = raw * 0.3515625 + (0) [degrees]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0005707a; body bytes: 30; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f3e8. Table purpose inferred from
   neighboring code. */

void candidate_diag_read_knock_retard(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(knock_retard_ffffa734,0x3eb40000,0);
  diag_append_u8((int)param_1,uVar1);
  return;
}


