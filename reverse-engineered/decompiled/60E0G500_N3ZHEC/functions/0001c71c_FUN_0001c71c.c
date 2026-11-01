/* ROM address: 0x0001c71c; body bytes: 494; decompiled_with_warnings */

/* WARNING: Heritage AFTER dead removal. Example location: r0xffffae38 : 0x0001c83a */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_0001c71c(void)

{
  ushort uVar1;
  uint uVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  float arg0;
  
  uVar1 = DAT_ffffccf4;
  arg0 = DAT_ffffadf4;
  fVar5 = DAT_ffffb520;
  uVar2 = FUN_0003eaa4(&DAT_ffff80ca,1);
  if (((uVar2 & 0xff) == 0) && (2 < uVar1)) {
    cVar3 = FUN_0003eaa4(&DAT_ffff8766,0);
    if (cVar3 != '\0') goto LAB_0001c7d0;
    DAT_ffffadda = '\x01';
  }
  else {
LAB_0001c7d0:
    DAT_ffffadda = '\0';
  }
  DAT_ffffae3c = DAT_ffffae38;
  DAT_ffffae38 = DAT_ffffae34;
  DAT_ffffae34 = DAT_ffffae30;
  DAT_ffffae30 = DAT_ffffae2c;
  DAT_ffffae2c = DAT_ffffae28;
  DAT_ffffae28 = fVar5;
  if (DAT_ffffadda == '\x01') {
    if (DAT_ffffae47 == '\0') {
      arg0 = fVar5;
    }
    arg0 = (arg0 + fVar5) * 0.5;
    DAT_ffffae04 = FUN_00002478((int)(char)DAT_ffffae04,1);
    fVar4 = rx8_absolute_difference(fVar5,DAT_ffffae38);
    if (((fVar5 < 15.0) || (25.0 < fVar5)) && (0.2442 <= fVar4)) {
      DAT_ffffae07 = '\x01';
    }
  }
  if ((((DAT_ffffaae0 != '\0') && (DAT_ffffccd8 != '\x01')) &&
      ((DAT_ffffccd9 != '\x01' && ((DAT_ffffb567 != '\x01' && (DAT_ffffb56b != '\x01')))))) &&
     (DAT_ffffb56d != '\x01')) {
    cVar3 = FUN_0003eaa4(&DAT_ffff8764,0);
    if (cVar3 != '\x01') {
      DAT_ffffadd9 = '\0';
      goto LAB_0001c904;
    }
  }
  DAT_ffffadd9 = '\x01';
  uVar2 = 1;
LAB_0001c904:
  if (((DAT_ffffadd9 == '\0') && (7 < uVar1)) && ((uVar2 & 0xff) == 0)) {
    DAT_ffffadd8 = 1;
    uVar2 = 1;
    if ((DAT_ffffae07 == '\0') && (3 < DAT_ffffae04)) {
      DAT_ffffaddb = 1;
      fVar5 = rx8_clamp_float(arg0,15.0,25.0);
      FUN_0003ec20(fVar5,&DAT_ffff80bc);
      fVar4 = rx8_clamp_float(DAT_ffffadcc,15.0,25.0);
      FUN_0003ec20(fVar4,&DAT_ffff80cc);
      DAT_ffffadf8 = rx8_clamp_float(fVar5 - fVar4,-0.428,0.428);
    }
  }
  DAT_ffffadf4 = arg0;
  FUN_0003ebc0(&DAT_ffff80ca,uVar2);
  DAT_ffffae47 = DAT_ffffadda;
  return;
}


