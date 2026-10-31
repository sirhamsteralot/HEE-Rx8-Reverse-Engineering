/* ROM address: 0x0005182e; body bytes: 78; decompiled */

uint FUN_0005182e(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffd0e0 = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffd0f2;
    if (((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcfaa, uVar1 == 0x88)) ||
       ((DAT_ffffd106 == '\0' && (uVar1 = (uint)DAT_ffffd0f5, uVar1 == 1)))) {
      DAT_ffffd0e0 = DAT_ffffcfe0;
    }
  }
  DAT_ffffd106 = DAT_ffffd0f5;
  return uVar1;
}


