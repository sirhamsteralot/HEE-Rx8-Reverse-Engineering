/* ROM address: 0x00036970; body bytes: 164; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00037090 (164 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00036970(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char local_18 [4];
  undefined1 local_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  
  iVar3 = 0;
  ref_udsServiceResponse(0xb1,local_18,1);
  if (((DAT_ffffaa68 == '\x01') && (engine_stopped_latch_ffffa41c == '\x01')) &&
     ((cVar1 = FUN_00055e3e(0), cVar1 == '\0' || (cVar1 = FUN_00055e3e(2), cVar1 == '\0')))) {
    if (local_18[0] == '\x10') {
      DAT_ffffc238 = 1;
    }
    else {
      iVar3 = 0x31;
    }
  }
  else {
    iVar3 = 0x22;
  }
  if (iVar3 == 0) {
    uVar2 = 3;
    local_14 = 0xf1;
    uStack_13 = 0;
    uStack_12 = 0x50;
    ref_setupForUdsResponse_(0xb1,&local_14,3);
  }
  else {
    uVar2 = ref_udsErrorResponse(0xb1,iVar3);
  }
  return uVar2;
}


