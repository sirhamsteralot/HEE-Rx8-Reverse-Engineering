/* ROM address: 0x0005fe20; body bytes: 242; decompiled */

uint FUN_0005fe20(uint param_1,undefined4 param_2,short param_3)

{
  bool bVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  
  sVar2 = diag_permission_mask_ffffd3b4_ffffd3b4;
  iVar6 = (int)*(short *)(&DAT_0007df42 + (param_1 & 0xffff) * 2);
  if ((DAT_ffffd1c5 == '\x01') || (DAT_ffffd958 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0005ff5a(param_1);
  }
  uVar4 = (uint)dtc_eval_enable_ffffd688;
  if (uVar4 == 1) {
    uVar4 = ref_faultConfirmationSomething_(iVar6,(int)sVar2);
    uVar4 = uVar4 & 0xff;
    if (uVar4 == 0) {
      if (DAT_ffffd25d == '\0') {
        uVar4 = ref_faultEnableStatus2(iVar6,2);
        uVar4 = uVar4 & 0xff;
        if ((uVar4 == 0) && (!bVar1)) {
          uVar4 = FUN_00060062(param_1,uVar3,(int)param_3);
          return uVar4;
        }
      }
      else {
        cVar5 = ref_faultEnableStatus2(iVar6,4);
        if (cVar5 != '\0') {
          uVar4 = ref_faultEnableStatus2(iVar6,8);
          if ((uVar4 & 0xff) != 0) {
            return uVar4 & 0xff;
          }
        }
        uVar4 = 0;
        if (DAT_ffffd25a == '\0') {
          uVar4 = FUN_000601cc(param_1,uVar3,(int)param_3);
          return uVar4;
        }
      }
    }
  }
  return uVar4;
}


