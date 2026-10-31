/* ROM address: 0x00063d8c; body bytes: 152; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006267c (152 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00063d8c(void)

{
  char cVar1;
  char cVar3;
  undefined2 uVar2;
  undefined2 *puVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  
  uVar8 = 0;
  cVar3 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8e72);
  if (((cVar3 != '\0') || (cVar3 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8e74), cVar3 != '\0')) ||
     (cVar3 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8e70), cVar3 != '\0')) {
    uVar8 = 1;
  }
  cVar3 = '\0';
  pcVar6 = &DAT_ffff8d54;
  iVar7 = 0x8c;
  do {
    pcVar5 = pcVar6;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      cVar3 = cVar3 + cVar1;
    } while (pcVar5 < pcVar6 + 2);
    iVar7 = iVar7 + -1;
    pcVar6 = pcVar6 + 2;
  } while (iVar7 != 0);
  if ((char)(cVar3 + DAT_ffff8e6c._0_1_) == -0x5b) {
    uVar2 = rx8_pack_u8_with_complement();
    puVar4 = &DAT_ffff8e6e;
  }
  else {
    if ((char)(cVar3 + DAT_ffff8e6e._0_1_) != -0x5b) {
      return 1;
    }
    uVar2 = rx8_pack_u8_with_complement((int)DAT_ffff8e6e._0_1_);
    puVar4 = &DAT_ffff8e6c;
  }
  *puVar4 = uVar2;
  return uVar8;
}


