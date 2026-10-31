/* ROM address: 0x00066a58; body bytes: 160; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065348 (160 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00066a58(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  cVar1 = FUN_00066af8();
  if (cVar1 != '\0') {
    uVar2 = 0x80000000;
  }
  cVar1 = FUN_00066afc(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x40000000;
  }
  cVar1 = FUN_00066af8(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x20000000;
  }
  cVar1 = FUN_00066b70(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x10000000;
  }
  cVar1 = FUN_00066b8e(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x8000000;
  }
  cVar1 = FUN_00066af8(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x4000000;
  }
  cVar1 = FUN_00066af8(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x2000000;
  }
  cVar1 = FUN_00066af8(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x1000000;
  }
  cVar1 = FUN_00066baa(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x800000;
  }
  return uVar2;
}


