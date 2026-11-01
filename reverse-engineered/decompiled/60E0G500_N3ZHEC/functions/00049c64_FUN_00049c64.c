/* ROM address: 0x00049c64; body bytes: 188; decompiled */

void FUN_00049c64(void)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = FUN_00049d2c();
  uVar2 = 0x80;
  DAT_ffffcd4c = uVar2;
  if (cVar1 != '\n') {
    if (cVar1 == '\x01') {
      DAT_ffffcd4c = 0x40;
    }
    else if (cVar1 == '\x02') {
      DAT_ffffcd4c = 0x20;
    }
    else if (cVar1 == '\x06') {
      DAT_ffffcd4c = 0x10;
    }
    else if (cVar1 == -0xf) {
      DAT_ffffcd4c = 8;
    }
    else if (cVar1 == -0x10) {
      DAT_ffffcd4c = 4;
    }
    else {
      DAT_ffffcd4c = 0;
      if (cVar1 == '\x05') {
        DAT_ffffcd4c = 2;
      }
    }
  }
  cVar1 = FUN_00049d88();
  DAT_ffffcd4d = uVar2;
  if ((cVar1 != '\0') && (DAT_ffffcd4d = 0, cVar1 == '\x01')) {
    DAT_ffffcd4d = 0x40;
  }
  cVar1 = FUN_00049de6();
  DAT_ffffcd4e = uVar2;
  if (cVar1 != '\0') {
    if (cVar1 == '\x01') {
      DAT_ffffcd4e = 0x40;
    }
    else {
      DAT_ffffcd4e = 0;
      if (cVar1 == '\x02') {
        DAT_ffffcd4e = 0x20;
      }
    }
  }
  FUN_00049e6e();
  return;
}


