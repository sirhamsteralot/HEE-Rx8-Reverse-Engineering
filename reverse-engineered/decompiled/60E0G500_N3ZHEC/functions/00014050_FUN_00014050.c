/* ROM address: 0x00014050; body bytes: 118; decompiled */

void FUN_00014050(float param_1)

{
  byte bVar1;
  byte bVar2;
  
  if (0.0 <= param_1) {
    bVar1 = 0x15;
    if (param_1 < 9.0) {
      bVar2 = 0;
      while ((bVar1 = DAT_ffffa785, bVar2 < 0x15 &&
             ((param_1 < (float)(&DAT_00072de8)[bVar2] ||
              (bVar1 = bVar2, (float)(&DAT_00072de8)[(byte)(bVar2 + 1)] <= param_1))))) {
        bVar2 = bVar2 + 1;
      }
    }
  }
  else {
    DAT_ffffa785 = 0;
    bVar1 = DAT_ffffa785;
  }
  DAT_ffffa785 = bVar1;
  FUN_00002500(0x3f000000,0xc2480000,(int)(char)(&DAT_00072e40)[DAT_ffffa785]);
  return;
}


