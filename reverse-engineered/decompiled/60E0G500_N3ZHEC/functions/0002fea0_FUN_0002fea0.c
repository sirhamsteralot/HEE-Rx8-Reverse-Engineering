/* ROM address: 0x0002fea0; body bytes: 504; decompiled */

uint FUN_0002fea0(void)

{
  char cVar1;
  uint uVar2;
  undefined4 local_18 [2];
  
  cVar1 = DAT_ffffaae0;
  if (DAT_ffffae54 < 40.0) {
    if (DAT_ffffae54 < 37.0) {
      DAT_ffffbe19 = '\0';
    }
  }
  else {
    DAT_ffffbe19 = '\x01';
  }
  if (DAT_ffffcd34 < 32.0) {
    if (DAT_ffffcd34 < 29.0) {
      DAT_ffffbe1a = '\0';
    }
  }
  else {
    DAT_ffffbe1a = '\x01';
  }
  if (DAT_ffffaa10 < 85.0) {
    if (DAT_ffffaa10 < 79.0) {
      DAT_ffffbe1b = '\0';
    }
  }
  else {
    DAT_ffffbe1b = '\x01';
  }
  if (DAT_ffffc6b4 < 750.0) {
    if (DAT_ffffc6b4 < 700.0) {
      DAT_ffffbe1c = '\0';
    }
  }
  else {
    DAT_ffffbe1c = '\x01';
  }
  if (DAT_ffffaa10 < 105.0) {
    if (DAT_ffffaa10 < 99.0) {
      DAT_ffffbe1d = '\0';
    }
  }
  else {
    DAT_ffffbe1d = '\x01';
  }
  if (DAT_ffffaae0 == '\x01') {
    DAT_ffffbe10 = 0x493e;
  }
  else if (DAT_ffffbe10 != 0) {
    DAT_ffffbe10 = DAT_ffffbe10 + -1;
  }
  if ((((((DAT_ffffbe19 == '\x01') && (DAT_ffffbe1a == '\x01')) && (DAT_ffffbe1b == '\x01')) &&
       ((DAT_ffffbe1c == '\x01' && (DAT_ffffbe10 != 0)))) && (0x24a < DAT_ffffa422)) ||
     (((DAT_ffffbe1d == '\x01' && (DAT_ffffbe10 != 0)) ||
      ((DAT_ffffa9e9 == '\x01' && (DAT_ffffbe10 != 0)))))) {
    DAT_ffffbe12 = '\x01';
  }
  else {
    DAT_ffffbe12 = '\0';
  }
  if ((DAT_ffffaae0 == '\x01') || (DAT_ffffbe12 == '\0')) {
    DAT_ffffbe0c = '\0';
  }
  else if (DAT_ffffbe22 == '\x01') {
    if (DAT_ffffbe12 == '\x01') {
      DAT_ffffbe0c = '\x01';
    }
    else {
      DAT_ffffbe0c = '\0';
    }
  }
  if ((DAT_ffffbe21 == 0) && (DAT_ffffbe0c == '\x01')) {
    local_18[0] = 0;
    FUN_00009630(0,2,local_18);
  }
  uVar2 = (uint)DAT_ffffbe21;
  if ((uVar2 == 1) && (DAT_ffffbe0c == '\0')) {
    local_18[0] = 0;
    uVar2 = FUN_00009630(0,3,local_18);
  }
  DAT_ffffbe21 = DAT_ffffbe0c;
  DAT_ffffbe22 = cVar1;
  return uVar2;
}


