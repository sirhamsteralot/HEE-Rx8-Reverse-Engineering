/* ROM address: 0x0004876c; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000477f8 (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 * FUN_0004876c(void)

{
  undefined2 *puVar1;
  
  if ((((DAT_ffffb4fd == '\x01') || (DAT_ffffb4fe == '\x01')) &&
      ((DAT_ffffb4f7 == '\x01' || (DAT_ffffb4f8 == '\x01')))) ||
     ((puVar1 = &DAT_0007c6ba, DAT_ffffcce8 < 0x177 && (0x176 < DAT_ffffccb8)))) {
    puVar1 = (undefined2 *)ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8764,1);
  }
  DAT_ffffcce8 = DAT_ffffccb8;
  return puVar1;
}


