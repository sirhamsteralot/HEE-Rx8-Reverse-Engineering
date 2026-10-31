/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003b214; body bytes: 410; decompiled */

char FUN_0003b214(void)

{
  char cVar1;
  float snapshot_engine_speed_rpm_ffffb548;
  
  DAT_ffffc593 = maf_voltage_latched_ffffa9e4 < 0.64;
  DAT_ffffc594 = 4.9 < maf_voltage_latched_ffffa9e4;
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc58c = '\x04';
    DAT_ffffc58d = '\x04';
    DAT_ffffc58e = '\x1f';
    DAT_ffffc590 = 0;
    DAT_ffffc591 = '\0';
    DAT_ffffc592 = '\0';
    DAT_ffffc595 = 0;
    cVar1 = '\x01';
  }
  else {
    if (8.0 <= inferred_battery_voltage_ffffb590) {
      if (DAT_ffffc58e != '\0') {
        DAT_ffffc58e = DAT_ffffc58e + -1;
      }
    }
    else {
      DAT_ffffc58e = '\x1f';
    }
    if ((bool)DAT_ffffc594 || (bool)DAT_ffffc593) {
      if (DAT_ffffc58e == '\0') {
        snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
        if (500.0 <= engine_speed_rpm_ffffb548) {
          if ((bool)DAT_ffffc593) {
            if (DAT_ffffc58c == '\0') {
              cVar1 = ref_getFaultStatus__(10);
              if (cVar1 == '\0') {
                DAT_ffffc591 = '\x01';
              }
            }
            else {
              DAT_ffffc58c = DAT_ffffc58c + -1;
            }
          }
        }
        else {
          DAT_ffffc58c = '\x04';
        }
        if (snapshot_engine_speed_rpm_ffffb548 <= 6500.0) {
          if (DAT_ffffc594 == '\x01') {
            if (DAT_ffffc58d == '\0') {
              cVar1 = ref_getFaultStatus__(0xb);
              if (cVar1 == '\0') {
                DAT_ffffc592 = '\x01';
              }
            }
            else {
              DAT_ffffc58d = DAT_ffffc58d + -1;
            }
          }
        }
        else {
          DAT_ffffc58d = '\x04';
        }
      }
      else {
        DAT_ffffc58c = '\x04';
        DAT_ffffc58d = '\x04';
      }
      cVar1 = '\x01';
      if ((DAT_ffffc591 == '\x01') || (cVar1 = DAT_ffffc592, DAT_ffffc592 == '\x01')) {
        DAT_ffffc590 = 1;
        DAT_ffffc595 = 0;
      }
    }
    else {
      cVar1 = ref_getFaultStatus__(10);
      if ((cVar1 == '\0') && (cVar1 = ref_getFaultStatus__(0xb), cVar1 == '\0')) {
        DAT_ffffc595 = 1;
        DAT_ffffc58c = '\x04';
        DAT_ffffc58d = '\x04';
        DAT_ffffc590 = 0;
        DAT_ffffc591 = '\0';
        DAT_ffffc592 = '\0';
      }
    }
  }
  return cVar1;
}


