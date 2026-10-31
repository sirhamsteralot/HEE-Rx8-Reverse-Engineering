/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000487d6; body bytes: 960; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000489de) */
/* WARNING: Removing unreachable block (ram,0x000489e6) */
/* WARNING: Removing unreachable block (ram,0x000489f4) */
/* WARNING: Removing unreachable block (ram,0x000489fe) */
/* WARNING: Removing unreachable block (ram,0x00048a08) */
/* WARNING: Removing unreachable block (ram,0x00048a12) */
/* WARNING: Removing unreachable block (ram,0x00048a1e) */
/* WARNING: Removing unreachable block (ram,0x00048a28) */
/* WARNING: Removing unreachable block (ram,0x00048a30) */
/* WARNING: Removing unreachable block (ram,0x00048a38) */

uint FUN_000487d6(void)

{
  bool bVar1;
  char cVar2;
  char cVar4;
  byte bVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  uint uVar3;
  float fVar11;
  float fVar12;
  float snapshot_engine_speed_rpm_ffffb548;
  float arg0;
  
  cVar10 = DAT_ffffb4ed;
  fVar11 = inferred_battery_voltage_ffffb590;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  arg0 = inferred_coolant_temperature_ffffa98c;
  cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873c,0);
  cVar2 = DAT_ffffaa68;
  bVar5 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff809e,0);
  cVar6 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff809c,0);
  cVar7 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8104,0);
  cVar8 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80a0,0);
  cVar9 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80a2,1);
  fVar12 = -2.0;
  if (snapshot_engine_speed_rpm_ffffb548 < 300.0) {
    if (snapshot_engine_speed_rpm_ffffb548 < 200.0) {
      DAT_ffffccec = '\0';
    }
  }
  else {
    DAT_ffffccec = '\x01';
  }
  if (fVar11 < 6.0) {
    if (fVar11 < 5.8) {
      DAT_ffffcced = '\0';
    }
  }
  else {
    DAT_ffffcced = '\x01';
  }
  if (arg0 < 100.0) {
    if (arg0 < 98.0) {
      DAT_ffffccee = '\0';
    }
  }
  else {
    DAT_ffffccee = '\x01';
  }
  if (arg0 < 100.0) {
    if (arg0 < 98.0) {
      DAT_ffffccef = '\0';
    }
  }
  else {
    DAT_ffffccef = '\x01';
  }
  fVar11 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(coolant_temperature_ffff9f70,&DAT_ffff8060);
  fVar11 = rx8_absolute_difference(arg0,fVar11);
  if (fVar11 < 0.0) {
    if (fVar11 < fVar12) {
      DAT_ffffccf0 = '\0';
    }
  }
  else {
    DAT_ffffccf0 = '\x01';
  }
  if ((((((DAT_ffffccec == '\0') && (DAT_ffffcced == '\x01')) && (DAT_ffffccc1 == '\x01')) &&
       ((cVar10 == '\x01' && (cVar4 == '\0')))) && (DAT_ffffcc98 == '\0')) &&
     ((DAT_ffffcc99 == '\0' && (DAT_ffffc63c == '\0')))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((((cVar2 == '\0') && (DAT_ffffccb6 < 0x271)) && (DAT_ffffccba == 1)) &&
     ((bVar5 == 0 && (bVar1)))) {
    DAT_ffffccbc = 1;
    DAT_ffffccbd = 0;
    DAT_ffffccbe = 0;
    DAT_ffffccbf = 0;
    DAT_ffffccc0 = 0;
  }
  else if ((((((cVar2 == '\x01') && (engine_injectors_off_ffffa42c == '\0')) &&
             ((DAT_ffffccee == '\0' || (DAT_ffffccef == '\x01')))) &&
            (((DAT_ffffccf0 == '\x01' && (cVar6 == '\0')) && (cVar7 == '\x01')))) || (cVar8 == '\0')
           ) && ((((DAT_ffffad60 == '\x01' || (DAT_ffffad61 == '\x01')) || (cVar9 == '\x01')) &&
                 ((DAT_ffffccb4 < 0x271 && (bVar1)))))) {
    DAT_ffffccbc = 1;
    DAT_ffffccbd = 0;
    DAT_ffffccbe = 0;
    DAT_ffffccbf = 0;
    DAT_ffffccc0 = 1;
  }
  else {
    if (((cVar2 == '\x01') &&
        (cVar10 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8764,0), cVar10 == '\0')) &&
       (cVar6 == '\x01')) {
      DAT_ffffccbd = 1;
      DAT_ffffccbe = 0;
    }
    else {
      if ((cVar2 == '\0') &&
         ((((bVar5 == 1 && (DAT_ffffccba == 1)) && (1 < DAT_ffffccea)) || (0x4e1 < DAT_ffffccb6))))
      {
        DAT_ffffccc9 = 1;
      }
      if (DAT_ffffcca2 != '\x01') {
        DAT_ffffccbc = 0;
        DAT_ffffccbd = 0;
        DAT_ffffccbe = 0;
        DAT_ffffccbf = 1;
        goto LAB_00048c3a;
      }
      DAT_ffffccbd = 0;
      DAT_ffffccbe = 1;
    }
    DAT_ffffccbc = 0;
    DAT_ffffccbf = 0;
  }
LAB_00048c3a:
  DAT_ffffccbb = 0;
  uVar3 = (uint)bVar5;
  if ((uVar3 == 1) && (uVar3 = (uint)DAT_ffffccba, uVar3 == 1)) {
    uVar3 = rx8_add_u16_saturate((int)(short)DAT_ffffccea,1);
    DAT_ffffccea = (ushort)uVar3;
  }
  else {
    DAT_ffffccea = 0;
  }
  return uVar3;
}


