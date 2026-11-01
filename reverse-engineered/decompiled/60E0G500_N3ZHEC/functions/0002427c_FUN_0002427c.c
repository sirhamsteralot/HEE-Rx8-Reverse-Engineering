/* ROM address: 0x0002427c; body bytes: 90; decompiled */

void FUN_0002427c(void)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  byte bVar4;
  
  FUN_0002432a();
  uVar1 = FUN_00003920(0x10);
  DAT_ffffb4e6 = 0;
  bVar4 = 0;
  DAT_ffffb4b0 = 0xa55a;
  iVar3 = 0;
  do {
    bVar4 = bVar4 + 1;
    DAT_ffffb4e6 = DAT_ffffb4e6 + *(short *)((int)&DAT_ffffb4b0 + iVar3);
    iVar3 = iVar3 + 2;
  } while (bVar4 < 0x1b);
  cVar2 = FUN_0000b886(&DAT_ffffb4b0,0x1c);
  if (cVar2 != '\0') {
    DAT_ffffb4ab = 1;
  }
  FUN_00003934(uVar1);
  return;
}


