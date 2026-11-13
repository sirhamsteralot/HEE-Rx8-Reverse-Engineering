/* ROM address: 0x0004b84a; body bytes: 94; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004aa02 (94 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004b84a(void)

{
  uint uVar1;
  
  uVar1 = (uint)engine_injectors_off_ffffa42c;
  if ((engine_running_flag_ffffaa68 == '\0') || (engine_stopped_latch_ffffa41c == '\x01')) {
    DAT_ffffce49 = 0;
  }
  else if ((uVar1 == 1) && (1 < DAT_ffffce4b)) {
    DAT_ffffce49 = 1;
  }
  if (uVar1 == 1) {
    uVar1 = rx8_add_u8_saturate((int)(char)DAT_ffffce4b,1);
    DAT_ffffce4b = (byte)uVar1;
  }
  else {
    DAT_ffffce4b = 0;
  }
  return uVar1;
}


