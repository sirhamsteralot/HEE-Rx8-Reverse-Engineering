/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b3b0: Table 2D - 365 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000387d4; body bytes: 370; decompiled */

char FUN_000387d4(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  float snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  
  snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998 = inferred_coolant_temperature_catalyst_temp_model_ffffa998;
  DAT_ffffc510 = rx8_min_float(inferred_coolant_temperature_catalyst_temp_model_ffffa998,DAT_ffffcf98);
  DAT_ffffc522 = rx8_lookup_2d_raw_u16(DAT_ffffc510,&tbl_table_2d_365_check_datatype_0006b3b0);
  cVar4 = DAT_ffffc50a;
  cVar5 = DAT_ffffc509;
  cVar2 = DAT_ffffc508;
  cVar3 = DAT_ffffc507;
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc507 = '\0';
    DAT_ffffc508 = '\0';
    DAT_ffffc505 = 0;
    DAT_ffffc509 = '\0';
    DAT_ffffc50a = '\0';
    DAT_ffffc506 = 0;
    cVar5 = '\x01';
  }
  else {
    if (((((DAT_ffffc522 < DAT_ffffc4fc) && (-40.0 < DAT_ffffc4c8)) && (DAT_ffffc5fe == '\0')) &&
        ((snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998 < 71.0 && (cVar1 = ref_getFaultStatus__(0x17), cVar1 == '\0')))) &&
       ((DAT_ffffc590 == '\0' && (DAT_ffffc5e6 == '\0')))) {
      if (71.25 <= DAT_ffffc5f0) {
        cVar4 = '\x01';
      }
      else {
        cVar2 = '\x01';
      }
    }
    cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fbc,0);
    if ((cVar1 == '\x01') && (snapshot_inferred_coolant_temperature_catalyst_temp_model_ffffa998 < 71.0)) {
      if (cVar2 == '\x01') {
        cVar3 = '\x01';
      }
      if (cVar4 == '\x01') {
        cVar5 = '\x01';
      }
    }
    DAT_ffffc507 = cVar3;
    DAT_ffffc508 = cVar2;
    if ((cVar3 == '\x01') || (cVar2 == '\x01')) {
      DAT_ffffc505 = 1;
      DAT_ffffc506 = 0;
      DAT_ffffc509 = '\0';
      DAT_ffffc50a = '\0';
      cVar5 = '\x01';
    }
    else {
      DAT_ffffc509 = cVar5;
      DAT_ffffc50a = cVar4;
      if ((cVar5 == '\x01') && (cVar5 = cVar4, cVar4 == '\x01')) {
        DAT_ffffc506 = 1;
        DAT_ffffc505 = 0;
      }
    }
  }
  return cVar5;
}


