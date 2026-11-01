/* ROM address: 0x00053de6; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00051efa (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00053de6(void)

{
  uint uVar1;
  
  uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fda,0);
  if ((inferred_ram_d1a1_ffffd1a1_ffffd1a1 == '\0') && ((uVar1 = uVar1 & 0xff, uVar1 == 1 || (engine_running_ffffa428 == '\0')))) {
    inferred_ram_d1a2_ffffd1a2_ffffd1a2 = 1;
  }
  else {
    inferred_ram_d1a2_ffffd1a2_ffffd1a2 = 0;
  }
  return uVar1;
}


