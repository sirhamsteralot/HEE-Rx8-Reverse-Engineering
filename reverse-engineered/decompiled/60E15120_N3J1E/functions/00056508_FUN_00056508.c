/* [ADDITIONAL SOURCE REVIEW]
 * uds_service_3e_tester_present [high]: service table record 0x5ebc4 (service 0x3e) -> handler; ROM bytes verified; UDS 0x3E
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00056508; body bytes: 166; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00054824 (166 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint uds_service_3e_tester_present(short param_1,uint param_2)

{
  ushort snapshot_DAT_ffffd3b4;
  short sVar2;
  char local_10 [4];
  short sStack_c;
  
  snapshot_DAT_ffffd3b4 = diag_permission_mask_ffffd3b4_ffffd3b4;
  param_2 = param_2 & 0xff;
  sStack_c = param_1;
  if (param_2 == 1) {
    if (param_1 == 1) {
      ref_udsServiceResponse(0x3e,local_10,1);
      if ((local_10[0] == '\x01') && ((snapshot_DAT_ffffd3b4 & 0xfffc) != 0)) {
        sVar2 = FUN_000565ae();
      }
      else if ((local_10[0] == '\x02') && ((snapshot_DAT_ffffd3b4 & 0xfffc) != 0)) {
        sVar2 = 0;
      }
      else {
        sVar2 = ref_udsErrorResponse(0x3e,0x12);
      }
    }
    else {
      sVar2 = ref_udsErrorResponse(0x3e,0x12);
    }
    if (sVar2 == 0) {
      param_2 = FUN_0005494a(0x3e);
    }
    else {
      param_2 = ref_udsResponseRelated__(0x3e);
    }
  }
  else if (param_2 == 0) {
    param_2 = FUN_0005494a(0x3e);
  }
  return param_2;
}


