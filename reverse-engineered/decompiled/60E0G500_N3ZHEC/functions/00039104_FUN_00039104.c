/* ROM address: 0x00039104; body bytes: 52; decompiled */

uint FUN_00039104(void)

{
  uint uVar1;
  
  uVar1 = FUN_00009890(&DAT_0004ea18);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 0) {
    FUN_0000e050();
    FUN_00039138();
    FUN_00039172();
    uVar1 = FUN_0003917c();
    DAT_ffffc52f = 1;
    DAT_ffffc530 = 1;
  }
  return uVar1;
}


