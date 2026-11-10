/* [ADDITIONAL SOURCE REVIEW]
 * uds_service_21_read_data_by_local_id [medium]: service table record 0x5ebdc (service 0x21) -> handler; ROM bytes verified; record 0x5ebdc -> 0x5b414 (ref_UDSService21Function)
 */
/* ROM address: 0x0005b414; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00059c04 (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint uds_service_21_read_data_by_local_id(short param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 != 1) {
      uVar1 = ref_udsErrorResponse(0x21,0x12);
      uVar2 = ref_udsResponseRelated__(0x21,uVar1);
      return uVar2;
    }
    ref_udsServiceResponse(0x21,&DAT_ffffd2e8,1);
    param_2 = FUN_0005b4e8();
    if ((param_2 & 0xff) != 0) {
      uVar1 = ref_udsErrorResponse(0x21);
      uVar2 = ref_udsResponseRelated__(0x21,uVar1);
      return uVar2;
    }
    DAT_ffffd2f0 = 1;
    DAT_ffffd2f1 = 1;
  }
  else if (param_2 == 0) {
    uVar2 = FUN_0005494a(0x21);
    return uVar2;
  }
  return param_2;
}


