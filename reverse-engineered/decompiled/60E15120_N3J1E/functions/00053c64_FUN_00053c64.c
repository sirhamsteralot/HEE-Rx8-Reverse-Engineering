/* ROM address: 0x00053c64; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00051d78 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00053c64(void)

{
  undefined4 uVar1;
  
  if ((DAT_ffff8780._0_1_ == '\0') || (DAT_ffffd1c5 == '\x01')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fd8,uVar1);
  return;
}


