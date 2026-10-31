/* ROM address: 0x0000f450; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000f454 (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000f450(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  
  iVar3 = 0;
  do {
    iVar5 = 0;
    (&DAT_ffffa4c0)[iVar3 * 0x58] = (char)iVar3;
    (&DAT_ffffa4bc)[iVar3 * 0x16] = (&DAT_0004e2c0)[iVar3];
    puVar2 = &DAT_0004e2c8 + iVar3 * 3;
    puVar4 = &DAT_ffffa4c4 + iVar3 * 0x58;
    do {
      iVar5 = iVar5 + 1;
      uVar1 = *puVar2;
      puVar2 = puVar2 + 1;
      *puVar4 = uVar1;
      puVar4 = puVar4 + 0x18;
    } while (iVar5 < 3);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  ref_setAllInjectorto0_();
  return;
}


