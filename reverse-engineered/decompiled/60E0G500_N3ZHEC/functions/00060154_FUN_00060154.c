/* ROM address: 0x00060154; body bytes: 18; decompiled */

bool FUN_00060154(uint param_1,byte param_2)

{
  return (param_2 & (&DAT_0007e338)[param_1 & 0xffff]) == 0;
}


