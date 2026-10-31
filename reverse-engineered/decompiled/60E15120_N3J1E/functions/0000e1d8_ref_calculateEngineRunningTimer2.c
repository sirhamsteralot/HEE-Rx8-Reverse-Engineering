/* ROM address: 0x0000e1d8; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000e1dc (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_calculateEngineRunningTimer2(void)

{
  uint uVar1;
  
  uVar1 = (uint)engine_running_ffffa428;
  if (uVar1 == 1) {
    uVar1 = rx8_add_u16_saturate((int)DAT_ffffa420,1);
    DAT_ffffa420 = (short)uVar1;
  }
  return uVar1;
}


