/* ROM address: 0x00042768; body bytes: 94; decompiled */

uint FUN_00042768(void)

{
  uint uVar1;
  
  uVar1 = FUN_000671a4(2);
  uVar1 = uVar1 & 0xff;
  if (((uVar1 == 0) && (uVar1 = (uint)DAT_ffffb3c8, uVar1 == 1)) && (DAT_ffffd201 == '\0')) {
    DAT_ffffc98e = 0x1905 < DAT_ffffc990;
    uVar1 = FUN_00002460((int)(short)DAT_ffffc990,1);
    DAT_ffffc990 = (ushort)uVar1;
  }
  else {
    DAT_ffffc98e = 0;
    DAT_ffffc990 = 0;
  }
  return uVar1;
}


