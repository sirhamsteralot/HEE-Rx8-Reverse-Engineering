/* ROM address: 0x00002304; body bytes: 18; decompiled */

int FUN_00002304(int param_1,int param_2)

{
  char cVar1;
  
  cVar1 = (param_1 < 0) + (param_2 < 0);
  param_1 = param_2 + param_1;
  if ((cVar1 == '\0' || cVar1 == '\x02') && (char)((param_1 < 0) + (param_2 < 0)) == '\x01') {
    param_1 = (-1 < param_1) + 0x7fffffff;
  }
  return param_1;
}


