/* ROM address: 0x00054aa0; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00052b8c (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00054aa0(byte param_1)

{
  char cVar2;
  uint uVar1;
  undefined4 uVar3;
  
  cVar2 = FUN_00055e3e(0);
  if (cVar2 == '\0') {
    uVar3 = 0;
  }
  else {
    uVar3 = 3;
  }
  FUN_00055cec(uVar3);
  FUN_0005bb00(3);
  FUN_0005e1a0(3);
  FUN_0005dcf8(3);
  FUN_000566f0(3);
  uVar1 = (uint)param_1;
  if (uVar1 != 0x11) {
    if (uVar1 != 0xb1) {
      return uVar1;
    }
    uVar1 = FUN_000563de(2);
    return uVar1;
  }
  uVar1 = FUN_0005b018(3);
  return uVar1;
}


