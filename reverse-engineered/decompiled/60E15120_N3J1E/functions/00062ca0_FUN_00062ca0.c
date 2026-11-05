/* ROM address: 0x00062ca0; body bytes: 108; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00061590 (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00062ca0(void)

{
  undefined4 *puVar1;
  
  dtc_master_current_index_ffff8900 = rx8_pack_u16_with_complement(0);
  _DAT_ffff8904 = rx8_pack_u16_with_complement(1);
  puVar1 = (undefined4 *)&dtc_master_table_21_ffff87b0;
  do {
    *(undefined2 *)puVar1 = 0xffff;
    *(undefined2 *)((int)puVar1 + 2) = 0xffff;
    *(undefined2 *)(puVar1 + 1) = 0xffff;
    *(undefined1 *)((int)puVar1 + 6) = 0;
    *(undefined1 *)((int)puVar1 + 7) = 0;
    *(undefined1 *)(puVar1 + 2) = 3;
    *(undefined1 *)((int)puVar1 + 9) = 0x28;
    *(undefined1 *)((int)puVar1 + 10) = 0x50;
    *(undefined1 *)((int)puVar1 + 0xb) = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
    *(undefined1 *)((int)puVar1 + 0xd) = 8;
    *(undefined1 *)((int)puVar1 + 0xe) = 0x28;
    puVar1 = puVar1 + 4;
  } while (puVar1 < &dtc_master_current_index_ffff8900);
  return 0x28;
}


