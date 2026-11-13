/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002aa88; body bytes: 792; decompiled */

void FUN_0002aa88(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  float snapshot_vehicle_speed_ffffbbb4;
  
  cVar6 = DAT_ffffbc04;
  cVar5 = DAT_ffffbb9b;
  cVar4 = inferred_ram_ad18_ffffad18_ffffad18;
  cVar3 = engine_running_flag_ffffaa68;
  cVar2 = engine_running_ffffa428;
  cVar1 = engine_stopped_latch_ffffa41c;
  if (engine_speed_rpm_ffffb548 <= 7000.0) {
    if (engine_speed_rpm_ffffb548 <= 6900.0) {
      DAT_ffffbb9a = '\0';
    }
  }
  else {
    DAT_ffffbb9a = '\x01';
  }
  if ((DAT_ffffbb9d == '\x01') && (engine_stopped_latch_ffffa41c == '\0')) {
    DAT_ffffbb88 = 0x1f;
  }
  else if (DAT_ffffbb88 != 0) {
    DAT_ffffbb88 = DAT_ffffbb88 + -1;
  }
  if (vehicle_speed_ffffbbb4 < 3.0) {
    if (vehicle_speed_ffffbbb4 < 1.0) {
      DAT_ffffbb9b = '\0';
    }
  }
  else {
    DAT_ffffbb9b = '\x01';
    DAT_ffffbb98 = '\x01';
  }
  if (DAT_ffffbb68 - DAT_ffffbb6c < 5.0) {
    if (DAT_ffffbb68 - DAT_ffffbb6c < 3.0) {
      DAT_ffffbb9c = '\0';
    }
  }
  else {
    DAT_ffffbb9c = '\x01';
  }
  snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
  if ((cVar5 == '\x01') && (DAT_ffffbb9b == '\0')) {
    DAT_ffffbb99 = '\x01';
    DAT_ffffbb8a = 0;
  }
  else {
    DAT_ffffbb8a = rx8_add_u16_saturate((int)(short)DAT_ffffbb8a,1);
  }
  if ((DAT_ffffbb9e == '\x01') && (cVar4 == '\0')) {
    DAT_ffffbb8e = 0x9c;
  }
  else if (DAT_ffffbb8e != 0) {
    DAT_ffffbb8e = DAT_ffffbb8e + -1;
  }
  if ((DAT_ffffbb88 == 0) && (DAT_ffffbb98 != '\x01')) {
    if ((cVar3 == '\x01') && (snapshot_vehicle_speed_ffffbbb4 < 3.0)) {
      DAT_ffffbb72 = '\x01';
    }
  }
  else {
    DAT_ffffbb72 = '\0';
  }
  if (DAT_ffffbb9b == '\x01') {
    DAT_ffffbb73 = '\0';
  }
  else if ((DAT_ffffbb99 == '\x01') && (0x7c < DAT_ffffbb8a)) {
    DAT_ffffbb73 = '\x01';
  }
  if ((((cVar4 == '\x01') || (DAT_ffffbb8e != 0)) || (DAT_ffffbb9b == '\0')) ||
     (DAT_ffffbb9c == '\x01')) {
    DAT_ffffbb74 = '\0';
  }
  else if (0x3a9 < DAT_ffffbb8c) {
    DAT_ffffbb74 = '\x01';
  }
  if (cVar6 == '\x01') {
    if (DAT_ffffbb9a == '\0') {
      if (DAT_ffffc61e == '\0') {
        if ((((DAT_ffffbb72 == '\x01') && (DAT_ffffbb90 != 0)) ||
            ((DAT_ffffbb73 == '\x01' && (DAT_ffffbb90 != 0)))) ||
           ((DAT_ffffbb74 == '\x01' && (0x4e1 < DAT_ffffbb90)))) {
          DAT_ffffbb70 = '\x01';
        }
      }
      else if (0x57d < DAT_ffffbb90) {
        DAT_ffffbb70 = '\x01';
      }
    }
  }
  else {
    DAT_ffffbb70 = '\0';
  }
  if (((cVar3 == '\x01') && (((cVar2 == '\0' && (DAT_ffffbb96 < 0x1f)) || (DAT_ffffbb70 == '\x01')))
      ) || ((DAT_ffffbc14 == '\x01' && (DAT_ffffbb9a == '\x01')))) {
    DAT_ffffbb66 = 1;
  }
  else {
    DAT_ffffbb66 = 0;
  }
  if (DAT_ffffbb9c == '\x01') {
    DAT_ffffbb8c = 0;
  }
  else {
    DAT_ffffbb8c = rx8_add_u16_saturate((int)(short)DAT_ffffbb8c,1);
  }
  if (cVar6 == '\0') {
    DAT_ffffbb90 = 0;
  }
  else {
    DAT_ffffbb90 = rx8_add_u16_saturate((int)(short)DAT_ffffbb90,1);
  }
  if ((cVar3 == '\x01') && (cVar2 == '\0')) {
    DAT_ffffbb96 = rx8_add_u16_saturate((int)(short)DAT_ffffbb96,1);
  }
  else {
    DAT_ffffbb96 = 0;
  }
  DAT_ffffbb9d = cVar1;
  DAT_ffffbb9e = cVar4;
  return;
}


