/* ROM address: 0x0000dddc; body bytes: 96; decompiled */

int FUN_0000dddc(void)

{
  int iVar1;
  undefined *puVar2;
  byte bVar3;
  undefined *puVar4;
  
  bVar3 = 0;
  puVar2 = &DAT_0004e6c8;
  puVar4 = puVar2;
  do {
    if (puVar4[4] == '\0') {
      FUN_00009b92(puVar2);
    }
    bVar3 = bVar3 + 1;
    puVar2 = puVar2 + 0x10;
    puVar4 = puVar4 + 0x10;
  } while (bVar3 < 0x10);
  puVar2 = &DAT_0004e9c8;
  bVar3 = 0;
  puVar4 = puVar2;
  do {
    iVar1 = (int)(char)puVar4[4];
    if (iVar1 == 0) {
      iVar1 = FUN_00009b92(puVar2);
    }
    bVar3 = bVar3 + 1;
    puVar2 = puVar2 + 0x10;
    puVar4 = puVar4 + 0x10;
  } while (bVar3 < 6);
  return iVar1;
}


