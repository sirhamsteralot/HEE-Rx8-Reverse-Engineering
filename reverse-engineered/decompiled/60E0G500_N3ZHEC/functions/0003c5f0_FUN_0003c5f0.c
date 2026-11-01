/* ROM address: 0x0003c5f0; body bytes: 236; decompiled */

uint FUN_0003c5f0(void)

{
  uint uVar1;
  float fVar2;
  float extraout_fr0;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  
  uVar4 = 0;
  fVar5 = DAT_ffffcfcc;
  fVar2 = (float)FUN_0003eb72(0,&DAT_ffff86a4);
  if (fVar2 < 100.0) {
    if (fVar2 < 99.9) {
      DAT_ffffc62f = '\0';
    }
  }
  else {
    DAT_ffffc62f = '\x01';
  }
  if (fVar2 < 0.0) {
    if (fVar2 < -0.1) {
      DAT_ffffc630 = '\0';
    }
  }
  else {
    DAT_ffffc630 = '\x01';
  }
  if ((DAT_ffffc630 == '\x01') && (DAT_ffffc62f == '\0')) {
    DAT_ffffc61c = 1;
  }
  else {
    DAT_ffffc61c = 0;
  }
  uVar3 = 0x42c80000;
  if (DAT_ffffd201 == '\x01') {
    FUN_0003ec20(uVar4,&DAT_ffff8714);
    FUN_0003ec20(uVar3,&DAT_ffff871c);
    uVar1 = FUN_0003ec20(uVar4,&DAT_ffff8724);
  }
  else {
    uVar1 = (uint)DAT_ffffc61c;
    if (uVar1 == 1) {
      fVar2 = (float)FUN_0003eb72(0x42c80000,&DAT_ffff871c);
      if (fVar5 < fVar2) {
        FUN_0003ec20(fVar5,&DAT_ffff871c);
      }
      uVar1 = FUN_0003eb72(uVar4,&DAT_ffff8724);
      if (extraout_fr0 < fVar5) {
        uVar1 = FUN_0003ec20(fVar5,&DAT_ffff8724);
      }
    }
  }
  return uVar1;
}


