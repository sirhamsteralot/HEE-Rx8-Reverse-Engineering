/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000565e8; body bytes: 234; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00054904 (234 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_UDSServiceB1Function(uint param_1,uint param_2)

{
  ushort snapshot_DAT_ffffd3b4;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  ushort local_24 [2];
  ushort local_20 [8];
  
  snapshot_DAT_ffffd3b4 = DAT_ffffd3b4;
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if ((param_1 & 0xffff) < 2) {
      param_2 = ref_udsErrorResponse(0xb1,0x12);
    }
    else {
      ref_udsServiceResponse(0xb1,local_24,2);
      puVar2 = local_20;
      uVar3 = (uint)local_24[0];
      do {
        FUN_00004218();
        uVar4 = (uint)*puVar2;
        if (uVar4 == (uVar3 & 0xffff)) break;
      } while (uVar4 != 0);
      if (uVar4 == 0) {
        param_2 = (**(code **)(puVar2 + 2))();
      }
      else if ((snapshot_DAT_ffffd3b4 & puVar2[4]) == 0) {
        param_2 = FUN_000567c2();
      }
      else if ((uint)puVar2[1] == (param_1 & 0xffff) - 2) {
        param_2 = (**(code **)(puVar2 + 2))();
      }
      else {
        param_2 = ref_udsErrorResponse(0xb1,0x12);
      }
    }
    if ((param_2 & 0xffff) != 0) {
      param_2 = ref_udsResponseRelated__(0xb1);
    }
  }
  else if (param_2 == 0) {
    param_2 = FUN_0005494a(0xb1);
  }
  return param_2;
}


