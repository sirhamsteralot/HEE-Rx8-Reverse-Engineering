/* ROM address: 0x0000dddc; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000dddc (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

int ref_CANSetupSomethingDifferentBasedOnBit(void)

{
  int iVar1;
  undefined *puVar2;
  byte bVar3;
  undefined *puVar4;
  
  bVar3 = 0;
  puVar2 = &DAT_0004df1c;
  puVar4 = puVar2;
  do {
    if (puVar4[4] == '\0') {
      ref_doSomethingIfByteIs1InCANSetup(puVar2);
    }
    bVar3 = bVar3 + 1;
    puVar2 = puVar2 + 0x10;
    puVar4 = puVar4 + 0x10;
  } while (bVar3 < 0x10);
  puVar2 = &DAT_0004e21c;
  bVar3 = 0;
  puVar4 = puVar2;
  do {
    iVar1 = (int)(char)puVar4[4];
    if (iVar1 == 0) {
      iVar1 = ref_doSomethingIfByteIs1InCANSetup(puVar2);
    }
    bVar3 = bVar3 + 1;
    puVar2 = puVar2 + 0x10;
    puVar4 = puVar4 + 0x10;
  } while (bVar3 < 6);
  return iVar1;
}


