/* ROM address: 0x0005a5a6; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00058d5e (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_0005a5a6(undefined4 *param_1)

{
  char cVar2;
  undefined4 uVar1;
  
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff910c,0);
  uVar1 = ref_readValue_32bit_ADDRESS_VAL(&DAT_ffff9104,0);
  *param_1 = uVar1;
  if ((cVar2 == '\0') || (DAT_ffffc63c == '\x01')) {
    DAT_ffffd2dc = '\x01';
  }
  return (int)DAT_ffffd2dc;
}


