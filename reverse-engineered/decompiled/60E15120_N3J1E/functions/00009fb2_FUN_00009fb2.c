/* ROM address: 0x00009fb2; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009fb2 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00009fb2(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = os_wake_posted_task(0x12);
  if (iVar1 != 0) {
    uVar2 = ref_calledLots(0x12);
    return uVar2;
  }
  return 0;
}


