/* ROM address: 0x00066c80; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065570 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00066c80(char param_1,undefined1 *param_2,uint param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (param_1 == '\0') {
    puVar2 = &DAT_ffffd935;
    iVar3 = 0;
    if ((param_3 & 0xffff) != 0) {
      do {
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        iVar3 = iVar3 + 1;
        *puVar2 = uVar1;
        puVar2 = puVar2 + 1;
      } while (iVar3 < (int)(param_3 & 0xffff));
    }
    param_2 = &DAT_ffffd934;
    param_3 = param_3 + 1;
  }
  FUN_00067160(param_1,param_2,param_3);
  return;
}


