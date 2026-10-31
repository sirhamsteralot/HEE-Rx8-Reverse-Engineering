/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): 0x43960000; decode = raw * 0.1219999939 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x000584ae; body bytes: 58; decompiled */

void FUN_000584ae(void)

{
  undefined2 local_14;
  undefined2 uStack_12;
  undefined2 uStack_10;
  
  local_14 = rx8_encode_u16_affine_saturate(0x43960000,0x3df9db22,0);
  uStack_12 = local_14;
  uStack_10 = local_14;
  FUN_0005904a(&DAT_ffff9044,&local_14);
  return;
}


