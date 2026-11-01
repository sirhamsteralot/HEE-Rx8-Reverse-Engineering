/* ROM address: 0x00053952; body bytes: 198; decompiled */

uint FUN_00053952(void)

{
  ushort uVar2;
  uint uVar1;
  undefined4 uVar3;
  
  uVar3 = FUN_0003eb72(0,&DAT_ffff86a4);
  DAT_ffffd18c = (float)FUN_00002068(uVar3,&DAT_0006b920);
  DAT_ffffd190 = (float)FUN_00002068(uVar3,&DAT_0006b934);
  uVar2 = FUN_00002460((int)DAT_ffffcfe4,1);
  if ((DAT_ffffd201 != '\x01') && (DAT_ffffcfb4 != '\x01')) {
    if (DAT_ffffd002 != 1) {
      return (uint)DAT_ffffd002;
    }
    if (uVar2 <= DAT_ffffcfe6) {
      if (DAT_ffffd184 == '\x01') {
        if (DAT_ffffd18c < DAT_ffffd17c) {
          uVar1 = FUN_00002478((int)DAT_ffffd181,1);
          DAT_ffffd181 = (char)uVar1;
          return uVar1;
        }
      }
      else {
        if (DAT_ffffd185 != 1) {
          return (uint)DAT_ffffd185;
        }
        if ((DAT_ffffd18c < DAT_ffffd17c) || (DAT_ffffd17c < DAT_ffffd190)) {
          uVar1 = FUN_00002478((int)DAT_ffffd181,1);
          DAT_ffffd181 = (char)uVar1;
          return uVar1;
        }
      }
    }
  }
  DAT_ffffd181 = 0;
  return 1;
}


