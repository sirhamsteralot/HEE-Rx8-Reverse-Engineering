/* ROM address: 0x00064b5c; body bytes: 96; decompiled */

uint FUN_00064b5c(ushort *param_1)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *(byte *)(param_1 + 3);
  uVar2 = (uint)(byte)(&DAT_ffff8d7c)[(uint)*param_1 * 2];
  if ((uVar2 != 0x11) &&
     ((((bVar1 == 0 || (uVar2 = (uint)bVar1, 0x3f < uVar2)) && ((bVar1 < 0x81 || (0xbf < bVar1))))
      || ((byte)(&DAT_ffff87e2)[(uint)DAT_ffff8928 * 0x10] < 0x50)))) {
    return uVar2;
  }
  uVar2 = FUN_0006383c(0);
  return uVar2;
}


