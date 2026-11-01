/* ROM address: 0x00017dbc; body bytes: 382; decompiled */

uint FUN_00017dbc(void)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  char cVar5;
  uint uVar4;
  undefined4 local_3c;
  char cStack_38;
  char cStack_34;
  char cStack_30;
  char cStack_2c;
  undefined1 uStack_28;
  undefined1 uStack_24;
  
  cVar3 = DAT_ffffa96c;
  bVar2 = false;
  bVar1 = false;
  cStack_34 = DAT_ffffaae0;
  cStack_30 = DAT_ffffa978;
  uStack_24 = 0;
  uStack_28 = 0;
  cStack_38 = DAT_ffffa96c;
  cStack_2c = DAT_ffffa96a;
  if ((DAT_ffffa428 == '\0') && (DAT_ffffaae0 == '\x01')) {
    uStack_24 = 1;
    DAT_ffffa979 = '\0';
    DAT_ffffa975 = 2;
  }
  else if ((DAT_ffffa428 == '\x01') && ((DAT_ffffa979 == '\0' && (DAT_ffffa998 == '\0')))) {
    uStack_28 = 1;
  }
  else {
    bVar1 = DAT_ffffa979 == '\x01';
    if ((DAT_ffffaae0 == '\0') &&
       (((bVar1 && (DAT_ffffa998 == '\0')) && (cVar5 = FUN_0003eaa4(&DAT_ffff807c,0), cVar5 == '\0')
        ))) {
      bVar2 = true;
    }
    DAT_ffffa96c = cVar3;
    if (((!bVar2) && (cStack_30 == '\0')) && (DAT_ffffa970 == '\x01')) {
      DAT_ffffa96c = '\x01';
    }
    if ((cStack_38 == '\0') && (DAT_ffffa96c == '\x01')) {
      DAT_ffffa96e = 0;
    }
  }
  DAT_ffffa96b = uStack_24;
  DAT_ffffa968 = uStack_28;
  if (DAT_ffffaa10 < -40.0) {
    if (499 < DAT_ffffa96e) {
      DAT_ffffa96c = '\0';
    }
  }
  else if (0x9b < DAT_ffffa96e) {
    DAT_ffffa96c = '\0';
  }
  DAT_ffffa969 = bVar1;
  DAT_ffffa96a = bVar2;
  DAT_ffffa96e = FUN_00002460((int)(short)DAT_ffffa96e,1);
  DAT_ffffa970 = cStack_30;
  uVar4 = 0x10;
  if ((cStack_2c == '\0') && (uVar4 = (uint)DAT_ffffa96a, uVar4 == 1)) {
    local_3c = 0;
    uVar4 = FUN_00009630(0,2,&local_3c);
  }
  return uVar4;
}


