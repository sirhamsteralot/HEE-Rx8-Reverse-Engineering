/* ROM address: 0x00004740; body bytes: 210; decompiled */

void FUN_00004740(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint *in_stack_00000000;
  uint in_stack_00000004;
  uint in_stack_00000008;
  
  uVar5 = (uint)(short)in_stack_00000004;
  if ((int)uVar5 < (int)(undefined *)0xffff8002) {
    uVar7 = (uint)((in_stack_00000004 & 0x80000000) != 0) * -0x80000000 | 0x8001;
    uVar5 = 0;
    goto LAB_000047e8;
  }
  if ((in_stack_00000004 & 0x80000000) == 0) {
    if ((int)uVar5 < (int)(undefined *)0x7fff) {
      uVar7 = 0;
      uVar3 = 0;
      uVar2 = 0;
      iVar9 = 0x1d;
      puVar6 = (undefined *)(uVar5 >> 1);
      if ((uVar5 & 1) == 1) {
        uVar5 = in_stack_00000008 & 0x80000000;
        in_stack_00000008 = in_stack_00000008 << 1;
        uVar7 = (uint)(uVar5 != 0);
      }
      uVar7 = uVar7 << 1 | (uint)((in_stack_00000008 & 0x80000000) != 0);
      uVar5 = in_stack_00000008 << 1;
      do {
        uVar4 = uVar5;
        uVar2 = uVar2 << 1 | 1;
        bVar1 = uVar2 <= uVar7;
        if (bVar1) {
          uVar3 = uVar3 << 1 | (uint)bVar1;
          uVar7 = uVar7 - uVar2;
          uVar2 = uVar2 + 1;
        }
        else {
          uVar2 = uVar2 ^ 1;
          uVar3 = uVar3 << 1 | (uint)bVar1;
        }
        uVar7 = (uVar7 << 1 | (uint)((uVar4 & 0x80000000) != 0)) << 1 |
                (uint)((uVar4 & 0x40000000) != 0);
        iVar9 = iVar9 + -1;
        uVar5 = uVar4 << 2;
      } while (0 < iVar9);
      uVar5 = uVar2 << 1 | 1;
      bVar1 = uVar5 <= uVar7;
      if (bVar1) {
        uVar2 = uVar3 << 1 | (uint)bVar1;
        uVar7 = uVar7 - uVar5;
        uVar5 = uVar5 + 1;
      }
      else {
        uVar5 = uVar5 ^ 1;
        uVar2 = uVar3 << 1 | (uint)bVar1;
      }
      uVar8 = (uVar7 << 1 | (uint)((uVar4 << 2 & 0x80000000) != 0)) << 1 |
              (uint)((uVar4 & 0x10000000) != 0);
      uVar10 = (uint)((uVar7 & 0x80000000) != 0) << 1 | (uint)((uVar7 << 1 & 0x80000000) != 0);
      uVar7 = uVar5 << 1 | 1;
      uVar3 = (uint)((uVar5 & 0x80000000) != 0);
      if ((uVar3 < uVar10) || ((uVar3 <= uVar10 && (uVar7 <= uVar8)))) {
        uVar5 = uVar2 << 1 | 1;
        uVar7 = uVar8 - uVar7;
        uVar2 = uVar7 - ((uVar2 & 0x80000000) != 0);
        uVar10 = (uVar10 - uVar3) - (uint)(uVar8 < uVar7 || uVar7 < uVar2);
        uVar8 = uVar2;
      }
      else {
        uVar5 = uVar2 << 1;
      }
      uVar5 = uVar5 << 1;
      if ((((uVar10 & 0x3fffffff) != 0 || (uVar8 & 0x80000000) != 0) ||
           (uVar8 << 1 & 0x80000000) != 0) ||
         (((uVar8 << 1 & 0x7fffffff) != 0 || (uVar4 & 0x8000000) != 0) || (uVar4 & 0x4000000) != 0))
      {
        uVar5 = uVar5 | 1;
      }
    }
    else {
      if (in_stack_00000008 != 0) goto LAB_0000480c;
      puVar6 = (undefined *)0x7fff;
      uVar5 = 0;
    }
  }
  else {
LAB_0000480c:
    puVar6 = (undefined *)0x7fff;
    uVar5 = 0xffffffff;
  }
  uVar7 = (uint)puVar6 & 0xffff;
LAB_000047e8:
  *in_stack_00000000 = uVar7;
  in_stack_00000000[1] = uVar5;
  return;
}


