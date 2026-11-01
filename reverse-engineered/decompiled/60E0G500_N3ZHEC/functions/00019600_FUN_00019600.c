/* ROM address: 0x00019600; body bytes: 180; decompiled */

undefined4 secondary_air_solenoid_control(void)

{
  undefined4 uVar1;
  undefined4 local_c;
  char cStack_8;
  
  if (DAT_ffffc12c <= 0.8) {
    if (DAT_ffffc12c <= 0.75) {
      DAT_ffffa9e5 = '\0';
    }
  }
  else {
    DAT_ffffa9e5 = '\x01';
  }
  if (DAT_ffffb5b8 <= 4000.0) {
    if (DAT_ffffb5b8 <= 3900.0) {
      DAT_ffffa9e6 = '\0';
    }
  }
  else {
    DAT_ffffa9e6 = '\x01';
  }
  if ((((DAT_ffffbfd4 == '\x01') && (DAT_ffffa9e5 == '\0')) && (DAT_ffffa9e6 == '\0')) ||
     (DAT_ffffd2aa == '\x01')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  cStack_8 = secondary_air_diag_override(uVar1);
  DAT_ffffa9e4 = cStack_8;
  FUN_00002054(&local_c,0xe0);
  FUN_00004bbc(0xfffff754,0x100,cStack_8 == '\x01');
  uVar1 = FUN_00002064(local_c);
  return uVar1;
}


