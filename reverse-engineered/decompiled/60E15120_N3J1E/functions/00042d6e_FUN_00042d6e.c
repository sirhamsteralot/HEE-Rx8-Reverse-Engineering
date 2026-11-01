/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b878: Table 2D - 276 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b88c: Table 3D - 92 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b8a8: Table 3D - 93 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b8c4: Table 3D - 94 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b8e0: Table 3D - 95 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00042d6e; body bytes: 212; decompiled */

void FUN_00042d6e(void)

{
  char cVar1;
  char cVar2;
  undefined **ppuVar3;
  undefined4 uVar4;
  undefined4 snapshot_DAT_ffffca28;
  
  cVar2 = DAT_ffffca4d;
  cVar1 = DAT_ffffca4a;
  if (cranking_active_ffffaa62_ffffaa62 == '\x01') {
    DAT_ffffca3d = 0;
  }
  else if (DAT_ffffca34 <= 5.0) {
    DAT_ffffca3d = 1;
  }
  else if (DAT_ffffca34 < 6.5) {
    DAT_ffffca3d = 2;
  }
  else {
    DAT_ffffca3d = 3;
  }
  if (DAT_ffffca3e == '\x02') {
    DAT_ffffca20 = DAT_ffffca28;
  }
  else {
    DAT_ffffca20 = 0;
  }
  snapshot_DAT_ffffca28 = DAT_ffffca28;
  uVar4 = rx8_decode_u8_affine(0x3f800000,0,DAT_ffffca3d);
  if ((cVar1 == '\0') && (cVar2 == '\0')) {
    ppuVar3 = &tbl_table_3d_92_0006b88c;
  }
  else {
    if (cVar1 != '\0') {
      if (cVar2 == '\0') {
        ppuVar3 = &tbl_table_3d_94_0006b8c4;
      }
      else {
        ppuVar3 = &tbl_table_3d_95_0006b8e0;
      }
      DAT_ffffca18 = lookup_3d_descriptor_scaled(DAT_ffffca20,uVar4,ppuVar3);
      goto LAB_00042e70;
    }
    ppuVar3 = &tbl_table_3d_93_0006b8a8;
  }
  DAT_ffffca18 = lookup_3d_descriptor_scaled(ppuVar3);
LAB_00042e70:
  DAT_ffffca1c = lookup_2d_descriptor_scaled(snapshot_DAT_ffffca28,&tbl_table_2d_276_0006b878);
  return;
}


