/* ROM address: 0x00019c00; body bytes: 90; decompiled */

uint FUN_00019c00(void)

{
  uint uVar1;
  
  if (DAT_ffffa9ea == '\x01') {
    DAT_ffffa9ec = 0x36ef;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffaae0;
    if ((uVar1 == 1) && (uVar1 = 0, DAT_ffffa9ec != 0)) {
      uVar1 = (int)DAT_ffffa9ec + 0xffff;
      DAT_ffffa9ec = (short)uVar1;
    }
  }
  if ((DAT_ffffa9ec == 0) && (uVar1 = (uint)DAT_ffffa9f0, uVar1 != 1)) {
    DAT_ffffa9e9 = 0;
  }
  else {
    DAT_ffffa9e9 = 1;
  }
  return uVar1;
}


