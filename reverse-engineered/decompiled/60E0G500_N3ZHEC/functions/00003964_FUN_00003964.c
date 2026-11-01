/* ROM address: 0x00003964; body bytes: 86; decompiled */

void FUN_00003964(undefined1 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)&DAT_ffff7668;
  uVar3 = 0;
  *param_1 = 0xff;
  *(undefined2 *)(param_1 + 6) = 0xffff;
  *(undefined **)(param_1 + 0x20) = (&PTR_DAT_00004aec)[(char)param_1[1]];
  *(undefined **)(param_1 + 0x24) = &DAT_ffff74a0;
  do {
    *puVar1 = 0;
    uVar3 = uVar3 + 2;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
  } while (uVar3 < 4);
  iVar4 = 0;
  iVar2 = *(int *)(param_1 + 0x20);
  do {
    puVar1 = (undefined4 *)(iVar2 + 4);
    iVar2 = iVar2 + 8;
    if ((undefined2 *)*puVar1 != (undefined2 *)0x0) {
      *(undefined2 *)*puVar1 = 0xffff;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 5);
  return;
}


