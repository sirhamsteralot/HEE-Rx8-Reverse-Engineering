/* ROM address: 0x0005b492; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00059c82 (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005b492(void)

{
  uint uVar1;
  
  if (DAT_ffffd2f0 == 1) {
    FUN_0005b5b0();
    (*(code *)(&PTR_ref_grablast28ByteFromE2_0005f6e4)[(uint)DAT_ffffd2e9 * 3])(0x21);
    DAT_ffffd2f0 = 0;
    DAT_ffffd2f1 = 0;
    uVar1 = ref_udsResponseRelated__(0x21,(byte)(&DAT_0005f6de)[(uint)DAT_ffffd2e9 * 0xc] + 2);
    return uVar1;
  }
  return (uint)DAT_ffffd2f0;
}


