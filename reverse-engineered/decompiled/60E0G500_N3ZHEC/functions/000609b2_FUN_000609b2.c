/* ROM address: 0x000609b2; body bytes: 90; decompiled */

void FUN_000609b2(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 uVar3;
  ushort *puVar4;
  ushort auStack_44 [22];
  
  uVar2 = FUN_00061d6a(0xf0,0,auStack_44);
  FUN_00060a30();
  puVar4 = auStack_44 + uVar2;
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    puVar4 = puVar4 + -1;
    uVar1 = *puVar4;
    uVar3 = FUN_00061fa4((int)(short)uVar1);
    (&DAT_ffffd638)[uVar1] = uVar3;
  }
  return;
}


