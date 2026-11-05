/* ROM address: 0x00060f02; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f7f2 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00060f02(uint param_1)

{
  if (((&DAT_ffff87b6)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10] == -0x40) &&
     ((&CAL_DTC_0300_Enable_Disable_1_1129)[param_1 & 0xffff] == '\x01')) {
    FUN_00062e4a(0xc0);
    return;
  }
  return;
}


