/* ROM address: 0x00027eec; body bytes: 170; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00028834 (170 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 * FUN_00027eec(byte param_1)

{
  undefined2 *puVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  
  bVar3 = 0;
  do {
    uVar4 = (uint)(char)param_1;
    bVar2 = 0;
    do {
      uVar4 = rx8_add_u8_saturate(uVar4,0x11);
      FUN_0000420c();
      bVar2 = bVar2 + 1;
      puVar1 = (undefined2 *)(&e2ram_learned_table_flag_a_ffff8548 + (uVar4 & 0xff) * 2 + (uint)bVar3 * 0x88);
      *puVar1 = *(undefined2 *)(&e2ram_learned_table_flag_a_ffff8548 + (uint)param_1 * 2 + (uint)bVar3 * 0x88);
    } while (bVar2 < 3);
    bVar3 = bVar3 + 1;
  } while (bVar3 < 2);
  return puVar1;
}


