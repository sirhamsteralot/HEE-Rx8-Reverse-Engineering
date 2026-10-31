/* ROM address: 0x00054ca6; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00052d92 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00054ca6(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar4 = 0;
  pbVar3 = &DAT_ffff8fe8;
  for (bVar2 = 0; (bVar2 < DAT_ffff9011 && (bVar2 < 0x28)); bVar2 = bVar2 + 1) {
    bVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
    iVar4 = iVar4 + (uint)bVar1;
  }
  return iVar4 + (uint)bVar2;
}


