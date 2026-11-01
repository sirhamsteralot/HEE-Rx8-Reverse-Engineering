/* ROM address: 0x0005446e; body bytes: 40; decompiled */

undefined4 FUN_0005446e(void)

{
  undefined4 uVar1;
  
  if (DAT_ffffa428 == '\x01') {
    DAT_ffffd1dc = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_00002478((int)DAT_ffffd1dc,1);
    DAT_ffffd1dc = (char)uVar1;
  }
  return uVar1;
}


