/* ROM address: 0x00044b58; body bytes: 466; decompiled */

uint FUN_00044b58(void)

{
  char cVar1;
  char cVar3;
  char cVar4;
  uint uVar2;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float arg1;
  
  cVar1 = DAT_ffffd201;
  fVar9 = DAT_ffffcb40;
  fVar5 = rx8_absolute_difference(DAT_ffffaae8,DAT_ffffae74);
  arg1 = 0.0;
  fVar6 = rx8_absolute_difference(DAT_ffffcb28,0.0);
  fVar7 = rx8_absolute_difference(DAT_ffffcb2c,arg1);
  fVar8 = rx8_absolute_difference(DAT_ffffadc8,arg1);
  cVar3 = FUN_00002440(DAT_ffffb360,arg1,0x3727c5ac);
  DAT_ffffcba8 = FUN_00002120(DAT_ffffc12c,DAT_ffffb5b8,&DAT_0006bd24);
  cVar4 = FUN_000671a4(0x2c);
  if (((((((cVar4 != '\0') || (DAT_ffffcbaa != '\x01')) || (DAT_ffffb0ed != '\x01')) ||
        ((DAT_ffffaa10 < 70.0 || (fVar9 < 400.0)))) ||
       (((1200.0 <= fVar9 || ((0.0996 <= fVar5 || (DAT_ffffcbc6 < 0x1f)))) || (DAT_ffffbc1c < 0.0)))
       ) || ((((DAT_ffffcba8 < 0x80 || (50.0 <= fVar6)) || (0.05 <= fVar7)) ||
             (((0.42 <= fVar8 || (DAT_ffffc772 != '\x01')) ||
              ((DAT_ffffcb3c != '\0' || (cVar1 != '\0')))))))) ||
     ((cVar3 != '\0' && (DAT_ffffb364 < 0x271)))) {
    DAT_ffffcb38 = 0;
  }
  else {
    DAT_ffffcb38 = 1;
  }
  if ((0.0996 <= fVar5) || (cVar1 != '\0')) {
    DAT_ffffcbc6 = 0;
  }
  else {
    DAT_ffffcbc6 = FUN_00002460((int)(short)DAT_ffffcbc6,1);
  }
  uVar2 = (uint)DAT_ffffcb38;
  if (uVar2 == 1) {
    if (0x25 < DAT_ffffcbc8) {
      DAT_ffffcb39 = 1;
    }
    uVar2 = FUN_00002460((int)(short)DAT_ffffcbc8,1);
    DAT_ffffcbc8 = (ushort)uVar2;
  }
  else {
    DAT_ffffcb39 = 0;
    DAT_ffffcbc8 = 0;
  }
  return uVar2;
}


