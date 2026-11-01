/* ROM address: 0x0004b2aa; body bytes: 60; decompiled */

int FUN_0004b2aa(void)

{
  int iVar1;
  
  if ((DAT_ffffce06 == '\x01') || (DAT_ffffd201 == '\x01')) {
    iVar1 = 1;
    DAT_ffffcdff = 0;
  }
  else {
    iVar1 = (int)DAT_ffffce11;
    if (iVar1 == 0) {
      DAT_ffffcdff = 1;
    }
  }
  return iVar1;
}


