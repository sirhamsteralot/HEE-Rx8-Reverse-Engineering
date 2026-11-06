/* [ADDITIONAL SOURCE REVIEW]
 * idle_trim_load [medium]: 0xffffa88c = learned idle trim read from 0xffff8040 (when 0xffffb534==1) or 0xffff8048 (MT: 0xffffb53c selects; addresses as sign-extended mov.w -0x7fc0/-0x7fb8) via ref_readValue_float_DEFAULTVAL_ADDRESS. Called from 0x167c0 via pool 0x168cc.
 */
/* ROM address: 0x00015fa0; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00015da4 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_idle_trim_load(void)

{
  short sVar1;
  
  if (automatic_transmission_ffffb534 == '\x01') {
    DAT_ffffa88c = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff8040);
  }
  else {
    if (DAT_ffffb53c == '\0') {
      sVar1 = -0x7fc0;
    }
    else {
      sVar1 = -0x7fb8;
    }
    DAT_ffffa88c = ref_readValue_float_DEFAULTVAL_ADDRESS(0,(int)sVar1);
  }
  return;
}


