/* ROM address: 0x0005a92c; body bytes: 184; decompiled */

uint FUN_0005a92c(void)

{
  char cVar1;
  byte bVar3;
  uint uVar2;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  
  uVar7 = 0;
  fVar4 = (float)FUN_00002500(0x39cdc3b7,0,(int)DAT_ffffce60);
  cVar1 = DAT_ffffd201;
  bVar3 = FUN_0003eaa4(&DAT_ffff9000,0);
  DAT_ffffd2bc = fVar4 - DAT_ffffd2c8;
  if (DAT_ffffd2bc < 0.0) {
    DAT_ffffd2bc = DAT_ffffd2bc + 0.09968603;
  }
  if ((((DAT_ffffd2cc == '\0') && (bVar3 == 1)) || (DAT_ffffd2c2 == '\0')) || (cVar1 == '\x01')) {
    uVar2 = FUN_0003ec20(uVar7,&DAT_ffff911c);
  }
  else {
    uVar2 = (uint)bVar3;
    if (uVar2 == 1) {
      fVar5 = (float)FUN_0003eb72(uVar7,&DAT_ffff911c);
      fVar6 = fVar5 + DAT_ffffd2bc;
      if (65535.0 < fVar5 + DAT_ffffd2bc) {
        fVar6 = 65535.0;
      }
      uVar2 = FUN_0003ec20(fVar6,&DAT_ffff911c);
    }
  }
  DAT_ffffd2cc = bVar3;
  DAT_ffffd2c8 = fVar4;
  return uVar2;
}


