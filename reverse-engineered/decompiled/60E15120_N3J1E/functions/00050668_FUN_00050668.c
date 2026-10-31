/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b4a4: Table 2D - 367 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00050668; body bytes: 168; decompiled */

undefined1 * FUN_00050668(void)

{
  byte bVar2;
  byte bVar3;
  undefined1 *puVar1;
  undefined4 uVar4;
  undefined4 uVar5;
  
  bVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a0,0);
  bVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a2,0);
  uVar5 = 0;
  uVar4 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff867c);
  DAT_ffffd076 = rx8_lookup_2d_raw_u16(uVar4,&tbl_table_2d_367_check_datatype_0006b4a4);
  if (DAT_ffffd1c5 == '\x01') {
    puVar1 = (undefined1 *)ref_updateMemoryAtAddress_float_VAL_ADDR(uVar5,&DAT_ffff8694);
  }
  else {
    puVar1 = &DAT_ffffd084;
    if ((DAT_ffffd084 == '\0') &&
       (puVar1 = (undefined1 *)(uint)bVar3, puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)
       )) {
      uVar4 = DAT_ffffd024;
      if (DAT_ffffcfaa <= DAT_ffffd076) {
        uVar4 = DAT_ffffd020;
      }
      puVar1 = (undefined1 *)ref_updateMemoryAtAddress_float_VAL_ADDR(uVar4,&DAT_ffff8694);
    }
    else if ((DAT_ffffd083 == '\0') &&
            (puVar1 = (undefined1 *)(uint)bVar2,
            puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) {
      puVar1 = (undefined1 *)ref_updateMemoryAtAddress_float_VAL_ADDR(DAT_ffffd024,&DAT_ffff8694);
    }
  }
  DAT_ffffd084 = bVar3;
  DAT_ffffd083 = bVar2;
  return puVar1;
}


