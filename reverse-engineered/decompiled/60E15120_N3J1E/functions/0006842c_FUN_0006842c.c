/* ROM address: 0x0006842c; body bytes: 136; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066d1c (136 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 isotp_frame_type_dispatch(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_1 == '\0') {
    cVar1 = FUN_000686f8();
    if (cVar1 == '\0') {
      uVar2 = isotp_single_frame_accept();
    }
  }
  else if (param_1 == '\x10') {
    cVar1 = FUN_00068712();
    if (cVar1 == '\0') {
      isotp_first_frame_accept();
    }
  }
  else if (param_1 == ' ') {
    cVar1 = isotp_consecutive_frame_check();
    if ((cVar1 == '\0') && (FUN_00068620(), DAT_ffffdde6 <= DAT_ffffdde8)) {
      FUN_00068c58(5);
      uVar2 = 0;
    }
  }
  else if (param_1 == '0') {
    cVar1 = isotp_flow_control_check();
    if (cVar1 == '\0') {
      FUN_00068688();
    }
  }
  return uVar2;
}


