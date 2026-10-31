/* ROM address: 0x00068be8; body bytes: 112; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000674d8 (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068be8(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  puVar3 = &DAT_ffffddfc;
  iVar6 = 0;
  piVar5 = &DAT_ffffde04;
  iVar4 = 0;
  do {
    uVar2 = sh_raise_interrupt_mask_return_previous(0x90);
    if (((&DAT_ffffddfc)[iVar6] == '\x01') &&
       (iVar1 = ATUII_TCNT0H_W, 0x7fffffff < (uint)(*piVar5 - iVar1))) {
      *puVar3 = 0;
      (**(code **)((int)&PTR_FUN_00068edc + iVar4))();
    }
    ref_setSR(uVar2);
    iVar6 = iVar6 + 1;
    iVar4 = iVar4 + 4;
    puVar3 = puVar3 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar6 < 7);
  return;
}


