/* [ADDITIONAL SOURCE REVIEW]
 * dsc_mode_bit80_check [medium]: 0xffffbbcb = 1 when (0xffffbbf6 & 0x80) == 0x80 && engine running. Called from 0x2a2ae via pool 0x2a478.
 * RAM 0xffffbbf6 dsc_mode_byte (uint8): DSC/ABS mode byte from CAN 0x212 payload byte 6 (via 0x2b7e2: bbf6 = bbc6); bits 0x80/0x40/0x20/0x10 checked by 0x2b6c2/0x2b754/0x2b788/0x2b7a6 -> 0xffffbbcb-ce.
 */
/* ROM address: 0x0002b6c2; body bytes: 64; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002be16 (64 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * candidate_dsc_mode_bit80_check(void)

{
  undefined1 *puVar1;
  
  if ((dsc_mode_byte_ffffbbf6 & 0x80) == 0x80) {
    puVar1 = (undefined1 *)(uint)engine_running_ffffa428;
    if (puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) {
      DAT_ffffbbcb = 1;
      return puVar1;
    }
  }
  else {
    puVar1 = &DAT_00078c6a;
  }
  DAT_ffffbbcb = 0;
  return puVar1;
}


