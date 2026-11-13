/* ROM address: 0x00031318; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000317c0 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00031318(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(uint)engine_running_flag_ffffaa68;
  if (puVar1 == (undefined1 *)0x1) {
    puVar1 = &inferred_ram_bf3c_ffffbf3c_ffffbf3c;
    inferred_ram_bf3c_ffffbf3c_ffffbf3c = DAT_ffffbf3d;
  }
  return puVar1;
}


