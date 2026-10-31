/* ROM address: 0x00049080; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004810c (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00049080(void)

{
  undefined4 uVar1;
  
  if ((((DAT_ffffb2cf == '\x01') || (DAT_ffffc030 == '\x01')) || (DAT_ffffccbc == '\x01')) ||
     (DAT_ffffccbb == '\x01')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8762,uVar1);
  return;
}


