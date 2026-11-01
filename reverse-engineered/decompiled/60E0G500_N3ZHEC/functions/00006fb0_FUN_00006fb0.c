/* ROM address: 0x00006fb0; body bytes: 174; decompiled */

int FUN_00006fb0(void)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  byte bVar4;
  byte bVar5;
  undefined4 uVar6;
  
  bVar1 = false;
  uVar6 = FUN_00003920(0x90);
  bVar4 = DAT_fffff858;
  bVar5 = DAT_fffff859;
  bVar2 = (bVar5 & 0x20) == 0;
  if (bVar2) {
    bVar5 = DAT_fffff858;
    bVar1 = (bVar5 & 0x80) != 0;
  }
  else {
    bVar5 = DAT_fffff859;
    DAT_fffff859 = bVar5 & 0xdf;
    bVar5 = DAT_fffff858;
    DAT_fffff858 = bVar5 & 0x7f;
  }
  bVar5 = DAT_fffff859;
  DAT_fffff859 = bVar5 & 0xdf;
  DAT_fffff858 = 0x18;
  bVar5 = DAT_fffff859;
  DAT_fffff859 = bVar5 & 0x2f | 0x20;
  do {
    bVar5 = DAT_fffff858;
  } while ((bVar5 & 0x80) == 0);
  sVar3 = DAT_fffff840;
  DAT_fffff858 = bVar4 | 0x80;
  if (bVar2) {
    if (!bVar1) {
      bVar4 = DAT_fffff858;
      DAT_fffff858 = bVar4 & 0x7f;
    }
  }
  else {
    bVar4 = DAT_fffff859;
    DAT_fffff859 = bVar4 & 0xdf;
    bVar4 = DAT_fffff858;
    DAT_fffff858 = bVar4 & 0x7f;
    bVar4 = DAT_fffff859;
    DAT_fffff859 = bVar4 | 0x20;
  }
  FUN_00003934(uVar6);
  return (int)sVar3;
}


