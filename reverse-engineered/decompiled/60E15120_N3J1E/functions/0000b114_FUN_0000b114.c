/* ROM address: 0x0000b114; body bytes: 130; decompiled */

void FUN_0000b114(char param_1)

{
  short sVar1;
  undefined4 uVar2;
  short sVar3;
  undefined4 uVar4;
  short sVar5;
  undefined4 local_20 [2];
  
  sVar3 = 0x10;
  uVar2 = 0x10;
  if (param_1 == '\0') {
    uVar4 = uVar2;
    uVar2 = 0x2d;
    sVar5 = sVar3;
    sVar3 = 0;
  }
  else {
    sVar5 = 0;
    uVar4 = 5;
  }
  ref_setSR_PARAM(local_20,0xe0);
  sVar1 = ATUII_TCNT1A_W;
  FUN_0000a8a4(0xfffff64c,uVar2);
  ATUII_GR1G_W = sVar5 + sVar1 + 4;
  FUN_0000a8a4(0xfffff64e,uVar4);
  ATUII_GR1H_W = sVar3 + sVar1 + 4;
  FUN_0000a8a4(0xfffff65e,1);
  ATUII_OCR2H_W = sVar1 + 0x12;
  FUN_00002064(local_20[0]);
  return;
}


