/* [ADDITIONAL SOURCE REVIEW]
 * relay_output_pair_pd7_pe0 [medium]: Writes PDDR_W 0xfffff746 bit 0x80 (PD7, pkg pin 256) = (DAT_ffffcfb6 == 1) and PEDR_W 0xfffff754 bit 0x1 (PE0, pkg pin 7) = (DAT_ffffcfb7 == 0). Raw-bin verified pools: 0x3a1aa=0xcfb6, 0x3a1ac=0x0080, 0x3a1ae=0xf746 (PDDR), 0x3a1b0=0xcfb7, 0x3a1b2=0xf754 (PEDR), helper 0x3a1be=0x4bbc. Caller 0x38e12 (task 0x114d0 batch). PD7 dynamically high only while cranking (0xffffd15c path) - harness candidate: starter relay 5A; PE0 mostly high - harness candidate: DBW relay 4C.
 * RAM 0xffffcfb6 pd7_relay_flag (uint8): = (0xffffcfbc == 1) computed by 0x4ef86; pool 0x3a1a8/0x3a1aa anchor 0xffffcfb6. Drives PD7 (pkg pin 256); harness candidate starter relay 5A (high only while cranking).
 * RAM 0xffffcfb7 pe0_relay_flag (uint8): Computed by 0x4ef86 from 3D tables 0x6b3c8/0x6b3dc (RX8Defs 'Table 3D - 120/121') over counters cfad/cfac/cfaf/cfae; PE0 = (cfb7 == 0). Pool 0x3a1b0 anchors 0xffffcfb7. Harness candidate: DBW relay 4C.
 */
/* ROM address: 0x0003a0ec; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003a520 (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0003a0ec(void)

{
  undefined4 local_10;
  undefined4 auStack_c [2];
  
  ref_setSR_PARAM(auStack_c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff746,0x80,DAT_ffffcfb6 == '\x01');
  FUN_00002064(auStack_c[0]);
  ref_setSR_PARAM(&local_10,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,1,pe0_relay_flag_ffffcfb7 == '\0');
  FUN_00002064(local_10);
  return;
}


