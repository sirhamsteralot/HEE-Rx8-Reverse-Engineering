/* ROM address: 0x00009f7a; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009f7a (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00009f7a(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = os_wake_posted_task(8);
  if (iVar1 != 0) {
    uVar2 = ref_calledLots(8);
    return uVar2;
  }
  return 0;
}


