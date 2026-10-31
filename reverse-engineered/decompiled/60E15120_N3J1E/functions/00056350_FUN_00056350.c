/* ROM address: 0x00056350; body bytes: 140; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005466c (140 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00056350(void)

{
  char cVar2;
  undefined4 uVar1;
  char local_14 [8];
  
  cVar2 = FUN_00055e3e(1);
  if (cVar2 == '\0') {
    cVar2 = ref_securityNotUnlocked(1);
    if (cVar2 == '\0') {
      cVar2 = FUN_00056428();
      if (cVar2 == '\0') {
        ref_udsServiceResponse(0xb1,local_14,1);
        if (local_14[0] == '\0') {
          uVar1 = FUN_000564ac();
          FUN_000563de(3);
        }
        else {
          uVar1 = ref_udsErrorResponse(0xb1,0x31);
        }
      }
      else {
        uVar1 = ref_udsErrorResponse(0xb1);
      }
    }
    else {
      uVar1 = ref_udsErrorResponse(0xb1,0x33);
    }
  }
  else {
    uVar1 = ref_udsErrorResponse(0xb1,0x22);
  }
  return uVar1;
}


