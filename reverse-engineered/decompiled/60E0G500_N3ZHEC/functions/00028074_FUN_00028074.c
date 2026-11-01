/* ROM address: 0x00028074; body bytes: 358; decompiled */

code * FUN_00028074(void)

{
  uint uVar1;
  code *pcVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar3 = 0.0;
  fVar4 = DAT_ffffb5b8;
  fVar5 = DAT_ffffb360;
  uVar1 = FUN_00002440(DAT_ffffb360,0,0x3727c5ac);
  fVar3 = rx8_absolute_difference(DAT_ffffadc8,fVar3);
  pcVar2 = (code *)(uint)DAT_ffffb70c;
  if (((((((pcVar2 != (code *)&UNK_00000001) || (pcVar2 = (code *)0x9c4, DAT_ffffa424 < 0x9c4)) ||
         (pcVar2 = (code *)(int)DAT_ffffa42c, pcVar2 != (code *)0x0)) ||
        ((pcVar2 = (code *)&DAT_ffffba85, DAT_ffffba85 < 8 || (0.97 <= fVar3)))) ||
       (((1.05 <= DAT_ffffc1c0 ||
         ((DAT_ffffb13a != '\0' || (pcVar2 = (code *)&DAT_000759e2, DAT_ffffba86 < 0x10)))) ||
        (DAT_ffffaa10 < 70.0)))) ||
      (((fVar4 < 660.0 || (8500.0 <= fVar4)) ||
       (pcVar2 = (code *)(uint)DAT_ffffaaf9, pcVar2 != (code *)&UNK_00000001)))) ||
     (((pcVar2 = (code *)(uint)DAT_ffffba88, pcVar2 != (code *)(uVar1 & 0xff) ||
       (pcVar2 = (code *)&DAT_ffffba87, DAT_ffffba87 < 8)) ||
      (((uVar1 & 0xff) != 0 &&
       (((fVar5 <= 0.0 || (0.2 < DAT_ffffb290)) ||
        (pcVar2 = (code *)&DAT_000759ec, DAT_ffffb364 < 0x271)))))))) {
    DAT_ffffba7a = 0;
    DAT_ffffba76 = 8;
  }
  else {
    DAT_ffffba7a = 1;
    if (DAT_ffffba76 != 0) {
      DAT_ffffba76 = DAT_ffffba76 + -1;
    }
  }
  return pcVar2;
}


