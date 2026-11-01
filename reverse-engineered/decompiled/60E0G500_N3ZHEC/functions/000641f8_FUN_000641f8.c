/* ROM address: 0x000641f8; body bytes: 52; decompiled */

void FUN_000641f8(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8d74;
  (&DAT_ffff8962)[uVar1 * 0x34] =
       (&DAT_ffff8962)[uVar1 * 0x34] +
       (((char)(&DAT_ffff8932)[uVar1 * 0x1a] + (char)((ushort)(&DAT_ffff8932)[uVar1 * 0x1a] >> 8)) -
       ((char)((uint)param_1 >> 8) + (char)param_1));
  (&DAT_ffff8932)[uVar1 * 0x1a] = (short)param_1;
  return;
}


