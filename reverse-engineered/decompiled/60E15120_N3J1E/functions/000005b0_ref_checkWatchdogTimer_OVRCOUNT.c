/* ROM address: 0x000005b0; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000005b0 (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_checkWatchdogTimer_OVRCOUNT(ushort param_1)

{
  byte bVar1;
  short sVar4;
  undefined4 uVar2;
  int iVar3;
  ushort uVar5;
  
  uVar5 = 0;
  if (param_1 != 0) {
    do {
      DAT_ffffdfa8 = FUN_00000624();
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


