/* ROM address: 0x000617b8; body bytes: 90; decompiled */

undefined4 FUN_000617b8(void)

{
  char cVar2;
  short sVar1;
  undefined4 uVar3;
  
  uVar3 = 0;
  cVar2 = FUN_00065d88();
  if ((((cVar2 != '\0') || (cVar2 = FUN_00064c88(), cVar2 != '\0')) ||
      (sVar1 = FUN_00002034(&DAT_ffff87b0), sVar1 != 0)) ||
     ((cVar2 = FUN_00002044(&DAT_ffff87b4), cVar2 != '\0' ||
      (sVar1 = FUN_00002034(&DAT_ffff87ac), sVar1 != 0)))) {
    uVar3 = 1;
  }
  return uVar3;
}


