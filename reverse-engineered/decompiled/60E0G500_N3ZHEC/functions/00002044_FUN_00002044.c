/* ROM address: 0x00002044; body bytes: 14; decompiled */

uint FUN_00002044(short *param_1)

{
  return ~(int)*param_1 - ((uint)(int)*param_1 >> 8) & 0xff;
}


