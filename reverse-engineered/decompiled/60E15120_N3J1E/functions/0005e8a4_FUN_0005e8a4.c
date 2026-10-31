/* ROM address: 0x0005e8a4; body bytes: 316; decompiled */

int FUN_0005e8a4(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_28;
  undefined1 local_24;
  undefined1 uStack_23;
  
  iVar2 = 0;
  if (DAT_ffffd3ae == '\0') {
    if (DAT_ffffd3af == '\x01') {
      DAT_ffffd3ae = '\x01';
      iVar2 = 1;
    }
  }
  else if (DAT_ffffd3ae == '\x01') {
    if (DAT_ffffd3af != '\x01') {
      if (DAT_ffffd3af == '\x02') {
        local_24 = (undefined1)((ushort)DAT_ffffd3a8 >> 8);
        uStack_23 = (undefined1)DAT_ffffd3a8;
        ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x78,&local_24,2);
        DAT_ffffd3b0 = FUN_000378dc(0x78,2);
        DAT_ffffd3ae = '\x02';
      }
      else {
        iVar2 = 2;
        DAT_ffffd3ae = '\x03';
      }
    }
    DAT_ffffd3ac = 0;
  }
  else if (DAT_ffffd3ae == '\x02') {
    if (DAT_ffffd3b0 == '\x01') {
      DAT_ffffd3b0 = FUN_000378dc(0x78,2);
    }
    else if ((DAT_ffffc28c == '\x01') || (DAT_ffffc289 == '\x01')) {
      iVar2 = 2;
      DAT_ffffd3ae = '\x03';
    }
    DAT_ffffd3ac = DAT_ffffd3ac + 1;
    if ((0x4e1 < DAT_ffffd3ac) || (DAT_ffffd3ae == '\x03')) {
      DAT_ffffd3ae = '\x03';
      iVar2 = 2;
    }
  }
  else if (DAT_ffffd3ae != '\x03') {
    DAT_ffffd3ae = '\x03';
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
  iVar2 = ref_osTaskScheduler(0,uVar1,&local_28);
  return iVar2;
}


