/* ROM address: 0x0000b958; body bytes: 68; decompiled */

int FUN_0000b958(undefined2 *param_1,byte param_2)

{
  undefined2 uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 *puVar5;
  
  uVar3 = FUN_00003920(0x90);
  puVar5 = &DAT_ffffa2de;
  iVar4 = 0;
  if (param_2 != 0) {
    do {
      iVar4 = iVar4 + 1;
      uVar1 = *puVar5;
      puVar5 = puVar5 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (iVar4 < (int)(uint)param_2);
  }
  cVar2 = DAT_ffffa320;
  DAT_ffffa228 = 0;
  FUN_00003934(uVar3);
  return (int)cVar2;
}


