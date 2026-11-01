/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b850: Table 2D - 274 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00042afc; body bytes: 212; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00042330 (212 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * ref_liftoffRelated__(void)

{
  char cVar1;
  undefined1 *puVar2;
  float fVar3;
  float snapshot_DAT_ffffa9bc;
  float snapshot_engine_speed_rpm_ffffb548;
  
  cVar1 = cranking_active_ffffaa62_ffffaa62;
  snapshot_DAT_ffffa9bc = inferred_ram_a9bc_ffffa9bc_ffffa9bc;
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  fVar3 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_274_0006b850);
  puVar2 = (undefined1 *)((int)&vector_Poweron_Reset + 1);
  if ((cVar1 == '\x01') || (puVar2 = &DAT_0007b611, DAT_ffffca3f == 'd')) {
    DAT_ffffca46 = 0;
    DAT_ffffca48 = 0;
    DAT_ffffca49 = 0;
  }
  else {
    if (((DAT_ffffca99 == 1) || ((DAT_ffffca94 < fVar3 && (fVar3 <= snapshot_DAT_ffffa9bc)))) && (DAT_ffffca47 == 1)
       ) {
      DAT_ffffca46 = 1;
    }
    puVar2 = (undefined1 *)(uint)DAT_ffffca99;
    if ((puVar2 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) &&
       (puVar2 = (undefined1 *)(uint)DAT_ffffca47,
       puVar2 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) {
      DAT_ffffca48 = 1;
    }
    if ((DAT_ffffca40 != '\0') &&
       (puVar2 = (undefined1 *)(uint)DAT_ffffca46,
       puVar2 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) {
      DAT_ffffca49 = 1;
    }
  }
  if (DAT_ffffca3f == '\0') {
    if (3200.0 < snapshot_engine_speed_rpm_ffffb548) {
      DAT_ffffca4a = 1;
    }
    else {
      DAT_ffffca4a = 0;
    }
  }
  DAT_ffffca94 = snapshot_DAT_ffffa9bc;
  DAT_ffffca99 = cVar1;
  return puVar2;
}


