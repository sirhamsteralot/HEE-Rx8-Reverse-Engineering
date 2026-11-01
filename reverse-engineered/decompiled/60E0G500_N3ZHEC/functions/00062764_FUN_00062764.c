/* ROM address: 0x00062764; body bytes: 128; decompiled */

void FUN_00062764(undefined4 param_1,char param_2)

{
  byte bVar1;
  undefined1 uVar2;
  
  uVar2 = 8;
  bVar1 = FUN_0006359c();
  if (((bVar1 == 0) || (bVar1 == 0x50)) || ((bVar1 != 0 && (bVar1 < 0x40)))) {
    if (param_2 == '\x03') {
      if ((DAT_ffffd6ff & 0x80) == 0x80) {
        uVar2 = 6;
      }
      else {
        uVar2 = 8;
      }
    }
    else if (param_2 == '\x01') {
      uVar2 = 7;
    }
  }
  else if ((bVar1 & 0x80) == 0x80) {
    uVar2 = 8;
  }
  DAT_ffffd6fe = uVar2;
  return;
}


