/* ROM address: 0x0001f99a; body bytes: 240; decompiled */

undefined4 FUN_0001f99a(void)

{
  char cVar1;
  undefined4 uVar2;
  float fVar3;
  float extraout_fr0;
  float fVar4;
  float fVar5;
  
  cVar1 = DAT_ffffcb38;
  fVar5 = 0.0;
  if (DAT_ffffb178 == '\0') {
    DAT_ffffb180 = 0;
    uVar2 = FUN_0003ec20(0,&DAT_ffff8124);
    fVar4 = fVar5;
  }
  else {
    DAT_ffffb180 = FUN_00002460((int)(short)DAT_ffffb180,1);
    fVar3 = (float)FUN_0003eb72(fVar5,&DAT_ffff8124);
    fVar3 = DAT_ffffb0e4 + fVar3;
    uVar2 = FUN_0003ec20(fVar3,&DAT_ffff8124);
    fVar4 = fVar5;
    if (DAT_ffffb180 != 0) {
      uVar2 = FUN_000024c0(0x3f800000,fVar5,(int)(short)DAT_ffffb180);
      fVar4 = fVar3 / extraout_fr0;
    }
  }
  DAT_ffffb17c = fVar4;
  if (0x1ff < DAT_ffffb180) {
    DAT_ffffb180 = 0;
    fVar4 = rx8_clamp_float(DAT_ffffb17c,-0.01,0.01);
    FUN_0003ec20(fVar4,&DAT_ffff8114);
    DAT_ffffb17c = fVar5;
    uVar2 = FUN_0003ec20(fVar5,&DAT_ffff8124);
  }
  if (cVar1 != DAT_ffffb187) {
    DAT_ffffb180 = 0;
    if (cVar1 == '\x01') {
      uVar2 = FUN_0003eb72(fVar5,&DAT_ffff8114);
      fVar4 = fVar5;
      FUN_0003ec20(uVar2,&DAT_ffff811c);
      fVar5 = fVar4;
    }
    else {
      fVar4 = (float)FUN_0003eb72(fVar5,&DAT_ffff811c);
    }
    FUN_0003ec20(fVar4,&DAT_ffff8114);
    DAT_ffffb17c = fVar5;
    uVar2 = FUN_0003ec20(fVar5,&DAT_ffff8124);
  }
  DAT_ffffb187 = cVar1;
  return uVar2;
}


