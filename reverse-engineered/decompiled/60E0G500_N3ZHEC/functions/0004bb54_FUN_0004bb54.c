/* ROM address: 0x0004bb54; body bytes: 216; decompiled */

undefined1 * FUN_0004bb54(void)

{
  undefined1 *puVar1;
  undefined1 *extraout_r0;
  char cVar2;
  
  puVar1 = &DAT_ffffd12e;
  cVar2 = '\x04';
  if (DAT_ffffd12e == '\0') {
    DAT_ffffce4c = 0.0;
  }
  else {
    if (((0x3d < DAT_ffffcfe6) && (cVar2 = DAT_ffffce50, DAT_ffffcfe6 < 0x89)) &&
       (DAT_ffffce50 != '\0')) {
      cVar2 = DAT_ffffce50 + -1;
    }
    puVar1 = (undefined1 *)0x1;
    if (((DAT_ffffd198 == '\x01') || (puVar1 = (undefined1 *)0x1, DAT_ffffcfb4 == '\x01')) ||
       ((puVar1 = (undefined1 *)(uint)DAT_ffffcfc1, puVar1 != (undefined1 *)0x0 ||
        (DAT_ffffcfe6 < 0x3e)))) {
      DAT_ffffce4c = 0.0;
    }
    else if (DAT_ffffcfe6 == 0x3e) {
      DAT_ffffce4c = 2.92969;
    }
    else if ((DAT_ffffcfe6 < 0x3f) || (0x88 < DAT_ffffcfe6)) {
      DAT_ffffce4c = 0.0;
    }
    else if (cVar2 == '\0') {
      DAT_ffffce4c = rx8_clamp_float(DAT_ffffce4c + 2929.6,0.0,6054.6);
      cVar2 = '\x04';
      puVar1 = extraout_r0;
    }
  }
  DAT_ffffce50 = cVar2;
  return puVar1;
}


