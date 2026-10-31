/* ROM address: 0x0005d874; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005c064 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_UDSService37Function(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    uVar1 = ref_udsErrorResponse(0x37,0x22);
    uVar2 = ref_udsResponseRelated__(0x37,uVar1);
    return uVar2;
  }
  if (param_2 == 0) {
    uVar2 = FUN_0005494a(0x37);
    return uVar2;
  }
  return param_2;
}


