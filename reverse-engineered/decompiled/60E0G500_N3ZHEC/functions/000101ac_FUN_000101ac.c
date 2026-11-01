/* ROM address: 0x000101ac; body bytes: 72; decompiled */

int FUN_000101ac(char param_1)

{
  float fVar1;
  
  fVar1 = DAT_ffffbeac;
  if ((((param_1 != '\0') && (param_1 != '\x03')) && (fVar1 = DAT_ffffbeb0, param_1 != '\x01')) &&
     (((param_1 != '\x02' && (param_1 != '\x04')) && (param_1 != '\x05')))) {
    fVar1 = 0.0;
  }
  return (int)(fVar1 / 0.25);
}


