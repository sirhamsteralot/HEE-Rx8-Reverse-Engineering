/* ROM address: 0x000695e2; body bytes: 134; decompiled */

uint FUN_000695e2(uint param_1,undefined1 param_2,uint param_3)

{
  undefined1 local_2c [4];
  undefined1 uStack_28;
  uint local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  param_3 = param_3 & 0xff;
  local_24 = param_1 & 0xff;
  uStack_28 = param_2;
  if (param_3 == 2) {
    FUN_0006895e(param_1);
    local_2c[0] = 0x7f;
    FUN_000688c8(param_1,local_2c,1);
    local_2c[0] = (undefined1)param_1;
    FUN_000688c8(param_1,local_2c,1);
    local_2c[0] = uStack_28;
    FUN_000688c8(param_1,local_2c,1);
    uStack_20 = 3;
    uStack_1c = 8;
    uStack_18 = 0;
    param_3 = FUN_000694fa();
  }
  else if (param_3 == 1) {
    uStack_20 = 3;
    uStack_1c = 8;
    uStack_18 = 1;
    param_3 = FUN_000694fa();
  }
  return param_3;
}


