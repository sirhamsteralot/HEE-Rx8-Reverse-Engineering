/* ROM address: 0x00007778; body bytes: 46; decompiled */

void FUN_00007778(void)

{
  ushort uVar1;
  
  if (DAT_ffff9fc4 == '\0') {
    DAT_fffff6e8 = 0xb;
    FUN_00007b58();
    uVar1 = DAT_fffff6ea;
    DAT_fffff6ea = uVar1 & 0xfffb | 4;
    DAT_ffff9fc4 = '\x01';
  }
  return;
}


