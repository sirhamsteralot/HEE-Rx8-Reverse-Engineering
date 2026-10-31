/* ROM address: 0x00037546; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00037c66 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00037546(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if (DAT_ffffc1d0 == '\x01') {
    uVar1 = 0x40;
  }
  if (DAT_ffffc274 == '\x01') {
    uVar1 = uVar1 | 4;
  }
  return uVar1;
}


