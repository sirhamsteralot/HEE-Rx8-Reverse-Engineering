/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003d1b2; body bytes: 324; decompiled */

undefined1 * FUN_0003d1b2(void)

{
  char cVar1;
  byte snapshot_DAT_ffffc614;
  undefined1 *puVar3;
  char cVar5;
  uint uVar4;
  undefined4 snapshot_vehicle_speed_ffffbbb4;
  
  snapshot_DAT_ffffc614 = DAT_ffffc614;
  cVar1 = DAT_ffffad18;
  if (DAT_ffffc614 == 0) {
    DAT_ffffc615 = 0;
  }
  else if (DAT_ffffc60c < -3.76) {
    DAT_ffffc615 = 1;
  }
  if (DAT_ffffd1c5 == '\x01') {
    puVar3 = &DAT_0007aab8;
    DAT_ffffc612 = 0;
    DAT_ffffc614 = 0;
    DAT_ffffc610 = '\x17';
    DAT_ffffc611 = '\b';
    DAT_ffffc616 = 0;
    DAT_ffffc617 = 0;
  }
  else {
    snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
    cVar5 = rx8_is_outside_tolerance_band(vehicle_speed_ffffbbb4,0,0x3727c5ac);
    if (cVar5 == '\0') {
      FUN_0003d354(snapshot_vehicle_speed_ffffbbb4);
      if (DAT_ffffc610 != '\0') {
        DAT_ffffc610 = DAT_ffffc610 + -1;
      }
    }
    else {
      DAT_ffffc610 = '\x17';
      FUN_0003d354(snapshot_vehicle_speed_ffffbbb4);
    }
    if (DAT_ffffc613 != cVar1) {
      DAT_ffffc612 = 1;
    }
    puVar3 = (undefined1 *)(uint)DAT_ffffc612;
    if (puVar3 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) {
      DAT_ffffc611 = '\b';
      uVar4 = ref_getFaultStatus__(0x4a);
      puVar3 = (undefined1 *)(uVar4 & 0xff);
      if (puVar3 == (undefined1 *)0x0) {
        DAT_ffffc617 = 1;
        DAT_ffffc616 = 0;
      }
    }
    else if (((DAT_ffffc614 == 0) &&
             (puVar3 = (undefined1 *)(uint)snapshot_DAT_ffffc614,
             puVar3 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) &&
            (puVar3 = (undefined1 *)(uint)DAT_ffffc615,
            puVar3 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) {
      if (DAT_ffffc611 != '\0') {
        DAT_ffffc611 = DAT_ffffc611 + -1;
      }
      if (DAT_ffffc611 == '\0') {
        uVar4 = ref_getFaultStatus__(0x4a);
        puVar3 = (undefined1 *)(uVar4 & 0xff);
        if (puVar3 == (undefined1 *)0x0) {
          DAT_ffffc616 = 1;
          DAT_ffffc617 = 0;
        }
      }
    }
  }
  DAT_ffffc613 = cVar1;
  return puVar3;
}


