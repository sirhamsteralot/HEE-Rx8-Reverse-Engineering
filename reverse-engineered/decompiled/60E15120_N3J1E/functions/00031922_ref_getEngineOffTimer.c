/* ROM address: 0x00031922; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00031dca (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_getEngineOffTimer(void)

{
  uint uVar1;
  
  uVar1 = (uint)engine_stopped_latch_ffffa41c;
  if (uVar1 == 1) {
    uVar1 = rx8_add_u16_saturate((int)DAT_ffffbf6e,1);
    DAT_ffffbf6e = (short)uVar1;
  }
  else {
    DAT_ffffbf6e = 0;
  }
  return uVar1;
}


