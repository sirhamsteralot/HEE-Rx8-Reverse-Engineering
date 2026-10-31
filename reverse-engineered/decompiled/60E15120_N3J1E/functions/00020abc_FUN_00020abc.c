/* ROM address: 0x00020abc; body bytes: 100; decompiled */

int FUN_00020abc(float param_1)

{
  byte bVar1;
  byte bVar2;
  
  if (-40.0 <= param_1) {
    bVar1 = 7;
    if (param_1 < 100.0) {
      bVar2 = 0;
      while ((bVar1 = DAT_ffffb25f, bVar2 < 7 &&
             ((param_1 < (float)(&DAT_0007229c)[bVar2] ||
              (bVar1 = bVar2, (float)(&DAT_0007229c)[(byte)(bVar2 + 1)] <= param_1))))) {
        bVar2 = bVar2 + 1;
      }
    }
  }
  else {
    DAT_ffffb25f = 0;
    bVar1 = DAT_ffffb25f;
  }
  DAT_ffffb25f = bVar1;
  return (int)(char)(&DAT_000722bc)[DAT_ffffb25f];
}


