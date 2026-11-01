/* ROM address: 0x0005afa6; body bytes: 474; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0005b1be) */

undefined1 FUN_0005afa6(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  
  cVar1 = DAT_ffffd04b;
  DAT_ffffd316 = DAT_ffffd315;
  fVar2 = DAT_ffffbc1c;
  fVar3 = DAT_ffffd19c;
  DAT_ffffd315 = FUN_00011f34();
  if (DAT_ffffd315 == '\0') {
    DAT_ffffd2d0 = 0;
    DAT_ffffd2d2 = 0;
    DAT_ffffd2d4 = 0;
    DAT_ffffd2d6 = 0;
    DAT_ffffd2d8 = 0;
    goto LAB_0005b102;
  }
  if ((cVar1 == '\x01') && (-10.0 <= fVar3)) {
    DAT_ffffd2d0 = FUN_00002460((int)DAT_ffffd2d0,1);
  }
  if ((4.444 <= fVar3) && (fVar3 <= 35.0)) {
    DAT_ffffd2d2 = FUN_00002460((int)DAT_ffffd2d2,1);
  }
  if ((cVar1 != '\x01') || (fVar3 < -10.0)) {
LAB_0005b0ca:
    DAT_ffffd2d6 = 0;
  }
  else {
    if (40.233 <= fVar2) {
      DAT_ffffd2d4 = FUN_00002460((int)DAT_ffffd2d4,1);
    }
    if (((fVar3 < -10.0) || (DAT_ffffaada != '\x01')) || (1.609 < fVar2)) goto LAB_0005b0ca;
    DAT_ffffd2d6 = FUN_00002460((int)(short)DAT_ffffd2d6,1);
  }
  if (DAT_ffffa9e4 == '\x01') {
    DAT_ffffd2d8 = FUN_00002460((int)(short)DAT_ffffd2d8,1);
  }
  else {
    DAT_ffffd2d8 = 0;
  }
LAB_0005b102:
  if (0x4d < DAT_ffffd2d8) {
    DAT_ffffd2f1 = 1;
  }
  if (0xe9 < DAT_ffffd2d6) {
    DAT_ffffd2db = 1;
  }
  cVar1 = FUN_00060194(0x37,0);
  if (((((cVar1 == '\x01') || (cVar1 = FUN_00060194(0x37,2), cVar1 == '\x01')) ||
       ((cVar1 = FUN_00060194(0xf,2), cVar1 == '\x01' ||
        ((cVar1 = FUN_00060194(0x10,2), cVar1 == '\x01' ||
         (cVar1 = FUN_00060194(0xe,2), cVar1 == '\x01')))))) ||
      (cVar1 = FUN_00060194(0xc,2), cVar1 == '\x01')) ||
     (((cVar1 = FUN_00060194(0xd,2), cVar1 == '\x01' ||
       (cVar1 = FUN_00060194(0x13,2), cVar1 == '\x01')) ||
      (cVar1 = FUN_00060194(0x14,2), cVar1 == '\x01')))) {
    DAT_ffffd2da = 1;
  }
  DAT_ffffd314 = 0;
  return DAT_ffffd201;
}


