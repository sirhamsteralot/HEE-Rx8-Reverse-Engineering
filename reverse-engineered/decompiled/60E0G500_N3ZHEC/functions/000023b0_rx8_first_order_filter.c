/* ROM address: 0x000023b0; body bytes: 40; decompiled */

float rx8_first_order_filter(float arg0,float arg1,float arg2,float arg3)

{
  float fVar1;
  
  if ((((uint)arg1 & 0x7f800000) == 0x7f800000) ||
     (fVar1 = arg0 + (arg1 - arg0) * (1.0 - arg2), ABS(arg0 - fVar1) < arg3)) {
    fVar1 = arg0;
  }
  return fVar1;
}


