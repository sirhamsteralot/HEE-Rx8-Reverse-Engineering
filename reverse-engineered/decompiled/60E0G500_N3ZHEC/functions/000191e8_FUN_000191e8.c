/* ROM address: 0x000191e8; body bytes: 704; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000193d2) */
/* WARNING: Removing unreachable block (ram,0x00019418) */
/* WARNING: Removing unreachable block (ram,0x000193de) */
/* WARNING: Removing unreachable block (ram,0x000193ee) */
/* WARNING: Removing unreachable block (ram,0x000193f6) */
/* WARNING: Removing unreachable block (ram,0x00019400) */
/* WARNING: Removing unreachable block (ram,0x0001940c) */
/* WARNING: Removing unreachable block (ram,0x00019412) */
/* WARNING: Removing unreachable block (ram,0x000192c8) */
/* WARNING: Removing unreachable block (ram,0x00019398) */
/* WARNING: Removing unreachable block (ram,0x000193a8) */
/* WARNING: Removing unreachable block (ram,0x000193b0) */
/* WARNING: Removing unreachable block (ram,0x000193ba) */
/* WARNING: Removing unreachable block (ram,0x000193c6) */
/* WARNING: Removing unreachable block (ram,0x000193c8) */
/* WARNING: Removing unreachable block (ram,0x00019414) */

char FUN_000191e8(uint param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  cVar1 = DAT_ffffa9dd;
  DAT_ffffa9d4 = FUN_0005dd7e(0);
  if (DAT_ffffa9d4 < 0x32) {
    uVar2 = (uint)(char)DAT_ffffa9d4;
  }
  else {
    uVar2 = (int)(char)DAT_ffffa9d4 + 0xce;
  }
  uVar3 = param_1 & 0xff;
  if (DAT_ffffa9db != DAT_ffffa9d4) {
    DAT_ffffa9dc = 0;
    DAT_ffffa9da = '\0';
    if ((uVar2 & 0xff) != 0) {
      if (DAT_ffffa9d4 < 0x32) {
        if ((uVar3 == 0) || (uVar3 == 0xc)) {
          DAT_ffffa9da = '\x01';
        }
      }
      else if ((DAT_ffffa9d4 < 0x65) && ((uVar3 == 6 || (uVar3 == 0x12)))) {
        DAT_ffffa9da = '\x01';
      }
    }
  }
  if (DAT_ffffa9de != '\0') {
    DAT_ffffa9df = 0;
  }
  if (DAT_ffffa41c == '\x01') {
    DAT_ffffa9d5 = 0;
    DAT_ffffa9d6 = 0;
    DAT_ffffa9d7 = 0;
    DAT_ffffa9d8 = 0;
    DAT_ffffa9df = 0;
    DAT_ffffa9e0 = 0;
    DAT_ffffa9dc = 0;
    DAT_ffffa9db = 0;
    DAT_ffffa9da = '\0';
    DAT_ffffa9dd = '\0';
  }
  else if (DAT_ffffa9da == '\x01') {
    if (DAT_ffffa9dc == 0) {
      FUN_00019520(0xf,param_1);
    }
    else {
      DAT_ffffa9d5 = 0;
      DAT_ffffa9d7 = 0;
      DAT_ffffa9d6 = 0;
      DAT_ffffa9d8 = 0;
    }
    if (DAT_ffffa9dc < (byte)(&DAT_0006f66f)[uVar2 & 0xff]) {
      DAT_ffffa9dc = FUN_00002478((int)(char)DAT_ffffa9dc,1);
    }
    else {
      DAT_ffffa9dc = 0;
    }
    DAT_ffffa9db = DAT_ffffa9d4;
    DAT_ffffa9dd = '\x05';
  }
  else if (((DAT_ffffa6b7 == '\x01') || (DAT_ffffa6b8 == '\x01')) || (DAT_ffffa6b9 == '\x01')) {
    FUN_00019520(0,param_1);
    DAT_ffffa9dd = '\x02';
  }
  else if ((((DAT_ffffb5b8 < 0.0) || (1200.0 <= DAT_ffffb5b8)) ||
           ((DAT_ffffaa10 < -40.0 || ((120.0 <= DAT_ffffaa10 || (DAT_ffffadbc < 0.0)))))) ||
          (125.0 <= DAT_ffffadbc)) {
    if ((uVar3 == 0) || (uVar3 == 0xc)) {
      DAT_ffffa9d5 = 0;
      DAT_ffffa9d7 = 0;
    }
    if ((uVar3 == 6) || (uVar3 == 0x12)) {
      DAT_ffffa9d6 = 0;
      DAT_ffffa9d8 = 0;
    }
    DAT_ffffa9dd = '\0';
  }
  else {
    FUN_00019520(0,param_1);
    DAT_ffffa9dd = '\x01';
  }
  DAT_ffffa9de = 0;
  if ((cVar1 != DAT_ffffa9dd) && (DAT_ffffa9dd != '\0')) {
    DAT_ffffa9d9 = 1;
    DAT_ffffa9df = 0;
  }
  return cVar1;
}


