/* ROM address: 0x00051fd2; body bytes: 78; decompiled */

uint FUN_00051fd2(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffd11c = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffd12e;
    if (((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcfe6, uVar1 == 0x88)) ||
       ((DAT_ffffd142 == '\0' && (uVar1 = (uint)DAT_ffffd131, uVar1 == 1)))) {
      DAT_ffffd11c = DAT_ffffd01c;
    }
  }
  DAT_ffffd142 = DAT_ffffd131;
  return uVar1;
}


