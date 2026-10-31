/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b404: Table 2D - 236 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b418: Table 2D - 237 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b42c: Table 2D - 238 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b440: Table 2D - 239 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b454: Table 2D - 240 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b468: Table 2D - 241 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b47c: Table 2D - 242 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b490: Table 2D - 243 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b4bc: Table 2D - 244 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0004fe9c; body bytes: 274; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004dab8 (274 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_fuelLevelSomething(void)

{
  char cVar1;
  undefined4 uVar2;
  float fVar3;
  
  fVar3 = 0.0;
  uVar2 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff867c);
  DAT_ffffd04c = (float)lookup_2d_descriptor_scaled(uVar2,&tbl_table_2d_236_0006b404);
  DAT_ffffd050 = (float)lookup_2d_descriptor_scaled(uVar2,&tbl_table_2d_237_0006b418);
  DAT_ffffd054 = (float)lookup_2d_descriptor_scaled(uVar2,&tbl_table_2d_238_0006b42c);
  DAT_ffffd058 = (float)lookup_2d_descriptor_scaled(uVar2,&tbl_table_2d_239_0006b440);
  DAT_ffffd05c = (float)lookup_2d_descriptor_scaled(uVar2,&tbl_table_2d_240_0006b454);
  DAT_ffffd060 = (float)lookup_2d_descriptor_scaled(uVar2,&tbl_table_2d_241_0006b468);
  DAT_ffffd064 = (float)lookup_2d_descriptor_scaled(uVar2,&tbl_table_2d_242_0006b47c);
  DAT_ffffd068 = (float)lookup_2d_descriptor_scaled(uVar2,&tbl_table_2d_243_0006b490);
  DAT_ffffd06c = (float)lookup_2d_descriptor_scaled(DAT_ffffd014,&tbl_table_2d_244_0006b4bc);
  if (DAT_ffffd1c5 == '\x01') {
    cVar1 = '\x01';
    DAT_ffffd018 = fVar3;
    DAT_ffffd01c = fVar3;
    DAT_ffffd020 = fVar3;
    DAT_ffffd024 = fVar3;
    DAT_ffffd028 = fVar3;
    DAT_ffffd02c = fVar3;
    DAT_ffffd030 = fVar3;
    DAT_ffffd034 = fVar3;
  }
  else {
    cVar1 = DAT_ffffd047;
    if (DAT_ffffd047 == '\x01') {
      DAT_ffffd018 = DAT_ffffd04c * DAT_ffffd06c;
      DAT_ffffd01c = DAT_ffffd050 * DAT_ffffd06c;
      DAT_ffffd020 = DAT_ffffd054 * DAT_ffffd06c;
      DAT_ffffd024 = DAT_ffffd058 * DAT_ffffd06c;
      DAT_ffffd028 = DAT_ffffd05c * DAT_ffffd06c;
      DAT_ffffd02c = DAT_ffffd060 * DAT_ffffd06c;
      DAT_ffffd030 = DAT_ffffd064 * DAT_ffffd06c;
      DAT_ffffd034 = DAT_ffffd068 * DAT_ffffd06c;
    }
  }
  return cVar1;
}


