/* ROM address: 0x0000ff32; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000ff36 (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

int ref_fuelInjectionRelated(char *param_1)

{
  int iVar1;
  
  iVar1 = (int)*param_1;
  if (iVar1 == 0) {
    iVar1 = 0x40;
    *(int *)(param_1 + 0x20) = (int)((DAT_ffffa440 + -275.0) * 65536.0);
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x20);
  }
  else if (iVar1 == 1) {
    *(int *)(param_1 + 0x20) = (int)(max_injection_angle_1_ffffa434 * 65536.0);
    *(int *)(param_1 + 0x38) = (int)(max_injection_angle_2_ffffa438 * 65536.0);
    iVar1 = 0x50;
    *(int *)(param_1 + 0x50) = (int)(max_injection_angle_3_ffffa43c * 65536.0);
  }
  return iVar1;
}


