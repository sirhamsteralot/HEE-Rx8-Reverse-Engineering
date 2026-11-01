/* ROM address: 0x0002d260; body bytes: 198; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0002d31c) */

int FUN_0002d260(void)

{
  float fVar1;
  
  DAT_ffffbcd4 = DAT_ffffbd14 * 0.75;
  DAT_ffffbcd8 = DAT_ffffbd14 * 0.5;
  fVar1 = DAT_ffffbd14 - DAT_ffffa9b8;
  DAT_ffffbcdc = DAT_ffffbd14 * 0.25;
  if (fVar1 <= DAT_ffffbcd4) {
    if (fVar1 <= DAT_ffffbcd4 - 3.0) {
      DAT_ffffbcf6 = '\0';
    }
  }
  else {
    DAT_ffffbcf6 = '\x01';
  }
  if ((DAT_ffffbcf6 == '\x01') || (DAT_ffffa9b0 < DAT_ffffa9b4)) {
    DAT_ffffbcec = '\0';
  }
  else if (4.9 < DAT_ffffa9b8) {
    if (0.75 < fVar1) {
      if (DAT_ffffbd14 * 0.25 < fVar1) {
        if (DAT_ffffbd14 * 0.5 < fVar1) {
          if (fVar1 <= DAT_ffffbcd4) {
            DAT_ffffbcec = '\x01';
          }
        }
        else {
          DAT_ffffbcec = '\x02';
        }
      }
      else {
        DAT_ffffbcec = '\x03';
      }
    }
    else {
      DAT_ffffbcec = '\x04';
    }
  }
  DAT_ffffbced = DAT_ffffbcec;
  return (int)DAT_ffffbcec;
}


