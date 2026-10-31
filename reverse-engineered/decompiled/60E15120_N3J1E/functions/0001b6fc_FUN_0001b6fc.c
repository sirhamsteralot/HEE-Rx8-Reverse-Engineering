/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001b6fc; body bytes: 438; decompiled */

void FUN_0001b6fc(void)

{
  short sVar1;
  char cVar3;
  ushort uVar2;
  char cVar4;
  float fVar5;
  float fVar6;
  float arg0;
  float fVar7;
  float snapshot_DAT_ffffad70;
  
  sVar1 = DAT_ffffad8a;
  if (DAT_ffffadd3 == '\0') {
    DAT_ffffada0 = DAT_ffffad70;
    DAT_ffffada4 = DAT_ffffad74;
    DAT_ffffadd3 = '\x01';
  }
  fVar7 = DAT_ffffad70 - 10.0;
  arg0 = DAT_ffffad74;
  snapshot_DAT_ffffad70 = DAT_ffffad70;
  fVar5 = rx8_absolute_difference(DAT_ffffad70,DAT_ffffada0);
  fVar6 = rx8_absolute_difference(arg0,DAT_ffffada4);
  if ((((((DAT_ffffb4bc < 80.0) || (DAT_ffffcc98 != '\0')) || (DAT_ffffcc99 != '\0')) ||
       (((DAT_ffffb4f9 != '\0' || (0.244 <= fVar5)) ||
        ((0.244 <= fVar6 || ((DAT_ffffccc1 != '\x01' || (DAT_ffffb4ed != '\x01')))))))) ||
      (DAT_ffffccbc != '\0')) ||
     ((((cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873e,0), cVar3 != '\0' ||
        (DAT_ffffb410 <= 90.0)) || (DAT_ffffad30 <= 5.0)) || (DAT_ffffb40c <= fVar7)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = rx8_add_u16_saturate((int)sVar1,1);
  }
  fVar5 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x42de0000,&DAT_ffff808c);
  cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff809c,0);
  cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff809e,0);
  if (uVar2 < 0x26) {
    if (((cVar3 == '\x01') && (DAT_ffffadcd == '\0')) ||
       ((cVar4 == '\x01' && (DAT_ffffadce == '\0')))) {
      fVar5 = rx8_min_float(111.0,fVar5 + 1.0);
      uVar2 = 0;
    }
  }
  else {
    fVar5 = rx8_max_float(snapshot_DAT_ffffad70 - 10.0,fVar5 - 10.0);
    fVar5 = rx8_max_float(-10.0,fVar5);
    uVar2 = 0;
  }
  ref_updateMemoryAtAddress_float_VAL_ADDR(fVar5,&DAT_ffff808c);
  DAT_ffffadcd = cVar3;
  DAT_ffffadce = cVar4;
  DAT_ffffada0 = snapshot_DAT_ffffad70;
  DAT_ffffada4 = arg0;
  DAT_ffffad8a = uVar2;
  return;
}


