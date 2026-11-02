/* ROM address: 0x0000a05a; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a05a (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000a05a(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = os_wake_posted_task(0xf);
  if (iVar1 != 0) {
    uVar2 = ref_calledLots(0xf);
    return uVar2;
  }
  return 0;
}


