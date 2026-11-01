/* ROM address: 0x0005458a; body bytes: 56; decompiled */

uint FUN_0005458a(void)

{
  uint uVar1;
  
  uVar1 = FUN_0003eaa4(&DAT_ffff9002,0);
  if ((DAT_ffffd1dd == '\0') && ((uVar1 = uVar1 & 0xff, uVar1 == 1 || (DAT_ffffa428 == '\0')))) {
    DAT_ffffd1de = 1;
  }
  else {
    DAT_ffffd1de = 0;
  }
  return uVar1;
}


