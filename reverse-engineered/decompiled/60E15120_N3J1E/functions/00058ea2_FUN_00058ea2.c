/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffc4e4 / 100.0; decode = raw * 0.003906199941 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00058ea2; body bytes: 96; decompiled */

void FUN_00058ea2(void)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 uVar3;
  undefined2 local_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  
  uVar3 = 0;
  uVar1 = 0x3b7fff29;
  fVar2 = 100.0;
  local_20 = rx8_encode_u16_affine_saturate(DAT_ffffc4e4 / 100.0,0x3b7fff29,0);
  uStack_1e = 0;
  uStack_1c = rx8_encode_u16_affine_saturate(DAT_ffffc50c / fVar2,uVar1,uVar3);
  FUN_0005904a(&DAT_ffff90d4,&local_20);
  return;
}


