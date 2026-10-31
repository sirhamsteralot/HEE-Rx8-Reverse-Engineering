/* ROM address: 0x00066e5a; body bytes: 172; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006574a (172 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 FUN_00066e5a(char *param_1,uint param_2)

{
  char cVar2;
  undefined4 uVar1;
  int iVar3;
  char *pcVar4;
  undefined1 uStack_28;
  undefined1 local_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  iVar3 = 0;
  uStack_28 = 1;
  pcVar4 = param_1;
  if ((param_2 & 0xffff) != 0) {
    do {
      cVar2 = FUN_00066678(6,(int)*param_1);
      if (cVar2 == '\0') {
        DAT_ffffd93c = *pcVar4;
        uVar1 = FUN_000666aa(6,(int)*pcVar4);
        local_24 = (undefined1)((uint)uVar1 >> 0x18);
        DAT_ffffd93d = local_24;
        uStack_23 = (undefined1)((uint)uVar1 >> 0x10);
        DAT_ffffd93e = uStack_23;
        uStack_22 = (undefined1)((uint)uVar1 >> 8);
        DAT_ffffd93f = uStack_22;
        uStack_21 = (undefined1)uVar1;
        DAT_ffffd940 = uStack_21;
        FUN_000672ec(&DAT_ffffd93c,5);
        uStack_28 = 0;
      }
      iVar3 = iVar3 + 1;
      pcVar4 = pcVar4 + 1;
      param_1 = param_1 + 1;
    } while (iVar3 < (int)(param_2 & 0xffff));
  }
  return uStack_28;
}


