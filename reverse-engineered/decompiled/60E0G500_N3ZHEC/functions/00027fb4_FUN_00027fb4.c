/* ROM address: 0x00027fb4; body bytes: 120; decompiled */

uint FUN_00027fb4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00002440(DAT_ffffb360,0,0x3727c5ac);
  if ((uint)DAT_ffffba88 == (uVar1 & 0xff)) {
    uVar2 = FUN_00002478((int)DAT_ffffba87,1);
    DAT_ffffba87 = (char)uVar2;
  }
  else {
    DAT_ffffba87 = 0;
    uVar2 = uVar1;
  }
  if (DAT_ffffa42c == '\0') {
    uVar2 = FUN_00002478((int)DAT_ffffba85,1);
    DAT_ffffba85 = (char)uVar2;
  }
  else {
    DAT_ffffba85 = 0;
  }
  if (DAT_ffffb13a == '\0') {
    uVar2 = FUN_00002478((int)DAT_ffffba86,1);
    DAT_ffffba86 = (char)uVar2;
  }
  else {
    DAT_ffffba86 = 0;
  }
  DAT_ffffba88 = (char)uVar1;
  return uVar2;
}


