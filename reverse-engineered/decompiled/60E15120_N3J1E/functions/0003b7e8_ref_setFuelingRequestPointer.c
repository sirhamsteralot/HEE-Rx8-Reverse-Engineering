/* ROM address: 0x0003b7e8; body bytes: 64; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003bc1c (64 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * ref_setFuelingRequestPointer(void)

{
  undefined1 *puVar1;
  float fVar2;
  
  puVar1 = (undefined1 *)(uint)DAT_ffffc5ac;
  if (((puVar1 == (undefined1 *)0x1) && (DAT_ffffb0ca == '\0')) &&
     (puVar1 = &DAT_ffffa914, DAT_ffffa914 == '\0')) {
    fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff86ec);
    puVar1 = (undefined1 *)
             ref_updateMemoryAtAddress_float_VAL_ADDR(fVar2 + fuel_volume_final_ffffbeb0,&DAT_ffff86ec);
    return puVar1;
  }
  return puVar1;
}


