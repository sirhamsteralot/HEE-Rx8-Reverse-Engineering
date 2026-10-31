/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b5a8: Table 2D - 372 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b5b4: Table 2D - 373 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0005356e; body bytes: 134; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000514f2 (134 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * FUN_0005356e(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff867c);
  DAT_ffffd184 = (float)lookup_2d_descriptor_scaled(uVar2,&tbl_table_2d_372_check_datatype_0006b5a8);
  DAT_ffffd188 = (float)lookup_2d_descriptor_scaled(uVar2,&tbl_table_2d_373_check_datatype_0006b5b4);
  puVar1 = (undefined4 *)0x1;
  if ((DAT_ffffd1c5 == '\x01') ||
     (puVar1 = (undefined4 *)(uint)DAT_ffffcf78, puVar1 == (undefined4 *)0x1)) {
    DAT_ffffd182 = 0;
  }
  else if ((DAT_ffffd170 < DAT_ffffd184) &&
          (((puVar1 = &DAT_ffffd17c, DAT_ffffd17c < DAT_ffffd188 &&
            (puVar1 = (undefined4 *)(uint)DAT_ffffcfc6, puVar1 == (undefined4 *)0x1)) &&
           (puVar1 = (undefined4 *)(uint)DAT_ffffd181, (undefined4 *)0x2 < puVar1)))) {
    DAT_ffffd182 = 1;
  }
  return puVar1;
}


