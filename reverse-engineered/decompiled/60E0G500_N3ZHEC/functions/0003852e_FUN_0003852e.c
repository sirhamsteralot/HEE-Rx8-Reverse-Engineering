/* ROM address: 0x0003852e; body bytes: 34; decompiled */

uint FUN_0003852e(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if (DAT_ffffc240 == '\x01') {
    uVar1 = 0x40;
  }
  if (DAT_ffffc2e4 == '\x01') {
    uVar1 = uVar1 | 4;
  }
  return uVar1;
}


