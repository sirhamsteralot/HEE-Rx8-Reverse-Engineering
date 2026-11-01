/* ROM address: 0x0005af54; body bytes: 194; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00059744 (194 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint uds_service_11_ecu_reset(short param_1,byte param_2)

{
  char cVar2;
  undefined4 uVar1;
  uint uVar3;
  char local_18 [4];
  short sStack_14;
  byte bStack_10;
  
  sStack_14 = param_1;
  bStack_10 = param_2;
  FUN_0005b018(0);
  uVar3 = (uint)bStack_10;
  if (uVar3 == 1) {
    if (sStack_14 == 1) {
      ref_udsServiceResponse(0x11,local_18,1);
      if (local_18[0] == '\x01') {
        cVar2 = ref_securityNotUnlocked(1);
        if ((cVar2 == '\0') || (cVar2 = ref_securityNotUnlocked(2), cVar2 == '\0')) {
          if (DAT_ffffd1cc == '\x01') {
            uVar1 = FUN_0005b076();
            FUN_0005b018(1);
          }
          else {
            uVar1 = ref_udsErrorResponse(0x11,0x22);
          }
        }
        else {
          uVar1 = ref_udsErrorResponse(0x11,0x33);
        }
      }
      else {
        uVar1 = ref_udsErrorResponse(0x11,0x12);
      }
    }
    else {
      uVar1 = ref_udsErrorResponse(0x11,0x12);
    }
    uVar3 = ref_udsResponseRelated__(0x11,uVar1);
  }
  else if (uVar3 == 0) {
    uVar3 = FUN_0005494a(0x11);
  }
  return uVar3;
}


