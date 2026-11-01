/* ROM address: 0x0002c3a6; body bytes: 170; decompiled */

uint FUN_0002c3a6(void)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = DAT_ffffbc5a == -1;
  if (!bVar2) {
    DAT_ffffbc30 = DAT_ffffbc5a;
  }
  if (DAT_ffffbc5b == -1) {
    bVar2 = true;
  }
  else if (DAT_ffffa428 == '\x01') {
    DAT_ffffbc31 = DAT_ffffbc5b;
  }
  if (DAT_ffffbc5c == -1) {
    bVar2 = true;
  }
  else if ((((DAT_ffffbb8c == '\0') && (DAT_ffffa428 == '\x01')) && (DAT_ffffa40a == '\0')) &&
          (DAT_ffffa401 == '\0')) {
    DAT_ffffbc32 = DAT_ffffbc5c;
  }
  uVar1 = (uint)bVar2;
  if (uVar1 == 1) {
    uVar1 = FUN_00002478((int)DAT_ffffbc2f,1);
    DAT_ffffbc2f = (char)uVar1;
  }
  else {
    DAT_ffffbc2f = 0;
  }
  return uVar1;
}


