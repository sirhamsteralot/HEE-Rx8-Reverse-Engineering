/* ROM address: 0x0005ab98; body bytes: 358; decompiled */

uint FUN_0005ab98(void)

{
  short sVar3;
  undefined4 uVar1;
  byte bVar4;
  uint uVar2;
  uint uVar5;
  uint *puVar6;
  byte *pbVar7;
  
  pbVar7 = &DAT_ffffd2f0;
  puVar6 = &DAT_ffffd2e8;
  if (DAT_ffffd317 == '\x01') {
    DAT_ffffd317 = '\0';
    DAT_ffffd2e8 = 0x2000;
    DAT_ffffd2f0 = 1;
    DAT_ffffd2ec = 0;
    DAT_ffffd2ee = 0;
    DAT_ffffd2f2 = '\x01';
    DAT_ffffd2f3 = '\0';
  }
  if (DAT_ffffd2f2 == '\x01') {
    uVar2 = 0;
    while ((uVar2 < 0x1000 && (DAT_ffffd2e8 < 0x80000))) {
      if (((undefined2 *)*puVar6 < &DAT_0007fb00) || ((int)&PTR_0007fb7c + 3U < *puVar6)) {
        uVar5 = (uint)*pbVar7;
        sVar3 = FUN_00003fe8();
        DAT_ffffd2ec = DAT_ffffd2ec + sVar3;
        sVar3 = FUN_00004144();
        DAT_ffffd2ee = DAT_ffffd2ee + sVar3;
        if ((int)uVar5 < 0xff) {
          *pbVar7 = *pbVar7 + 1;
        }
        else {
          *pbVar7 = 1;
        }
      }
      uVar2 = uVar2 + 2;
      *puVar6 = *puVar6 + 2;
    }
    if (0x7ffff < *puVar6) {
      FUN_0005aeb8();
      DAT_ffffd2f3 = '\x01';
    }
    if (DAT_ffffd2f3 == '\x01') {
      DAT_ffffd2f2 = '\0';
      uVar2 = (uint)DAT_ffffd2ec;
      uVar5 = (uint)DAT_ffffd2ee;
      uVar1 = FUN_00003920(0x10);
      FUN_0003ebe0(&DAT_ffff912c,uVar2 * 0x10000 + uVar5);
      FUN_0003ebc0(&DAT_ffff9134,1);
      FUN_00003934(uVar1);
    }
  }
  bVar4 = FUN_0003eaa4(&DAT_ffff9134,0);
  FUN_0003eb24(&DAT_ffff912c,0);
  uVar2 = (uint)DAT_ffffd318;
  if (((uVar2 == 1) && (uVar2 = (uint)bVar4, uVar2 == 1)) && (DAT_ffffc6ac == '\0')) {
    DAT_ffffd318 = 0;
    uVar2 = FUN_00066c20();
    return uVar2;
  }
  return uVar2;
}


