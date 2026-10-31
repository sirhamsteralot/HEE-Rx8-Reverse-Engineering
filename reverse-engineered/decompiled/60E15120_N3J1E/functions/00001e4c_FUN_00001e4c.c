/* ROM address: 0x00001e4c; body bytes: 38; decompiled */

int FUN_00001e4c(byte *param_1)

{
  return (uint)param_1[1] * 0x10000 + (uint)param_1[2] * 0x100 + (uint)*param_1 * 0x1000000 +
         (uint)param_1[3];
}


