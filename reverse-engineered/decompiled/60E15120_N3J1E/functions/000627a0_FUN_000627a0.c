/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000627a0; body bytes: 250; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00061090 (250 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000627a0(void)

{
  ushort snapshot_DAT_ffff879c;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  undefined4 uVar6;
  
  snapshot_DAT_ffff879c = DAT_ffff879c;
  cVar2 = DAT_ffff87a4._0_1_;
  cVar3 = DAT_ffff87a6._0_1_;
  cVar4 = DAT_ffff87a8._0_1_;
  cVar5 = DAT_ffff87ac._0_1_;
  DAT_ffff8798 = rx8_pack_u8_with_complement(0);
  uVar6 = sh_raise_interrupt_mask_return_previous(0x10);
  if (cVar2 == '\0') {
    DAT_ffff8e6c = rx8_pack_u8_with_complement((int)DAT_ffff8e70);
    *(ushort *)(&DAT_ffff8d54 + (uint)snapshot_DAT_ffff879c * 2) =
         (ushort)DAT_ffff8e72 * 0x100 + (ushort)DAT_ffff8e74;
    DAT_ffff8e6e = rx8_pack_u8_with_complement((int)DAT_ffff8e70);
  }
  if (cVar3 == '\0') {
    dtc_master_current_index_ffff8900 = rx8_pack_u16_with_complement((int)DAT_ffff8904);
  }
  if (cVar4 == '\0') {
    DAT_ffff8d4c = rx8_pack_u16_with_complement((int)DAT_ffff8d50);
  }
  if (DAT_ffff87aa == '\0') {
    FUN_000675b0();
  }
  if (cVar5 == '\0') {
    FUN_00067b16();
  }
  ref_setSR(uVar6);
  DAT_ffff8798 = rx8_pack_u8_with_complement(1);
  DAT_ffff87a4 = rx8_pack_u8_with_complement(2);
  DAT_ffff87a6 = rx8_pack_u8_with_complement(2);
  DAT_ffff87a8 = rx8_pack_u8_with_complement(2);
  _DAT_ffff87aa = rx8_pack_u8_with_complement(2);
  DAT_ffff87ac = rx8_pack_u8_with_complement(2);
  return;
}


