/* ROM address: 0x0006672a; body bytes: 138; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006501a (138 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0006672a(uint param_1,undefined1 param_2,uint param_3)

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
    ref_unknownMode22Func(param_1);
    local_2c[0] = 0x7f;
    ref_setupForUdsResponse_(param_1,local_2c,1);
    local_2c[0] = (undefined1)param_1;
    ref_setupForUdsResponse_(param_1,local_2c,1);
    local_2c[0] = uStack_28;
    ref_setupForUdsResponse_(param_1,local_2c,1);
    uStack_20 = 3;
    uStack_1c = 8;
    uStack_18 = 0;
    param_3 = FUN_00068d56();
  }
  else if (param_3 == 1) {
    uStack_20 = 3;
    uStack_1c = 8;
    uStack_18 = 1;
    param_3 = FUN_00068d56();
  }
  return param_3;
}


