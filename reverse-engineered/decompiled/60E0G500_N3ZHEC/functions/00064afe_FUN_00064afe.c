/* ROM address: 0x00064afe; body bytes: 62; decompiled */

uint FUN_00064afe(ushort *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_ffff8d7c)[(uint)*param_1 * 2];
  if (uVar1 == 0x11) {
    uVar1 = FUN_00063744(0x50);
    return uVar1;
  }
  if (((uVar1 == 0x10) || (uVar1 == 0)) &&
     (uVar1 = (uint)(char)*(byte *)(param_1 + 5), *(byte *)(param_1 + 5) < 0x50)) {
    uVar1 = FUN_00063744(uVar1 + 1);
    return uVar1;
  }
  return uVar1;
}


