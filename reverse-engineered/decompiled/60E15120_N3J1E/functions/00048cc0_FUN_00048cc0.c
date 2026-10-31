/* ROM address: 0x00048cc0; body bytes: 120; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00047d4c (120 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00048cc0(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if (((DAT_ffffaa68 == '\x01') ||
      ((uVar1 = (uint)DAT_ffffb4ee, uVar1 == 1 && (uVar1 = (uint)DAT_ffffccb6, uVar1 < 0x271)))) &&
     (DAT_ffffcca0 == '\0')) {
    if ((DAT_ffffad60 != '\x01') && (DAT_ffffad61 != '\x01')) {
      uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80a2,1);
      if ((uVar1 & 0xff) != 1) {
        DAT_ffffccc1 = 0;
        return uVar1 & 0xff;
      }
    }
    uVar1 = 1;
    if (DAT_ffffb51a == '\0') {
      DAT_ffffccc1 = 1;
      return 1;
    }
  }
  DAT_ffffccc1 = 0;
  return uVar1;
}


