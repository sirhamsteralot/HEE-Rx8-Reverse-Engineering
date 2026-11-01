/* ROM address: 0x00009b92; body bytes: 106; decompiled */

void FUN_00009b92(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort *puVar3;
  ushort uVar5;
  undefined2 *puVar4;
  undefined2 uVar6;
  
  uVar2 = FUN_00003920(0x90);
  puVar3 = (ushort *)FUN_0000cee8((int)*(char *)(param_1 + 5),&DAT_ffffe406);
  uVar1 = *puVar3;
  uVar5 = FUN_0000cf12((int)*(char *)(param_1 + 5));
  if ((uVar5 & uVar1) != 0) {
    puVar4 = (undefined2 *)FUN_0000cee8((int)*(char *)(param_1 + 5),&DAT_ffffe40c);
    uVar6 = FUN_0000cf12((int)*(char *)(param_1 + 5));
    *puVar4 = uVar6;
    puVar4 = (undefined2 *)FUN_0000cee8((int)*(char *)(param_1 + 5),&DAT_ffffe408);
    uVar6 = FUN_0000cf12((int)*(char *)(param_1 + 5));
    *puVar4 = uVar6;
  }
  FUN_00003934(uVar2);
  return;
}


