/* ROM address: 0x0003ef70; body bytes: 306; decompiled */

undefined4 FUN_0003ef70(void)

{
  bool bVar1;
  short sVar2;
  char cVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  DAT_ffffc6ad = '\0';
  FUN_0003eca2(&DAT_ffff872c);
  sVar2 = FUN_0003eae4(&DAT_ffff872c,0);
  if (sVar2 == -0x55ab) {
    FUN_00060a84();
    thunk_FUN_00025e6a();
    thunk_FUN_00029948();
    FUN_0001ad56();
    FUN_0002f30c();
    FUN_0003aeb4();
    FUN_00022052();
    thunk_FUN_0001376e();
    thunk_FUN_00015fde();
    FUN_00017d46();
    thunk_FUN_0003f250();
    FUN_00023c58();
    thunk_FUN_00027c32();
    thunk_FUN_00035a54();
    FUN_0005aa5a();
    FUN_0005ab6a();
    FUN_0005adde();
    FUN_0005ea9c();
    FUN_000589fa();
    FUN_00058a7e();
    FUN_00058ba2();
    FUN_00058c46();
    FUN_00058cb4();
    FUN_00058d60();
    FUN_00058e98();
    FUN_00058f90();
    FUN_000590ce();
    FUN_00059216();
    FUN_00059352();
    FUN_0005946e();
    FUN_0005963a();
    FUN_000596ce();
    cVar3 = FUN_0000ab6c();
    if (cVar3 == '\x01') {
      FUN_0003eecc();
    }
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((DAT_ffffc6ad == '\x01') || (bVar1)) {
    DAT_ffffc6ad = '\0';
    uVar4 = 1;
    DAT_ffffc6ac = 0;
    FUN_0003ebd0(&DAT_ffff872c,0);
  }
  return uVar4;
}


