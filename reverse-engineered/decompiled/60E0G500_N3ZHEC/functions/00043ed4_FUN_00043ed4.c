/* ROM address: 0x00043ed4; body bytes: 154; decompiled */

int FUN_00043ed4(void)

{
  char cVar2;
  int iVar1;
  float extraout_fr0;
  float fVar3;
  float fVar4;
  
  fVar3 = 0.0;
  fVar4 = DAT_ffffca94;
  cVar2 = FUN_00002440(DAT_ffffca94,0,0x3727c5ac);
  if (cVar2 != '\0') {
    DAT_ffffcaa8 = ((1.0 / fVar4) * 2000.0) / DAT_ffffca80;
  }
  iVar1 = FUN_00002500(0x3f800000,fVar3,(int)DAT_ffffcaaf);
  DAT_ffffca44 = fVar3;
  if (extraout_fr0 < DAT_ffffcaa8) {
    DAT_ffffca44 = DAT_ffffca48 / DAT_ffffca5c;
    if (DAT_ffffcab9 == '\x01') {
      DAT_ffffca44 = DAT_ffffca44 * 0.25;
      iVar1 = 1;
    }
    else {
      iVar1 = (int)DAT_ffffcab8;
      if (iVar1 == 0) {
        DAT_ffffca44 = DAT_ffffca44 * 0.15;
      }
    }
  }
  return iVar1;
}


