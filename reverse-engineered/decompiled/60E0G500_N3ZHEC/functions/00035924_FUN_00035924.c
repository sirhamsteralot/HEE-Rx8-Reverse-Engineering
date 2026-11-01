/* ROM address: 0x00035924; body bytes: 132; decompiled */

void vfad_solenoid_control(void)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 auStack_18 [2];
  
  iVar1 = (int)DAT_ffffc234;
  if (DAT_ffffb5b8 < 5250.0) {
    if (DAT_ffffb5b8 < 5062.0) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 1;
  }
  DAT_ffffc234 = vfad_diag_override(iVar1);
  if (DAT_ffffc234 == '\x01') {
    FUN_00002054(auStack_18,0xe0);
    FUN_00004bbc(0xfffff754,0x400,1);
  }
  else {
    FUN_00002054(&local_1c,0xe0);
    FUN_00004bbc(0xfffff754,0x400,0);
    auStack_18[0] = local_1c;
  }
  FUN_00002064(auStack_18[0]);
  return;
}


