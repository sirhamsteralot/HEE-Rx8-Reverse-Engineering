/* ROM address: 0x0005d7bc; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005bfac (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_UDSMode34Func(short param_1,uint param_2)

{
  char cVar2;
  uint uVar1;
  undefined4 uVar3;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    cVar2 = ref_securityNotUnlocked(1);
    if (cVar2 == '\0') {
      if (param_1 == 8) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = 0x12;
      }
      uVar3 = ref_udsErrorResponse(0x34,uVar3);
    }
    else {
      uVar3 = ref_udsErrorResponse(0x34,0x33);
    }
    uVar1 = ref_udsResponseRelated__(0x34,uVar3);
    return uVar1;
  }
  if (param_2 == 0) {
    uVar1 = FUN_0005494a(0x34);
    return uVar1;
  }
  return param_2;
}


