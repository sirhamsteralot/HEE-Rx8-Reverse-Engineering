/* ROM address: 0x00000ae8; body bytes: 36; decompiled */

uint FUN_00000ae8(byte param_1,uint param_2,char *param_3,char *param_4)

{
  char cVar1;
  
  for (; (param_2 & 0xff) < (uint)param_1; param_2 = param_2 + 1) {
    cVar1 = *param_3;
    do {
      *param_4 = cVar1;
    } while (*param_4 != cVar1);
    param_4 = param_4 + 1;
    param_3 = param_3 + 1;
  }
  return param_2;
}


