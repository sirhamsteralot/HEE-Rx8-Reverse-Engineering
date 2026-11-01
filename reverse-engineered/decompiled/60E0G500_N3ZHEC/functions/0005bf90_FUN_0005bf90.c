/* ROM address: 0x0005bf90; body bytes: 162; decompiled */

uint FUN_0005bf90(void)

{
  uint uVar1;
  undefined1 local_98 [132];
  
  uVar1 = (uint)DAT_ffffd344;
  if (uVar1 == 1) {
    if (DAT_ffffd345 == '\0') {
      DAT_ffffd345 = '\x01';
      FUN_0005c128();
      DAT_ffffd340 = DAT_ffffd330;
      local_98[0] = 99;
      FUN_000688c8(0x23,local_98,1);
    }
    for (uVar1 = 0; (DAT_ffffd340 < DAT_ffffd334 && ((uVar1 & 0xffff) < 0x80)); uVar1 = uVar1 + 1) {
      local_98[uVar1 & 0xffff] = *DAT_ffffd340;
      DAT_ffffd340 = DAT_ffffd340 + 1;
    }
    uVar1 = FUN_000688c8(0x23,local_98,uVar1);
    if (DAT_ffffd334 <= DAT_ffffd340) {
      DAT_ffffd344 = 0;
      DAT_ffffd345 = '\0';
      uVar1 = FUN_000550ca(0x23,DAT_ffffd338 + 1);
    }
  }
  return uVar1;
}


