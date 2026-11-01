/* ROM address: 0x0000c1f8; body bytes: 126; decompiled */

void FUN_0000c1f8(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  
  DAT_ffffa37e = 0x5e;
  DAT_ffffa37c = 0xc1;
  DAT_ffffa328 = 0x406c0000;
  DAT_ffffa360 = 0x41200000;
  DAT_ffffa364 = 0x42800000;
  DAT_ffffa384 = 0xff;
  DAT_ffffa385 = 0;
  iVar4 = 0;
  puVar5 = &DAT_0007a164;
  DAT_ffffa386 = 0;
  DAT_ffffa324 = 0;
  DAT_ffffa32c = 0;
  iVar2 = 0;
  puVar3 = &DAT_ffffa389;
  DAT_ffffa348 = 0;
  do {
    iVar4 = iVar4 + 1;
    *(undefined4 *)((int)&DAT_ffffa350 + iVar2) = 0x41200000;
    *(undefined4 *)((int)&DAT_ffffa368 + iVar2) = 0x42800000;
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar3 = uVar1;
    *(undefined4 *)((int)&DAT_ffffa334 + iVar2) = 0;
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar4 < 2);
  return;
}


