/* ROM address: 0x0005aeb8; body bytes: 238; decompiled */

void FUN_0005aeb8(void)

{
  char cVar1;
  undefined1 uVar3;
  short sVar2;
  char *pcVar4;
  short *psVar5;
  undefined4 in_r7;
  short *psVar6;
  uint uVar7;
  undefined1 local_2c [3];
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 auStack_26 [2];
  undefined1 uStack_24;
  undefined1 uStack_23;
  
  FUN_00038ed8(100,local_2c,3,in_r7,&DAT_0005fe8c,local_2c);
  uVar3 = 0xff;
  uStack_29 = uVar3;
  FUN_00038ed8(0x68,&uStack_28,1);
  uStack_27 = uVar3;
  FUN_00038ed8(0x6a,auStack_26,2);
  FUN_00038ed8(0x6c,&uStack_24,1);
  psVar6 = &DAT_ffffd2ee;
  psVar5 = &DAT_ffffd2ec;
  uVar7 = 0;
  pcVar4 = &DAT_ffffd2f0;
  uStack_23 = uVar3;
  do {
    cVar1 = *pcVar4;
    sVar2 = FUN_00003fe8();
    *psVar5 = *psVar5 + sVar2;
    sVar2 = FUN_00004144();
    *psVar6 = *psVar6 + sVar2;
    uVar7 = uVar7 + 2;
    if (cVar1 == -1) {
      *pcVar4 = '\x01';
    }
    else {
      *pcVar4 = *pcVar4 + '\x01';
    }
  } while ((uVar7 & 0xff) < 10);
  return;
}


