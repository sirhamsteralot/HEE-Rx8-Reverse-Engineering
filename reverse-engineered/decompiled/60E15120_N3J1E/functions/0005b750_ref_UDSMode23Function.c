/* [ADDITIONAL SOURCE REVIEW]
 * uds_service_23_read_memory_by_address [high]: service table record 0x5ebf4 (service 0x23) -> handler; ROM bytes verified; UDS 0x23 (ref_UDSMode23Function)
 */
/* ROM address: 0x0005b750; body bytes: 156; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00059f40 (156 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint uds_service_23_read_memory_by_address(short param_1,uint param_2)

{
  char cVar3;
  undefined4 uVar1;
  uint uVar2;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 == 6) {
      cVar3 = ref_securityNotUnlocked(1);
      if (cVar3 == '\0') {
        ref_udsServiceResponse(0x23,&DAT_ffffd2fe,6);
        param_2 = ref_checkIfAddressInRange();
        if ((param_2 & 0xff) == 0) {
          DAT_ffffd308 = 1;
        }
        else {
          uVar1 = ref_udsErrorResponse(0x23,0x31);
          param_2 = ref_udsResponseRelated__(0x23,uVar1);
        }
      }
      else {
        uVar1 = ref_udsErrorResponse(0x23,0x33);
        param_2 = ref_udsResponseRelated__(0x23,uVar1);
      }
    }
    else {
      uVar1 = ref_udsErrorResponse(0x23,0x12);
      param_2 = ref_udsResponseRelated__(0x23,uVar1);
    }
  }
  else if (param_2 == 0) {
    uVar2 = FUN_0005494a(0x23);
    return uVar2;
  }
  return param_2;
}


