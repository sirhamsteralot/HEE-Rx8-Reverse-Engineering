/* ROM address: 0x0005f048; body bytes: 316; decompiled */

int FUN_0005f048(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_28;
  undefined1 local_24;
  undefined1 uStack_23;
  
  iVar2 = 0;
  if (DAT_ffffd3ea == '\0') {
    if (DAT_ffffd3eb == '\x01') {
      DAT_ffffd3ea = '\x01';
      iVar2 = 1;
    }
  }
  else if (DAT_ffffd3ea == '\x01') {
    if (DAT_ffffd3eb != '\x01') {
      if (DAT_ffffd3eb == '\x02') {
        local_24 = (undefined1)((ushort)DAT_ffffd3e4 >> 8);
        uStack_23 = (undefined1)DAT_ffffd3e4;
        FUN_00038e8c(0x78,&local_24,2);
        DAT_ffffd3ec = FUN_000388c4(0x78,2);
        DAT_ffffd3ea = '\x02';
      }
      else {
        iVar2 = 2;
        DAT_ffffd3ea = '\x03';
      }
    }
    DAT_ffffd3e8 = 0;
  }
  else if (DAT_ffffd3ea == '\x02') {
    if (DAT_ffffd3ec == '\x01') {
      DAT_ffffd3ec = FUN_000388c4(0x78,2);
    }
    else if ((DAT_ffffc2fc == '\x01') || (DAT_ffffc2f9 == '\x01')) {
      iVar2 = 2;
      DAT_ffffd3ea = '\x03';
    }
    DAT_ffffd3e8 = DAT_ffffd3e8 + 1;
    if ((0x4e1 < DAT_ffffd3e8) || (DAT_ffffd3ea == '\x03')) {
      DAT_ffffd3ea = '\x03';
      iVar2 = 2;
    }
  }
  else if (DAT_ffffd3ea != '\x03') {
    DAT_ffffd3ea = '\x03';
    iVar2 = 2;
  }
  local_28 = 0;
  if (iVar2 == 1) {
    uVar1 = 2;
  }
  else {
    if (iVar2 != 2) {
      return iVar2;
    }
    uVar1 = 3;
  }
  iVar2 = FUN_00009630(0,uVar1,&local_28);
  return iVar2;
}


