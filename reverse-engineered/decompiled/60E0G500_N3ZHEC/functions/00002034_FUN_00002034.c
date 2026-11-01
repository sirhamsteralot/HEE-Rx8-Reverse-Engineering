/* ROM address: 0x00002034; body bytes: 14; decompiled */

uint FUN_00002034(uint *param_1)

{
  return ~*param_1 - (*param_1 >> 0x10) & 0xffff;
}


