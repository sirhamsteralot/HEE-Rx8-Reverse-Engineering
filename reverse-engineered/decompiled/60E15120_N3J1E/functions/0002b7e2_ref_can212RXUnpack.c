/* [ADDITIONAL SOURCE REVIEW]
 * can212_rx_unpack [high]: Unpacks CAN 0x212 payload buffer 0xffffbbc0-0xffffbbc6 into working cells: 0xffffbbf2=bbc0, bbf3=bbc1, bbf4=bbc2, bbf5=bbc3, 0xffffbbde = bbc4*0x100+bbc5 (u16), 0xffffbbf6=bbc6 (mode byte). Called from 0x2b29c.
 */
/* ROM address: 0x0002b7e2; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002bf36 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void can212_rx_unpack(void)

{
  DAT_ffffbbf2 = DAT_ffffbbc0;
  DAT_ffffbbf3 = DAT_ffffbbc1;
  DAT_ffffbbf4 = DAT_ffffbbc2;
  DAT_ffffbbf5 = DAT_ffffbbc3;
  can212_status_word_ffffbbde = (ushort)DAT_ffffbbc4 * 0x100 + (ushort)DAT_ffffbbc5;
  dsc_mode_byte_ffffbbf6 = DAT_ffffbbc6;
  return;
}


