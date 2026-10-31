/* ROM address: 0x0000d648; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000d648 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000d648(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  while (param_1 < param_2) {
    *param_1 = 0x5aa5a55a;
    iVar2 = *param_1;
    *param_1 = -0x5aa5a55b;
    if (iVar2 != 0x5aa5a55a) {
      uVar1 = 1;
    }
    iVar2 = *param_1;
    param_1 = param_1 + 1;
    if (iVar2 != -0x5aa5a55b) {
      uVar1 = 1;
    }
  }
  return uVar1;
}


