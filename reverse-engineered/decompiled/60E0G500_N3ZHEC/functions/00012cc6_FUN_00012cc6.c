/* ROM address: 0x00012cc6; body bytes: 214; decompiled */

uint FUN_00012cc6(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  uint extraout_r0;
  float fVar4;
  
  cVar2 = DAT_ffffa445;
  cVar1 = DAT_ffffa444;
  fVar4 = 0.0;
  if (((DAT_ffffc600 == '\0') && (0x9c3 < DAT_ffffa424)) && (DAT_ffffaada == '\0')) {
    DAT_ffffa678 = (float)FUN_0003ea74(DAT_ffffc128 - DAT_ffffc12c);
  }
  else {
    DAT_ffffa678 = 0.0;
  }
  if (((DAT_ffffa6a9 == '\x01') && (cVar1 == '\0')) || ((DAT_ffffa6aa == '\x01' && (cVar2 == '\0')))
     ) {
    uVar3 = 1;
    DAT_ffffa68f = 0xff;
  }
  else {
    uVar3 = (uint)DAT_ffffa68f;
    if (uVar3 != 0) {
      DAT_ffffa68f = DAT_ffffa68f - 1;
    }
  }
  if (DAT_ffffa68f == 0) {
    if ((DAT_ffffa670 <= 0.0) && (DAT_ffffa674 <= 0.0)) {
      DAT_ffffa680 = fVar4;
    }
  }
  else {
    DAT_ffffa680 = rx8_max_float(DAT_ffffa680,DAT_ffffa678);
    uVar3 = extraout_r0;
  }
  DAT_ffffa6a9 = cVar1;
  DAT_ffffa6aa = cVar2;
  return uVar3;
}


