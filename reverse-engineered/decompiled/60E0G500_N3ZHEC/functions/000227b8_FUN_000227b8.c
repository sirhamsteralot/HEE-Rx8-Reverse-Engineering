/* ROM address: 0x000227b8; body bytes: 202; decompiled */

void FUN_000227b8(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = DAT_ffffce44;
  if ((((DAT_ffffd29f != '\x01') && (DAT_ffffd2a0 != '\x01')) &&
      ((((int)DAT_ffffcff1 & 0x80U) == 0 || (DAT_ffffd183 != '\x01')))) &&
     ((DAT_ffffcfc1 == '\0' && (DAT_ffffd12e != '\x01')))) {
    uVar3 = 0;
    cVar1 = FUN_00002440(DAT_ffffb35c,0,0x3727c5ac);
    if (DAT_ffffb366 == '\x01') {
      if (cVar1 != '\0') {
        uVar3 = FUN_000020dc(DAT_ffffbe74,DAT_ffffb24c,&DAT_0006a76c);
      }
      goto LAB_00022870;
    }
    uVar2 = DAT_ffffb378;
    if (DAT_ffffb389 != '\x01') goto LAB_00022870;
  }
  uVar3 = uVar2;
LAB_00022870:
  DAT_ffffb38c = uVar3;
  DAT_ffffb360 = FUN_0005c894(DAT_ffffb38c);
  return;
}


