/* ROM address: 0x00027c32; body bytes: 112; decompiled */

void FUN_00027c32(void)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  byte bVar4;
  undefined *puVar5;
  undefined *puVar6;
  
  bVar1 = 0;
  puVar3 = &DAT_ffff8130;
  puVar2 = &DAT_ffff8570;
  do {
    bVar4 = 0;
    puVar5 = puVar2;
    puVar6 = puVar3;
    do {
      FUN_0003ed52(puVar6);
      FUN_0003ec66(puVar5);
      bVar4 = bVar4 + 1;
      puVar5 = puVar5 + 2;
      puVar6 = puVar6 + 8;
    } while (bVar4 < 0x44);
    bVar1 = bVar1 + 1;
    puVar3 = puVar3 + 0x220;
    puVar2 = puVar2 + 0x88;
  } while (bVar1 < 2);
  FUN_0003ec66(&DAT_ffff8680);
  FUN_0003ec66(&DAT_ffff8682);
  FUN_0003ec66(&DAT_ffff8684);
  return;
}


