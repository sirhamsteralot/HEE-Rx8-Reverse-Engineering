/* ROM address: 0x00066f6c; body bytes: 210; decompiled */

/* Function candidate recovered from ROM pointer at 662c8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_00066f6c(char param_1,undefined2 *param_2,ushort *param_3,byte param_4)

{
  ushort uVar2;
  uint uVar1;
  undefined2 *puVar3;
  int iVar4;
  ushort uVar6;
  ushort *puVar5;
  uint uVar7;
  
  uVar6 = 1;
  uVar2 = 0;
  uVar7 = 0;
  if ((param_1 == '\x01') || (param_1 == '\x03')) {
    uVar2 = FUN_00068360(0);
  }
  else if (param_1 == '\a') {
    uVar2 = FUN_000683be(0);
  }
  puVar3 = &DAT_0007e104;
  do {
    if ((uVar6 & uVar2) != 0) {
      uVar1 = uVar7 & 0xff;
      uVar7 = uVar7 + 1;
      param_2[uVar1] = *puVar3;
    }
    uVar6 = uVar6 << 1;
    puVar3 = puVar3 + 1;
  } while (puVar3 < &UNK_0007e10f);
  iVar4 = 0;
  if (1 < (uVar7 & 0xff)) {
    uVar7 = 1;
    *param_2 = 0x300;
  }
  puVar5 = param_3;
  if (param_4 != 0) {
    do {
      uVar2 = *puVar5;
      puVar5 = puVar5 + 1;
      if ((uVar2 != 0) && (uVar2 != 1)) {
        uVar1 = uVar7 & 0xff;
        uVar7 = uVar7 + 1;
        param_2[uVar1] = (&DAT_0007e108)[*param_3];
      }
      iVar4 = iVar4 + 1;
      param_3 = param_3 + 1;
    } while (iVar4 < (int)(uint)param_4);
  }
  return uVar7;
}


