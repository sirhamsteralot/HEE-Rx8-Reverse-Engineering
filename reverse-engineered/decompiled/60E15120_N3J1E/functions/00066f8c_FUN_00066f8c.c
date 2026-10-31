/* ROM address: 0x00066f8c; body bytes: 264; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006587c (264 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066f8c(undefined1 param_1,undefined1 *param_2)

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
    DAT_ffffd93d = *puVar5;
    DAT_ffffd93e = puVar5[1];
    DAT_ffffd93c = param_1;
    cVar3 = (**(code **)(puVar5 + 4))();
    if (cVar3 == '\0') {
      uVar2 = (**(code **)(puVar6 + 8))();
      local_24 = (undefined1)((ushort)uVar2 >> 8);
      DAT_ffffd93f = local_24;
      uStack_23 = (undefined1)uVar2;
      DAT_ffffd940 = uStack_23;
      uVar2 = (**(code **)(puVar6 + 0xc))();
      local_24 = (undefined1)((ushort)uVar2 >> 8);
      DAT_ffffd941 = local_24;
      uStack_23 = (undefined1)uVar2;
      DAT_ffffd942 = uStack_23;
      uVar2 = (**(code **)(puVar6 + 0x10))();
      local_24 = (undefined1)((ushort)uVar2 >> 8);
      DAT_ffffd943 = local_24;
      uStack_23 = (undefined1)uVar2;
      DAT_ffffd944 = uStack_23;
    }
    else {
      DAT_ffffd93f = 0;
      DAT_ffffd940 = 0;
      DAT_ffffd941 = 0;
      DAT_ffffd942 = 0;
      DAT_ffffd943 = 0;
      DAT_ffffd944 = 0;
    }
    uVar1 = FUN_000672ec(&DAT_ffffd93c,9);
    puVar6 = puVar6 + 0x14;
    puVar5 = puVar5 + 0x14;
  }
  return uVar1;
}


