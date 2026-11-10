/* [ADDITIONAL SOURCE REVIEW]
 * uds_service_32 [medium]: service table record 0x5ec48 (service 0x32) -> handler; ROM bytes verified; record 0x5ec48 -> 0x5e024
 */
/* ROM address: 0x0005e024; body bytes: 170; decompiled */

/* Function candidate recovered from ROM pointer at 5ec4c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint uds_service_32(short param_1,uint param_2)

{
  char cVar2;
  undefined4 uVar1;
  int iVar3;
  char local_14;
  char cStack_13;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 == 2) {
      ref_udsServiceResponse(0x32,&local_14,2);
      iVar3 = (int)local_14;
      cVar2 = FUN_000592b0(iVar3);
      if (cVar2 == '\0') {
        cVar2 = FUN_00059190(iVar3);
        if ((cVar2 == '\0') && (cStack_13 == '\0')) {
          uVar1 = FUN_0005e292(iVar3);
          FUN_00059398(iVar3);
        }
        else {
          uVar1 = ref_udsErrorResponse(0x32,0x31);
        }
      }
      else {
        uVar1 = ref_udsErrorResponse(0x32,0x22);
      }
    }
    else {
      uVar1 = ref_udsErrorResponse(0x32,0x12);
    }
    param_2 = ref_udsResponseRelated__(0x32,uVar1);
  }
  else if (param_2 == 0) {
    param_2 = FUN_0005494a(0x32);
  }
  return param_2;
}


