/* ROM address: 0x00066cb4; body bytes: 194; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000655a4 (194 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00066cb4(char *param_1,uint param_2)

{
  char cVar2;
  undefined4 uVar1;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined1 auStack_38 [4];
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 local_24;
  
  puStack_34 = &DAT_ffffd935;
  iVar3 = 1;
  iVar4 = 0;
  auStack_38[0] = 0;
  puStack_30 = &DAT_ffffd936;
  puStack_28 = &DAT_ffffd938;
  puStack_2c = &DAT_ffffd937;
  pcVar5 = param_1;
  if ((param_2 & 0xffff) != 0) {
    do {
      cVar2 = FUN_00066678(8,(int)*param_1);
      if (cVar2 == '\0') {
        DAT_ffffd934 = *pcVar5;
        uVar1 = FUN_000666aa(8,(int)*pcVar5);
        local_24._0_1_ = (undefined1)((uint)uVar1 >> 0x18);
        *puStack_34 = local_24._0_1_;
        local_24._1_1_ = (undefined1)((uint)uVar1 >> 0x10);
        *puStack_30 = local_24._1_1_;
        local_24._2_1_ = (undefined1)((uint)uVar1 >> 8);
        *puStack_2c = local_24._2_1_;
        local_24._3_1_ = (undefined1)uVar1;
        *puStack_28 = (undefined1)local_24;
        local_24 = uVar1;
        FUN_0006713c(&DAT_ffffd934,5);
        iVar3 = 0;
      }
      iVar4 = iVar4 + 1;
      pcVar5 = pcVar5 + 1;
      param_1 = param_1 + 1;
    } while (iVar4 < (int)(param_2 & 0xffff));
  }
  if (iVar3 == 0) {
    FUN_00067160(0,auStack_38);
  }
  return iVar3;
}


