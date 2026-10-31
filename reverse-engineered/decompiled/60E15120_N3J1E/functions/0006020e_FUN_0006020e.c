/* ROM address: 0x0006020e; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005eafe (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006020e(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 uVar3;
  ushort *puVar4;
  ushort auStack_44 [22];
  
  uVar2 = FUN_000615c6(0xf0,0,auStack_44);
  FUN_0006028c();
  puVar4 = auStack_44 + uVar2;
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    puVar4 = puVar4 + -1;
    uVar1 = *puVar4;
    uVar3 = FUN_00061800((int)(short)uVar1);
    (&DAT_ffffd5fc)[uVar1] = uVar3;
  }
  return;
}


