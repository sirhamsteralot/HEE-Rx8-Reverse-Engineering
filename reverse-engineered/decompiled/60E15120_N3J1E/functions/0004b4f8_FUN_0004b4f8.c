/* ROM address: 0x0004b4f8; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004a6b0 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004b4f8(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if ((engine_stopped_latch_ffffa41c == '\x01') ||
     ((uVar1 = (uint)engine_injectors_off_ffffa42c, uVar1 == 1 && (uVar1 = (uint)engine_running_ffffa428, uVar1 == 0)))) {
    DAT_ffffce20 = 0x80;
  }
  else {
    DAT_ffffce20 = 0;
  }
  return uVar1;
}


