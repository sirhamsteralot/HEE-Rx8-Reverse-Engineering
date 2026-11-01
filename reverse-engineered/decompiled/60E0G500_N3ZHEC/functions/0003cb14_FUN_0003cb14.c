/* ROM address: 0x0003cb14; body bytes: 194; decompiled */

uint FUN_0003cb14(void)

{
  uint uVar1;
  char cVar2;
  float extraout_fr0;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc623 = 0;
    DAT_ffffc624 = 0;
    uVar1 = 1;
  }
  else {
    uVar6 = 0;
    uVar1 = FUN_0003eb72(0,&DAT_ffff8714);
    if (100000.0 <= extraout_fr0) {
      if ((DAT_ffffc621 == '\0') && (cVar2 = FUN_000671a4(0x33), cVar2 == '\0')) {
        fVar3 = (float)FUN_0003eb72(uVar6,&DAT_ffff8724);
        fVar4 = (float)FUN_0003eb72(0x42c80000,&DAT_ffff871c);
        if (-100.0 <= fVar3 - fVar4) {
          cVar2 = FUN_000671a4(0x33);
          if (cVar2 == '\0') {
            DAT_ffffc624 = 1;
            DAT_ffffc623 = 0;
          }
        }
        else {
          DAT_ffffc623 = 1;
          DAT_ffffc624 = 0;
        }
      }
      uVar1 = (uint)DAT_ffffc61c;
      if (uVar1 == 1) {
        uVar5 = DAT_ffffcfcc;
        FUN_0003ec20(uVar6,&DAT_ffff8714);
        FUN_0003ec20(uVar5,&DAT_ffff871c);
        uVar1 = FUN_0003ec20(uVar5,&DAT_ffff8724);
      }
    }
  }
  return uVar1;
}


