/* [ADDITIONAL SOURCE REVIEW]
 * uds_diag_utility_batch [high]: 15-call batch, pool 0x11cd4-0x11d0c ROM-verified: 0x59164 (timer 0xffffd240 decrement), 0x5a162 (engine runtime counter 0xffffd284 increment), ref_getTireSize 0x5de74 (E2 id 0x9a), 0x5e748 (E2 id 0x9f), 0x5e664 (E2 ids 0x100/0x68/0x6a/0x6c) via 0x37ef0, 0x54cf8 (0xa5-unlock checksum verify of area 0xffff8fe8), 0x5e7e4, 0x19da2, 0x39cf0, 0x21476, 0x3176e, 0x2a3bc, 0x5fc40 (idle-target table lookup), 0x602fc, 0x3de70 (UDS read/write memory by address). Called only from task[16] 0x65e8.
 */
/* ROM address: 0x00011b22; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00011b9a (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

void uds_diag_utility_batch(void)

{
  FUN_00059164();
  FUN_0005a162();
  e2ram_tire_revs_read();
  candidate_e2ram_config_bit_9f_read();
  e2ram_ecu_id_read();
  FUN_00054cf8();
  FUN_0005e7e4();
  FUN_00019da2();
  FUN_00039cf0();
  FUN_00021476();
  FUN_0003176e();
  FUN_0002a3bc();
  FUN_0005fc40();
  FUN_000602fc();
  FUN_0003de70();
  return;
}


