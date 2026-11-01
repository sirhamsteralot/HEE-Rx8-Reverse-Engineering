/* ROM address: 0x0002c336; body bytes: 30; decompiled */

undefined1 FUN_0002c336(void)

{
  bool bVar1;
  undefined1 uVar2;
  
  bVar1 = (DAT_ffffbc5e & 0x10) != 0x10;
  if (bVar1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x10;
  }
  DAT_ffffbc36 = !bVar1;
  return uVar2;
}


