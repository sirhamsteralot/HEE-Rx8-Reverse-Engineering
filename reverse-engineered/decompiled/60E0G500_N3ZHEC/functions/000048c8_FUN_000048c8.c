/* ROM address: 0x000048c8; body bytes: 98; decompiled */

void FUN_000048c8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  uint *in_stack_00000000;
  
  uVar2 = (param_1 & 0x7fffffff) >> 0x17;
  uVar4 = param_1 << 9;
  if (uVar2 == 0xff) {
    if (uVar4 == 0) {
      puVar3 = (undefined *)0x7fff;
      uVar2 = 0;
    }
    else {
      puVar3 = (undefined *)0x7fff;
      param_1 = 0;
      uVar2 = 0xffffffff;
    }
  }
  else {
    if (uVar2 == 0) {
      if (uVar4 == 0) {
        puVar3 = (undefined *)((int)&DAT_ffff8000 + 1);
        uVar2 = 0;
        goto LAB_000048ec;
      }
      uVar1 = param_1 << 10;
      uVar5 = uVar4;
      while (uVar4 = uVar1, (uVar5 & 0x80000000) == 0) {
        uVar2 = uVar2 - 1;
        uVar1 = uVar4 << 1;
        uVar5 = uVar4;
      }
    }
    puVar3 = (undefined *)(uVar2 - 0x7f);
    uVar2 = uVar4 >> 1 | 0x80000000;
  }
LAB_000048ec:
  *in_stack_00000000 = (uint)puVar3 & 0xffff | (uint)((param_1 & 0x80000000) != 0) * -0x80000000;
  in_stack_00000000[1] = uVar2;
  return;
}


