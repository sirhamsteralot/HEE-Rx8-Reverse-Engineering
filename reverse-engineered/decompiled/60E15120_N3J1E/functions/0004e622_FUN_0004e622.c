/* ROM address: 0x0004e622; body bytes: 112; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004c0f6 (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004e622(void)

{
  byte bVar2;
  uint uVar1;
  
  bVar2 = ref_getKnownBooleanValue__();
  if (DAT_ffffd1ad == '\x01') {
    DAT_ffffcf90 = DAT_ffffcf8c;
  }
  else {
    DAT_ffffcf90 = rx8_first_order_filter(DAT_ffffcf8c,DAT_ffffcf90,0.0078099966,1e-05);
  }
  uVar1 = (uint)DAT_ffffcfb5;
  if ((((uVar1 & 0x80) == 0) && (uVar1 = (uint)bVar2, uVar1 == 1)) &&
     (uVar1 = (uint)DAT_ffffcf96, uVar1 == 1)) {
    uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(DAT_ffffcf90,&DAT_ffff867c);
  }
  DAT_ffffcf96 = bVar2;
  return uVar1;
}


