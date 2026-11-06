/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_load_decode_entry [high]: Calls 0x23844 (block decode) then 0x23f4e (stored DTC replay, 38 x 0x5fd38 calls); called from 0x235c8 and 0x235f8 after E2RAM read (0xb99c into 0xffffb440 / 0xb958 into 0xffffb478) with magic 0x5aa5 and checksum verification.
 */
/* ROM address: 0x0002376c; body bytes: 14; decompiled */

void e2ram_load_decode_entry(void)

{
  e2ram_block_decode();
  e2ram_stored_dtc_replay();
  return;
}


