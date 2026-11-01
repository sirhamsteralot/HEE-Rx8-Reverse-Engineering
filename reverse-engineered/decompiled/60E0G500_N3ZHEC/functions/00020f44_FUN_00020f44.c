/* ROM address: 0x00020f44; body bytes: 390; decompiled */

uint FUN_00020f44(void)

{
  char cVar1;
  char cVar2;
  char cVar4;
  uint uVar3;
  float fVar5;
  float fVar6;
  
  cVar2 = DAT_ffffa445;
  cVar1 = DAT_ffffa444;
  fVar5 = DAT_ffffb35c;
  fVar6 = DAT_ffffbf24;
  cVar4 = FUN_00002440(DAT_ffffb35c,0,0x3727c5ac);
  if (DAT_ffffaada == '\0') {
    DAT_ffffb2a8 = 0;
  }
  else if (((DAT_ffffb2b2 == '\x01') && (cVar1 == '\0')) ||
          ((DAT_ffffb2b3 == '\x01' && (cVar2 == '\0')))) {
    DAT_ffffb2a8 = 1;
  }
  if (((((((DAT_ffffae97 != '\x01') || (DAT_ffffb366 != '\x01')) || (cVar4 == '\0')) ||
        ((DAT_ffffd299 != '\0' || (DAT_ffffd12e != '\0')))) ||
       ((-0.015 <= fVar6 && (fVar6 < 0.015)))) || ((DAT_ffffb2a8 == 1 && (DAT_ffffb2ac < 0x26)))) ||
     ((fVar5 < 0.25 && (fVar5 = (float)FUN_0003eb72(DAT_ffff9f60,&DAT_ffff80e4), fVar5 < 50.0)))) {
    DAT_ffffb298 = 0;
  }
  else {
    if (fVar6 < 0.015) {
      DAT_ffffb2a0 = 0x38a7c5ac;
      DAT_ffffb298 = 2;
      fVar5 = DAT_ffffb290 + 8e-05;
    }
    else {
      fVar5 = DAT_ffffb290 - 8e-05;
      DAT_ffffb298 = 1;
    }
    DAT_ffffb290 = rx8_clamp_float(fVar5,-0.05,0.15);
  }
  uVar3 = (uint)DAT_ffffb2a8;
  if (uVar3 == 1) {
    uVar3 = FUN_00002460((int)(short)DAT_ffffb2ac,1);
    DAT_ffffb2ac = (ushort)uVar3;
  }
  else {
    DAT_ffffb2ac = 0;
  }
  DAT_ffffb2b2 = cVar1;
  DAT_ffffb2b3 = cVar2;
  return uVar3;
}


