/* ROM address: 0x0000a022; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a022 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000a022(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = os_wake_posted_task(0xd);
  if (iVar1 != 0) {
    uVar2 = ref_calledLots(0xd);
    return uVar2;
  }
  return 0;
}


