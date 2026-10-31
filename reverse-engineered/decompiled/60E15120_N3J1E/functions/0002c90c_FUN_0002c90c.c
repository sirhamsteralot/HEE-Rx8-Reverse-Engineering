/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): 0x40800000; decode = raw * 1 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0002c90c; body bytes: 160; decompiled */

void FUN_0002c90c(void)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (DAT_ffffbbcd == '\0') {
    uVar3 = 0;
    uVar4 = 0x3f800000;
    bVar1 = rx8_encode_u8_affine_saturate(0x40800000,0x3f800000,0);
    bVar2 = DAT_ffffbc81;
    if (bVar1 < DAT_ffffbc81) {
      bVar2 = bVar1;
    }
    bVar1 = rx8_encode_u8_affine_saturate(0x41980000,uVar4,uVar3);
    if (DAT_ffffbc82 <= bVar1) {
      bVar1 = DAT_ffffbc82;
    }
    DAT_ffffbc83 = (&CAL_Table_3D___110__1075)[(short)(ushort)bVar1 * 5 + (uint)bVar2];
    if (4 < DAT_ffffbc83) {
      DAT_ffffbc83 = 4;
    }
  }
  else {
    DAT_ffffbc83 = 0;
  }
  return;
}


