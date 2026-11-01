/* ROM address: 0x00014fbc; body bytes: 202; decompiled */

uint FUN_00014fbc(void)

{
  uint uVar1;
  float fVar2;
  
  if (((DAT_ffffa8b8 == '\x01') || (DAT_ffffa41c == '\x01')) ||
     ((fVar2 = DAT_ffffa7d0, DAT_ffffa7c4 == 1 &&
      (((0x1e < DAT_ffffa824 && (DAT_ffffa7c5 == '\0')) && (0x1e < DAT_ffffa826)))))) {
    fVar2 = DAT_ffffa7b8;
  }
  if (DAT_ffffa7c4 == 0) {
    DAT_ffffa80c = (float)FUN_000020dc(DAT_ffffaa14,DAT_ffffad8c,&PTR_DAT_00069b08);
    if (DAT_ffffa80c < fVar2) {
      fVar2 = rx8_max_float(fVar2 - 0.00087,DAT_ffffa80c);
    }
  }
  uVar1 = (uint)DAT_ffffa7c4;
  DAT_ffffa7d0 = fVar2;
  if (uVar1 == 1) {
    uVar1 = FUN_00002460((int)(short)DAT_ffffa824,1);
    DAT_ffffa824 = (ushort)uVar1;
  }
  else {
    DAT_ffffa824 = 0;
  }
  if (DAT_ffffa7c5 == '\0') {
    uVar1 = FUN_00002460((int)(short)DAT_ffffa826,1);
    DAT_ffffa826 = (ushort)uVar1;
  }
  else {
    DAT_ffffa826 = 0;
  }
  return uVar1;
}


