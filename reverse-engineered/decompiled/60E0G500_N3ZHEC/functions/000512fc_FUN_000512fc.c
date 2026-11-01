/* ROM address: 0x000512fc; body bytes: 170; decompiled */

uint FUN_000512fc(void)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  float fVar4;
  
  fVar4 = 0.0;
  uVar3 = FUN_0003eb72(0,&DAT_ffff86a4);
  DAT_ffffd0f8 = (float)FUN_00002068(uVar3,&DAT_0006b898);
  DAT_ffffd0fc = (float)FUN_00002068(uVar3,&DAT_0006b8ac);
  DAT_ffffd0f4 = (float)FUN_00002068(DAT_ffffd050,&DAT_0006b884);
  cVar1 = DAT_ffffd034;
  if (DAT_ffffd201 == '\x01') {
    uVar2 = FUN_0003ec20(fVar4,&DAT_ffff86e0);
    DAT_ffffd0d8 = fVar4;
  }
  else {
    uVar2 = (uint)DAT_ffffd0e4;
    if ((((uVar2 == 1) && (uVar2 = (uint)DAT_ffffcfe6, (uint)(int)DAT_ffffcfe4 < uVar2)) &&
        (uVar2 = (uint)DAT_ffffd10e, uVar2 != 0)) && (DAT_ffffd034 == '\0')) {
      uVar2 = FUN_0003ec20(DAT_ffffd0f4 * DAT_ffffd0f8,&DAT_ffff86e0);
      DAT_ffffd0d8 = DAT_ffffd0f4 * DAT_ffffd0fc;
    }
  }
  DAT_ffffd10e = cVar1;
  return uVar2;
}


