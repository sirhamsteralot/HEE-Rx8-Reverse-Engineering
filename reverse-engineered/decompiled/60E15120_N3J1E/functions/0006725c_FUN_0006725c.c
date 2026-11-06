/* [ADDITIONAL SOURCE REVIEW]
 * obd_mode06_test_results [high]: service table record 0x5eb70 (service 0x06) -> handler; ROM bytes verified; OBD Mode 06
 */
/* ROM address: 0x0006725c; body bytes: 144; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065b4c (144 bytes). Names prefixed ref_
   are inherited hypotheses. */

void obd_mode06_test_results(undefined4 param_1,char param_2)

{
  char cVar1;
  undefined4 unaff_r12;
  int iVar2;
  undefined1 local_1c [4];
  char cStack_18;
  
  iVar2 = 0;
  local_1c[0] = 0x46;
  cStack_18 = param_2;
  cVar1 = FUN_00067310(param_1);
  if (cVar1 == '\0') {
    ref_udsServiceResponse(6,&DAT_ffffd952,param_1);
    unaff_r12 = FUN_00066718((int)DAT_ffffd952);
    cVar1 = FUN_00067326(unaff_r12,&DAT_ffffd952,param_1);
    if (cVar1 != '\0') {
      iVar2 = 1;
    }
  }
  else {
    iVar2 = 1;
  }
  if (iVar2 == 0) {
    ref_setupForUdsResponse_(6,local_1c,1);
    DAT_ffffd950 = 1;
    cVar1 = FUN_00066e30(unaff_r12,&DAT_ffffd952,param_1);
    if (cVar1 != '\0') {
      iVar2 = 2;
    }
  }
  FUN_0006734c(iVar2,(int)cStack_18);
  return;
}


