/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b3bc: Table 2D - 366 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0004e398; body bytes: 272; decompiled */

undefined4 * FUN_0004e398(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff867c);
  puVar1 = (undefined4 *)rx8_lookup_2d_raw_u16(uVar3,&tbl_table_2d_366_check_datatype_0006b3bc);
  DAT_ffffcf78 = DAT_ffffd26f;
  if (DAT_ffffd26f == 0) {
    DAT_ffffcf7a = '\0';
    puVar2 = puVar1;
  }
  else {
    puVar2 = &DAT_ffffcfe4;
    if (((((DAT_ffffcfe4 < DAT_ffffcfe0) && (DAT_ffffcff8 == '\0')) &&
         (puVar2 = (undefined4 *)(uint)DAT_ffffd26f, puVar2 == (undefined4 *)0x1)) &&
        (puVar2 = (undefined4 *)(uint)DAT_ffffcfaa, (undefined4 *)0x4e < puVar2)) ||
       ((uint)DAT_ffffcf7c == ((uint)puVar1 & 0xffff))) {
      DAT_ffffcf7a = '\x01';
    }
  }
  if (DAT_ffffd26f == 0) {
    DAT_ffffcf79 = 0;
  }
  else {
    puVar2 = (undefined4 *)0x1;
    if ((DAT_ffffcf7a == '\x01') ||
       ((puVar2 = (undefined4 *)(uint)DAT_ffffd26f, puVar2 == (undefined4 *)0x1 &&
        (((((puVar2 = (undefined4 *)0x1, DAT_ffffd045 == '\x01' ||
            (puVar2 = (undefined4 *)0x1, DAT_ffffd042 == '\x01')) ||
           ((puVar2 = (undefined4 *)0x1, DAT_ffffd10f == '\x01' ||
            ((puVar2 = (undefined4 *)0x1, DAT_ffffd110 == '\x01' ||
             (puVar2 = (undefined4 *)0x1, DAT_ffffd112 == '\x01')))))) ||
          (puVar2 = (undefined4 *)0x1, DAT_ffffd113 == '\x01')) ||
         (((puVar2 = (undefined4 *)0x1, DAT_ffffd115 == '\x01' ||
           (puVar2 = (undefined4 *)0x1, DAT_ffffd117 == '\x01')) ||
          (puVar2 = (undefined4 *)(uint)DAT_ffffd119, puVar2 == (undefined4 *)0x1)))))))) {
      DAT_ffffcf79 = 1;
    }
  }
  DAT_ffffcf7c = DAT_ffffcfaa;
  return puVar2;
}


