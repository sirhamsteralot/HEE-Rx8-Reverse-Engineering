/* ROM address: 0x00010fe6; body bytes: 84; decompiled */

void FUN_00010fe6(void)

{
  byte bVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  
  for (puVar3 = &DAT_ffffa578; puVar3 < &DAT_ffffa5d0; puVar3 = puVar3 + 0x2c) {
    for (pbVar4 = puVar3 + 0xc; pbVar4 < puVar3 + 0x2c; pbVar4 = pbVar4 + 0x10) {
      bVar1 = *pbVar4;
      uVar2 = FUN_00010f80((int)(char)bVar1);
      (&DAT_ffffa0c4)[bVar1] = uVar2;
    }
  }
  return;
}


