/* ROM address: 0x00065344; body bytes: 122; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063c34 (122 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00065344(ushort *param_1)

{
  char cVar1;
  byte bVar3;
  uint uVar2;
  undefined1 auStack_18 [20];
  
  cVar1 = (&DAT_ffff8d54)[(uint)*param_1 * 2];
  bVar3 = FUN_0006559c((int)*(char *)(param_1 + 3));
  if ((cVar1 == ' ') && ((bVar3 == 0x60 || (bVar3 == 0x70)))) {
    uVar2 = FUN_00067826((int)(short)*param_1,auStack_18);
    if ((uVar2 & 0xff) == 0) {
      uVar2 = FUN_00067732(auStack_18);
    }
  }
  else {
    uVar2 = (uint)bVar3;
    if ((uVar2 == 0) || ((uVar2 == 0x50 || (uVar2 == 0xc1)))) {
      uVar2 = FUN_00067760();
    }
  }
  return uVar2;
}


