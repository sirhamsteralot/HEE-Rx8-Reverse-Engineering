/* ROM address: 0x000469c4; body bytes: 244; decompiled */

uint FUN_000469c4(void)

{
  char cVar2;
  uint uVar1;
  undefined4 uVar3;
  
  if ((((DAT_ffffb4ae == '\x01') || (DAT_ffffb4ad == '\x01')) || (DAT_ffffa228 == '\x02')) ||
     (DAT_ffffa229 == '\x01')) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  FUN_0003ebc0(&DAT_ffff8766,uVar3);
  if (DAT_ffffcc55 == '\x01') {
    cVar2 = FUN_0003eaa4(&DAT_ffff8766,0);
    if (cVar2 != '\x01') {
      if (0xf9 < DAT_ffffcc58) {
        DAT_ffffcc54 = 1;
      }
      DAT_ffffcc58 = FUN_00002460((int)(short)DAT_ffffcc58,1);
      DAT_ffffcc56 = 0;
      goto LAB_00046a94;
    }
    if (0x18 < DAT_ffffcc56) {
      FUN_0003ebc0(&DAT_ffff8764,1);
    }
    DAT_ffffcc56 = FUN_00002460((int)(short)DAT_ffffcc56,1);
  }
  else {
    DAT_ffffcc56 = 0;
  }
  DAT_ffffcc58 = 0;
LAB_00046a94:
  cVar2 = FUN_0003eaa4(&DAT_ffff8764,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_000604dc(0x62,1);
    return uVar1;
  }
  if (DAT_ffffcc54 == 1) {
    uVar1 = FUN_000604dc(0x62,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc54;
}


