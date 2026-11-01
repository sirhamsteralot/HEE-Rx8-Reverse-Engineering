/* ROM address: 0x0004be14; body bytes: 192; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0004be2a) */

uint FUN_0004be14(void)

{
  uint uVar1;
  
  if ((DAT_ffffc68e == '\x01') || (8.0 < DAT_ffffce74)) {
    DAT_ffffce6c = -0x100;
  }
  DAT_ffffce74 = (DAT_ffffbc1c * 1024.0) / 3.6e+06 + DAT_ffffce74;
  if (DAT_ffffce6c != DAT_ffffce82) {
    DAT_ffffce88 = 1;
    FUN_00038e8c(0x7a,&DAT_ffffce6c,2);
    DAT_ffffce86 = FUN_000388c4(0x7a,2);
    DAT_ffffce82 = DAT_ffffce6c;
  }
  uVar1 = (uint)DAT_ffffce88;
  if (uVar1 == 1) {
    if (DAT_ffffce86 == '\x01') {
      uVar1 = FUN_000388c4(0x7a,2);
      DAT_ffffce86 = (char)uVar1;
    }
    else {
      uVar1 = (uint)DAT_ffffc2f9;
      if (uVar1 == 1) {
        DAT_ffffce88 = 0;
      }
    }
  }
  return uVar1;
}


