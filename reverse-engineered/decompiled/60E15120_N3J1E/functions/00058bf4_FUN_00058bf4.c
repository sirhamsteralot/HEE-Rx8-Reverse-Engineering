/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffd0e0 * 1000.0; decode = raw * 0.00390625 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00058bf4; body bytes: 92; decompiled */

void FUN_00058bf4(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined2 local_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  
  uVar2 = 0;
  fVar1 = 1000.0;
  uVar3 = 0x3b800000;
  local_20 = rx8_encode_u16_affine_saturate(DAT_ffffd0e0 * 1000.0,0x3b800000,0);
  uStack_1e = 0;
  uStack_1c = rx8_encode_u16_affine_saturate(DAT_ffffd0dc * fVar1,uVar3,uVar2);
  FUN_0005904a(&DAT_ffff90b4,&local_20);
  return;
}


