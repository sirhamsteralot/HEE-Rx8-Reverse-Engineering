/* ROM address: 0x00017b34; body bytes: 84; decompiled */

uint FUN_00017b34(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar1 = FUN_00002440(DAT_ffffa73c,0,0x3727c5ac);
  uVar3 = uVar1;
  if ((DAT_ffffa95c == '\0') && (uVar3 = 0, (uVar1 & 0xff) != 0)) {
    DAT_ffffa93b = FUN_00002478((int)DAT_ffffa93b,1);
    uVar2 = FUN_0003eaa4(&DAT_ffff8076,0);
    uVar2 = FUN_00002478(uVar2,1);
    uVar3 = FUN_0003ebc0(&DAT_ffff8076,uVar2);
  }
  DAT_ffffa95c = (char)uVar1;
  return uVar3;
}


