/* ROM address: 0x00015aea; body bytes: 938; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00015b24) */
/* WARNING: Removing unreachable block (ram,0x00015b42) */
/* WARNING: Removing unreachable block (ram,0x00015b4c) */
/* WARNING: Removing unreachable block (ram,0x00015b58) */
/* WARNING: Removing unreachable block (ram,0x00015b5c) */
/* WARNING: Removing unreachable block (ram,0x00015b6c) */
/* WARNING: Removing unreachable block (ram,0x00015b66) */
/* WARNING: Removing unreachable block (ram,0x00015b8e) */

undefined4 FUN_00015aea(void)

{
  char cVar1;
  undefined4 extraout_r0;
  float fVar2;
  float fVar3;
  float arg1;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  char local_3c;
  
  cVar1 = DAT_ffffb5aa;
  local_3c = DAT_ffffb5aa;
  if (DAT_ffffa894 == '\0') {
    DAT_ffffa87c = 0;
    DAT_ffffa894 = '\x04';
  }
  DAT_ffffa844 = ((DAT_ffffa7b0 + DAT_ffffa8d4 + DAT_ffffa8b4 + DAT_ffffa898 + DAT_ffffa7b8 +
                   DAT_ffffa89c + DAT_ffffa840) - DAT_ffffa8ac) + DAT_ffffc0ac + DAT_ffffc20c;
  if (DAT_ffffb5b8 < DAT_ffffa7bc + 0.0) {
    if (DAT_ffffb5b8 < 312.0) {
      DAT_ffffa854 = '\0';
    }
  }
  else {
    DAT_ffffa854 = '\x01';
  }
  DAT_ffffa868 = DAT_ffffa860;
  DAT_ffffa86c = DAT_ffffa864;
  arg1 = 0.0;
  fVar4 = DAT_ffffa7bc;
  uVar5 = DAT_ffffaa14;
  fVar6 = DAT_ffffb5b8;
  fVar2 = DAT_ffffa844;
  if ((DAT_ffffa854 == '\x01') &&
     (local_3c = FUN_00002440(DAT_ffffb5b8,0,0x3727c5ac), fVar2 = DAT_ffffa860, local_3c != '\0')) {
    fVar2 = (DAT_ffffa844 * fVar4) / fVar6;
    if (cVar1 == '\x01') {
      fVar3 = 0.0;
    }
    else {
      fVar3 = (float)FUN_00002068(fVar6,&DAT_00069b60);
      DAT_ffffa888 = fVar3;
    }
    fVar2 = rx8_max_float(fVar2,fVar3);
  }
  DAT_ffffa860 = fVar2;
  if (DAT_ffffa854 == '\x01') {
    DAT_ffffa88c = (float)FUN_00002068(fVar6,&PTR_LAB_00069b74);
    DAT_ffffa864 = rx8_first_order_filter(DAT_ffffa860,DAT_ffffa86c,1.0 - DAT_ffffa88c,1e-05);
  }
  else {
    DAT_ffffa864 = DAT_ffffa844;
  }
  fVar2 = arg1;
  if ((((DAT_ffffa895 != '\0') || (DAT_ffffa854 != '\x01')) && (DAT_ffffa854 != '\0')) &&
     (fVar2 = DAT_ffffa874, DAT_ffffa854 == '\x01')) {
    fVar2 = rx8_max_float(DAT_ffffa860 - DAT_ffffa864,arg1);
    fVar2 = (fVar6 * fVar2) / 38.07;
  }
  DAT_ffffa874 = fVar2;
  if ((DAT_ffffaada != '\0') && (DAT_ffffa854 != '\0')) {
    if (cVar1 == '\0') {
      DAT_ffffa890 = (float)FUN_00002068(uVar5,&DAT_00069b88);
      fVar2 = (DAT_ffffa874 - DAT_ffffa890) * 0.5;
      fVar3 = 0.446;
    }
    else {
      DAT_ffffa890 = (float)FUN_00002068(uVar5,&DAT_00069b88);
      fVar2 = DAT_ffffa874 - DAT_ffffa890;
      fVar3 = 0.892;
    }
    arg1 = rx8_clamp_float((fVar2 * 0.892) / 0.15,arg1,fVar3);
  }
  DAT_ffffa878 = arg1;
  if (DAT_ffffa854 == '\0') {
    DAT_ffffa870 = DAT_ffffa844;
  }
  else if (local_3c != '\0') {
    fVar2 = (DAT_ffffc0b0 * fVar4) / fVar6 +
            (DAT_ffffa860 - DAT_ffffa868 * DAT_ffffa878) / (1.0 - DAT_ffffa878);
    DAT_ffffa880 = (float)FUN_00002068(uVar5,&DAT_00069b24);
    DAT_ffffa884 = (float)FUN_00002068(uVar5,&DAT_00069b38);
    DAT_ffffa870 = rx8_clamp_float(fVar2,DAT_ffffa880,DAT_ffffa884);
  }
  if (DAT_ffffa428 == '\x01') {
    fVar2 = (DAT_ffffa844 * fVar4) / 38.07;
    if (DAT_ffffa854 != '\0') {
      DAT_ffffa85c = fVar2;
      fVar2 = rx8_clamp_float((DAT_ffffa870 * fVar6) / 38.07,fVar2,fVar2 + 29.1969);
    }
  }
  else {
    fVar2 = (float)FUN_00002068(uVar5,&DAT_00069b4c);
  }
  DAT_ffffa858 = fVar2;
  if (cVar1 == '\x01') {
    DAT_ffffa84c = 29.1969;
  }
  else {
    DAT_ffffa84c = (float)FUN_00002068(fVar6 - fVar4,&DAT_00069b9c);
  }
  DAT_ffffa850 = 0x402e147b;
  DAT_ffffa848 = rx8_min_float(DAT_ffffa8a8 * DAT_ffffa8d0 * DAT_ffffa858 - 0.0,DAT_ffffa84c);
  if (DAT_ffffa894 != '\0') {
    DAT_ffffa894 = DAT_ffffa894 + -1;
  }
  DAT_ffffa895 = DAT_ffffa854;
  return extraout_r0;
}


