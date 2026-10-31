/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00007eca; body bytes: 116; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00007ef0) */

uint FUN_00007eca(void)

{
  ushort uVar1;
  undefined1 snapshot_DAT_ffff9fa0;
  uint uVar3;
  byte bVar4;
  
  uVar1 = ATUII_TSR10_W;
  if ((uVar1 & 1) != 0) {
    DAT_ffff9fce = 1;
  }
  DAT_ffff9fa0 = 1;
  snapshot_DAT_ffff9fa0 = DAT_ffff9fa0;
  DAT_ffff9fa0 = 1;
  bVar4 = DAT_ffff9fce;
  if (DAT_ffff9fa3 == '\x02') {
    bVar4 = DAT_ffff9fa0;
  }
  if ((bVar4 == 1) && (DAT_ffff9f8c == '\0')) {
    DAT_ffff9f8c = 1;
    DAT_ffff9fa0 = snapshot_DAT_ffff9fa0;
    ref_reInitCrankSensor__();
    FUN_00007b84();
    ref_engineSpeedInit();
    FUN_0000806a();
    uVar3 = ref_putTaskInSchedule_FuelArrayStuff(0);
    return uVar3;
  }
  return (uint)bVar4;
}


