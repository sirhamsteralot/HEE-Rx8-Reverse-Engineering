/* ROM address: 0x00067314; body bytes: 30; decompiled */

bool FUN_00067314(uint param_1)

{
  return (&DAT_ffff8d7c)[(uint)*(ushort *)(&DAT_0007daea + (param_1 & 0xffff) * 2) * 2] != '\0';
}


