/* ROM address: 0x000252c2; body bytes: 178; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025b4a (178 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_000252c2(void)

{
  undefined1 *puVar1;
  
  if (engine_running_flag_ffffaa68 == '\x01') {
    if (DAT_ffffb57a != '\0') {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8104,0);
      puVar1 = (undefined1 *)ref_whileLoop();
      return puVar1;
    }
    puVar1 = (undefined1 *)0x5a;
    DAT_ffffdf99 = 0x5a;
    DAT_ffffb580 = 0;
    DAT_ffffb579 = 1;
  }
  else if (DAT_ffffb57a == '\0') {
    DAT_ffffb57c = 0;
    DAT_ffffb57a = '\x01';
    DAT_ffffb578 = 1;
    puVar1 = &DAT_ffffb578;
    DAT_ffffb580 = DAT_ffffb580 + 1;
  }
  else {
    if (DAT_ffffb57c != 0xffffffff) {
      DAT_ffffb57c = DAT_ffffb57c + 1;
    }
    if ((0x36ee7 < DAT_ffffb57c) ||
       ((puVar1 = (undefined1 *)((int)&vector_Slot_illegal + 1), 0x18 < DAT_ffffb57c &&
        (puVar1 = &DAT_ffffb583, DAT_ffffb582 <= DAT_ffffb583)))) {
      DAT_ffffb57a = 2;
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8104,1);
      DAT_ffffb579 = 0;
      DAT_ffffdf99 = 0;
      puVar1 = (undefined1 *)FUN_00009ea2();
      return puVar1;
    }
  }
  return puVar1;
}


