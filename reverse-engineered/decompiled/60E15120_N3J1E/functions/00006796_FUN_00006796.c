/* ROM address: 0x00006796; body bytes: 172; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00006796 (172 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00006796(void)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  
  uVar2 = PFDR_W;
  DAT_ffff9ec8 = (DAT_ffff9ed8 | uVar2) & DAT_ffff9ec8 | DAT_ffff9ed8 & uVar2;
  uVar1 = PHDR_W;
  DAT_ffff9eca = (DAT_ffff9eda | uVar1) & DAT_ffff9eca | DAT_ffff9eda & uVar1;
  DAT_ffff9ed8 = uVar2;
  DAT_ffff9eda = uVar1;
  bVar3 = ref_getFromGPIO_(0);
  DAT_ffff9ecc = (DAT_ffff9edc | bVar3) & DAT_ffff9ecc | DAT_ffff9edc & bVar3;
  DAT_ffff9edc = bVar3;
  bVar3 = ref_getFromGPIO_(1);
  DAT_ffff9ecd = (DAT_ffff9edd | bVar3) & DAT_ffff9ecd | DAT_ffff9edd & bVar3;
  DAT_ffff9edd = bVar3;
  bVar3 = ref_getFromGPIO_(2);
  DAT_ffff9ece = (DAT_ffff9ede | bVar3) & DAT_ffff9ece | DAT_ffff9ede & bVar3;
  DAT_ffff9ede = bVar3;
  DAT_ffff9ed0 = DAT_ffff9ed4 & DAT_ffff9ed0 | DAT_ffff9ed4;
  return;
}


