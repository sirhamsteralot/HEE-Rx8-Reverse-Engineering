/* ROM address: 0x000182ba; body bytes: 666; decompiled */

void FUN_000182ba(uint param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  char acStack_44 [40];
  
  FUN_000042b0();
  uVar2 = param_1 & 0xff;
  DAT_ffffa98d = (undefined1)param_1;
  if (uVar2 == 0) {
    bVar1 = DAT_ffffa97c + 1;
    DAT_ffffa97c = bVar1 & 7;
    if (((bVar1 & 1) == 0) && (DAT_ffffa974 < 0x3c)) {
      DAT_ffffa97f = DAT_ffffa974 + 1;
    }
  }
  else if (uVar2 == 1) {
    if (DAT_ffffa97c == 8) {
      DAT_ffffa97c = DAT_ffffa97d - 1 & 7;
    }
    else {
      DAT_ffffa97c = DAT_ffffa97c - 1 & 7;
      if (((DAT_ffffa974 == 1) && (DAT_ffffa98a != '\x04')) &&
         ((DAT_ffffa969 == '\x01' || (DAT_ffffa96a == '\x01')))) {
        DAT_ffffa97f = '\0';
      }
    }
    if ((((DAT_ffffa97c & 1) == 0) && (DAT_ffffa98a != '\x04')) && (DAT_ffffa974 != 0)) {
      DAT_ffffa97f = DAT_ffffa974 - 1;
    }
  }
  else if (uVar2 == 2) {
    if ((DAT_ffffa98a == '\x04') || ((DAT_ffffa97c & 1) == 1)) {
      if (DAT_ffffa97c == 8) {
        DAT_ffffa97c = DAT_ffffa97d;
      }
      bVar1 = DAT_ffffa97c + 1;
    }
    else {
      bVar1 = DAT_ffffa97c + 2;
    }
    DAT_ffffa97c = bVar1 & 7;
    if (DAT_ffffa974 < 0x3c) {
      DAT_ffffa97f = DAT_ffffa974 + 1;
    }
  }
  else if (uVar2 == 3) {
    if ((DAT_ffffa98a == '\x04') || ((DAT_ffffa97c & 1) == 1)) {
      if (DAT_ffffa97c == 8) {
        DAT_ffffa97c = DAT_ffffa97d - 1 & 7;
      }
      else {
        DAT_ffffa97c = DAT_ffffa97c - 1 & 7;
        if ((DAT_ffffa974 == 1) && (DAT_ffffa98a != '\x04')) {
          DAT_ffffa97f = '\0';
        }
      }
    }
    else {
      DAT_ffffa97c = DAT_ffffa97c - 2 & 7;
      if (DAT_ffffa974 != 0) {
        DAT_ffffa97f = DAT_ffffa974 - 1;
      }
    }
  }
  else if (uVar2 == 4) {
    if (DAT_ffffa97c == 8) {
      DAT_ffffa97c = DAT_ffffa97d;
    }
    else if ((DAT_ffffa97c & 1) == 0) {
      DAT_ffffa97c = DAT_ffffa97c + 1 & 7;
      DAT_ffffa97d = DAT_ffffa97c;
    }
    else {
      DAT_ffffa97c = 8;
    }
  }
  else if (uVar2 == 6) {
    DAT_ffffa97c = 8;
  }
  DAT_ffffa98a = DAT_ffffa98d;
  FUN_00002054(&uStack_48,0xe0);
  FUN_00004bbc(0xfffff746,1,acStack_44[(uint)DAT_ffffa97c * 4] == '\x01');
  FUN_00002064(uStack_48);
  FUN_00002054(&uStack_4c,0xe0);
  FUN_00004bbc(0xfffff746,2,acStack_44[(uint)DAT_ffffa97c * 4 + 1] == '\x01');
  FUN_00002064(uStack_4c);
  FUN_00002054(&uStack_50,0xe0);
  FUN_00004bbc(0xfffff746,4,acStack_44[(uint)DAT_ffffa97c * 4 + 2] == '\x01');
  FUN_00002064(uStack_50);
  FUN_00002054(&local_54,0xe0);
  FUN_00004bbc(0xfffff746,8,acStack_44[(uint)DAT_ffffa97c * 4 + 3] == '\x01');
  FUN_00002064(local_54);
  return;
}


