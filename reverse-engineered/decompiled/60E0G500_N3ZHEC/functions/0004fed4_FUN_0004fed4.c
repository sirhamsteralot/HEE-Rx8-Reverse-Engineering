/* ROM address: 0x0004fed4; body bytes: 110; decompiled */

char FUN_0004fed4(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar2 = DAT_ffffcfe6;
  uVar1 = DAT_ffffcfe4;
  if (((DAT_ffffcffb == '\x01') && (DAT_ffffd037 == '\0')) && (DAT_ffffcfe4 <= DAT_ffffcfe6)) {
    DAT_ffffd030 = rx8_clamp_float(DAT_ffffd028 - DAT_ffffd02c,0.0,0.038);
  }
  if ((DAT_ffffcffa == '\x01') && (uVar1 <= uVar2)) {
    DAT_ffffd037 = 1;
  }
  else {
    DAT_ffffd037 = 0;
  }
  return DAT_ffffcffa;
}


