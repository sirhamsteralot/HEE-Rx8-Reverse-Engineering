/* ROM address: 0x000671fc; body bytes: 160; decompiled */

uint FUN_000671fc(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  cVar1 = FUN_0006729c();
  if (cVar1 != '\0') {
    uVar2 = 0x80000000;
  }
  cVar1 = FUN_000672a0(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x40000000;
  }
  cVar1 = FUN_0006729c(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x20000000;
  }
  cVar1 = FUN_00067314(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x10000000;
  }
  cVar1 = FUN_00067332(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x8000000;
  }
  cVar1 = FUN_0006729c(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x4000000;
  }
  cVar1 = FUN_0006729c(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x2000000;
  }
  cVar1 = FUN_0006729c(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x1000000;
  }
  cVar1 = FUN_0006734e(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x800000;
  }
  return uVar2;
}


