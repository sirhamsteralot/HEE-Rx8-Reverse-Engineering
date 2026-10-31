/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b4a4: Table 2D - 367 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000505c0; body bytes: 168; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004e1dc (168 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_000505c0(void)

{
  byte bVar2;
  byte bVar3;
  undefined1 *puVar1;
  undefined4 uVar4;
  undefined4 uVar5;
  
  bVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a4,0);
  bVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a6,0);
  uVar5 = 0;
  uVar4 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff867c);
  DAT_ffffd074 = rx8_lookup_2d_raw_u16(uVar4,&tbl_table_2d_367_check_datatype_0006b4a4);
  if (DAT_ffffd1c5 == '\x01') {
    puVar1 = (undefined1 *)ref_updateMemoryAtAddress_float_VAL_ADDR(uVar5,&DAT_ffff868c);
  }
  else {
    puVar1 = &DAT_ffffd082;
    if ((DAT_ffffd082 == '\0') &&
       (puVar1 = (undefined1 *)(uint)bVar3, puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)
       )) {
      uVar4 = DAT_ffffd01c;
      if (DAT_ffffcfaa <= DAT_ffffd074) {
        uVar4 = DAT_ffffd018;
      }
      puVar1 = (undefined1 *)ref_updateMemoryAtAddress_float_VAL_ADDR(uVar4,&DAT_ffff868c);
    }
    else if ((DAT_ffffd081 == '\0') &&
            (puVar1 = (undefined1 *)(uint)bVar2,
            puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) {
      puVar1 = (undefined1 *)ref_updateMemoryAtAddress_float_VAL_ADDR(DAT_ffffd01c,&DAT_ffff868c);
    }
  }
  DAT_ffffd082 = bVar3;
  DAT_ffffd081 = bVar2;
  return puVar1;
}


