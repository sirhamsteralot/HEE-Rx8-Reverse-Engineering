/* ROM address: 0x00056bcc; body bytes: 100; decompiled */

undefined4 FUN_00056bcc(void)

{
  ushort uVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  
  uVar2 = 0;
  fVar3 = DAT_ffffaa10;
  fVar4 = DAT_ffffb600;
  uVar1 = FUN_00001008();
  if (uVar1 < 100) {
    if (((fVar4 <= 8.0) || (16.5 <= fVar4)) ||
       ((DAT_ffffc656 == '\0' && ((fVar3 <= -40.0 || (120.0 <= fVar3)))))) {
      uVar2 = 0x22;
    }
  }
  else {
    uVar2 = 0x10;
  }
  return uVar2;
}


