/* ROM address: 0x0004a9a2; body bytes: 306; decompiled */

undefined1 * FUN_0004a9a2(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar5;
  undefined1 *puVar4;
  float fVar6;
  
  cVar3 = DAT_ffffd201;
  cVar2 = DAT_ffffcdc3;
  cVar1 = DAT_ffffaada;
  if ((DAT_ffffd201 == '\x01') || ((DAT_ffffcdc3 == '\0' && (DAT_ffffcdf4 == '\x01')))) {
    DAT_ffffcdc6 = 10;
  }
  else if (DAT_ffffcdc6 != 0) {
    DAT_ffffcdc6 = DAT_ffffcdc6 + -1;
  }
  fVar6 = DAT_ffffaa10;
  if ((DAT_ffffaada == '\0') && (DAT_ffffd201 == '\0')) {
    if (DAT_ffffcdf5 == '\x01') {
      DAT_ffffcdf6 = '\x01';
    }
    if (DAT_ffffcdf6 == '\x01') {
      DAT_ffffcde8 = FUN_00002460((int)(short)DAT_ffffcde8,1);
    }
  }
  else {
    DAT_ffffcdf6 = '\0';
    DAT_ffffcde8 = 0;
  }
  cVar5 = FUN_000671a4(0x59);
  if (((((((cVar5 != '\0') || (cVar5 = FUN_000671a4(0x5a), cVar5 != '\0')) ||
         (DAT_ffffb178 != '\x01')) || ((fVar6 < 70.0 || (120.0 <= fVar6)))) ||
       ((110.0 <= DAT_ffffae54 || ((DAT_ffffae98 != '\0' || (DAT_ffffcde8 < 0x7e)))))) ||
      (DAT_ffffcdf6 != '\x01')) || ((DAT_ffffcdc6 != 0 || (cVar3 != '\0')))) {
    puVar4 = &DAT_ffffcddc;
    DAT_ffffcddc = 0;
  }
  else {
    DAT_ffffcddc = 1;
    puVar4 = (undefined1 *)0x0;
  }
  DAT_ffffcdf4 = cVar2;
  DAT_ffffcdf5 = cVar1;
  return puVar4;
}


