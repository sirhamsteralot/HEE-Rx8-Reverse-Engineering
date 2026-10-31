/* ROM address: 0x00041818; body bytes: 94; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004104c (94 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00041818(void)

{
  uint uVar1;
  
  uVar1 = ref_getFaultStatus__(2);
  uVar1 = uVar1 & 0xff;
  if (((uVar1 == 0) && (uVar1 = (uint)DAT_ffffb358, uVar1 == 1)) && (DAT_ffffd1c5 == '\0')) {
    DAT_ffffc91e = 0x1905 < DAT_ffffc920;
    uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffc920,1);
    DAT_ffffc920 = (ushort)uVar1;
  }
  else {
    DAT_ffffc91e = 0;
    DAT_ffffc920 = 0;
  }
  return uVar1;
}


