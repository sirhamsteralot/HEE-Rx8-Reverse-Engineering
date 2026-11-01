/* ROM address: 0x0006288c; body bytes: 80; decompiled */

uint FUN_0006288c(uint param_1,byte param_2,char param_3)

{
  uint uVar1;
  
  uVar1 = (uint)param_2;
  if ((uVar1 == 0x10) || (uVar1 == 0x11)) {
    uVar1 = FUN_00064670((int)(char)(&DAT_ffff8d7d)[(param_1 & 0xffff) * 2] | 1);
    return uVar1;
  }
  if ((uVar1 == 0x20) && ((param_3 == -0x40 || (param_3 == -0x3f)))) {
    uVar1 = FUN_00064670((int)(char)(&DAT_ffff8d7d)[(param_1 & 0xffff) * 2] | 2);
    return uVar1;
  }
  return uVar1;
}


