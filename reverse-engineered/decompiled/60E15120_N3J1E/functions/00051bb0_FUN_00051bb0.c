/* ROM address: 0x00051bb0; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004f90c (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00051bb0(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff869c,0);
  if ((((DAT_ffffd103 == '\0') && (cVar2 == '\x01')) ||
      ((DAT_ffffd103 == '\x02' && (cVar2 == '\x03')))) || (uVar1 = (uint)DAT_ffffd1c5, uVar1 == 1))
  {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c4,0x17);
  }
  DAT_ffffd103 = cVar2;
  return uVar1;
}


