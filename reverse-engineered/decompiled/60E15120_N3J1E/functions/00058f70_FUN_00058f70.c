/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffc5f0; decode = raw * 0.09999999404 + (-40) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00058f70; body bytes: 82; decompiled */

void FUN_00058f70(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined2 local_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  
  uVar1 = 0x3dcccccc;
  uVar2 = 0xc2200000;
  local_1c = rx8_encode_u16_affine_saturate(DAT_ffffc5f0,0x3dcccccc,0xc2200000);
  uStack_1a = rx8_encode_u16_affine_saturate(0x428e8000,uVar1,uVar2);
  uStack_18 = 0xffff;
  FUN_0005904a(&DAT_ffff90e4,&local_1c);
  return;
}


