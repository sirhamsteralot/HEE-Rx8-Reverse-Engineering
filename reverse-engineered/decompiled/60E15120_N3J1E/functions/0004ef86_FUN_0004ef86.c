/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b3c8: Table 3D - 120 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b3dc: Table 3D - 121 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * relay_flag_pair_pd7_pe0_calc [high]: First block copies 0xffffcfbc (pool 0x4efb8, cmp/eq at 0x4efa4) into 0xffffcfb6 (pool 0x4efb6) at 0x4efaa/0x4efce; the rest of the body computes the PE0 half 0xffffcfb7 from 3D tables 0x6b3c8/0x6b3dc for the throttle/DBW relay.
 * RAM 0xffffcfbc pd7_relay_condition (uint8): Written by 0x4ed3c: = 1 if (cfbe==1 && cfaa>=cfa6) || 0xffffd15c(cranking_in_progress)==1, cleared if cfc1==1. Feeds PD7 via cfb6.
 */
/* ROM address: 0x0004ef86; body bytes: 212; decompiled */

char relay_flag_pair_pd7_pe0_calc(void)

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
  pd7_relay_flag_ffffcfb6 = pd7_relay_condition_ffffcfbc == '\x01';
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
  pe0_relay_flag_ffffcfb7 = 0;
  if (cVar2 == '\x01') {
    cVar2 = '\x01';
    if (DAT_ffffcfba == '\0') {
      pe0_relay_flag_ffffcfb7 = 1;
    }
    else if (cVar1 == '\x01') {
      pe0_relay_flag_ffffcfb7 = 1;
    }
  }
  else {
    cVar2 = DAT_ffffcfbb;
    if ((DAT_ffffcfbb == '\x01') && (cVar1 == '\x01')) {
      pe0_relay_flag_ffffcfb7 = 1;
    }
  }
  return cVar2;
}


