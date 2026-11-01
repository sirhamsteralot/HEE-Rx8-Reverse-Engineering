/* ROM address: 0x00008f2a; body bytes: 80; decompiled */

void FUN_00008f2a(void)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  
  FUN_00008f94();
  puVar2 = &DAT_ffffa0c4;
  ppuVar3 = &PTR_DAT_0000d81c;
  bVar1 = 0;
  puVar4 = &DAT_ffffa0d8;
  do {
    FUN_0000a8a4(*ppuVar3,0);
    puVar4[4] = 0;
    bVar1 = bVar1 + 1;
    puVar4[5] = 0;
    *puVar2 = 0;
    puVar4 = puVar4 + 8;
    puVar2 = puVar2 + 1;
    ppuVar3 = ppuVar3 + 6;
  } while (bVar1 < 4);
  FUN_00009490();
  return;
}


