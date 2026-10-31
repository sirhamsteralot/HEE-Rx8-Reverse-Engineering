/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006babc: Table 2D - 387 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00049964; body bytes: 336; decompiled */

undefined2 * FUN_00049964(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  float fVar3;
  float extraout_fr0;
  undefined4 uVar4;
  float snapshot_DAT_ffffad20;
  
  uVar4 = 0;
  puVar1 = (undefined2 *)(uint)DAT_ffffd1c5;
  if (puVar1 == (undefined2 *)((int)&vector_Poweron_Reset + 1)) {
    DAT_ffffcd1e = 0;
    DAT_ffffcd24 = 0.0;
    DAT_ffffcd28 = 0.0;
  }
  else {
    puVar2 = (undefined2 *)(uint)DAT_ffffcd34;
    if ((((puVar2 != (undefined2 *)0x0) &&
         (puVar1 = (undefined2 *)(int)DAT_ffffcd1e, puVar1 != (undefined2 *)&UNK_ffffffff)) &&
        ((DAT_ffffad20 < 0.3 || ((5.0 <= DAT_ffffcd2c && (DAT_ffffcd2c < 150.0)))))) &&
       ((DAT_ffffad20 < 0.3 || ((0.6 <= DAT_ffffad20 || (0.05 <= DAT_ffffad20 - DAT_ffffcd38)))))) {
      if (puVar2 != (undefined2 *)((int)&vector_Poweron_Reset + 1U)) {
        DAT_ffffcd38 = DAT_ffffad20;
        return puVar2;
      }
      if (0.6 <= DAT_ffffad20) {
        if (DAT_ffffcd1e == -1) {
          DAT_ffffcd38 = DAT_ffffad20;
          return &DAT_0007c9cc;
        }
        DAT_ffffcd34 = 0;
        DAT_ffffcd20 = 0;
        fVar3 = DAT_ffffcd2c;
        snapshot_DAT_ffffad20 = DAT_ffffad20;
        DAT_ffffcd30 = rx8_add_u16_saturate((int)DAT_ffffcd30,1);
        DAT_ffffcd1e = rx8_add_u16_saturate((int)DAT_ffffcd1e,1);
        puVar1 = (undefined2 *)rx8_lookup_2d_raw_u16(fVar3,&tbl_table_2d_387_check_datatype_0006babc);
        DAT_ffffcd3c = (short)puVar1;
        if (DAT_ffffcd3c != 0) {
          fVar3 = (float)rx8_decode_u16_affine
                                   (0x42000000,uVar4,(int)DAT_ffffcd30);
          puVar1 = (undefined2 *)
                   rx8_decode_u16_affine(0x41000000,uVar4,(int)DAT_ffffcd3c);
          DAT_ffffcd24 = fVar3 / extraout_fr0;
        }
        DAT_ffffcd28 = DAT_ffffcd24 + DAT_ffffcd28;
        DAT_ffffcd30 = 0;
        DAT_ffffcd38 = snapshot_DAT_ffffad20;
        return puVar1;
      }
      if (DAT_ffffad20 < 0.3) {
        DAT_ffffcd38 = DAT_ffffad20;
        return puVar2;
      }
      if (DAT_ffffad20 - DAT_ffffcd38 < 0.05) {
        DAT_ffffcd38 = DAT_ffffad20;
        return puVar2;
      }
      fVar3 = DAT_ffffad20;
      puVar1 = (undefined2 *)rx8_add_u16_saturate((int)DAT_ffffcd30,1);
      DAT_ffffcd30 = (short)puVar1;
      DAT_ffffcd38 = fVar3;
      return puVar1;
    }
    DAT_ffffcd34 = 0;
  }
  DAT_ffffcd30 = 0;
  DAT_ffffcd20 = 0;
  DAT_ffffcd38 = DAT_ffffad20;
  return puVar1;
}


