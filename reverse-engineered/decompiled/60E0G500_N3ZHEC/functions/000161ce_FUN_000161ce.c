/* ROM address: 0x000161ce; body bytes: 408; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000161f4) */

undefined4 FUN_000161ce(void)

{
  short sVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  
  uVar5 = 0;
  fVar4 = DAT_ffffa7b8;
  fVar2 = (float)FUN_0003eb72(0,&DAT_ffff8040);
  fVar3 = (float)FUN_0003eb72(uVar5,&DAT_ffff8048);
  if (DAT_ffffb5a4 == '\0') {
    if (DAT_ffffa8a0 == '\x01') {
      if (DAT_ffffb5ac == '\0') {
        if (fVar4 < 0.005) {
          if (fVar4 <= -0.005) {
            fVar2 = fVar2 - 1e-05;
          }
        }
        else {
          fVar2 = fVar2 + 1e-05;
        }
        fVar4 = rx8_clamp_float(fVar2,-0.12,0.12);
        FUN_0003ec20(fVar4,&DAT_ffff8040);
        fVar6 = fVar3 + 0.03;
        fVar2 = fVar3 - 0.03;
        fVar4 = (float)FUN_0003eb72(uVar5,&DAT_ffff8040);
        if (fVar4 <= fVar6) {
          if (fVar4 < fVar2) {
            fVar3 = fVar4 + 0.03;
          }
        }
        else {
          fVar3 = fVar4 - 0.03;
        }
        fVar4 = rx8_clamp_float(fVar3,-0.12,0.12);
        sVar1 = -0x7fb8;
      }
      else {
        if (fVar4 < 0.005) {
          if (fVar4 <= -0.005) {
            fVar3 = fVar3 - 1e-05;
          }
        }
        else {
          fVar3 = fVar3 + 1e-05;
        }
        fVar4 = rx8_clamp_float(fVar3,-0.12,0.12);
        FUN_0003ec20(fVar4,&DAT_ffff8048);
        fVar3 = fVar2 + 0.03;
        fVar6 = fVar2 - 0.03;
        fVar4 = (float)FUN_0003eb72(uVar5,&DAT_ffff8048);
        if (fVar4 <= fVar3) {
          if (fVar4 < fVar6) {
            fVar2 = fVar4 + 0.03;
          }
        }
        else {
          fVar2 = fVar4 - 0.03;
        }
        fVar4 = rx8_clamp_float(fVar2,-0.12,0.12);
        sVar1 = -0x7fc0;
      }
      uVar5 = FUN_0003ec20(fVar4,(int)sVar1);
    }
    else {
      fVar4 = rx8_clamp_float(fVar2,-0.12,0.12);
      FUN_0003ec20(fVar4,&DAT_ffff8040);
      fVar4 = rx8_clamp_float(fVar3,-0.12,0.12);
      uVar5 = FUN_0003ec20(fVar4,&DAT_ffff8048);
    }
  }
  else {
    if (DAT_ffffa8a0 == '\x01') {
      if (fVar4 < 0.005) {
        if (fVar4 <= -0.005) {
          fVar2 = fVar2 - 1e-05;
        }
      }
      else {
        fVar2 = fVar2 + 1e-05;
      }
    }
    fVar4 = rx8_clamp_float(fVar2,-0.12,0.12);
    uVar5 = FUN_0003ec20(fVar4,&DAT_ffff8040);
  }
  return uVar5;
}


