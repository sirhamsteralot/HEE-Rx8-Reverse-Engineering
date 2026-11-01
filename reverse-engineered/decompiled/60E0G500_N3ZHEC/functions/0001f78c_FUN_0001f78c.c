/* ROM address: 0x0001f78c; body bytes: 98; decompiled */

char FUN_0001f78c(void)

{
  if ((DAT_ffffb16a != 0) && (DAT_ffffb146 == 0)) {
    if (DAT_ffffb290 < 0.015) {
      DAT_ffffb144 = 0x61a;
    }
    else {
      DAT_ffffb144 = FUN_000020c4(&PTR_PTR_0006a2dc);
    }
  }
  if ((DAT_ffffb366 == '\x01') && (DAT_ffffb144 != 0)) {
    DAT_ffffb144 = DAT_ffffb144 + -1;
  }
  DAT_ffffb16a = DAT_ffffb146;
  return DAT_ffffb366;
}


