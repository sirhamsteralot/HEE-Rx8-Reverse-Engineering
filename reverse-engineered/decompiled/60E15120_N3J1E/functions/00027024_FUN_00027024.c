/* ROM address: 0x00027024; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000279a0 (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00027024(void)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  byte bVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 uVar7;
  
  puVar2 = &e2ram_learned_table_value_pos_ffff8108;
  bVar1 = 0;
  puVar3 = &e2ram_learned_table_flag_a_ffff8548;
  uVar7 = 0;
  do {
    bVar4 = 0;
    puVar5 = puVar2;
    puVar6 = puVar3;
    do {
      ref_updateMemoryAtAddress_float_VAL_ADDR(uVar7,puVar5);
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(puVar6,0);
      bVar4 = bVar4 + 1;
      puVar6 = puVar6 + 2;
      puVar5 = puVar5 + 8;
    } while (bVar4 < 0x44);
    bVar1 = bVar1 + 1;
    puVar3 = puVar3 + 0x88;
    puVar2 = puVar2 + 0x220;
  } while (bVar1 < 2);
  return;
}


