/* ROM address: 0x0005a714; body bytes: 238; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00058ecc (238 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0005a714(void)

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
  
  FUN_00037ef0(100,local_2c,3,in_r7,&DAT_0005f6e8,local_2c);
  uVar3 = 0xff;
  uStack_29 = uVar3;
  FUN_00037ef0(0x68,&uStack_28,1);
  uStack_27 = uVar3;
  FUN_00037ef0(0x6a,auStack_26,2);
  FUN_00037ef0(0x6c,&uStack_24,1);
  psVar6 = &DAT_ffffd2b2;
  psVar5 = &DAT_ffffd2b0;
  uVar7 = 0;
  pcVar4 = &DAT_ffffd2b4;
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


