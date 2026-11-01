/* ROM address: 0x0000871c; body bytes: 134; decompiled */

uint FUN_0000871c(byte param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = DAT_ffff9f88;
  iVar5 = (uint)param_1 * 0x18;
  if ((byte)(&DAT_ffffa017)[iVar5] == 2) {
    uVar2 = FUN_00003920(0x10);
    iVar3 = FUN_00002158((&DAT_ffffa0ac)[param_1] + *(int *)(&DAT_ffffa004 + iVar5) +
                         (&DAT_ffffa094)[param_1],uVar1);
    *(int *)(&DAT_ffffa008 + iVar5) =
         *(int *)(&DAT_ffffa008 + iVar5) + *(int *)(&DAT_ffffa00c + iVar5) + iVar3 * -0xb4;
    *(int *)(&DAT_ffffa00c + iVar5) = iVar3 * 0xb4;
    uVar4 = FUN_00003934(uVar2);
    return uVar4;
  }
  return (uint)(byte)(&DAT_ffffa017)[iVar5];
}


