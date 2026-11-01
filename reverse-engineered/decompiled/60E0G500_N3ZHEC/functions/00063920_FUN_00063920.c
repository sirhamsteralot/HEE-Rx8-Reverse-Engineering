/* ROM address: 0x00063920; body bytes: 46; decompiled */

void FUN_00063920(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8928;
  (&DAT_ffff87e6)[uVar1 * 0x10] =
       (&DAT_ffff87e6)[uVar1 * 0x10] +
       (((char)(&DAT_ffff87da)[uVar1 * 8] + (char)((ushort)(&DAT_ffff87da)[uVar1 * 8] >> 8)) -
       ((char)((uint)param_1 >> 8) + (char)param_1));
  (&DAT_ffff87da)[uVar1 * 8] = (short)param_1;
  return;
}


