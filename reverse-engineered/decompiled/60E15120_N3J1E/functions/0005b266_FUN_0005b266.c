/* ROM address: 0x0005b266; body bytes: 140; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00059a56 (140 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0005b266(void)

{
  char cVar2;
  int iVar1;
  uint unaff_r11;
  int unaff_r12;
  uint unaff_r14;
  undefined1 uStack00000008;
  undefined1 uStack0000000a;
  
  if (((unaff_r14 & 0xffff) == unaff_r11) || (cVar2 = FUN_00061ae6(), cVar2 != '\0')) {
    iVar1 = ref_udsErrorResponse(0x12,0x31);
  }
  else {
    uStack00000008 = 0x52;
    ref_setupForUdsResponse_(0x12,&stack0x00000008,2);
    iVar1 = FUN_0005b33a(&stack0x0000000c);
    uStack00000008 = 4;
    uStack0000000a = *(undefined1 *)(unaff_r12 + 1);
    ref_setupForUdsResponse_(0x12,&stack0x00000008,3);
    iVar1 = iVar1 + 5;
  }
  ref_udsResponseRelated__(0x12,iVar1);
  ref_dtcCodeTypeInit();
  return;
}


