/* ROM address: 0x000671f0; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065ae0 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000671f0(uint param_1,char param_2)

{
  undefined4 uVar1;
  
  param_1 = param_1 & 0xff;
  if (param_1 == 1) {
    if (param_2 == '\x01') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    param_1 = FUN_0006672a(8,0x12,uVar1);
  }
  else if (param_1 == 2) {
    if (param_2 == '\x01') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    param_1 = FUN_0006672a(8,0x12,uVar1);
  }
  return param_1;
}


