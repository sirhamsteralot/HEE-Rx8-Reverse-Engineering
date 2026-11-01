/* ROM address: 0x00061580; body bytes: 52; decompiled */

uint FUN_00061580(undefined4 param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_0006359c();
  if ((param_2 & 0xff) != (uVar1 & 0xff)) {
    FUN_0006357c(param_2);
    uVar1 = FUN_0006297c(uVar1,param_2);
    return uVar1;
  }
  return uVar1;
}


