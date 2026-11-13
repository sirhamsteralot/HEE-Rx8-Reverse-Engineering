/* ROM address: 0x00026a42; body bytes: 94; decompiled */

undefined4 FUN_00026a42(void)

{
  short sVar1;
  short sVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffb688 = 0;
    DAT_ffffb68a = 0;
    DAT_ffffb68c = 0;
    DAT_ffffb68e = 0;
    DAT_ffffb694 = 0;
    return 1;
  }
  if ((sector_parity_bank_ffffb660 & 1) == 1) {
    sVar1 = -0x4974;
    sVar2 = -0x4978;
    cVar3 = DAT_ffffba24;
    cVar4 = DAT_ffffba26;
  }
  else {
    sVar1 = -0x4972;
    sVar2 = -0x4976;
    cVar3 = DAT_ffffba25;
    cVar4 = DAT_ffffba27;
  }
  uVar5 = FUN_00026b34((int)cVar3,(int)cVar4,(int)sVar2,(int)sVar1);
  return uVar5;
}


