/* [ADDITIONAL SOURCE REVIEW]
 * uds_service_85_control_dtc_setting [high]: service table record 0x5eba0 (service 0x85) -> handler; ROM bytes verified; UDS 0x85 (ref_UDSMode85Func)
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005dc44; body bytes: 180; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005c434 (180 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint uds_service_85_control_dtc_setting(short param_1,uint param_2)

{
  ushort snapshot_DAT_ffffd3b4;
  char cVar3;
  undefined4 uVar2;
  char local_18 [4];
  short sStack_14;
  
  snapshot_DAT_ffffd3b4 = diag_permission_mask_ffffd3b4_ffffd3b4;
  param_2 = param_2 & 0xff;
  sStack_14 = param_1;
  if (param_2 == 1) {
    if (param_1 == 1) {
      cVar3 = FUN_00055e3e(0);
      if (cVar3 == '\0') {
        ref_udsServiceResponse(0x85,local_18,(int)sStack_14);
        if (((local_18[0] == '\x01') && ((snapshot_DAT_ffffd3b4 & 0xfffc) != 0)) ||
           ((local_18[0] == '\x02' && ((snapshot_DAT_ffffd3b4 & 0xfffc) != 0)))) {
          ref_setDiagMode85Bool2((int)local_18[0]);
          uVar2 = FUN_0005de18((int)local_18[0]);
        }
        else {
          uVar2 = ref_udsErrorResponse(0x85,0x12);
        }
      }
      else {
        uVar2 = ref_udsErrorResponse(0x85,0x22);
      }
    }
    else {
      uVar2 = ref_udsErrorResponse(0x85,0x12);
    }
    param_2 = ref_udsResponseRelated__(0x85,uVar2);
  }
  else if (param_2 == 0) {
    param_2 = FUN_0005494a(0x85);
  }
  return param_2;
}


