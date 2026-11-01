/* ROM address: 0x0000b886; body bytes: 162; decompiled */

undefined4 FUN_0000b886(undefined2 *param_1,byte param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (DAT_ffffa31f < 2) {
    iVar4 = 0;
    (&DAT_ffffa31a)[DAT_ffffa31d] = param_2;
    iVar3 = 0;
    if (param_2 != 0) {
      do {
        uVar1 = *param_1;
        param_1 = param_1 + 1;
        iVar4 = iVar4 + 1;
        *(undefined2 *)(&DAT_ffffa22a + iVar3 + (uint)DAT_ffffa31d * 0x3c) = uVar1;
        iVar3 = iVar3 + 2;
      } while (iVar4 < (int)(uint)param_2);
    }
    DAT_ffffa31d = DAT_ffffa31d + 1;
    if (1 < DAT_ffffa31d) {
      DAT_ffffa31d = 0;
    }
    uVar2 = FUN_00003920(0x90);
    DAT_ffffa31f = DAT_ffffa31f + 1;
    if (DAT_ffffa31f < 2) {
      FUN_0000bccc();
    }
    uVar5 = 0;
    FUN_00003934(uVar2);
  }
  else {
    uVar5 = 1;
  }
  return uVar5;
}


