/* ROM address: 0x0004394c; body bytes: 102; decompiled */

void FUN_0004394c(void)

{
  float fVar1;
  float fVar2;
  
  if (((DAT_ffffcab6 == '\x01') && (DAT_ffffcb08 < 4)) || (DAT_ffffaada == '\x01')) {
    if ((DAT_ffffcab8 == '\x01') || (DAT_ffffaada == '\x01')) {
      DAT_ffffcaa4 = DAT_ffffaa40;
    }
    else {
      fVar2 = DAT_ffffaa40;
      fVar1 = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006bbf0);
      DAT_ffffcaa4 = fVar2 - fVar1;
    }
  }
  DAT_ffffcb08 = DAT_ffffcab1;
  return;
}


