/* ROM address: 0x0000daf0; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000daf0 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_handleCANReset(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffa411;
  if (uVar1 == 1) {
    uVar1 = ref_resetCANTimers();
    DAT_ffffa411 = 0;
  }
  return uVar1;
}


