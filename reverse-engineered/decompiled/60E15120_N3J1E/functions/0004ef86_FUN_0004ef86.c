/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b3c8: Table 3D - 120 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b3dc: Table 3D - 121 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0004ef86; body bytes: 212; decompiled */

char FUN_0004ef86(void)

{
  char cVar1;
  char cVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  cVar2 = DAT_ffffcfbd;
  DAT_ffffcfb6 = DAT_ffffcfbc == '\x01';
  uVar8 = 0x3f800000;
  uVar7 = 0;
  uVar4 = rx8_decode_u8_affine(0x3f800000,0,(int)DAT_ffffcfad);
  uVar5 = rx8_decode_u8_affine(uVar8,uVar7,(int)DAT_ffffcfac);
  uVar6 = rx8_decode_u8_affine(uVar8,uVar7,(int)DAT_ffffcfaf);
  uVar7 = rx8_decode_u8_affine(uVar8,uVar7,(int)DAT_ffffcfae);
  if (cVar2 == '\x01') {
    puVar3 = &tbl_table_3d_120_0006b3c8;
    uVar6 = uVar4;
    uVar7 = uVar5;
  }
  else {
    puVar3 = &tbl_table_3d_121_0006b3dc;
  }
  cVar1 = rx8_lookup_3d_raw_u8(uVar6,uVar7,puVar3);
  DAT_ffffcfb7 = 0;
  if (cVar2 == '\x01') {
    cVar2 = '\x01';
    if (DAT_ffffcfba == '\0') {
      DAT_ffffcfb7 = 1;
    }
    else if (cVar1 == '\x01') {
      DAT_ffffcfb7 = 1;
    }
  }
  else {
    cVar2 = DAT_ffffcfbb;
    if ((DAT_ffffcfbb == '\x01') && (cVar1 == '\x01')) {
      DAT_ffffcfb7 = 1;
    }
  }
  return cVar2;
}


