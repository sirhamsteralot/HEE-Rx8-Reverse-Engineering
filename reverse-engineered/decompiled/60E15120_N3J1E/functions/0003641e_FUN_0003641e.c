/* ROM address: 0x0003641e; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00036b3e (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_0003641e(void)

{
  undefined1 *puVar1;
  undefined1 *in_r0;
  
  if ((DAT_ffffc246 == '\0') &&
     (in_r0 = (undefined1 *)(uint)DAT_ffffb578,
     in_r0 != (undefined1 *)((int)&vector_Poweron_Reset + 1U))) {
    if (DAT_ffffc276 != '\0') {
      DAT_ffffc276 = DAT_ffffc276 + -1;
      DAT_ffffc242 = 1;
      in_r0 = (undefined1 *)(int)DAT_ffffc276;
      if ((in_r0 == (undefined1 *)0x0) &&
         (in_r0 = (undefined1 *)(uint)inferred_ram_c1d2_ffffc1d2_ffffc1d2, in_r0 == (undefined1 *)0x55)) {
        puVar1 = (undefined1 *)(uint)inferred_ram_c1d2_ffffc1d2_ffffc1d2;
        if (puVar1 != (undefined1 *)((int)&vector_usr_break + 3)) {
          inferred_ram_c1d2_ffffc1d2_ffffc1d2 = 0x33;
          DAT_ffffc275 = DAT_ffffc275 & 0xfd;
          DAT_ffffc247 = 0;
          DAT_ffffc234 = 0;
          puVar1 = &DAT_ffffc23c;
          DAT_ffffc23c = 0;
          DAT_ffffc23e = 1;
          DAT_ffffc238 = 0;
        }
        return puVar1;
      }
    }
  }
  return in_r0;
}


