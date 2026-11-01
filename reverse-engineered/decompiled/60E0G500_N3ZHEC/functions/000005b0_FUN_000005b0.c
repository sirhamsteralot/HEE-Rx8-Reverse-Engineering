/* ROM address: 0x000005b0; body bytes: 116; decompiled */

undefined4 FUN_000005b0(ushort param_1)

{
  byte bVar1;
  short sVar4;
  undefined4 uVar2;
  int iVar3;
  ushort uVar5;
  
  uVar5 = 0;
  if (param_1 != 0) {
    do {
      DAT_ffffdfa8 = FUN_00000624();
      FUN_00000364();
      sVar4 = FUN_000003e0();
      if (sVar4 != 0) {
        uVar2 = FUN_000003b0();
        iVar3 = FUN_00000636(uVar2);
        if (iVar3 != 0) {
          return 0;
        }
      }
      bVar1 = DAT_ffffec10;
      if ((bVar1 & 0x80) != 0) {
        uVar5 = uVar5 + 1;
        FUN_0000031c();
      }
    } while (uVar5 < param_1);
  }
  return 1;
}


