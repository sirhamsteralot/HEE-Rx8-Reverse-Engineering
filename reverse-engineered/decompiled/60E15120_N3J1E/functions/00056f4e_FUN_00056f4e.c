/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): DAT_ffffa9bc; decode = raw * 0.3921568394 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056f4e; body bytes: 30; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f388. Table purpose inferred from
   neighboring code. */

void FUN_00056f4e(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(DAT_ffffa9bc,0x3ec8c8c8,0);
  diag_append_u8((int)param_1,uVar1);
  return;
}


