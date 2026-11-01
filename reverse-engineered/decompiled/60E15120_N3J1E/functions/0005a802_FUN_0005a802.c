/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005a802; body bytes: 474; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0005aa1a) */

undefined1 FUN_0005a802(void)

{
  char cVar1;
  float snapshot_vehicle_speed_ffffbbb4;
  float snapshot_DAT_ffffd160;
  
  cVar1 = DAT_ffffd00f;
  DAT_ffffd2da = DAT_ffffd2d9;
  snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
  snapshot_DAT_ffffd160 = DAT_ffffd160;
  DAT_ffffd2d9 = ref_getKnownBooleanValue__();
  if (DAT_ffffd2d9 == '\0') {
    DAT_ffffd294 = 0;
    DAT_ffffd296 = 0;
    DAT_ffffd298 = 0;
    DAT_ffffd29a = 0;
    DAT_ffffd29c = 0;
    goto LAB_0005a95e;
  }
  if ((cVar1 == '\x01') && (-10.0 <= snapshot_DAT_ffffd160)) {
    DAT_ffffd294 = rx8_add_u16_saturate((int)DAT_ffffd294,1);
  }
  if ((4.444 <= snapshot_DAT_ffffd160) && (snapshot_DAT_ffffd160 <= 35.0)) {
    DAT_ffffd296 = rx8_add_u16_saturate((int)DAT_ffffd296,1);
  }
  if ((cVar1 != '\x01') || (snapshot_DAT_ffffd160 < -10.0)) {
LAB_0005a926:
    DAT_ffffd29a = 0;
  }
  else {
    if (40.233 <= snapshot_vehicle_speed_ffffbbb4) {
      DAT_ffffd298 = rx8_add_u16_saturate((int)DAT_ffffd298,1);
    }
    if (((snapshot_DAT_ffffd160 < -10.0) || (cranking_active_ffffaa62_ffffaa62 != '\x01')) || (1.609 < snapshot_vehicle_speed_ffffbbb4)) goto LAB_0005a926;
    DAT_ffffd29a = rx8_add_u16_saturate((int)(short)DAT_ffffd29a,1);
  }
  if (secondary_air_request_final_ffffa960 == '\x01') {
    DAT_ffffd29c = rx8_add_u16_saturate((int)(short)DAT_ffffd29c,1);
  }
  else {
    DAT_ffffd29c = 0;
  }
LAB_0005a95e:
  if (0x4d < DAT_ffffd29c) {
    DAT_ffffd2b5 = 1;
  }
  if (0xe9 < DAT_ffffd29a) {
    DAT_ffffd29f = 1;
  }
  cVar1 = FUN_0005f9f0(0x37,0);
  if (((((cVar1 == '\x01') || (cVar1 = FUN_0005f9f0(0x37,2), cVar1 == '\x01')) ||
       ((cVar1 = FUN_0005f9f0(0xf,2), cVar1 == '\x01' ||
        ((cVar1 = FUN_0005f9f0(0x10,2), cVar1 == '\x01' ||
         (cVar1 = FUN_0005f9f0(0xe,2), cVar1 == '\x01')))))) ||
      (cVar1 = FUN_0005f9f0(0xc,2), cVar1 == '\x01')) ||
     (((cVar1 = FUN_0005f9f0(0xd,2), cVar1 == '\x01' ||
       (cVar1 = FUN_0005f9f0(0x13,2), cVar1 == '\x01')) ||
      (cVar1 = FUN_0005f9f0(0x14,2), cVar1 == '\x01')))) {
    DAT_ffffd29e = 1;
  }
  DAT_ffffd2d8 = 0;
  return DAT_ffffd1c5;
}


