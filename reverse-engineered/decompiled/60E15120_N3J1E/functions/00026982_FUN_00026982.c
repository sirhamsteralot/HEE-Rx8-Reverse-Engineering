/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffb660 sector_parity_bank (uint16): DAT_ffffb660 = DAT_ffffa3b0 = ATUII sector index 0..5 (set in the CMI10B sector ISR); &1 selects the rotor bank in the learned table (0x271b0/0x276ec/0x28198): bank 0 reads value_pos 0xffff8108, bank 1 reads value_neg 0xffff8328.
 */
/* ROM address: 0x00026982; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000272a6 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00026982(void)

{
  sector_parity_bank_ffffb660 = (ushort)DAT_ffffa3b0;
  return;
}


