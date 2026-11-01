/* ROM address: 0x00031b2c; body bytes: 738; decompiled */

int FUN_00031b2c(void)

{
  undefined4 uVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  float *pfVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fStack_3c;
  float fStack_34;
  
  bVar2 = DAT_ffffbf78;
  uVar1 = DAT_ffffaa10;
  fVar11 = 0.0;
  fVar12 = 6e+07;
  fVar8 = DAT_ffffbf34;
  if (DAT_ffffbf3a == '\0') {
    fStack_3c = (float)FUN_0003ea74(DAT_ffffbf5c * 1.0 * 6e+07);
    fStack_34 = fVar11;
  }
  else {
    if (DAT_ffffbf7c == '\0') {
      if (DAT_ffffbf34 + DAT_ffffbf54 <= DAT_ffffbf5c) {
        fVar10 = DAT_ffffbf34 * 1.0;
        fVar7 = (DAT_ffffbf5c - DAT_ffffbf34) * 1.0;
        fVar9 = fVar7;
      }
      else {
        fVar7 = (DAT_ffffbf5c - DAT_ffffbf54) * 1.0;
        fVar9 = DAT_ffffbf54 * 1.0;
        fVar10 = fVar7;
      }
      fVar10 = fVar10 * 6e+07;
      fVar9 = fVar9 * 6e+07;
    }
    else if (DAT_ffffbf7d == '\0') {
      fVar7 = (DAT_ffffbf5c - DAT_ffffbf58) * 1.0;
      fVar10 = fVar7 * 6e+07;
      fVar9 = DAT_ffffbf58 * 1.0 * 6e+07;
    }
    else {
      fVar7 = DAT_ffffbf5c;
      fVar9 = DAT_ffffbf4c;
      fVar10 = DAT_ffffbf44;
      if (DAT_ffffbf5c < DAT_ffffbf44 + DAT_ffffbf4c) {
        fVar7 = (DAT_ffffbf5c - DAT_ffffbf44) * 1.0;
        fVar9 = fVar7;
        fVar10 = DAT_ffffbf44 * 1.0;
      }
      fVar10 = fVar10 * 6e+07;
      fVar9 = fVar9 * 6e+07;
    }
    fStack_3c = (float)FUN_0003ea74(fVar10,0x43b8bc6a,fVar7);
    fStack_34 = (float)FUN_0003ea74(fVar9,0x43edf70a);
  }
  fVar10 = 1e-05;
  cVar3 = FUN_00002440(0x43b8bc6a,fVar11,0x3727c5ac);
  DAT_ffffbf6c = fVar11;
  if (cVar3 != '\0') {
    DAT_ffffbf6c = fStack_3c;
  }
  cVar4 = FUN_00002440(0x43edf70a,fVar11,fVar10);
  iVar6 = 0;
  DAT_ffffbf30 = fVar11;
  if (cVar4 != '\0') {
    DAT_ffffbf30 = fStack_34;
  }
  DAT_ffffbf9c = FUN_000020ac(uVar1,&DAT_0006b01c);
  DAT_ffffbf9d = FUN_000020ac(uVar1,&DAT_0006b040);
  if (bVar2 == 0) {
    if (DAT_ffffbf79 == '\0') {
      if (DAT_ffffbf7a == '\0') {
        if (DAT_ffffbf7b == '\0') {
          iVar6 = 1;
          goto LAB_00031da8;
        }
        pfVar5 = (float *)&DAT_00078414;
      }
      else {
        pfVar5 = (float *)&DAT_00078410;
      }
    }
    else {
      pfVar5 = (float *)&DAT_0007840c;
    }
    DAT_ffffbf98 = *pfVar5;
    iVar6 = 4;
  }
  else if ((DAT_ffffbf9c < DAT_ffffbf9d) || ((byte)(DAT_ffffbf9c - DAT_ffffbf9d) < bVar2)) {
    iVar6 = 2;
  }
  else if (bVar2 != (byte)(DAT_ffffbf9c - DAT_ffffbf9d)) {
    iVar6 = 3;
  }
LAB_00031da8:
  if (iVar6 == 0) {
    DAT_ffffbf98 = (float)FUN_00002068(uVar1);
    fVar7 = rx8_first_order_filter(DAT_ffffbf6c,DAT_ffffbf28,DAT_ffffbf98,fVar10);
  }
  else if (iVar6 == 1) {
    DAT_ffffbf28 = DAT_ffffbf6c;
    fVar7 = DAT_ffffbf28;
  }
  else if (iVar6 == 3) {
    DAT_ffffbf98 = (float)FUN_00002068(uVar1);
    fVar8 = rx8_first_order_filter(DAT_ffffbf6c,DAT_ffffbf28,DAT_ffffbf98,fVar10);
    fVar7 = rx8_max_float(DAT_ffffbf6c,fVar8);
  }
  else if (iVar6 == 4) {
    fVar7 = rx8_first_order_filter(DAT_ffffbf6c,DAT_ffffbf28,DAT_ffffbf98,fVar10);
  }
  else {
    fVar7 = fVar11;
    if (cVar3 != '\0') {
      fVar8 = rx8_min_float(DAT_ffffbf1c,fVar8);
      fVar7 = (float)FUN_0003ea74(fVar8 * fVar12,0x43b8bc6a);
    }
  }
  DAT_ffffbf28 = fVar7;
  cVar3 = FUN_00002440(0x43edf70a,fVar11,fVar10);
  cVar4 = FUN_00002440(DAT_ffffbf30,fVar11,fVar10);
  if (cVar3 != 0) {
    if (cVar4 == '\0') {
      fVar11 = (DAT_ffffbf60 * 1.0 * fVar12) / 475.93;
    }
    else {
      fVar11 = DAT_ffffbf2c;
      if (0.0 < DAT_ffffbf30) {
        fVar11 = (DAT_ffffbf60 * 1.0 * fVar12) / 475.93;
      }
    }
  }
  DAT_ffffbf2c = fVar11;
  return (int)cVar3;
}


