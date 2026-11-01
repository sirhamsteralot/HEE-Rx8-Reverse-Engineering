/* ROM address: 0x0000553e; body bytes: 38; decompiled */

void FUN_0000553e(void)

{
  ushort uVar1;
  
  uVar1 = DAT_fffff460;
  if ((uVar1 & 0x100) == 0x100) {
    DAT_fffff460 = 1;
    DAT_fffff45e = 0xff;
    FUN_00005348(0x68);
    return;
  }
  return;
}


