/* [ADDITIONAL SOURCE REVIEW]
 * shutdown_e2_flag_clear [medium]: Clears E2-shadow 0xffff8104 = 0 via 0x3dc70 (pools 0x25376=0x8104, 0x25384=0x3dc70); reached from 0x113b8 <- 0x6366 <- 0x9f52 (boot path).
 * RAM 0xffff8104 shutdown_e2_shadow_flag (uint8): E2RAM-shadow shutdown flag: written 0/1 by 0x2529e/0x252c2 via 0x3dc70 (pool 0x25376=0x8104), read back by 0x487d6 as the persistent shutdown marker.
 */
/* ROM address: 0x0002529e; body bytes: 8; decompiled */

void candidate_shutdown_e2_flag_clear(void)

{
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&shutdown_e2_shadow_flag_ffff8104,0);
  return;
}


