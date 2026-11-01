/* ROM address: 0x000080f0; body bytes: 148; decompiled */

char FUN_000080f0(void)

{
  float fVar1;
  float fVar2;
  
  if (DAT_ffff9f95 != '$') {
    fVar2 = (float)DAT_ffff9fb0;
    if (DAT_ffff9fb0 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    fVar1 = (float)DAT_ffff9fb4;
    if (DAT_ffff9fb4 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    DAT_ffff9fec = fVar2 / fVar1;
    if ((DAT_ffff9f95 == '!') || (DAT_ffff9f95 == '\x0f')) {
      if (DAT_ffff9fec < DAT_ffff9ff0) {
        DAT_ffff9ff0 = DAT_ffff9fec;
      }
    }
    else if (DAT_ffff9f95 == '\"') {
      if (DAT_ffff9ffc < DAT_ffff9fec) {
        DAT_ffff9ffc = DAT_ffff9fec;
      }
    }
    else if (DAT_ffff9f95 == '\x12') {
      if (DAT_ffff9fec < DAT_ffff9ff4) {
        DAT_ffff9ff4 = DAT_ffff9fec;
      }
    }
    else if (DAT_ffff9ff8 < DAT_ffff9fec) {
      DAT_ffff9ff8 = DAT_ffff9fec;
    }
  }
  return DAT_ffff9f95;
}


