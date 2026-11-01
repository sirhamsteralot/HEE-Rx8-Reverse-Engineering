/* ROM address: 0x00067730; body bytes: 264; decompiled */

undefined4 FUN_00067730(undefined1 param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  char cVar3;
  undefined2 uVar2;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 local_24;
  undefined1 uStack_23;
  
  uVar1 = 0x1c;
  puVar5 = param_2;
  puVar6 = param_2;
  for (iVar4 = 0; param_2[iVar4 * 0x14] != -1; iVar4 = iVar4 + 1) {
    DAT_ffffd979 = *puVar5;
    DAT_ffffd97a = puVar5[1];
    DAT_ffffd978 = param_1;
    cVar3 = (**(code **)(puVar5 + 4))();
    if (cVar3 == '\0') {
      uVar2 = (**(code **)(puVar6 + 8))();
      local_24 = (undefined1)((ushort)uVar2 >> 8);
      DAT_ffffd97b = local_24;
      uStack_23 = (undefined1)uVar2;
      DAT_ffffd97c = uStack_23;
      uVar2 = (**(code **)(puVar6 + 0xc))();
      local_24 = (undefined1)((ushort)uVar2 >> 8);
      DAT_ffffd97d = local_24;
      uStack_23 = (undefined1)uVar2;
      DAT_ffffd97e = uStack_23;
      uVar2 = (**(code **)(puVar6 + 0x10))();
      local_24 = (undefined1)((ushort)uVar2 >> 8);
      DAT_ffffd97f = local_24;
      uStack_23 = (undefined1)uVar2;
      DAT_ffffd980 = uStack_23;
    }
    else {
      DAT_ffffd97b = 0;
      DAT_ffffd97c = 0;
      DAT_ffffd97d = 0;
      DAT_ffffd97e = 0;
      DAT_ffffd97f = 0;
      DAT_ffffd980 = 0;
    }
    uVar1 = FUN_00067a90(&DAT_ffffd978,9);
    puVar6 = puVar6 + 0x14;
    puVar5 = puVar5 + 0x14;
  }
  return uVar1;
}


