/* ROM address: 0x0004f99c; body bytes: 54; decompiled */

ushort FUN_0004f99c(void)

{
  bool bVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  uVar3 = FUN_0003eb72(0,&DAT_ffff86a4);
  uVar2 = FUN_000020c4(uVar3,&DAT_0006b75c);
  DAT_ffffd008 = uVar2;
  bVar1 = DAT_ffffcfe6 < uVar2;
  if (bVar1) {
    uVar2 = 0;
  }
  DAT_ffffd001 = !bVar1;
  return uVar2;
}


