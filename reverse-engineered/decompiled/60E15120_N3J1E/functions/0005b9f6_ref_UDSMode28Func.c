/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005b9f6; body bytes: 236; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005a1e6 (236 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_UDSMode28Func(short param_1,uint param_2)

{
  ushort snapshot_DAT_ffffd3b4;
  char cVar3;
  undefined4 uVar2;
  char local_18;
  char local_17;
  char cStack_16;
  
  snapshot_DAT_ffffd3b4 = DAT_ffffd3b4;
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 == 3) {
      if ((DAT_ffffd1cc == '\x01') && (cVar3 = FUN_00055e3e(0), cVar3 == '\0')) {
        ref_udsServiceResponse(0x28,&local_18,3);
        if (local_18 == '\x01') {
          if (((local_17 == '\0') && ((snapshot_DAT_ffffd3b4 & 0xfffc) != 0)) ||
             ((local_17 == '\x01' && ((snapshot_DAT_ffffd3b4 & 0xfffc) != 0)))) {
            if (cStack_16 == '\x01') {
              FUN_0005bbc6((int)local_17);
              uVar2 = FUN_0005bbee();
            }
            else {
              uVar2 = ref_udsErrorResponse(0x28,0x31);
            }
          }
          else {
            uVar2 = ref_udsErrorResponse(0x28,0x31);
          }
        }
        else {
          uVar2 = ref_udsErrorResponse(0x28,0x12);
        }
      }
      else {
        uVar2 = ref_udsErrorResponse(0x28,0x22);
      }
    }
    else {
      uVar2 = ref_udsErrorResponse(0x28,0x12);
    }
    param_2 = ref_udsResponseRelated__(0x28,uVar2);
  }
  else if (param_2 == 0) {
    param_2 = FUN_0005494a(0x28);
  }
  return param_2;
}


