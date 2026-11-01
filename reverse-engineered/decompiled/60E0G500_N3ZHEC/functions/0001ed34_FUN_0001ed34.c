/* ROM address: 0x0001ed34; body bytes: 72; decompiled */

void FUN_0001ed34(void)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  
  bVar1 = 0;
  puVar3 = &DAT_ffff810c;
  puVar2 = &DAT_ffff80ec;
  uVar4 = 0;
  do {
    FUN_0003ec20(uVar4,puVar2);
    FUN_0003ebc0(puVar3,0);
    bVar1 = bVar1 + 1;
    puVar3 = puVar3 + 2;
    puVar2 = puVar2 + 8;
  } while (bVar1 < 4);
  return;
}


