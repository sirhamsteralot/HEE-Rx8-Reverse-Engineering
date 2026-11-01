/* ROM address: 0x00009016; body bytes: 34; decompiled */

void FUN_00009016(int param_1)

{
  undefined *puVar1;
  byte bVar2;
  
  if (param_1 == 0) {
    puVar1 = &DAT_ffffa0d8;
    bVar2 = 0;
    do {
      bVar2 = bVar2 + 1;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1 = puVar1 + 8;
    } while (bVar2 < 4);
  }
  return;
}


