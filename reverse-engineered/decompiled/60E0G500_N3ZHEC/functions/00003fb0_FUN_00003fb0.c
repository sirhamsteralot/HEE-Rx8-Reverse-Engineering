/* ROM address: 0x00003fb0; body bytes: 40; decompiled */

undefined4 FUN_00003fb0(short param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((0x12 < param_1) ||
     ((*(uint *)(&DAT_00004b44 + DAT_ffff7639 * 4) & *(uint *)(&DAT_00004940 + param_1 * 4)) == 0))
  {
    uVar1 = 3;
  }
  return uVar1;
}


