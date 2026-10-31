/* ROM address: 0x000653e0; body bytes: 160; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063cd0 (160 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000653e0(short param_1,uint param_2,char param_3)

{
  char cVar4;
  uint uVar1;
  uint uVar2;
  short sVar3;
  
  FUN_000626d4(0);
  cVar4 = FUN_0006559c((int)param_3);
  uVar1 = FUN_00067c78(0);
  FUN_00067c64(uVar1 | param_2);
  uVar2 = FUN_000676de((int)param_1);
  FUN_000676c8(uVar2 | param_2);
  sVar3 = FUN_00067c1a(0);
  if (sVar3 == 0) {
    FUN_00067c06(param_2);
  }
  if (((cVar4 == 'p') || (cVar4 == -0x40)) || (cVar4 == -0x3f)) {
    uVar2 = FUN_00067674((int)param_1);
    FUN_0006763c(uVar2 | param_2);
    sVar3 = FUN_00067bbc(0);
    if (sVar3 == 0) {
      FUN_00067b88(uVar1 | param_2);
    }
  }
  FUN_00062918(0);
  return;
}


