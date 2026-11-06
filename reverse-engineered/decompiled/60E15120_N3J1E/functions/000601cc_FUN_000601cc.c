/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffd3c0 dtc_first_stored_code (uint16): First stored DTC code, recorded by 0x601cc when flag table goes 0->1.
 */
/* ROM address: 0x000601cc; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005eabc (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined * FUN_000601cc(uint param_1,byte param_2,short param_3)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(uint)param_2;
  if (((puVar1 != (undefined *)((int)&vector_Poweron_Reset + 2)) && (puVar1 != &UNK_00000004)) &&
     (puVar1 == (undefined *)((int)&vector_Poweron_Reset + 1))) {
    puVar1 = &dtc_ram_flag_table_ffffd570_ffffd570;
    (&dtc_ram_flag_table_ffffd570_ffffd570)[*(ushort *)(&DAT_0007df42 + (param_1 & 0xffff) * 2)] = 1;
    if (dtc_first_stored_code_ffffd3c0 == 0) {
      dtc_first_stored_code_ffffd3c0 = param_3;
    }
  }
  return puVar1;
}


