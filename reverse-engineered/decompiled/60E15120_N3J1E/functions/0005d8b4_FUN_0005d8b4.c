/* ROM address: 0x0005d8b4; body bytes: 244; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005c0a4 (244 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005d8b4(ushort param_1,uint param_2)

{
  char cVar2;
  uint uVar1;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    cVar2 = ref_securityNotUnlocked(1);
    if ((cVar2 == '\0') || (cVar2 = ref_securityNotUnlocked(2), cVar2 == '\0')) {
      if (param_1 < 2) {
        param_2 = ref_udsErrorResponse(0x3b,0x12);
        uVar1 = param_2;
      }
      else {
        ref_udsServiceResponse(0x3b,&DAT_ffffd372,1);
        DAT_ffffd370 = param_1 - 1;
        if ((DAT_ffffd1cc == '\x01') &&
           ((DAT_ffffd372 < 0xe0 || (cVar2 = FUN_00055e3e(3), cVar2 == '\0')))) {
          param_2 = FUN_0005db38();
          if ((param_2 & 0xff) == 0) {
            DAT_ffffd375 = 1;
            DAT_ffffd376 = 1;
            uVar1 = 0;
          }
          else {
            param_2 = ref_udsErrorResponse(0x3b);
            uVar1 = param_2;
          }
        }
        else {
          param_2 = ref_udsErrorResponse(0x3b,0x22);
          uVar1 = param_2;
        }
      }
    }
    else {
      param_2 = ref_udsErrorResponse(0x3b,0x33);
      uVar1 = param_2;
    }
    if ((uVar1 & 0xffff) != 0) {
      uVar1 = ref_udsResponseRelated__(0x3b,uVar1);
      return uVar1;
    }
  }
  else if (param_2 == 0) {
    uVar1 = FUN_0005494a(0x3b);
    return uVar1;
  }
  return param_2;
}


