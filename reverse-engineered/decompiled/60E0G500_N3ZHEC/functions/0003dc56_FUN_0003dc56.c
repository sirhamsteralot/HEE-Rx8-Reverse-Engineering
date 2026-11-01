/* ROM address: 0x0003dc56; body bytes: 484; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003de76) */
/* WARNING: Removing unreachable block (ram,0x0003de7e) */

undefined ** FUN_0003dc56(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar5;
  undefined **ppuVar4;
  float fVar6;
  float fVar7;
  float extraout_fr0;
  undefined4 uVar8;
  undefined4 uVar9;
  
  cVar3 = DAT_ffffd201;
  cVar2 = DAT_ffffc656;
  fVar6 = DAT_ffffaa10;
  DAT_ffffc674 = FUN_000020c4(DAT_ffffaa1c,&DAT_00069f8c);
  DAT_ffffc670 = DAT_ffffa424 < DAT_ffffc674;
  FUN_0003df60();
  uVar9 = 0;
  if (cVar3 == '\x01') {
    DAT_ffffc66c = '\0';
    DAT_ffffc66d = '\0';
    DAT_ffffc66e = '\0';
    DAT_ffffc66f = '\0';
  }
  else {
    bVar1 = false;
    if (-100.0 <= DAT_ffffaa10) {
      DAT_ffffc66f = '\x01';
    }
    if (-10.0 <= DAT_ffffae54) {
      if ((((DAT_ffffc66e == '\0') && (cVar2 == '\0')) && (DAT_ffffc64b == '\0')) &&
         (cVar5 = FUN_000671a4(0x15), cVar5 == '\0')) {
        if ((DAT_ffffc66f == '\x01') && (DAT_ffffc66c == '\0')) {
          DAT_ffffc66d = '\x01';
        }
        bVar1 = true;
      }
    }
    else {
      DAT_ffffc66e = '\x01';
    }
    if (DAT_ffffc66d == '\x01') {
      DAT_ffffc66c = '\0';
    }
    else {
      cVar5 = FUN_00002440(DAT_ffffc65c,uVar9,0x3727c5ac);
      if (((bVar1) && (DAT_ffffc668 == 0)) && ((cVar5 == '\0' && (DAT_ffffc66f == '\0')))) {
        DAT_ffffc66c = '\x01';
      }
    }
  }
  if (cVar3 == '\x01') {
    DAT_ffffc672 = '\0';
  }
  else {
    if ((((5.625 <= DAT_ffffc660 - DAT_ffffc664) || (fVar6 < 200.0)) && (DAT_ffffd1e9 == '\0')) &&
       (cVar2 == '\0')) {
      DAT_ffffc672 = '\x01';
    }
    if (DAT_ffffc672 != '\x01') {
      uVar8 = 0x44800000;
      fVar6 = (float)FUN_000024c0(0x44800000,uVar9,0xffffffff);
      fVar7 = (float)FUN_000024c0(0x42800000,uVar9,(int)DAT_ffffc1d8);
      ppuVar4 = (undefined **)FUN_000024c0(uVar8,uVar9,(int)DAT_ffffa426);
      if (extraout_fr0 <= fVar6 + fVar7) {
        return ppuVar4;
      }
      return &PTR_0007a890;
    }
  }
  DAT_ffffc671 = 0;
  return (undefined **)&UNK_00000001;
}


