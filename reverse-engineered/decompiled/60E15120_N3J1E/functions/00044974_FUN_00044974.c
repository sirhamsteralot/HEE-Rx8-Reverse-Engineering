/* ROM address: 0x00044974; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00044190 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00044974(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(uint)DAT_ffffd1c5;
  if ((puVar1 == (undefined1 *)0x1) &&
     (puVar1 = (undefined1 *)(uint)engine_stopped_latch_ffffa41c, puVar1 == (undefined1 *)0x1)) {
    puVar1 = &DAT_ffffcb87;
    DAT_ffffcb84 = 1000;
    DAT_ffffcb87 = 0;
  }
  return puVar1;
}


