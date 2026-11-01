/* ROM address: 0x0003df60; body bytes: 286; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003dfba) */

uint FUN_0003df60(void)

{
  char cVar1;
  uint uVar2;
  uint extraout_r0;
  float extraout_fr0;
  float fVar3;
  undefined4 uVar4;
  
  cVar1 = DAT_ffffa42c;
  if ((DAT_ffffa428 == '\0') || ((DAT_ffffa42c == '\x01' && (DAT_ffffc678 == '\0')))) {
    uVar4 = DAT_ffffaa1c;
    DAT_ffffc668 = FUN_000020c4(DAT_ffffaa1c,&PTR_DAT_0006b9b0);
    DAT_ffffc66a = (short)(int)((float)((uint)DAT_ffffc668 * 0x80) * 0.00390625);
    DAT_ffffc676 = DAT_ffffc668;
    uVar2 = FUN_00002068(uVar4,&PTR_DAT_0006b9bc);
    DAT_ffffc65c = extraout_fr0;
  }
  else {
    uVar2 = (uint)DAT_ffffc670;
    if ((uVar2 == 1) || (95.88 < DAT_ffffbc1c)) {
      if ((DAT_ffffc66a != 0) && (DAT_ffffc66a = DAT_ffffc66a + -1, DAT_ffffc668 != 0)) {
        DAT_ffffc668 = DAT_ffffc668 - 1;
      }
    }
    else if (DAT_ffffc668 != 0) {
      DAT_ffffc668 = DAT_ffffc668 - 1;
    }
    if (((DAT_ffffc5fe == '\0') && (uVar2 = (uint)DAT_ffffc600, uVar2 == 0)) &&
       (DAT_ffffb13b == '\0')) {
      fVar3 = DAT_ffffaa88 * 0.099999994;
      if (DAT_ffffb19a == '\x01') {
        fVar3 = fVar3 * 1.0;
      }
      DAT_ffffc65c = rx8_max_float(DAT_ffffc65c - fVar3,0.0);
      uVar2 = extraout_r0;
    }
  }
  DAT_ffffc678 = cVar1;
  return uVar2;
}


