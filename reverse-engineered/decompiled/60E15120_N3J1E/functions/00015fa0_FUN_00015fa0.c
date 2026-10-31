/* ROM address: 0x00015fa0; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00015da4 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00015fa0(void)

{
  short sVar1;
  
  if (DAT_ffffb534 == '\x01') {
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


