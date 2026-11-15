/* [ADDITIONAL SOURCE REVIEW]
 * wdt_overflow_reset_check [high]: Was ref_checkWatchdogTimer_OVRCOUNT: loops param times - stores 0x624() result into reset cause 0xffffdfa8 (pool 0x6b6=0xdfa8), jsr 0x364 (pool 0x6ba=0x364), remaining 0x3e0 (0x6bc), ring 0x3b0 (0x6be); returns 0 when a record was processed; otherwise counts WDT TCSR 0xffffec10 (pool 0x6b8=0xec10) OVF bit 0x80, servicing via 0x31c (pool 0x6c0). Called from 0x4e0 with r4=7: any overflow => warm reset.
 */
/* ROM address: 0x000005b0; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000005b0 (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 wdt_overflow_reset_check(ushort param_1)

{
  byte bVar1;
  short sVar4;
  undefined4 uVar2;
  int iVar3;
  ushort uVar5;
  
  uVar5 = 0;
  if (param_1 != 0) {
    do {
      reset_cause_ffffdfa8 = FUN_00000624();
      FUN_00000364();
      sVar4 = FUN_000003e0();
      if (sVar4 != 0) {
        uVar2 = FUN_000003b0();
        iVar3 = FUN_00000636(uVar2);
        if (iVar3 != 0) {
          return 0;
        }
      }
      bVar1 = WDT_TCSR_RW__B;
      if ((bVar1 & 0x80) != 0) {
        uVar5 = uVar5 + 1;
        service_wdt_overflow_and_toggle_pb15();
      }
    } while (uVar5 < param_1);
  }
  return 1;
}


