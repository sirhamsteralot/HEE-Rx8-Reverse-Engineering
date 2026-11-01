/* ROM address: 0x00059f0c; body bytes: 112; decompiled */

undefined4 FUN_00059f0c(void)

{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = FUN_00003920(0x10);
  cVar2 = FUN_000565ce();
  if ((DAT_ffffd2ae == '\x01') || (DAT_ffffd2ba != cVar2)) {
    DAT_ffffd298 = '\0';
    DAT_ffffd2ae = '\0';
  }
  if (DAT_ffffd298 == '\0') {
    DAT_ffffd28c = 0;
  }
  if ((DAT_ffffd2bb == '\x01') && (DAT_ffffd298 == '\0')) {
    DAT_ffffd296 = 1;
  }
  DAT_ffffd2bb = DAT_ffffd298;
  DAT_ffffd2ba = cVar2;
  uVar1 = FUN_00003934(uVar1);
  return uVar1;
}


