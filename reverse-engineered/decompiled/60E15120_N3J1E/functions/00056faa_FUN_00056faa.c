/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffad10; decode = raw * 7.629394531e-05 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056faa; body bytes: 30; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f3ac. Table purpose inferred from
   neighboring code. */

void FUN_00056faa(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(DAT_ffffad10,0x38a00000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


