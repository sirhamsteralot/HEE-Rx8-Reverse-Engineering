/* ROM address: 0x00032326; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000327ce (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_debounceCruiseControlSET(void)

{
  uint uVar1;
  
  if (((DAT_ffffbced == '\x01') && (DAT_ffffbc35 == 1)) && (0x3d < DAT_ffffbfc0)) {
    DAT_ffffbfba = 1;
  }
  else {
    DAT_ffffbfba = 0;
  }
  uVar1 = (uint)DAT_ffffbc35;
  if (uVar1 == 1) {
    uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffbfc0,1);
    DAT_ffffbfc0 = (ushort)uVar1;
  }
  else {
    DAT_ffffbfc0 = 0;
  }
  return uVar1;
}


