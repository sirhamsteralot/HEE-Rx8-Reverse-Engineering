/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a1fc: Table 3D - 45 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00021c14; body bytes: 184; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00022580 (184 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00021c14(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = DAT_ffffce08;
  if ((((DAT_ffffd263 != '\x01') && (DAT_ffffd264 != '\x01')) &&
      ((((int)DAT_ffffcfb5 & 0x80U) == 0 || (DAT_ffffd147 != '\x01')))) &&
     ((DAT_ffffcf85 == '\0' && (DAT_ffffd0f2 != '\x01')))) {
    uVar3 = 0;
    cVar1 = rx8_is_outside_tolerance_band(DAT_ffffb2ec,0,0x3727c5ac);
    if (DAT_ffffb2f6 == '\x01') {
      if (cVar1 == '\0') {
        DAT_ffffb31c = uVar3;
        FUN_00021ccc();
        return;
      }
      DAT_ffffb31c = lookup_3d_descriptor_scaled(inferred_manifold_relative_pressure_ffffbe08,DAT_ffffb1dc,&tbl_table_3d_45_0006a1fc);
      FUN_00021ccc();
      return;
    }
    uVar2 = DAT_ffffb308;
    if (DAT_ffffb319 != '\x01') {
      DAT_ffffb31c = uVar3;
      DAT_ffffb2f0 = FUN_0005c0f0(uVar3);
      return;
    }
  }
  DAT_ffffb31c = uVar2;
  FUN_00021ccc();
  return;
}


