/* ROM address: 0x000583b2; body bytes: 70; decompiled */

int FUN_000583b2(undefined1 param_1,undefined1 *param_2,byte param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  byte bVar3;
  int iVar4;
  undefined1 local_14;
  undefined1 uStack_13;
  undefined1 local_12 [10];
  
  iVar4 = 2;
  bVar3 = 0;
  local_14 = 0x67;
  puVar2 = local_12;
  if (param_3 != 0) {
    do {
      iVar4 = iVar4 + 1;
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      bVar3 = bVar3 + 1;
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
    } while (bVar3 < param_3);
  }
  uStack_13 = param_1;
  FUN_000688c8(0x27,&local_14,iVar4);
  return iVar4;
}


