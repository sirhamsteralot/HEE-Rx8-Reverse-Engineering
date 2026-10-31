/* ROM address: 0x000215f8; body bytes: 194; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00021f64 (194 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_acCompressorTrailingTimingRetard(void)

{
  char cVar1;
  uint uVar2;
  byte *pbVar3;
  
  cVar1 = DAT_ffffbd68;
  if ((DAT_ffffb2a3 == '\x01') && (DAT_ffffbd68 == '\0')) {
    DAT_ffffb2a1 = 1;
    if (DAT_ffffaa62 == '\x01') {
      DAT_ffffb294 = 0xc0a00000;
      pbVar3 = &DAT_000722f9;
    }
    else {
      DAT_ffffb294 = 0;
      pbVar3 = &DAT_000722fb;
    }
    DAT_ffffb29e = 0;
    DAT_ffffb29f = *pbVar3;
    DAT_ffffb29d = 0;
    DAT_ffffb29c = 0;
  }
  uVar2 = (uint)DAT_ffffb2a1;
  if (uVar2 == 1) {
    if (DAT_ffffb29c < DAT_ffffb29e) {
      uVar2 = rx8_add_u8_saturate((int)(char)DAT_ffffb29c,1);
      DAT_ffffb29c = (byte)uVar2;
    }
    else if (DAT_ffffb29d < DAT_ffffb29f) {
      ac_compressor_trailing_timing_retard_ffffb28c = DAT_ffffb294;
      uVar2 = rx8_add_u8_saturate((int)(char)DAT_ffffb29d,1);
      DAT_ffffb29d = (byte)uVar2;
    }
    else {
      DAT_ffffb29c = 0;
      DAT_ffffb29d = 0;
      DAT_ffffb2a1 = 0;
      ac_compressor_trailing_timing_retard_ffffb28c = 0;
    }
  }
  DAT_ffffb2a3 = cVar1;
  return uVar2;
}


