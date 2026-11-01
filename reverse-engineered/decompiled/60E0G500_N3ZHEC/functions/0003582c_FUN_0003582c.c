/* ROM address: 0x0003582c; body bytes: 126; decompiled */

void vdi_solenoid_control(void)

{
  int iVar1;
  undefined4 local_18;
  undefined4 auStack_14 [2];
  
  iVar1 = (int)DAT_ffffc230;
  if (DAT_ffffb5b8 < 7250.0) {
    if (DAT_ffffb5b8 < 7062.0) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 1;
  }
  DAT_ffffc230 = vdi_diag_override(iVar1);
  if (DAT_ffffc230 == '\x01') {
    FUN_00002054(auStack_14,0xe0);
    FUN_00004bbc(0xfffff746,0x20,1);
  }
  else {
    FUN_00002054(&local_18,0xe0);
    FUN_00004bbc(0xfffff746,0x20,0);
    auStack_14[0] = local_18;
  }
  FUN_00002064(auStack_14[0]);
  return;
}


