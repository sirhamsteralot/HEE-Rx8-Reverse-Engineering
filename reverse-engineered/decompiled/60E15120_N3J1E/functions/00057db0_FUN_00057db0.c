/* [ADDITIONAL SOURCE REVIEW]
 * uds_service_18 [medium]: service table record 0x5ec0c (service 0x18) -> handler; ROM bytes verified; record 0x5ec0c -> 0x57db0
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00057db0; body bytes: 194; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00056280 (194 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint candidate_uds_service_18(short param_1,uint param_2)

{
  ushort snapshot_DAT_ffffd3b4;
  uint uVar2;
  char local_18;
  char cStack_17;
  char cStack_16;
  
  snapshot_DAT_ffffd3b4 = diag_permission_mask_ffffd3b4_ffffd3b4;
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 == 3) {
      ref_udsServiceResponse(0x18,&local_18,3);
      if (((local_18 == '\0') && ((snapshot_DAT_ffffd3b4 & 0xfffc) != 0)) ||
         ((local_18 == '\x01' && ((snapshot_DAT_ffffd3b4 & 0xfffc) != 0)))) {
        if ((cStack_17 == -1) && (cStack_16 == '\0')) {
          param_2 = FUN_00058168((int)local_18);
          uVar2 = 0;
        }
        else {
          param_2 = ref_udsErrorResponse(0x18,0x31);
          uVar2 = param_2;
        }
      }
      else {
        param_2 = ref_udsErrorResponse(0x18,0x12);
        uVar2 = param_2;
      }
    }
    else {
      param_2 = ref_udsErrorResponse(0x18,0x12);
      uVar2 = param_2;
    }
    if ((uVar2 & 0xffff) != 0) {
      param_2 = ref_udsResponseRelated__(0x18,uVar2);
    }
  }
  else if (param_2 == 0) {
    param_2 = FUN_0005494a(0x18);
  }
  return param_2;
}


