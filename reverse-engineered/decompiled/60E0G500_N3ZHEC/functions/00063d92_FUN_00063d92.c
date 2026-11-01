/* ROM address: 0x00063d92; body bytes: 112; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00063d92(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  _DAT_ffff8d74 = FUN_00002430(0);
  _DAT_ffff8d78 = FUN_00002430(1);
  puVar2 = &DAT_ffff8930;
  puVar4 = puVar2;
  puVar5 = puVar2;
  do {
    *puVar2 = 0xffff;
    puVar2[1] = 0xffff;
    puVar3 = puVar5 + 5;
    puVar2[2] = 0xffff;
    *(undefined1 *)(puVar2 + 3) = 0;
    *(undefined1 *)((int)puVar2 + 7) = 0;
    *(undefined1 *)(puVar2 + 4) = 8;
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined2 *)((int)puVar3 + 1);
    } while (iVar1 < 0x28);
    puVar2 = puVar2 + 0x1a;
    *(undefined1 *)(puVar4 + 0x19) = 0xa3;
    puVar4 = puVar4 + 0x1a;
    puVar5 = puVar5 + 0x1a;
  } while (puVar2 < &DAT_ffff8d74);
  return;
}


