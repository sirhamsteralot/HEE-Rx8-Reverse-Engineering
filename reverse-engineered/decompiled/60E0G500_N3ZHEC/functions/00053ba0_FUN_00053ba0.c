/* ROM address: 0x00053ba0; body bytes: 106; decompiled */

ushort FUN_00053ba0(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = FUN_00002460((int)DAT_ffffcfe4,0x10);
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffd1bc = 0;
    DAT_ffffd1bd = 0;
    DAT_ffffd1a4 = 0;
    DAT_ffffd1a8 = 0;
    DAT_ffffd1ac = 0;
    DAT_ffffd1b0 = 0;
    DAT_ffffd1b4 = 0;
    DAT_ffffd1b8 = 0;
    uVar2 = 1;
  }
  else {
    uVar2 = (ushort)DAT_ffffd002;
    if ((DAT_ffffd002 == 1) && (uVar2 = DAT_ffffcfe6, DAT_ffffcfe6 == uVar1)) {
      DAT_ffffd1bc = 0x27;
    }
  }
  return uVar2;
}


