/* ROM address: 0x00063cea; body bytes: 150; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000625da (150 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00063cea(char param_1,uint param_2,uint param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  iVar5 = 1;
  param_3 = param_3 & 0xff;
  while( true ) {
    if (0x14 < (int)uVar6) goto LAB_00063d54;
    if (((&DAT_ffff890e)[uVar6 * 0x34] == param_1) && (DAT_ffff8d4c._0_2_ != uVar6)) break;
    uVar6 = uVar6 + 1;
  }
  iVar5 = 0;
  puVar3 = &DAT_ffff8912 + (param_2 & 0xff) + uVar6 * 0x34;
  puVar2 = param_4;
  if (param_3 != 0) {
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      iVar5 = iVar5 + 1;
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
    } while (iVar5 < (int)param_3);
  }
  iVar5 = 0;
LAB_00063d54:
  if ((iVar5 == 1) && (iVar4 = 0, param_3 != 0)) {
    do {
      *param_4 = 0;
      iVar4 = iVar4 + 1;
      param_4 = param_4 + 1;
    } while (iVar4 < (int)param_3);
  }
  return iVar5;
}


