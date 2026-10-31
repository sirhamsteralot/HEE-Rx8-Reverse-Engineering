/* ROM address: 0x0004b3a8; body bytes: 216; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004a4a0 (216 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_0004b3a8(void)

{
  undefined1 *puVar1;
  undefined1 *extraout_r0;
  char cVar2;
  
  puVar1 = &DAT_ffffd0f2;
  cVar2 = '\x04';
  if (DAT_ffffd0f2 == '\0') {
    DAT_ffffce10 = 0.0;
  }
  else {
    if (((0x3d < DAT_ffffcfaa) && (cVar2 = DAT_ffffce14, DAT_ffffcfaa < 0x89)) &&
       (DAT_ffffce14 != '\0')) {
      cVar2 = DAT_ffffce14 + -1;
    }
    puVar1 = (undefined1 *)0x1;
    if (((DAT_ffffd15c == '\x01') || (puVar1 = (undefined1 *)0x1, DAT_ffffcf78 == '\x01')) ||
       ((puVar1 = (undefined1 *)(uint)DAT_ffffcf85, puVar1 != (undefined1 *)0x0 ||
        (DAT_ffffcfaa < 0x3e)))) {
      DAT_ffffce10 = 0.0;
    }
    else if (DAT_ffffcfaa == 0x3e) {
      DAT_ffffce10 = 2.92969;
    }
    else if ((DAT_ffffcfaa < 0x3f) || (0x88 < DAT_ffffcfaa)) {
      DAT_ffffce10 = 0.0;
    }
    else if (cVar2 == '\0') {
      DAT_ffffce10 = rx8_clamp_float(DAT_ffffce10 + 2929.6,0.0,6054.6);
      cVar2 = '\x04';
      puVar1 = extraout_r0;
    }
  }
  DAT_ffffce14 = cVar2;
  return puVar1;
}


