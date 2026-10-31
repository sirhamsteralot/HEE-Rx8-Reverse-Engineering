/* ROM address: 0x00044ffc; body bytes: 52; decompiled */

char FUN_00044ffc(void)

{
  float fVar1;
  
  fVar1 = rx8_absolute_difference(DAT_ffffad50,0.0);
  if ((DAT_ffffcca1 == '\x01') || (0.5 < fVar1)) {
    DAT_ffffcbb0 = 1;
  }
  else {
    DAT_ffffcbb0 = 0;
  }
  return DAT_ffffcca1;
}


