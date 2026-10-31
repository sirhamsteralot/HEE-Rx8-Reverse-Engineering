/* ROM address: 0x00023190; body bytes: 78; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00023a04 (78 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 * FUN_00023190(void)

{
  char cVar1;
  
  cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff809e,0);
  if (((cVar1 == '\x01') && (DAT_ffffb4ee == '\0')) &&
     (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873e,0), cVar1 == '\0')) {
    DAT_ffffb408 = 0;
    return (undefined2 *)0x0;
  }
  if (0x270 < DAT_ffffa9e2) {
    DAT_ffffb408 = 0;
    return &DAT_0007c6be;
  }
  DAT_ffffb408 = 1;
  return (undefined2 *)((int)&vector_Poweron_Reset + 1);
}


