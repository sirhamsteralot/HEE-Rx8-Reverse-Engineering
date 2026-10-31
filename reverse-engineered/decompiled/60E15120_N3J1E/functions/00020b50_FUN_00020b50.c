/* ROM address: 0x00020b50; body bytes: 100; decompiled */

int FUN_00020b50(float param_1)

{
  byte bVar1;
  byte bVar2;
  
  if (-40.0 <= param_1) {
    bVar1 = 7;
    if (param_1 < 100.0) {
      bVar2 = 0;
      while ((bVar1 = DAT_ffffb260, bVar2 < 7 &&
             ((param_1 < (float)(&DAT_000722c4)[bVar2] ||
              (bVar1 = bVar2, (float)(&DAT_000722c4)[(byte)(bVar2 + 1)] <= param_1))))) {
        bVar2 = bVar2 + 1;
      }
    }
  }
  else {
    DAT_ffffb260 = 0;
    bVar1 = DAT_ffffb260;
  }
  DAT_ffffb260 = bVar1;
  return (int)(char)(&DAT_000722e4)[DAT_ffffb260];
}


