/* [ADDITIONAL SOURCE REVIEW]
 * can_mailbox_bitmask [high]: returns *(i16*)(0xd914 + (mb&0xf)*2) from the ROM mask table; mask = 1<<((mb+8)&0xf), e.g. mb14 -> 0x40, mb15 -> 0x80 (verified vs ROM bytes at 0xd914 and emulator RXPR bits).
 */
/* ROM address: 0x0000cf12; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000cf12 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

int can_mailbox_bitmask(uint param_1)

{
  return (int)*(short *)(&DAT_0000d914 + (param_1 & 0xf) * 2);
}


