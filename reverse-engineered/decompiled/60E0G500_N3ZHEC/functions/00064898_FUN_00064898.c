/* ROM address: 0x00064898; body bytes: 46; decompiled */

uint FUN_00064898(uint param_1,uint param_2)

{
  if (((&DAT_ffff8d7c)[(param_1 & 0xffff) * 2] != ' ') &&
     (param_2 = param_2 + 1, (uint)(byte)(&DAT_0007df5e)[param_1 & 0xffff] <= (param_2 & 0x7f))) {
    param_2 = 0xc0;
  }
  return param_2;
}


