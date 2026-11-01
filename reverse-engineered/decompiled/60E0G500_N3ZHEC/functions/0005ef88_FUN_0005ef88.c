/* ROM address: 0x0005ef88; body bytes: 150; decompiled */

uint FUN_0005ef88(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffaae0;
  DAT_ffffd3e0 = DAT_ffffc71c;
  if (uVar1 == 1) {
    if (DAT_ffffc71c < 1.374) {
      uVar1 = FUN_00002460((int)(short)DAT_ffffd3e6,1);
      DAT_ffffd3e6 = (ushort)uVar1;
      if ((0x18 < DAT_ffffd3e6) && (DAT_ffffd3e6 = 0, DAT_ffffd3e4 != 0)) {
        uVar1 = (int)(short)DAT_ffffd3e4 - 1;
        DAT_ffffd3e4 = (ushort)uVar1;
      }
    }
    DAT_ffffd3eb = 1;
  }
  else {
    if ((DAT_ffffd3e6 != 0) && (uVar1 = (uint)(short)DAT_ffffd3e4, uVar1 != 0)) {
      DAT_ffffd3e6 = 0;
      DAT_ffffd3e4 = DAT_ffffd3e4 - 1;
    }
    if (DAT_ffffd3e4 < DAT_ffffd3dc) {
      DAT_ffffd3eb = 2;
    }
    else {
      uVar1 = 3;
      DAT_ffffd3eb = 3;
    }
  }
  return uVar1;
}


