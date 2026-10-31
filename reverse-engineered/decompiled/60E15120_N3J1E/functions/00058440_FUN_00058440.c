/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffb078 * 1000.0; decode = raw * 0.1219999939 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00058440; body bytes: 58; decompiled */

void FUN_00058440(void)

{
  undefined2 local_14;
  undefined2 uStack_12;
  undefined2 uStack_10;
  
  local_14 = rx8_encode_u16_affine_saturate(DAT_ffffb078 * 1000.0,0x3df9db22,0);
  uStack_12 = local_14;
  uStack_10 = local_14;
  FUN_0005904a(&DAT_ffff9034,&local_14);
  return;
}


