/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002be40; body bytes: 576; decompiled */

char FUN_0002be40(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  char cVar4;
  float snapshot_DAT_ffffbfa0;
  
  cVar2 = DAT_ffffbcec;
  cVar1 = DAT_ffffaa68;
  if (0.125 <= inferred_ram_bc30_ffffbc30_ffffbc30) {
    if (1.0 <= inferred_ram_bc30_ffffbc30_ffffbc30) {
      if (2.0 <= inferred_ram_bc30_ffffbc30_ffffbc30) {
        if (3.0 <= inferred_ram_bc30_ffffbc30_ffffbc30) {
          DAT_ffffbc37 = '\x05';
        }
        else {
          DAT_ffffbc37 = '\x04';
        }
      }
      else {
        DAT_ffffbc37 = '\x03';
      }
    }
    else {
      DAT_ffffbc37 = '\x02';
    }
  }
  else {
    DAT_ffffbc37 = '\x01';
  }
  snapshot_DAT_ffffbfa0 = DAT_ffffbfa0;
  if ((((DAT_ffffaa68 == '\x01') && (DAT_ffffbc3a == '\0')) && (DAT_ffffbd49 == '\x01')) ||
     (DAT_ffffbd48 == '\0')) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8664,0);
  }
  else if (((DAT_ffffbc37 == '\x01') && (DAT_ffffbc38 == '\x01')) && (DAT_ffffbc39 != '\x01')) {
    uVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8664,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8664,uVar3 ^ 1);
  }
  cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8664,0);
  if (((cVar4 == '\0') || (snapshot_DAT_ffffbfa0 < 22.5)) || ((DAT_ffffbc37 != '\x02' && (DAT_ffffbc38 != '\x02'))))
  {
    DAT_ffffbc34 = 0;
  }
  else {
    cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8664,0);
    if (((cVar4 == '\x01') && (DAT_ffffbc37 == '\x02')) && (DAT_ffffbc38 == '\x02')) {
      DAT_ffffbc34 = 1;
    }
  }
  cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8664,0);
  if (((cVar4 == '\0') || (snapshot_DAT_ffffbfa0 < 22.5)) || ((DAT_ffffbc37 != '\x03' && (DAT_ffffbc38 != '\x03'))))
  {
    inferred_ram_bc35_ffffbc35_ffffbc35 = 0;
  }
  else {
    cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8664,0);
    if (((cVar4 == '\x01') && (DAT_ffffbc37 == '\x03')) &&
       ((DAT_ffffbc38 == '\x03' && ((DAT_ffffbc39 != '\x03' && (cVar2 == '\x01')))))) {
      inferred_ram_bc35_ffffbc35_ffffbc35 = 1;
    }
  }
  cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8664,0);
  if (((cVar4 == '\0') || (snapshot_DAT_ffffbfa0 < 22.5)) ||
     ((DAT_ffffbc37 != '\x04' && (cVar4 = DAT_ffffbc38, DAT_ffffbc38 != '\x04')))) {
    DAT_ffffbc36 = 0;
  }
  else {
    cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8664,0);
    if ((((cVar4 == '\x01') && (cVar4 = DAT_ffffbc37, DAT_ffffbc37 == '\x04')) &&
        (cVar4 = DAT_ffffbc38, DAT_ffffbc38 == '\x04')) &&
       ((cVar4 = DAT_ffffbc39, DAT_ffffbc39 != '\x04' && (cVar4 = cVar2, cVar2 == '\x01')))) {
      DAT_ffffbc36 = 1;
    }
  }
  DAT_ffffbc39 = DAT_ffffbc38;
  DAT_ffffbc38 = DAT_ffffbc37;
  DAT_ffffbc3a = cVar1;
  return cVar4;
}


