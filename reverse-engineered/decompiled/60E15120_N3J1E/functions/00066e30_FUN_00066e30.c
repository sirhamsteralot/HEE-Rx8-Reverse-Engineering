/* ROM address: 0x00066e30; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065720 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066e30(char param_1,char *param_2,short param_3)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    uVar1 = FUN_00066e5a(param_2,(int)param_3);
  }
  else {
    uVar1 = FUN_00066f06((int)*param_2);
  }
  return uVar1;
}


