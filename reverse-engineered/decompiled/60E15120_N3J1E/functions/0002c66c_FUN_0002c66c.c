/* ROM address: 0x0002c66c; body bytes: 198; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0002c728) */

int FUN_0002c66c(void)

{
  float fVar1;
  
  DAT_ffffbc68 = DAT_ffffbca8 * 0.75;
  DAT_ffffbc6c = DAT_ffffbca8 * 0.5;
  fVar1 = DAT_ffffbca8 - DAT_ffffa934;
  DAT_ffffbc70 = DAT_ffffbca8 * 0.25;
  if (fVar1 <= DAT_ffffbc68) {
    if (fVar1 <= DAT_ffffbc68 - 3.0) {
      DAT_ffffbc8a = '\0';
    }
  }
  else {
    DAT_ffffbc8a = '\x01';
  }
  if ((DAT_ffffbc8a == '\x01') || (DAT_ffffa92c < DAT_ffffa930)) {
    DAT_ffffbc80 = '\0';
  }
  else if (4.9 < DAT_ffffa934) {
    if (0.75 < fVar1) {
      if (DAT_ffffbca8 * 0.25 < fVar1) {
        if (DAT_ffffbca8 * 0.5 < fVar1) {
          if (fVar1 <= DAT_ffffbc68) {
            DAT_ffffbc80 = '\x01';
          }
        }
        else {
          DAT_ffffbc80 = '\x02';
        }
      }
      else {
        DAT_ffffbc80 = '\x03';
      }
    }
    else {
      DAT_ffffbc80 = '\x04';
    }
  }
  DAT_ffffbc81 = DAT_ffffbc80;
  return (int)DAT_ffffbc80;
}


