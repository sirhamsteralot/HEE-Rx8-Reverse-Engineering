/* ROM address: 0x000270aa; body bytes: 112; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00027a26 (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000270aa(void)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  byte bVar4;
  undefined *puVar5;
  undefined *puVar6;
  
  bVar1 = 0;
  puVar3 = &e2ram_learned_table_value_pos_ffff8108;
  puVar2 = &e2ram_learned_table_flag_a_ffff8548;
  do {
    bVar4 = 0;
    puVar5 = puVar2;
    puVar6 = puVar3;
    do {
      ref_validateAddressCopy_float_ADDRESS__(puVar6);
      ref_validateAddressCopy_8bit_ADDRESS__(puVar5);
      bVar4 = bVar4 + 1;
      puVar5 = puVar5 + 2;
      puVar6 = puVar6 + 8;
    } while (bVar4 < 0x44);
    bVar1 = bVar1 + 1;
    puVar3 = puVar3 + 0x220;
    puVar2 = puVar2 + 0x88;
  } while (bVar1 < 2);
  ref_validateAddressCopy_8bit_ADDRESS__(&DAT_ffff8658);
  ref_validateAddressCopy_8bit_ADDRESS__(&DAT_ffff865a);
  ref_validateAddressCopy_8bit_ADDRESS__(&DAT_ffff865c);
  return;
}


