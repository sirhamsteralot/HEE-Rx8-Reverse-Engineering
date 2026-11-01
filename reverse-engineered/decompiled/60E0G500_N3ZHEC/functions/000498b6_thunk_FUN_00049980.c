/* ROM address: 0x000498b6; body bytes: 4; decompiled */

uint thunk_FUN_00049980(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint extraout_r0;
  float fVar4;
  float fVar5;
  float extraout_fr0;
  float arg1;
  float fVar6;
  
  cVar1 = DAT_ffffaae0;
  arg1 = DAT_ffffae54;
  fVar6 = DAT_ffffbc1c;
  fVar4 = (float)FUN_00002068(DAT_ffffbc1c,&DAT_0006bdd8);
  fVar5 = (float)FUN_00002068(fVar6,&DAT_0006bdec);
  uVar2 = FUN_000020c4(fVar6,&DAT_0006be14);
  uVar3 = FUN_00002068(fVar6,&DAT_0006be00);
  if (((((fVar6 <= 80.0) || (DAT_ffffc12c <= fVar4)) || (DAT_ffffaa88 <= fVar5)) ||
      ((uVar3 = 1, DAT_ffffc656 == '\x01' || (uVar3 = 1, DAT_ffffc64b == '\x01')))) ||
     (uVar3 = 1, DAT_ffffc68e == '\x01')) {
    DAT_ffffcd3c = 0xea6;
  }
  else {
    uVar3 = (uint)DAT_ffffcd3c;
    if (uVar3 < (uVar2 & 0xffff)) {
      DAT_ffffcd3c = 0;
    }
    else {
      DAT_ffffcd3c = DAT_ffffcd3c - (short)uVar2;
    }
  }
  if (DAT_ffffcd3c == 0) {
    DAT_ffffcd34 = arg1 - extraout_fr0;
  }
  else {
    DAT_ffffcd34 = rx8_min_float(DAT_ffffcd34,arg1);
    uVar3 = extraout_r0;
  }
  if ((cVar1 == '\0') && (uVar3 = (uint)DAT_ffffcd3e, uVar3 == 1)) {
    uVar3 = FUN_0003ec20(DAT_ffffcd34,&DAT_ffff8790);
  }
  DAT_ffffcd3e = cVar1;
  return uVar3;
}


