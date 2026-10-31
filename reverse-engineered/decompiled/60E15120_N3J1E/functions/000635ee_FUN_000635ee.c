/* ROM address: 0x000635ee; body bytes: 112; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00061ede (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000635ee(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  DAT_ffff8d4c = rx8_pack_u16_with_complement(0);
  _DAT_ffff8d50 = rx8_pack_u16_with_complement(1);
  puVar2 = (undefined4 *)&DAT_ffff8908;
  puVar4 = puVar2;
  puVar5 = puVar2;
  do {
    *(undefined2 *)puVar2 = 0xffff;
    *(undefined2 *)((int)puVar2 + 2) = 0xffff;
    puVar3 = (undefined2 *)((int)puVar5 + 10);
    *(undefined2 *)(puVar2 + 1) = 0xffff;
    *(undefined1 *)((int)puVar2 + 6) = 0;
    *(undefined1 *)((int)puVar2 + 7) = 0;
    *(undefined1 *)(puVar2 + 2) = 8;
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined2 *)((int)puVar3 + 1);
    } while (iVar1 < 0x28);
    puVar2 = puVar2 + 0xd;
    *(undefined1 *)((int)puVar4 + 0x32) = 0xa3;
    puVar4 = puVar4 + 0xd;
    puVar5 = puVar5 + 0xd;
  } while (puVar2 < &DAT_ffff8d4c);
  return;
}


