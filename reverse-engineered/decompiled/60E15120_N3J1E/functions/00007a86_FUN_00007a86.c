/* ROM address: 0x00007a86; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007a86 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00007a86(void)

{
  undefined4 uVar1;
  
  if (DAT_ffff9fc0 == '\0') {
    DAT_ffff9fc0 = '\x01';
    DAT_ffff9fa2 = 0;
    DAT_ffff9fa1 = 0;
  }
  if (DAT_ffff9fa3 != '\x02') {
    uVar1 = FUN_00007d90();
    return uVar1;
  }
  return 2;
}


