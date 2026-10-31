/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b8fc: Table 3D - 96 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000434d4; body bytes: 100; decompiled */

undefined4 * FUN_000434d4(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  float extraout_fr0;
  
  puVar1 = (undefined4 *)(uint)DAT_ffffca44;
  if (puVar1 == (undefined4 *)((int)&vector_Poweron_Reset + 1)) {
    puVar1 = &DAT_0007b648;
    if (DAT_ffffc9d0 < 20.0) {
      if (DAT_ffffc9d0 <= 0.0) {
        DAT_ffffc9b8 = 0.0;
      }
      else {
        uVar2 = rx8_decode_u8_affine(0x3f800000,0,(int)DAT_ffffca3d);
        puVar1 = (undefined4 *)lookup_3d_descriptor_scaled(DAT_ffffca20,uVar2,&tbl_table_3d_96_0006b8fc);
        DAT_ffffc9b8 = (DAT_ffffc9f0 + DAT_ffffc9d4 * extraout_fr0) - DAT_ffffca14;
      }
    }
    else {
      DAT_ffffc9b8 = 20.0;
    }
  }
  return puVar1;
}


