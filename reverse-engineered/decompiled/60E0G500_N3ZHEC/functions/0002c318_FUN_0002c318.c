/* ROM address: 0x0002c318; body bytes: 30; decompiled */

undefined1 FUN_0002c318(void)

{
  bool bVar1;
  undefined1 uVar2;
  
  bVar1 = (DAT_ffffbc5e & 0x20) != 0x20;
  if (bVar1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x20;
  }
  DAT_ffffbc35 = !bVar1;
  return uVar2;
}


