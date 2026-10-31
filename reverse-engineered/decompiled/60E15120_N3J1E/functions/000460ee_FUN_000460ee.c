/* ROM address: 0x000460ee; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004517a (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000460ee(void)

{
  char cVar2;
  uint uVar1;
  
  if (DAT_ffffcc0c == '\x01') {
    if (0x18 < DAT_ffffcc0e) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8738,1);
    }
    if (0xf9 < DAT_ffffcc10) {
      DAT_ffffcc0d = 1;
    }
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8738,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_0005fd38(0x85,1);
    return uVar1;
  }
  if (DAT_ffffcc0d == 1) {
    uVar1 = FUN_0005fd38(0x85,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc0d;
}


