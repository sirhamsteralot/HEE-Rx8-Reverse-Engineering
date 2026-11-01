/* ROM address: 0x00065b84; body bytes: 160; decompiled */

void FUN_00065b84(short param_1,uint param_2,char param_3)

{
  char cVar4;
  uint uVar1;
  uint uVar2;
  short sVar3;
  
  FUN_00062e78(0);
  cVar4 = FUN_00065d40((int)param_3);
  uVar1 = FUN_0006841c(0);
  FUN_00068408(uVar1 | param_2);
  uVar2 = FUN_00067e82((int)param_1);
  FUN_00067e6c(uVar2 | param_2);
  sVar3 = FUN_000683be(0);
  if (sVar3 == 0) {
    FUN_000683aa(param_2);
  }
  if (((cVar4 == 'p') || (cVar4 == -0x40)) || (cVar4 == -0x3f)) {
    uVar2 = FUN_00067e18((int)param_1);
    FUN_00067de0(uVar2 | param_2);
    sVar3 = FUN_00068360(0);
    if (sVar3 == 0) {
      FUN_0006832c(uVar1 | param_2);
    }
  }
  FUN_000630bc(0);
  return;
}


