/* ROM address: 0x00053a74; body bytes: 148; decompiled */

uint FUN_00053a74(void)

{
  uint uVar1;
  char cVar3;
  undefined4 uVar2;
  
  uVar1 = FUN_0003eae4(&DAT_ffff8710,0);
  cVar3 = FUN_00002440(DAT_ffffbc1c,0,0x3ff126e9);
  if ((((cVar3 == '\0') && (DAT_ffffaada == '\x01')) && (DAT_ffffa428 == '\x01')) &&
     ((uVar1 & 0xffff) < 0xea)) {
    DAT_ffffd198 = 1;
  }
  else {
    DAT_ffffd198 = 0;
  }
  if ((DAT_ffffd198 == 1) && ((uVar1 & 0xffff) != 0xea)) {
    uVar2 = FUN_00002460(uVar1,1);
    uVar1 = FUN_0003ebd0(&DAT_ffff8710,uVar2);
    return uVar1;
  }
  return (uint)DAT_ffffd198;
}


