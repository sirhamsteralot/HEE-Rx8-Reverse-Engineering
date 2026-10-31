/* ROM address: 0x00045514; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000445a0 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00045514(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8760,1);
  if (cVar2 == '\x01') {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8728,0);
  }
  DAT_ffffcbd6 = DAT_ffffad5c;
  DAT_ffffcbe4 = DAT_ffffad5c;
  DAT_ffffcbe6 = DAT_ffffad5c;
  uVar1 = (uint)DAT_ffffb4cc;
  DAT_ffffcbea = (uint)(int)DAT_ffffad5c < uVar1;
  if ((bool)DAT_ffffcbea) {
    uVar1 = 1;
  }
  return uVar1;
}


