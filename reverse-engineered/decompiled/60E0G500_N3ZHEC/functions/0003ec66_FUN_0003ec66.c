/* ROM address: 0x0003ec66; body bytes: 60; decompiled */

bool FUN_0003ec66(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  
  uVar3 = FUN_00003920(0x10);
  bVar1 = *param_1;
  bVar2 = param_1[1];
  if (bVar1 != (byte)~bVar2) {
    FUN_0003eecc();
  }
  FUN_00003934(uVar3);
  return bVar1 != (byte)~bVar2;
}


