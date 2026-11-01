/* ROM address: 0x00046102; body bytes: 290; decompiled */

uint FUN_00046102(void)

{
  char cVar2;
  uint uVar1;
  float *pfVar3;
  float fVar4;
  float fVar5;
  
  fVar5 = DAT_ffffaa34;
  fVar4 = rx8_absolute_difference(DAT_ffffaa30,DAT_ffffaa34);
  if (DAT_ffffcc30 != '\x01') {
    DAT_ffffcc32 = 0;
    goto LAB_0004621a;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff80a0,0);
  if (cVar2 == '\x01') {
    if (fVar5 < 0.6) {
      pfVar3 = (float *)&DAT_0007c378;
      goto LAB_000461cc;
    }
    if (1.2 <= fVar5) {
      if (fVar5 < 2.0) {
        pfVar3 = (float *)&DAT_0007c380;
        goto LAB_00046178;
      }
      if (fVar5 < 4.0) {
        pfVar3 = (float *)&DAT_0007c384;
        goto LAB_00046178;
      }
      fVar5 = 3.5;
    }
    else {
      pfVar3 = (float *)&DAT_0007c37c;
LAB_00046178:
      fVar5 = *pfVar3;
    }
  }
  else {
    pfVar3 = (float *)&DAT_0007c38c;
LAB_000461cc:
    fVar5 = *pfVar3;
  }
  if (fVar4 < fVar5) {
    if (0x18 < DAT_ffffcc32) {
      DAT_ffffcc2e = 0;
      DAT_ffffcc2c = 1;
    }
    DAT_ffffcc32 = FUN_00002460((int)(short)DAT_ffffcc32,1);
  }
  else {
    DAT_ffffcc32 = 0;
    DAT_ffffcc2e = FUN_00002460((int)(short)DAT_ffffcc2e,1);
    if (0x1c < DAT_ffffcc2e) {
      FUN_0003ebc0(&DAT_ffff8754,1);
    }
  }
LAB_0004621a:
  cVar2 = FUN_0003eaa4(&DAT_ffff8754,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_000604dc(0x6c,1);
    return uVar1;
  }
  if (DAT_ffffcc2c == 1) {
    uVar1 = FUN_000604dc(0x6c,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc2c;
}


