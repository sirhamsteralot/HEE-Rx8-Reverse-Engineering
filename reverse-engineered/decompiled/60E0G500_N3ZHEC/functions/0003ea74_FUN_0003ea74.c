/* ROM address: 0x0003ea74; body bytes: 48; decompiled */

float FUN_0003ea74(float param_1,float param_2)

{
  if (param_2 == 0.0) {
    if (param_1 == 0.0) {
      param_1 = 0.0;
    }
    else if (param_1 <= 0.0) {
      param_1 = -3.4028229e+38;
    }
    else {
      param_1 = 3.4028229e+38;
    }
  }
  else {
    param_1 = param_1 / param_2;
  }
  return param_1;
}


