/* ROM address: 0x00060e9a; body bytes: 40; decompiled */

bool FUN_00060e9a(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = FUN_0006413c();
  bVar1 = (uVar2 & 0xff) != 0;
  if (bVar1) {
    FUN_000643c0(uVar2,param_2);
  }
  return !bVar1;
}


