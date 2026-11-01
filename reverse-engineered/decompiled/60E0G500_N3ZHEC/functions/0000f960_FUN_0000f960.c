/* ROM address: 0x0000f960; body bytes: 146; decompiled */

void FUN_0000f960(float param_1,byte param_2)

{
  ushort uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  uVar1 = FUN_0000ff04();
  if ((uVar1 & *(ushort *)((int)&PTR_DAT_0004ea28 + (uint)param_2 * 2)) == 0) {
    iVar2 = 0;
    pcVar4 = &DAT_0004ea74 + (uint)param_2 * 3;
    pcVar3 = &DAT_0004ea7a + (uint)param_2 * 3;
    do {
      if (*pcVar3 == '\x01') {
        thunk_FUN_00008b4c((int)*pcVar4,(int)(param_1 / 0.25));
      }
      iVar2 = iVar2 + 1;
      pcVar4 = pcVar4 + 1;
      pcVar3 = pcVar3 + 1;
    } while (iVar2 < 3);
    FUN_0000fa06();
    return;
  }
  return;
}


