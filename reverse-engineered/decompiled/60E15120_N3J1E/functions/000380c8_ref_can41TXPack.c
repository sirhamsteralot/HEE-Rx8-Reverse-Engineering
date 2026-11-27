/* [ADDITIONAL SOURCE REVIEW]
 * immo_can_tx_pack [high]: ref_can41TXPack (unique_exact_bytes to 60E0FC00 0x387e8), called from can_tx_main_key_gated 0xdb58. If c1d1==1: copies c1c8..c1cf -> c4a8..c4af (mailbox 9 buffer for CAN 0x041, descriptor ROM 0x4dfac) and calls ref_txCAN_EventBased. Dynamically verified: buffer = 09 01 77 b2 76 00 00 00 after cmd 9/c220=1.
 * RAM 0xffffc1c8 immo_tx_frame (u8[8]): c1c8=cmd, c1c9..c1cc=payload, c1cd..c1cf=0, c1d1=valid flag; copied to 0xffffc4a8..c4af when c1d1==1
 * RAM 0xffffc1d1 immo_tx_frame_valid (u8): set to 1 by every 0x35738 path; 0xdb58 clears it after packing
 * RAM 0xffffc4a8 can041_tx_buffer (u8[8]): ROM descriptor bytes re-read: id 0x041, buf 0xffffc4a8
 */
/* ROM address: 0x000380c8; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000387e8 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint immo_can_tx_pack(void)

{
  uint uVar1;
  
  if (immo_tx_frame_valid_ffffc1d1 != 1) {
    return (uint)immo_tx_frame_valid_ffffc1d1;
  }
  can041_tx_buffer_ffffc4a8 = immo_tx_frame_ffffc1c8;
  DAT_ffffc4a9 = DAT_ffffc1c9;
  DAT_ffffc4aa = DAT_ffffc1ca;
  DAT_ffffc4ab = DAT_ffffc1cb;
  DAT_ffffc4ac = DAT_ffffc1cc;
  DAT_ffffc4ad = DAT_ffffc1cd;
  DAT_ffffc4ae = DAT_ffffc1ce;
  DAT_ffffc4af = DAT_ffffc1cf;
  uVar1 = ref_txCAN_EventBased(&DAT_0004dfac);
  return uVar1;
}


