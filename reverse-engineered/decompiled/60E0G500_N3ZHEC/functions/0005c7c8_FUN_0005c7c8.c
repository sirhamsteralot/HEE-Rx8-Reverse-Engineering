/* ROM address: 0x0005c7c8; body bytes: 164; decompiled */

float FUN_0005c7c8(float param_1)

{
  float fVar1;
  
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == 0x17e0) {
      if ((DAT_ffffd3a8 & 0x60) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd357 = '\0';
      }
      else {
        DAT_ffffd357 = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == '\a') {
          DAT_ffffd371 = (char)((ushort)DAT_ffffd352 >> 8);
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0x60) == 0) {
        DAT_ffffd357 = '\0';
      }
    }
  }
  if (DAT_ffffd357 == '\0') {
    DAT_ffffd371 = -0x80;
  }
  else if (DAT_ffffd357 == '\a') {
    fVar1 = (float)FUN_00002500(0x3b800000,0xbf000000,(int)DAT_ffffd371);
    param_1 = param_1 + fVar1;
  }
  return param_1;
}


