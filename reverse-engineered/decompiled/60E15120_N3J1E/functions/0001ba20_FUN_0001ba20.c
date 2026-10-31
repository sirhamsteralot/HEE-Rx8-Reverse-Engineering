/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001ba20; body bytes: 494; decompiled_with_warnings */

/* WARNING: Heritage AFTER dead removal. Example location: r0xffffadc0 : 0x0001bb3e */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_0001ba20(void)

{
  ushort snapshot_DAT_ffffccb4;
  uint uVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  float arg0;
  
  snapshot_DAT_ffffccb4 = DAT_ffffccb4;
  arg0 = DAT_ffffad7c;
  fVar5 = DAT_ffffb4b0;
  uVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80a2,1);
  if (((uVar2 & 0xff) == 0) && (2 < snapshot_DAT_ffffccb4)) {
    cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873e,0);
    if (cVar3 != '\0') goto LAB_0001bad4;
    DAT_ffffad62 = '\x01';
  }
  else {
LAB_0001bad4:
    DAT_ffffad62 = '\0';
  }
  DAT_ffffadc4 = DAT_ffffadc0;
  DAT_ffffadc0 = DAT_ffffadbc;
  DAT_ffffadbc = DAT_ffffadb8;
  DAT_ffffadb8 = DAT_ffffadb4;
  DAT_ffffadb4 = DAT_ffffadb0;
  DAT_ffffadb0 = fVar5;
  if (DAT_ffffad62 == '\x01') {
    if (DAT_ffffadcf == '\0') {
      arg0 = fVar5;
    }
    arg0 = (arg0 + fVar5) * 0.5;
    DAT_ffffad8c = rx8_add_u8_saturate((int)(char)DAT_ffffad8c,1);
    fVar4 = rx8_absolute_difference(fVar5,DAT_ffffadc0);
    if (((fVar5 < 15.0) || (25.0 < fVar5)) && (0.2442 <= fVar4)) {
      DAT_ffffad8f = '\x01';
    }
  }
  if ((((DAT_ffffaa68 != '\0') && (DAT_ffffcc98 != '\x01')) &&
      ((DAT_ffffcc99 != '\x01' && ((DAT_ffffb4f7 != '\x01' && (DAT_ffffb4fb != '\x01')))))) &&
     (DAT_ffffb4fd != '\x01')) {
    cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873c,0);
    if (cVar3 != '\x01') {
      DAT_ffffad61 = '\0';
      goto LAB_0001bc08;
    }
  }
  DAT_ffffad61 = '\x01';
  uVar2 = 1;
LAB_0001bc08:
  if (((DAT_ffffad61 == '\0') && (7 < snapshot_DAT_ffffccb4)) && ((uVar2 & 0xff) == 0)) {
    DAT_ffffad60 = 1;
    uVar2 = 1;
    if ((DAT_ffffad8f == '\0') && (3 < DAT_ffffad8c)) {
      DAT_ffffad63 = 1;
      fVar5 = rx8_clamp_float(arg0,15.0,25.0);
      ref_updateMemoryAtAddress_float_VAL_ADDR(fVar5,&DAT_ffff8094);
      fVar4 = rx8_clamp_float(DAT_ffffad54,15.0,25.0);
      ref_updateMemoryAtAddress_float_VAL_ADDR(fVar4,&DAT_ffff80a4);
      DAT_ffffad80 = rx8_clamp_float(fVar5 - fVar4,-0.428,0.428);
    }
  }
  DAT_ffffad7c = arg0;
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff80a2,uVar2);
  DAT_ffffadcf = DAT_ffffad62;
  return;
}


