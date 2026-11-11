/* [ADDITIONAL SOURCE REVIEW]
 * diag22_accept_identifier_request [medium]: Service 0x22 reads two request bytes into 0xffffd1ea and updates request state. Decompiled phase parameter comparison remains suspect; name describes visible path.
 * uds_service_22_read_data_by_identifier [high]: service table record 0x5ebe8 (service 0x22) -> handler; ROM bytes verified; record 0x5ebe8 -> 0x567e8 (Mode 22 PID request parser)
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000567e8; body bytes: 110; decompiled */

/* Function candidate recovered from ROM pointer at 5ebec and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined1 * uds_service_22_read_data_by_identifier(short param_1,uint param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined1 local_c;
  undefined1 uStack_b;
  
  puVar2 = (undefined1 *)(param_2 & 0xff);
  if (puVar2 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) {
    if (param_1 == 2) {
      ref_udsServiceResponse(RX8_SERVICE_READ_DATA,&local_c,2);
      diag22_current_identifier_ffffd1ea = CONCAT11(local_c,uStack_b);
      DAT_ffffd1e8 = 0;
      puVar2 = &DAT_ffffd1ec;
      DAT_ffffd1ec = 1;
    }
    else {
      uVar1 = ref_udsErrorResponse(RX8_SERVICE_READ_DATA,0x12);
      puVar2 = (undefined1 *)ref_udsResponseRelated__(RX8_SERVICE_READ_DATA,uVar1);
    }
  }
  else if (puVar2 == (undefined1 *)0x0) {
    puVar2 = (undefined1 *)FUN_0005494a(RX8_SERVICE_READ_DATA);
  }
  return puVar2;
}


