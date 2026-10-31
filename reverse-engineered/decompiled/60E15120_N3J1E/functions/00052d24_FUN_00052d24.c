/* ROM address: 0x00052d24; body bytes: 374; decompiled */

void FUN_00052d24(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86dc,4);
  cVar9 = DAT_ffffcf78;
  cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a4,0);
  cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a6,0);
  cVar5 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c0,0);
  cVar6 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c2,0);
  cVar7 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a0,0);
  cVar8 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a2,0);
  bVar1 = ((int)DAT_ffffcfb5 & 0x80U) == 0;
  if (DAT_ffffd03d == '\x01') {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86de,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86e0,0);
  }
  else {
    if ((cVar2 == '\0') && (DAT_ffffd133 != '\0')) {
      if ((bVar1) && (cVar9 != '\x01')) {
        DAT_ffffd133 = cVar2;
        DAT_ffffd137 = cVar3;
        DAT_ffffd138 = cVar4;
        DAT_ffffd139 = cVar5;
        DAT_ffffd13a = cVar6;
        DAT_ffffd13b = cVar7;
        DAT_ffffd13c = cVar8;
        return;
      }
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86de,1);
    }
    if ((((!bVar1) || (cVar9 == '\x01')) &&
        (cVar9 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86de,0), cVar9 == '\0')) &&
       ((((((DAT_ffffd137 == '\0' && (cVar3 == '\x01')) ||
           ((DAT_ffffd138 == '\0' && (cVar4 == '\x01')))) ||
          ((DAT_ffffd139 == '\0' && (cVar5 == '\x01')))) ||
         ((DAT_ffffd13a == '\0' && (cVar6 == '\x01')))) ||
        (((DAT_ffffd13b == '\0' && (cVar7 == '\x01')) ||
         ((DAT_ffffd13c == '\0' && (cVar8 == '\x01')))))))) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86e0,1);
    }
  }
  DAT_ffffd133 = cVar2;
  DAT_ffffd137 = cVar3;
  DAT_ffffd138 = cVar4;
  DAT_ffffd139 = cVar5;
  DAT_ffffd13a = cVar6;
  DAT_ffffd13b = cVar7;
  DAT_ffffd13c = cVar8;
  return;
}


