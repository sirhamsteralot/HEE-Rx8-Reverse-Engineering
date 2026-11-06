/* ROM address: 0x00042a62; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00042296 (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_calculateDriverConditions(void)

{
  undefined4 *puVar1;
  
  if (((automatic_transmission_ffffb534 != '\x01') || (puVar1 = (undefined4 *)0x1, DAT_ffffb53a != '\0')) &&
     ((puVar1 = &DAT_ffffbfa0, DAT_ffffbfa0 <= 15.0 ||
      ((DAT_ffffca40 == '\0' || (puVar1 = (undefined4 *)&inferred_ram_ad18_ffffad18_ffffad18, inferred_ram_ad18_ffffad18_ffffad18 != '\0')))))) {
    if ((automatic_transmission_ffffb534 != '\0') ||
       (puVar1 = (undefined4 *)(uint)DAT_ffffca4c, puVar1 != (undefined4 *)0x1)) {
      DAT_ffffca47 = 0;
      return puVar1;
    }
    puVar1 = (undefined4 *)0x1;
  }
  DAT_ffffca47 = 1;
  return puVar1;
}


