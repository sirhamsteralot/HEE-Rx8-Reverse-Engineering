/* ROM address: 0x0000d6e4; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000d6e4 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_0000d6e4(void)

{
  undefined4 local_c;
  char cStack_8;
  
  ref_setSR_PARAM(&local_c,0xe0);
  cStack_8 = DAT_ffffa3fc;
  DAT_ffffa3fc = 0;
  FUN_00002064(local_c);
  return (int)cStack_8;
}


