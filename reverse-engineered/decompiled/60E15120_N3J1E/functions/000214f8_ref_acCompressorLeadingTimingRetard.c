/* ROM address: 0x000214f8; body bytes: 194; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00021e64 (194 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_acCompressorLeadingTimingRetard(void)

{
  char cVar1;
  uint uVar2;
  byte *pbVar3;
  
  cVar1 = DAT_ffffbd68;
  if ((DAT_ffffb2a2 == '\x01') && (DAT_ffffbd68 == '\0')) {
    DAT_ffffb2a0 = 1;
    if (DAT_ffffaa62 == '\x01') {
      DAT_ffffb290 = 0xc0a00000;
      pbVar3 = &DAT_000722ed;
    }
    else {
      DAT_ffffb290 = 0;
      pbVar3 = &DAT_000722ef;
    }
    DAT_ffffb29a = 0;
    DAT_ffffb29b = *pbVar3;
    DAT_ffffb299 = 0;
    DAT_ffffb298 = 0;
  }
  uVar2 = (uint)DAT_ffffb2a0;
  if (uVar2 == 1) {
    if (DAT_ffffb298 < DAT_ffffb29a) {
      uVar2 = rx8_add_u8_saturate((int)(char)DAT_ffffb298,1);
      DAT_ffffb298 = (byte)uVar2;
    }
    else if (DAT_ffffb299 < DAT_ffffb29b) {
      ac_compressor_leading_timing_retard_ffffb288 = DAT_ffffb290;
      uVar2 = rx8_add_u8_saturate((int)(char)DAT_ffffb299,1);
      DAT_ffffb299 = (byte)uVar2;
    }
    else {
      DAT_ffffb298 = 0;
      DAT_ffffb299 = 0;
      DAT_ffffb2a0 = 0;
      ac_compressor_leading_timing_retard_ffffb288 = 0;
    }
  }
  DAT_ffffb2a2 = cVar1;
  return uVar2;
}


