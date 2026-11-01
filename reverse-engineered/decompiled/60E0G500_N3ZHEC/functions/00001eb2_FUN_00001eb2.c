/* ROM address: 0x00001eb2; body bytes: 30; decompiled */

byte FUN_00001eb2(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *param_1 & 0xfe;
  *param_1 = bVar1;
  iVar2 = 4000;
  do {
    if ((*param_2 & 8) == 0) {
      return bVar1;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return bVar1;
}


