/* ROM address: 0x00012294; body bytes: 174; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00012314) */

void FUN_00012294(void)

{
  char cVar1;
  float *pfVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  uVar4 = 0x3727c5ac;
  fVar3 = DAT_ffffb5b8;
  cVar1 = FUN_00002440(DAT_ffffa790,0,0x3727c5ac);
  FUN_00002440(DAT_ffffbce4,uVar5,uVar4);
  if ((((DAT_ffffaada != '\x01') || (cVar1 != '\0')) || (2000.0 <= fVar3)) ||
     (DAT_ffffce58 != '\x01')) {
    fVar3 = DAT_ffffa640;
    if ((DAT_ffffbc36 != '\0') || (DAT_ffffa9b8 <= 0.0)) goto LAB_00012326;
    pfVar2 = (float *)&DAT_ffffa9a8;
  }
  else {
    pfVar2 = (float *)&DAT_0006e3d8;
  }
  fVar3 = *pfVar2;
LAB_00012326:
  DAT_ffffa63c = rx8_clamp_float(fVar3,DAT_ffffa658,65.0);
  return;
}


