/* ROM address: 0x00063c1c; body bytes: 124; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006250c (124 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00063c1c(char param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  
  iVar5 = 1;
  uVar3 = 0;
  puVar6 = param_2 + 0x28;
  while( true ) {
    if (0x14 < (int)uVar3) goto LAB_00063c76;
    if (((&DAT_ffff890e)[uVar3 * 0x34] == param_1) && (DAT_ffff8d4c._0_2_ != uVar3)) break;
    uVar3 = uVar3 + 1;
  }
  puVar4 = &DAT_ffff8912 + uVar3 * 0x34;
  puVar2 = param_2;
  do {
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while (puVar2 < puVar6);
  iVar5 = 0;
LAB_00063c76:
  if (iVar5 == 1) {
    do {
      *param_2 = 0;
      param_2 = param_2 + 1;
    } while (param_2 < puVar6);
  }
  return iVar5;
}


