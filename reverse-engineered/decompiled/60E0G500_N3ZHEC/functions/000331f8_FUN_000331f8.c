/* ROM address: 0x000331f8; body bytes: 600; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003322e) */

void FUN_000331f8(void)

{
  float arg1;
  float fVar1;
  float fVar2;
  float fVar3;
  float arg1_00;
  float fVar4;
  
  arg1_00 = 0.0;
  fVar3 = DAT_ffffc008;
  fVar4 = DAT_ffffc00c;
  arg1 = (float)FUN_0003eb72(0,&DAT_ffff8694);
  if (DAT_ffffc01c == '\x01') {
    fVar1 = rx8_max_float(fVar3,27.0);
    fVar2 = fVar1;
  }
  else {
    fVar1 = arg1;
    fVar2 = arg1;
    if ((((fVar3 < arg1) || (DAT_ffffc01d != '\x01')) &&
        ((DAT_ffffbd58 != '\0' || ((DAT_ffffc03a != '\x01' || (DAT_ffffc01d != '\0')))))) &&
       ((((DAT_ffffc022 != '\0' || (DAT_ffffc021 != '\0')) ||
         (((fVar3 - arg1 < 0.0 || (1.6 < fVar3 - arg1)) &&
          ((arg1 - fVar3 < 0.0 || (0.5 < arg1 - fVar3)))))) ||
        ((DAT_ffffc03a != '\x01' || (DAT_ffffc01d != '\0')))))) {
      if ((arg1 <= fVar3) || (DAT_ffffc01d != '\x01')) {
        fVar1 = arg1_00;
        fVar2 = fVar4;
        if (((DAT_ffffbd55 != '\x01') && (fVar1 = arg1, fVar2 = 27.0, DAT_ffffbd59 != '\0')) &&
           (DAT_ffffc02c != '\x01')) {
          if (DAT_ffffc01e == '\x01') {
            fVar1 = rx8_max_float(arg1 - 1.6,27.0);
            fVar2 = fVar1;
          }
          else if (DAT_ffffc020 == '\x01') {
            fVar1 = arg1 + 1.6;
            fVar2 = arg1 + 1.6;
          }
          else if (DAT_ffffc022 == '\x01') {
            if ((DAT_ffffc038 == '\0') || ((DAT_ffffc03a == '\x01' && (DAT_ffffc01d == '\0')))) {
              fVar3 = 16.0;
            }
            else {
              fVar3 = 0.1;
            }
            fVar2 = fVar4 - fVar3;
          }
          else {
            fVar2 = fVar4;
            if (DAT_ffffc021 == '\x01') {
              if ((DAT_ffffc039 == '\0') || ((DAT_ffffc03a == '\x01' && (DAT_ffffc01d == '\0')))) {
                fVar3 = 1.0;
              }
              else {
                fVar3 = 0.025;
              }
              fVar2 = fVar3 + fVar4;
            }
          }
        }
      }
      else {
        if (DAT_ffffc03a == '\0') {
          fVar3 = fVar3 + 0.0;
        }
        else {
          fVar3 = fVar4 + 0.025;
        }
        fVar2 = rx8_min_float(fVar3,arg1);
        fVar1 = arg1;
      }
    }
  }
  if (DAT_ffffbdb5 == '\x01') {
    DAT_ffffc014 = 100.0;
  }
  else {
    DAT_ffffc014 = 200.0;
  }
  fVar3 = rx8_clamp_float(fVar1,arg1_00,DAT_ffffc014);
  FUN_0003ec20(fVar3,&DAT_ffff8694);
  DAT_ffffc00c = rx8_clamp_float(fVar2,27.0,DAT_ffffc014);
  DAT_ffffc010 = DAT_ffffc00c;
  DAT_ffffc02c = '\0';
  DAT_ffffc03a = DAT_ffffc01d;
  DAT_ffffc038 = DAT_ffffc022;
  DAT_ffffc039 = DAT_ffffc021;
  return;
}


