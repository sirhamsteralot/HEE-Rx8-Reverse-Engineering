/* ROM address: 0x00007ab2; body bytes: 80; decompiled */

bool FUN_00007ab2(float param_1)

{
  float fVar1;
  
  fVar1 = (float)DAT_ffff9fb4;
  if (DAT_ffff9fb4 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  fVar1 = fVar1 * param_1;
  if (2.1474836e+09 < fVar1) {
    fVar1 = fVar1 + -4.2949673e+09;
  }
  if ((uint)(int)fVar1 <= DAT_ffff9fb0) {
    DAT_ffff9fbc = DAT_ffff9fbc + 20.0;
  }
  return (uint)(int)fVar1 <= DAT_ffff9fb0;
}


