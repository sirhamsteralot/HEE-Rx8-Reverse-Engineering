/* ROM address: 0x00009fce; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009fce (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00009fce(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = os_wake_posted_task(10);
  if (iVar1 != 0) {
    uVar2 = ref_calledLots(10);
    return uVar2;
  }
  return 0;
}


