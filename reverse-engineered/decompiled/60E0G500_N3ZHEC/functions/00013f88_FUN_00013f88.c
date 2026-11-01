/* ROM address: 0x00013f88; body bytes: 118; decompiled */

void FUN_00013f88(float param_1)

{
  byte bVar1;
  byte bVar2;
  
  if (0.0 <= param_1) {
    bVar1 = 0x15;
    if (param_1 < 9.0) {
      bVar2 = 0;
      while ((bVar1 = DAT_ffffa784, bVar2 < 0x15 &&
             ((param_1 < (float)(&DAT_00072d78)[bVar2] ||
              (bVar1 = bVar2, (float)(&DAT_00072d78)[(byte)(bVar2 + 1)] <= param_1))))) {
        bVar2 = bVar2 + 1;
      }
    }
  }
  else {
    DAT_ffffa784 = 0;
    bVar1 = DAT_ffffa784;
  }
  DAT_ffffa784 = bVar1;
  FUN_00002500(0x3f000000,0xc2480000,(int)(char)(&DAT_00072dd0)[DAT_ffffa784]);
  return;
}


