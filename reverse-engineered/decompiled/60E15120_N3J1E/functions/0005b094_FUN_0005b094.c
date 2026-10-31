/* ROM address: 0x0005b094; body bytes: 154; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00059884 (154 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005b094(ushort param_1,uint param_2)

{
  uint uVar1;
  char local_18;
  char cStack_17;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 < 2) {
      param_2 = ref_udsErrorResponse(0x12);
      uVar1 = param_2;
    }
    else {
      ref_udsServiceResponse(0x12,&local_18,2);
      if ((local_18 == '\0') && (cStack_17 == '\x04')) {
        if (param_1 == 4) {
          param_2 = ref_writeDTCCodeType(2);
          uVar1 = 0;
        }
        else {
          param_2 = ref_udsErrorResponse(0x12);
          uVar1 = param_2;
        }
      }
      else {
        param_2 = ref_udsErrorResponse(0x12,0x31);
        uVar1 = param_2;
      }
    }
    if ((uVar1 & 0xffff) != 0) {
      param_2 = ref_udsResponseRelated__(0x12,uVar1);
    }
  }
  else if (param_2 == 0) {
    param_2 = FUN_0005494a(0x12);
  }
  return param_2;
}


