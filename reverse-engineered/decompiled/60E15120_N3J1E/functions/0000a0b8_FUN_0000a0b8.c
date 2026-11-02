/* ROM address: 0x0000a0b8; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a0b8 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000a0b8(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = os_wake_posted_task(6);
  if (iVar1 != 0) {
    ref_calledLots(6);
    return;
  }
  ref_setupStructRotorNumber_(1,param_1);
  return;
}


