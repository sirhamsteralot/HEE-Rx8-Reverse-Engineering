/* ROM address: 0x0005aa18; body bytes: 66; decompiled */

void FUN_0005aa18(void)

{
  float fVar1;
  float fVar2;
  
  if (DAT_ffffd201 == '\x01') {
    FUN_0003ec20(0,&DAT_ffff9124);
    return;
  }
  fVar1 = (float)FUN_0003eb72(0,&DAT_ffff9124);
  fVar2 = fVar1 + DAT_ffffd2bc;
  if (65535.0 < fVar1 + DAT_ffffd2bc) {
    fVar2 = 65535.0;
  }
  FUN_0003ec20(fVar2,&DAT_ffff9124);
  return;
}


