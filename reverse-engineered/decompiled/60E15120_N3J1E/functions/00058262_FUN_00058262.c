/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffc6f0; decode = raw * 0.003906199941 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00058262; body bytes: 80; decompiled */

void FUN_00058262(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined2 local_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  
  uVar2 = 0;
  uVar1 = 0x3b7fff29;
  local_1c = rx8_encode_u16_affine_saturate(o2_monitor_ratio_ch0_ffffc6f0,0x3b7fff29,0);
  uStack_1a = rx8_encode_u16_affine_saturate(DAT_ffffc6f8,uVar1,uVar2);
  uStack_18 = 0xffff;
  FUN_0005904a(&DAT_ffff9014,&local_1c);
  return;
}


