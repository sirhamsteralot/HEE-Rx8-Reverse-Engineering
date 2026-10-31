/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0004281c; body bytes: 278; decompiled */

undefined1 * FUN_0004281c(void)

{
  undefined1 *puVar1;
  uint uVar2;
  float snapshot_inferred_battery_voltage_ffffb590;
  float snapshot_DAT_ffffb330;
  
  puVar1 = (undefined1 *)(uint)DAT_ffffd1c5;
  if (puVar1 == (undefined1 *)0x1) {
    DAT_ffffc998 = 0;
    DAT_ffffc99a = 0;
    puVar1 = &DAT_ffffc995;
    DAT_ffffc995 = 0;
    DAT_ffffc994 = 0;
    DAT_ffffc997 = 0;
    DAT_ffffc996 = 0;
  }
  else {
    snapshot_inferred_battery_voltage_ffffb590 = inferred_battery_voltage_ffffb590;
    snapshot_DAT_ffffb330 = DAT_ffffb330;
    if (DAT_ffffb330 < 90.0) {
      uVar2 = ref_getFaultStatus__(5);
      puVar1 = (undefined1 *)(uVar2 & 0xff);
      if (puVar1 == (undefined1 *)0x1) {
        DAT_ffffc998 = 0;
      }
      else {
        if ((snapshot_inferred_battery_voltage_ffffb590 <= 10.0) || (puVar1 = (undefined1 *)0x1, DAT_ffffc6b1 == '\x01')) {
          DAT_ffffc998 = 0;
        }
        else {
          puVar1 = (undefined1 *)rx8_add_u16_saturate((int)(short)DAT_ffffc998,1);
          DAT_ffffc998 = (ushort)puVar1;
        }
        if (DAT_ffffc998 < 0x40) {
          puVar1 = (undefined1 *)0x40;
          if (DAT_ffffc998 < 0x40) {
            puVar1 = &DAT_ffffc994;
            DAT_ffffc994 = 1;
          }
        }
        else {
          DAT_ffffc995 = 1;
        }
      }
    }
    if (10.0 <= snapshot_DAT_ffffb330) {
      uVar2 = ref_getFaultStatus__(6);
      puVar1 = (undefined1 *)(uVar2 & 0xff);
      if (puVar1 == (undefined1 *)0x1) {
        DAT_ffffc99a = 0;
      }
      else {
        if ((snapshot_inferred_battery_voltage_ffffb590 <= 10.0) || (DAT_ffffc6b0 == '\0')) {
          DAT_ffffc99a = 0;
        }
        else {
          puVar1 = (undefined1 *)rx8_add_u16_saturate((int)(short)DAT_ffffc99a,1);
          DAT_ffffc99a = (ushort)puVar1;
        }
        if (DAT_ffffc99a < 0x40) {
          puVar1 = (undefined1 *)0x40;
          if (DAT_ffffc99a < 0x40) {
            puVar1 = &DAT_ffffc996;
            DAT_ffffc996 = 1;
          }
        }
        else {
          DAT_ffffc997 = 1;
        }
      }
    }
  }
  return puVar1;
}


