/* ROM address: 0x0004673c; body bytes: 50; decompiled */

uint FUN_0004673c(void)

{
  uint uVar1;
  
  DAT_ffffcc52 = DAT_ffffad90;
  DAT_ffffcc53 = DAT_ffffb55c;
  uVar1 = FUN_0003eaa4(&DAT_ffff8788,1);
  if ((uVar1 & 0xff) == 1) {
    uVar1 = FUN_0003ebc0(&DAT_ffff8760,0);
    return uVar1;
  }
  return uVar1 & 0xff;
}


