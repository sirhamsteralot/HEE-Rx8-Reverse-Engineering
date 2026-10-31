/* ROM address: 0x0005df60; body bytes: 196; decompiled */

/* Function candidate recovered from ROM pointer at 5ec40 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_0005df60(short param_1,uint param_2)

{
  char cVar2;
  undefined4 uVar1;
  int iVar3;
  char local_18;
  char cStack_17;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 == 2) {
      ref_udsServiceResponse(0x31,&local_18,2);
      iVar3 = (int)local_18;
      cVar2 = ref_udsCheckMode31Conditions(iVar3);
      if (cVar2 == '\0') {
        cVar2 = FUN_00059190(iVar3);
        if ((cVar2 == '\0') && (cVar2 = FUN_000591e8(iVar3,(int)cStack_17), cVar2 == '\0')) {
          uVar1 = FUN_0005e26e(iVar3);
          DAT_ffffd387 = 1;
          FUN_0005931a(iVar3,(int)cStack_17);
        }
        else {
          uVar1 = ref_udsErrorResponse(0x31);
          FUN_00059388();
        }
      }
      else {
        uVar1 = ref_udsErrorResponse(0x31,0x22);
      }
    }
    else {
      uVar1 = ref_udsErrorResponse(0x31,0x12);
    }
    param_2 = ref_udsResponseRelated__(0x31,uVar1);
  }
  else if (param_2 == 0) {
    param_2 = FUN_0005494a(0x31);
  }
  return param_2;
}


