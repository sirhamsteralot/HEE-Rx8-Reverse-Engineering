/* ROM address: 0x0001ed7c; body bytes: 62; decompiled */

void FUN_0001ed7c(void)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  bVar1 = 0;
  puVar3 = &DAT_ffff810c;
  puVar2 = &DAT_ffff80ec;
  do {
    FUN_0003ed52(puVar2);
    FUN_0003ec66(puVar3);
    bVar1 = bVar1 + 1;
    puVar3 = puVar3 + 2;
    puVar2 = puVar2 + 8;
  } while (bVar1 < 4);
  return;
}


