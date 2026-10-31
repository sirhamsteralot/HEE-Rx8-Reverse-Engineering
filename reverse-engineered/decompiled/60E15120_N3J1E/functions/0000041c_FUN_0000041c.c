/* ROM address: 0x0000041c; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000041c (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000041c(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  
  iVar5 = 8;
  puVar1 = &DAT_ffffdfe4;
  puVar2 = &DAT_ffffdff0;
  do {
    puVar4 = puVar2;
    puVar3 = puVar1;
    *puVar3 = 0;
    iVar5 = iVar5 + -1;
    *puVar4 = 0;
    puVar1 = puVar3 + 1;
    puVar2 = puVar4 + 1;
  } while (iVar5 != 0);
  puVar3[1] = 0xaa;
  puVar3 = puVar3 + 2;
  puVar4[1] = 0xaa;
  puVar4 = puVar4 + 2;
  iVar5 = 3;
  do {
    iVar5 = iVar5 + -1;
    *puVar3 = 0;
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar5 != 0);
  return;
}


