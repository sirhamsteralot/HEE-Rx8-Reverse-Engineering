/* ROM address: 0x0005a0dc; body bytes: 250; decompiled */

uint FUN_0005a0dc(void)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  bVar1 = DAT_ffffd28d;
  uVar2 = FUN_00003920(0x10);
  if ((((DAT_ffffd29a == '\0') || (DAT_ffffd298 == '\0')) || (DAT_ffffd293 == '\x01')) ||
     (DAT_ffffd28d == 0x30)) {
    DAT_ffffd28d = 0;
  }
  else if ((DAT_ffffd28d == 0) && (DAT_ffffd290 == '\x01')) {
    DAT_ffffd28d = 0x10;
  }
  else if ((DAT_ffffd28d == 0x10) && (0x5d < DAT_ffffd284)) {
    DAT_ffffd28d = 0x20;
  }
  else if ((DAT_ffffd28d == 0x20) && (0x5d < DAT_ffffd284)) {
    DAT_ffffd28d = 0x30;
  }
  if (DAT_ffffd28d == 0) {
    DAT_ffffd29d = 0;
  }
  DAT_ffffd290 = 0;
  DAT_ffffd293 = 0;
  uVar3 = FUN_00003934(uVar2);
  uVar4 = (uint)DAT_ffffd28d;
  if (((uVar4 == 0) || ((bVar1 == 0 && (uVar3 = uVar4, uVar4 == 0x10)))) ||
     ((uVar3 = (uint)bVar1, bVar1 == 0x10 && (uVar3 = uVar4, uVar4 == 0x20)))) {
    DAT_ffffd284 = 0;
  }
  else if (DAT_ffffd284 != 0xffff) {
    DAT_ffffd284 = DAT_ffffd284 + 1;
  }
  return uVar3;
}


