/* ROM address: 0x0001b032; body bytes: 164; decompiled */

undefined1 * FUN_0001b032(void)

{
  undefined1 *puVar1;
  undefined1 *extraout_r0;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar2 = DAT_ffffaa84;
  fVar4 = (float)(&DAT_ffffaaac)[DAT_ffffaacc];
  fVar3 = (float)(&DAT_ffffaa94)[DAT_ffffaacc];
  (&DAT_ffffaa94)[DAT_ffffaacc] = DAT_ffffaa84;
  (&DAT_ffffaaac)[DAT_ffffaacc] = fVar2;
  DAT_ffffaa90 = DAT_ffffaa88;
  puVar1 = &DAT_ffffc600;
  if (DAT_ffffc600 == '\0') {
    fVar2 = (float)FUN_0003ea74(0x43928000,DAT_ffffae54 + 273.0);
    DAT_ffffaa8c = fVar2 * 1000.0 * (DAT_ffffad8c / 101.33299);
    DAT_ffffaa88 = rx8_min_float((fVar3 + fVar4) * 0.5,DAT_ffffaa8c);
    puVar1 = extraout_r0;
  }
  else {
    DAT_ffffaa88 = DAT_ffffaac4;
  }
  if (DAT_ffffaacc < 5) {
    DAT_ffffaacc = DAT_ffffaacc + 1;
  }
  else {
    puVar1 = (undefined1 *)0x0;
    DAT_ffffaacc = '\0';
  }
  return puVar1;
}


