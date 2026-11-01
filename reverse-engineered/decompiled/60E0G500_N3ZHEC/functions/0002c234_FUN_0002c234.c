/* ROM address: 0x0002c234; body bytes: 30; decompiled */

undefined2 FUN_0002c234(void)

{
  bool bVar1;
  undefined2 uVar2;
  
  bVar1 = (DAT_ffffbc46 & 8) != 8;
  if (bVar1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 8;
  }
  DAT_ffffbc37 = !bVar1;
  return uVar2;
}


