/* ROM address: 0x0000e444; body bytes: 16; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0000e478) */
/* Unique exact-byte match to related 60E0FC00 function at 0000e448 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * FUN_0000e444(void)

{
  undefined4 *puVar1;
  
  if ((undefined4 *)(uint)DAT_ffff9f8c == (undefined4 *)0x1) {
    puVar1 = &DAT_0000e4cc;
    if (engine_speed_rpm_ffffb548 < 3000.0) {
      puVar1 = &DAT_0000e4e0;
      DAT_ffffa440 = 0x43e38000;
    }
    return puVar1;
  }
  return (undefined4 *)(uint)DAT_ffff9f8c;
}


