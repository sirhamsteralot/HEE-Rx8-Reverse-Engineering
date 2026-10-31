/* ROM address: 0x00055bda; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00053ef6 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

int switchD_00055ab6::caseD_2(undefined4 param_1)

{
  char cVar2;
  undefined4 uVar1;
  char local_10 [4];
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  local_10[0] = '\0';
  uStack_8 = param_1;
  cVar2 = FUN_0005a5a6(&uStack_c);
  if (cVar2 == '\0') {
    uVar1 = ref_updateRAM__(uStack_8,local_10,1);
    FUN_000548ec(uVar1,local_10,uStack_c);
  }
  return (int)local_10[0];
}


