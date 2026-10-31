/* ROM address: 0x0004e692; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004c166 (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0004e692(void)

{
  undefined4 uVar1;
  float extraout_fr0;
  
  uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff867c);
  if (extraout_fr0 < 15.0) {
    if (extraout_fr0 < 14.6079) {
      DAT_ffffcf94 = 0;
    }
  }
  else {
    DAT_ffffcf94 = 1;
  }
  if (extraout_fr0 < 85.0) {
    if (extraout_fr0 < 84.6079) {
      DAT_ffffcf95 = 0;
    }
  }
  else {
    DAT_ffffcf95 = 1;
  }
  return uVar1;
}


