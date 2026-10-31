/* ROM address: 0x00065270; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063b60 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065270(short param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_0005fc98();
  if (cVar1 == '\0') {
    uVar2 = 0;
  }
  else {
    cVar1 = FUN_000678b4((int)param_1);
    if ((byte)(cVar1 + 1U) < 4) {
      FUN_0006789e();
      uVar2 = 2;
    }
    else {
      FUN_0006789e(4);
      uVar2 = 1;
    }
  }
  return uVar2;
}


