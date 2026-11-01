/* ROM address: 0x00027606; body bytes: 94; decompiled */

undefined4 FUN_00027606(void)

{
  short sVar1;
  short sVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffb6f8 = 0;
    DAT_ffffb6fa = 0;
    DAT_ffffb6fc = 0;
    DAT_ffffb6fe = 0;
    DAT_ffffb704 = 0;
    return 1;
  }
  if ((DAT_ffffb6d0 & 1) == 1) {
    sVar1 = -0x4904;
    sVar2 = -0x4908;
    cVar3 = DAT_ffffba90;
    cVar4 = DAT_ffffba92;
  }
  else {
    sVar1 = -0x4902;
    sVar2 = -0x4906;
    cVar3 = DAT_ffffba91;
    cVar4 = DAT_ffffba93;
  }
  uVar5 = FUN_000276f8((int)cVar3,(int)cVar4,(int)sVar2,(int)sVar1);
  return uVar5;
}


