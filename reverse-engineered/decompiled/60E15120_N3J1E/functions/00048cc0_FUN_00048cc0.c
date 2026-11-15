/* [ADDITIONAL SOURCE REVIEW]
 * shutdown_allowed_flag [high]: Computes 0xffffccc1 (pool 0x48da2): = 1 only when (engine flag 0xffffaa68 == 1 (pool 0x48d92) or (0xffffb4ee == 1 (pool 0x48d94) && 0xffffccb6 < 0x271 (pool 0x48d96))) and 0xffffcca0 == 0 (pool 0x48d98) and not 0xffffad60/0xffffad61 (pools 0x48d9a/0x48d9c) and E2-shadow 0xffff80a2 != 1 (pool 0x48d9e, read via 0x3db54 pool 0x48db0) and 0xffffb51a == 0 (pool 0x48da0); else 0. Drives the PD11 relay-hold output via 0x251d0.
 * RAM 0xffffccc1 shutdown_allowed (uint8): Shutdown-allowed flag computed by 0x48cc0 from engine flag 0xffffaa68, 0xffffb4ee, 0xffffccb6 < 0x271, 0xffffcca0, 0xffffad60/ad61, E2-shadow 0xffff80a2 and 0xffffb51a (pool 0x48da2=0xccc1).
 */
/* ROM address: 0x00048cc0; body bytes: 120; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00047d4c (120 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint shutdown_allowed_flag(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if (((engine_running_flag_ffffaa68 == '\x01') ||
      ((uVar1 = (uint)DAT_ffffb4ee, uVar1 == 1 && (uVar1 = (uint)DAT_ffffccb6, uVar1 < 0x271)))) &&
     (DAT_ffffcca0 == '\0')) {
    if ((DAT_ffffad60 != '\x01') && (DAT_ffffad61 != '\x01')) {
      uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80a2,1);
      if ((uVar1 & 0xff) != 1) {
        shutdown_allowed_ffffccc1 = 0;
        return uVar1 & 0xff;
      }
    }
    uVar1 = 1;
    if (DAT_ffffb51a == '\0') {
      shutdown_allowed_ffffccc1 = 1;
      return 1;
    }
  }
  shutdown_allowed_ffffccc1 = 0;
  return uVar1;
}


