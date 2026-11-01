/* ROM address: 0x00066e4e; body bytes: 30; decompiled */

undefined4 FUN_00066e4e(byte param_1,uint param_2)

{
  return (&DAT_0005f440)[(param_1 - 1) * 8 + ((param_2 & 0xff) >> 5)];
}


