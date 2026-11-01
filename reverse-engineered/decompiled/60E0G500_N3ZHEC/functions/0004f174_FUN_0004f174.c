/* ROM address: 0x0004f174; body bytes: 68; decompiled */

uint FUN_0004f174(void)

{
  uint uVar1;
  
  if (((DAT_ffffd183 == '\x01') || (uVar1 = (uint)DAT_ffffd14a, uVar1 == 1)) &&
     (uVar1 = (uint)DAT_ffffcfee, uVar1 == 0)) {
    DAT_ffffd004 = 1;
  }
  else {
    DAT_ffffd004 = 0;
  }
  return uVar1;
}


