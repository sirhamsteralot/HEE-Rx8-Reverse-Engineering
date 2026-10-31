/* ROM address: 0x000048c8; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000048c8 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000048c8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *in_stack_00000000;
  
  uVar2 = (param_1 & 0x7fffffff) >> 0x17;
  uVar3 = param_1 << 9;
  if (uVar2 == 0xff) {
    if (uVar3 == 0) {
      uVar2 = 0x7fff;
      uVar3 = 0;
    }
    else {
      uVar2 = 0x7fff;
      param_1 = 0;
      uVar3 = 0xffffffff;
    }
  }
  else {
    if (uVar2 == 0) {
      if (uVar3 == 0) {
        uVar2 = 0xffff8001;
        uVar3 = 0;
        goto LAB_000048ec;
      }
      uVar1 = param_1 << 10;
      uVar4 = uVar3;
      while (uVar3 = uVar1, (uVar4 & 0x80000000) == 0) {
        uVar2 = uVar2 - 1;
        uVar1 = uVar3 << 1;
        uVar4 = uVar3;
      }
    }
    uVar2 = uVar2 - 0x7f;
    uVar3 = uVar3 >> 1 | 0x80000000;
  }
LAB_000048ec:
  *in_stack_00000000 = uVar2 & 0xffff | (uint)((param_1 & 0x80000000) != 0) * -0x80000000;
  in_stack_00000000[1] = uVar3;
  return;
}


