/* ROM address: 0x0000d2f6; body bytes: 162; decompiled */

undefined1 FUN_0000d2f6(byte param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  iVar3 = 0;
  piVar5 = (int *)(&PTR_DAT_0007fb80)[(uint)param_1 * 3];
  piVar4 = (int *)(&PTR_DAT_0007fb84)[(uint)param_1 * 3];
  cVar1 = FUN_0000d674(piVar5,piVar4);
  if (cVar1 == '\0') {
    while (piVar5 < piVar4) {
      FUN_0000a850();
      piVar2 = (int *)((int)&PTR_DAT_00020000 + (int)piVar5);
      if (piVar4 < (int *)((int)&PTR_DAT_00020000 + (int)piVar5)) {
        piVar2 = piVar4;
      }
      for (; piVar5 < piVar2; piVar5 = piVar5 + 1) {
        iVar3 = iVar3 + *piVar5;
      }
    }
    if (iVar3 + *(int *)(&DAT_0007fb88 + (uint)param_1 * 0xc) == 0x5aa5a55a) {
      DAT_ffffa3fa = 0;
    }
    else {
      DAT_ffffa3fa = 1;
    }
  }
  else {
    DAT_ffffa3fa = 1;
  }
  return DAT_ffffa3fa;
}


