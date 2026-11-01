/* ROM address: 0x00003ec0; body bytes: 80; decompiled */

void FUN_00003ec0(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar3 = &DAT_00004990;
  do {
    iVar1 = FUN_00003fb0(iVar4);
    if (iVar1 == 0) {
      puVar2 = *(undefined1 **)(puVar3 + 4);
      puVar2[2] = 0xff;
      *puVar2 = 0;
      puVar2[3] = puVar3[0xc];
    }
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 0x10;
  } while ((short)iVar4 < 0x13);
  return;
}


