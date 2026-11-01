/* ROM address: 0x000428b4; body bytes: 386; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00042958) */

uint FUN_000428b4(void)

{
  char cVar1;
  byte bVar2;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  uint uVar3;
  float fVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  bVar2 = DAT_ffffd201;
  cVar1 = DAT_ffffaada;
  fVar8 = DAT_ffffaa10;
  DAT_ffffc9c0 = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006ba90);
  uVar10 = 0;
  uVar9 = 0x3727c5ac;
  cVar4 = FUN_00002440(DAT_ffffc074,0,0x3727c5ac);
  cVar5 = FUN_00002440(DAT_ffffc084,uVar10,uVar9);
  cVar6 = FUN_00002440(DAT_ffffb134,uVar10,uVar9);
  cVar7 = FUN_000671a4(0x1f);
  if ((((cVar7 != '\0') || (cVar7 = FUN_000671a4(0x20), cVar7 != '\0')) || (bVar2 != 0)) ||
     ((DAT_ffffb14a != '\x01' &&
      (((((DAT_ffffae97 != '\x01' || (fVar8 < 70.0)) ||
         ((150.0 <= fVar8 || ((60.0 <= DAT_ffffae54 || (cVar4 != '\0')))))) || (cVar5 != '\0')) ||
       (((((cVar6 != '\0' || (1.0 <= DAT_ffffc1c0)) || (DAT_ffffcb38 != '\0')) ||
         (DAT_ffffc770 != '\0')) ||
        (((cVar1 != '\0' || (DAT_ffffc12c < DAT_ffffc9c0)) &&
         ((cVar1 != '\x01' || (DAT_ffffc9c4 < 8)))))))))))) {
    DAT_ffffc9bc = 0;
  }
  else {
    DAT_ffffc9bc = 1;
  }
  uVar3 = (uint)bVar2;
  if ((uVar3 == 1) || (cVar1 == '\0')) {
    DAT_ffffc9c4 = 0;
  }
  else {
    uVar3 = FUN_00002460((int)(short)DAT_ffffc9c4,1);
    DAT_ffffc9c4 = (ushort)uVar3;
  }
  return uVar3;
}


