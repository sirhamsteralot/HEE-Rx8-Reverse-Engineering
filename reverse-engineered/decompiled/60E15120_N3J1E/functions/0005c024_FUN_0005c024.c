/* ROM address: 0x0005c024; body bytes: 164; decompiled */

float FUN_0005c024(float param_1)

{
  float fVar1;
  
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == 0x17e0) {
      if ((DAT_ffffd36c & 0x60) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd31b = '\0';
      }
      else {
        DAT_ffffd31b = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd335 = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0x60) == 0) {
        DAT_ffffd31b = '\0';
      }
    }
  }
  if (DAT_ffffd31b == '\0') {
    DAT_ffffd335 = -0x80;
  }
  else if (DAT_ffffd31b == '\a') {
    fVar1 = (float)rx8_decode_u8_affine(0x3b800000,0xbf000000,(int)DAT_ffffd335);
    param_1 = param_1 + fVar1;
  }
  return param_1;
}


