/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffcac4 * 24.0; decode = raw * 0.003906199941 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00058700; body bytes: 86; decompiled */

void FUN_00058700(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined2 local_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  
  uVar2 = 0;
  uVar1 = 0x3b7fff29;
  local_1c = rx8_encode_u16_affine_saturate(DAT_ffffcac4 * 24.0,0x3b7fff29,0);
  uStack_1a = 0;
  uStack_18 = rx8_encode_u16_affine_saturate(0x41c00000,uVar1,uVar2);
  FUN_0005904a(&DAT_ffff9074,&local_1c);
  return;
}


