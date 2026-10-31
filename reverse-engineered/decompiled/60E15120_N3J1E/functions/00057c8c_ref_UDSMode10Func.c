/* ROM address: 0x00057c8c; body bytes: 160; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005615c (160 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_UDSMode10Func(short param_1,uint param_2)

{
  uint uVar1;
  char cVar4;
  uint uVar2;
  undefined4 uVar3;
  char local_14 [8];
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 == 1) {
      ref_udsServiceResponse(0x10,local_14,1);
      uVar1 = ref_getDiagSessionSubFunction((int)local_14[0]);
      if ((uVar1 & 0xff) == 5) {
        uVar3 = ref_udsErrorResponse(0x10,0x12);
      }
      else {
        cVar4 = ref_parseSubFunction(uVar1);
        if (cVar4 == '\0') {
          uVar2 = FUN_00055e2a();
          if ((uVar1 & 0xff) != (uVar2 & 0xff)) {
            ref_runSubfunction__(uVar1);
          }
          uVar3 = ref_udsResponseSOmething((int)local_14[0]);
        }
        else {
          uVar3 = ref_udsErrorResponse(0x10,0x22);
        }
      }
    }
    else {
      uVar3 = ref_udsErrorResponse(0x10,0x12);
    }
    param_2 = ref_udsResponseRelated__(0x10,uVar3);
  }
  else if (param_2 == 0) {
    param_2 = FUN_0005494a(0x10);
  }
  return param_2;
}


