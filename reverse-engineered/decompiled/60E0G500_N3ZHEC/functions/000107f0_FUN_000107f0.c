/* ROM address: 0x000107f0; body bytes: 22; decompiled */

int FUN_000107f0(int param_1,int param_2)

{
  param_2 = param_2 - param_1;
  if (param_2 < -0x1dffff) {
    param_2 = param_2 + 0x1680000;
  }
  return param_2;
}


