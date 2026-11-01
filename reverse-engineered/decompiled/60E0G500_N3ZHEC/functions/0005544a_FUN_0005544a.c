/* ROM address: 0x0005544a; body bytes: 48; decompiled */

int FUN_0005544a(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar4 = 0;
  pbVar3 = &DAT_ffff9010;
  for (bVar2 = 0; (bVar2 < DAT_ffff9039 && (bVar2 < 0x28)); bVar2 = bVar2 + 1) {
    bVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
    iVar4 = iVar4 + (uint)bVar1;
  }
  return iVar4 + (uint)bVar2;
}


