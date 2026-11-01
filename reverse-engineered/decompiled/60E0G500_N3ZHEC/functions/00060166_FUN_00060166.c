/* ROM address: 0x00060166; body bytes: 20; decompiled */

bool FUN_00060166(uint param_1,ushort param_2)

{
  return (param_2 & *(ushort *)(&DAT_0007e3c4 + (param_1 & 0xffff) * 2)) == 0;
}


