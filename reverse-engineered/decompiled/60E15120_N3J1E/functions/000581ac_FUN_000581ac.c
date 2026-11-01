/* ROM address: 0x000581ac; body bytes: 54; decompiled */

undefined4 FUN_000581ac(short param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = ref_faultConfirmationSomething_((int)param_1,(int)diag_permission_mask_ffffd3b4_ffffd3b4);
  if ((cVar1 == '\0') && (cVar1 = ref_faultEnableStatus2((int)param_1,2), cVar1 == '\0')) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


