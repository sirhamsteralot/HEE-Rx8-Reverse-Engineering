/* ROM address: 0x0006938c; body bytes: 112; decompiled */

void FUN_0006938c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  puVar3 = &DAT_ffffde38;
  iVar6 = 0;
  piVar5 = &DAT_ffffde40;
  iVar4 = 0;
  do {
    uVar2 = FUN_00003920(0x90);
    if (((&DAT_ffffde38)[iVar6] == '\x01') &&
       (iVar1 = DAT_fffff430, 0x7fffffff < (uint)(*piVar5 - iVar1))) {
      *puVar3 = 0;
      (**(code **)((int)&PTR_FUN_00069680 + iVar4))();
    }
    FUN_00003934(uVar2);
    iVar6 = iVar6 + 1;
    iVar4 = iVar4 + 4;
    puVar3 = puVar3 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar6 < 7);
  return;
}


