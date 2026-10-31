/* ROM address: 0x00052c8a; body bytes: 108; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00050c0e (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00052c8a(void)

{
  undefined1 *puVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    puVar1 = (undefined1 *)0x0;
    DAT_ffffd131 = 0;
  }
  else {
    puVar1 = (undefined1 *)(uint)DAT_ffffd0f2;
    if (((puVar1 == (undefined1 *)0x1) &&
        (puVar1 = (undefined1 *)(uint)DAT_ffffcfaa, (undefined1 *)0x1f < puVar1)) &&
       ((0.0015 < DAT_ffffcff4 ||
        (((DAT_ffffcfaa < 0x3f &&
          (puVar1 = (undefined1 *)(int)DAT_ffffcff8, puVar1 == (undefined1 *)0x0)) &&
         (puVar1 = &DAT_ffffd130, 0x17 < DAT_ffffd130)))))) {
      DAT_ffffd131 = 1;
    }
  }
  return puVar1;
}


