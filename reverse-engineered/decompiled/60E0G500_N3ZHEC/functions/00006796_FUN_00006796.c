/* ROM address: 0x00006796; body bytes: 172; decompiled */

void FUN_00006796(void)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  
  uVar2 = DAT_fffff74e;
  DAT_ffff9ec8 = (DAT_ffff9ed8 | uVar2) & DAT_ffff9ec8 | DAT_ffff9ed8 & uVar2;
  uVar1 = DAT_fffff72c;
  DAT_ffff9eca = (DAT_ffff9eda | uVar1) & DAT_ffff9eca | DAT_ffff9eda & uVar1;
  DAT_ffff9ed8 = uVar2;
  DAT_ffff9eda = uVar1;
  bVar3 = FUN_000070ac(0);
  DAT_ffff9ecc = (DAT_ffff9edc | bVar3) & DAT_ffff9ecc | DAT_ffff9edc & bVar3;
  DAT_ffff9edc = bVar3;
  bVar3 = FUN_000070ac(1);
  DAT_ffff9ecd = (DAT_ffff9edd | bVar3) & DAT_ffff9ecd | DAT_ffff9edd & bVar3;
  DAT_ffff9edd = bVar3;
  bVar3 = FUN_000070ac(2);
  DAT_ffff9ece = (DAT_ffff9ede | bVar3) & DAT_ffff9ece | DAT_ffff9ede & bVar3;
  DAT_ffff9ede = bVar3;
  DAT_ffff9ed0 = DAT_ffff9ed4 & DAT_ffff9ed0 | DAT_ffff9ed4;
  return;
}


