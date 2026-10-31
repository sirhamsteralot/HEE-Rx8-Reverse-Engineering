/* ROM address: 0x00010f3e; body bytes: 60; decompiled */

int FUN_00010f3e(char param_1)

{
  float fVar1;
  
  fVar1 = DAT_ffffbc1c;
  if ((((param_1 != '\0') && (param_1 != '\x01')) && (fVar1 = DAT_ffffbc20, param_1 != '\x02')) &&
     (param_1 != '\x03')) {
    fVar1 = 0.0;
  }
  return (int)(fVar1 / 0.25);
}


