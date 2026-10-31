/* ROM address: 0x0006477c; body bytes: 268; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006306c (268 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006477c(undefined4 param_1,char param_2,short param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  char cVar6;
  
  FUN_00062668();
  uVar1 = FUN_00062df8(param_1);
  uVar2 = FUN_00065270(param_1);
  uVar3 = FUN_00064c74(param_1,uVar1,uVar2);
  uVar4 = FUN_000618f8(param_1,uVar3,(int)param_2);
  cVar5 = FUN_00062420(uVar4);
  if (cVar5 == '\x01') {
    FUN_00062ebc(0);
    FUN_00062f2e(0);
    if (((uVar2 & 0xff) == 0) || ((uVar2 & 0xff) == 1)) {
      FUN_00064d74(uVar1,uVar3);
      FUN_00064ed0(uVar3);
      FUN_0006508c(uVar3);
      FUN_0006310a(uVar4);
      FUN_00063026((int)param_2);
      FUN_00063098(1);
      FUN_000653e0(param_1,(int)param_3,uVar3);
      FUN_000623b0();
      FUN_00062080(param_1,0x20);
      FUN_000620e8(param_1,0x20,uVar3);
      FUN_0006289a();
      cVar5 = FUN_0006559c(uVar3);
      cVar6 = FUN_0006559c(uVar1);
      if (((cVar6 != '`') && (cVar5 == '`')) || ((cVar6 != 'p' && (cVar5 == 'p')))) {
        DAT_ffffd7b4 = 1;
      }
    }
  }
  FUN_000628b8();
  FUN_000628f4();
  DAT_ffffd6c0 = (char)uVar4;
  DAT_ffffd6c3 = (char)uVar3;
  return;
}


