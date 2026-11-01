/* ROM address: 0x00068cec; body bytes: 86; decompiled */

undefined4 FUN_00068cec(void)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = (ushort)DAT_ffffde04;
  uVar2 = 1;
  if (((uVar1 & 0xf) < 8) && ((DAT_ffffde04 & 0xf) != 0)) {
    DAT_ffffde31 = DAT_ffffde31 | 4;
    FUN_00068b58();
    DAT_ffffde28 = FUN_0006922a((int)DAT_ffffde05);
    DAT_ffffde26 = DAT_ffffde05;
    DAT_ffffde22 = uVar1 & 0xf;
    FUN_000685c0((int)DAT_ffffde28,&DAT_ffffde05,7);
    uVar2 = 0;
  }
  return uVar2;
}


