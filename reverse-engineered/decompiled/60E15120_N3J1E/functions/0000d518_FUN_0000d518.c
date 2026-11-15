/* [ADDITIONAL SOURCE REVIEW]
 * shutdown_ram_swap_semaphore_mark [high]: Shutdown RAM handling (called from 0x9e68 via pool 0x9f24=0xd518): checksum 0xd648 (pools 0xd620=0xd748, 0xd61c=0xd744) over 0xffff9300..0xffffdffb; if OK: 0x4c70 (pool 0xd628) writes u32 0x3c to the SBL semaphore cell 0xffffdff8, pulses WDT 0xa850 (pool 0xd624), swaps RAM 0xffff6000-0xffff7fff with the shadow at 0xffff9300 (pools 0xd62c=0xd734, 0xd630=0xd738), re-checksums, 0x4c76 (pool 0xd634), 0xd5ac; sets 0xffffa3f0 = checksum-ok (pool 0xd638=0xffffa3f0).
 */
/* ROM address: 0x0000d518; body bytes: 148; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000d518 (148 bytes). Names prefixed ref_
   are inherited hypotheses. */

void shutdown_ram_swap_semaphore_mark(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  cVar1 = FUN_0000d648(&DAT_ffff9300,&DAT_ffffdffb);
  external_wdt_heartbeat_pulse();
  if (cVar1 == '\0') {
    FUN_00004c70(&warm_boot_magic_ffffdffc);
    puVar4 = &DAT_ffff9300;
    for (puVar3 = &DAT_ffff6000; puVar3 < &DAT_ffff7fff; puVar3 = puVar3 + 1) {
      *puVar4 = *puVar3;
      puVar4 = puVar4 + 1;
    }
    FUN_0000d648(&DAT_ffff6000,&DAT_ffff7fff);
    external_wdt_heartbeat_pulse();
    puVar4 = &DAT_ffff9300;
    for (puVar3 = &DAT_ffff6000; puVar3 < &DAT_ffff7fff; puVar3 = puVar3 + 1) {
      uVar2 = *puVar4;
      puVar4 = puVar4 + 1;
      *puVar3 = uVar2;
    }
    FUN_00004c76();
  }
  FUN_0000d5ac();
  DAT_ffffa3f0 = cVar1 != '\0';
  return;
}


