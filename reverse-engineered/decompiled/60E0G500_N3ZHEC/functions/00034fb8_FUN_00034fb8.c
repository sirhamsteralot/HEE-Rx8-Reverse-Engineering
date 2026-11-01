/* ROM address: 0x00034fb8; body bytes: 140; decompiled */

void FUN_00034fb8(void)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = DAT_ffffb13d;
  if ((DAT_ffffc1c8 < -0.01318) || (DAT_ffffa428 == '\0')) {
    DAT_ffffc184 = 0x3f800000;
  }
  else {
    if ((((DAT_ffffaa10 < -40.0) || (DAT_ffffc1d8 < 0x10)) || (DAT_ffffb13d != '\0')) ||
       (DAT_ffffc1bd != '\x01')) {
      DAT_ffffc1bc = 1;
      DAT_ffffc1bd = cVar1;
      return;
    }
    uVar2 = FUN_000024c0(0x42800000,0);
    DAT_ffffc184 = FUN_00002068(uVar2,&DAT_0006b4e8);
  }
  DAT_ffffc1bc = 0;
  DAT_ffffc1bd = cVar1;
  return;
}


