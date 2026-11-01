/* ROM address: 0x0003bdc0; body bytes: 62; decompiled */

bool FUN_0003bdc0(void)

{
  ushort uVar1;
  
  uVar1 = DAT_fffff726;
  DAT_ffffd1c8 = (uVar1 & 0x800) != 0;
  if ((DAT_ffffd1c9 == '\0') && (DAT_ffffd1c8)) {
    DAT_ffffc5f3 = 1;
  }
  else {
    DAT_ffffc5f3 = 0;
  }
  DAT_ffffd1c9 = DAT_ffffd1c8;
  return DAT_ffffd1c8;
}


