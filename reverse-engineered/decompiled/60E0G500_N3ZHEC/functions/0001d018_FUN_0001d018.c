/* ROM address: 0x0001d018; body bytes: 104; decompiled */

void FUN_0001d018(void)

{
  char cVar1;
  char cVar2;
  
  cVar2 = DAT_ffffbfd4;
  cVar1 = DAT_ffffb5aa;
  if ((DAT_ffffbfd4 == '\0') && (DAT_ffffb0de == '\x01')) {
    DAT_ffffb0d4 = 0;
  }
  else {
    DAT_ffffb0d4 = FUN_00002478((int)DAT_ffffb0d4,1);
  }
  if ((cVar1 == '\x01') && (DAT_ffffb0df == '\0')) {
    DAT_ffffb0d5 = 0;
  }
  else {
    DAT_ffffb0d5 = FUN_00002478((int)DAT_ffffb0d5,1);
  }
  DAT_ffffb0de = cVar2;
  DAT_ffffb0df = cVar1;
  return;
}


