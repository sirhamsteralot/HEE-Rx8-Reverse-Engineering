/* ROM address: 0x00063f64; body bytes: 160; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062854 (160 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063f64(undefined4 param_1,uint param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = 8;
  uVar3 = 0;
  if ((param_2 & 0xff) == 3) {
    uVar3 = FUN_00064088(param_1);
    uVar2 = FUN_000618f8(param_1,uVar3,param_2);
    cVar1 = FUN_00062420(uVar2);
    if (cVar1 == '\x01') {
      FUN_00064122(param_1,uVar3);
      FUN_000642b8();
      FUN_00062138(param_1);
      FUN_00064234(param_1,0x20);
      FUN_00064312();
      FUN_0006310a(uVar2);
      FUN_00063026(param_2);
      FUN_00063098(1);
      FUN_00064418(param_1,uVar3);
    }
    FUN_000628b8();
  }
  DAT_ffffd6c0 = (undefined1)uVar2;
  DAT_ffffd6c3 = (undefined1)uVar3;
  FUN_000623b0();
  FUN_00062080(param_1,0x20);
  FUN_000620e8(param_1,0x20,uVar3);
  FUN_0006289a();
  return;
}


