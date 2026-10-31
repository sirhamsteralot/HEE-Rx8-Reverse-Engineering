/* ROM address: 0x00053698; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00051f74 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00053698(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fc0,0);
    return uVar1;
  }
  if ((DAT_ffffd190 != '\x01') && (DAT_ffffc543 != 1)) {
    return (uint)DAT_ffffc543;
  }
  uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fc0,1);
  return uVar1;
}


