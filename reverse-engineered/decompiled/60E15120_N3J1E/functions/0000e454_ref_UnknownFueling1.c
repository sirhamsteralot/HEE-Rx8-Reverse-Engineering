/* ROM address: 0x0000e454; body bytes: 58; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0000e478) */
/* Unique exact-byte match to related 60E0FC00 function at 0000e458 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_UnknownFueling1_0000e454(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_0000e4cc;
  if (engine_speed_rpm_ffffb548 < 3000.0) {
    puVar1 = &DAT_0000e4e0;
    DAT_ffffa440 = 0x43e38000;
  }
  return puVar1;
}


