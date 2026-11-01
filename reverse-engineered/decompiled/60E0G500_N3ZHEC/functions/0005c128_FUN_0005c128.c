/* ROM address: 0x0005c128; body bytes: 62; decompiled */

void FUN_0005c128(void)

{
  int iVar1;
  
  if ((0x8000007f < DAT_ffffd330) && (DAT_ffffd330 < 0x80000100)) {
    iVar1 = FUN_00038fbc();
    DAT_ffffd330 = iVar1 + DAT_ffffd330 + 0x80000000;
    DAT_ffffd334 = DAT_ffffd338 + DAT_ffffd330;
  }
  return;
}


