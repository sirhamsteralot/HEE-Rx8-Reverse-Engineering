/* ROM address: 0x00027bac; body bytes: 106; decompiled */

void FUN_00027bac(void)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  byte bVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 uVar7;
  
  puVar2 = &DAT_ffff8130;
  bVar1 = 0;
  puVar3 = &DAT_ffff8570;
  uVar7 = 0;
  do {
    bVar4 = 0;
    puVar5 = puVar2;
    puVar6 = puVar3;
    do {
      FUN_0003ec20(uVar7,puVar5);
      FUN_0003ebc0(puVar6,0);
      bVar4 = bVar4 + 1;
      puVar6 = puVar6 + 2;
      puVar5 = puVar5 + 8;
    } while (bVar4 < 0x44);
    bVar1 = bVar1 + 1;
    puVar3 = puVar3 + 0x88;
    puVar2 = puVar2 + 0x220;
  } while (bVar1 < 2);
  return;
}


