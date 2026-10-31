/* [ADDITIONAL SOURCE REVIEW]
 * can201_pack_and_queue_payload [high]: Descriptor 0x4df1c contains ID 0x201, DLC 8 and RAM pointer 0xffffbaf4. Packs RPM at bytes 0..1 and speed at bytes 4..5.
 * RAM 0xffffbaf4 can201_tx_payload (uint8[8]): Descriptor-confirmed 8-byte buffer.
 */
/* ROM address: 0x000291dc; body bytes: 64; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00029b84 (64 bytes). Names prefixed ref_
   are inherited hypotheses. */

void can201_pack_and_queue_payload(void)

{
  can201_tx_payload_ffffbaf4 = (undefined1)((ushort)can201_encoded_rpm_ffffbafc >> 8);
  DAT_ffffbaf5 = (undefined1)can201_encoded_rpm_ffffbafc;
  DAT_ffffbaf6 = (undefined1)((ushort)DAT_ffffbafe >> 8);
  DAT_ffffbaf7 = (undefined1)DAT_ffffbafe;
  DAT_ffffbaf8 = (undefined1)((ushort)can201_encoded_vehicle_speed_ffffbb00 >> 8);
  DAT_ffffbaf9 = (undefined1)can201_encoded_vehicle_speed_ffffbb00;
  DAT_ffffbafa = DAT_ffffbb02;
  DAT_ffffbafb = DAT_ffffbb03;
  ref_txCAN_EventBased(&DAT_0004df1c);
  return;
}


