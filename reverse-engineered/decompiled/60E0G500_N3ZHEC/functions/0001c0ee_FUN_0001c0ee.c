/* ROM address: 0x0001c0ee; body bytes: 558; decompiled */

void FUN_0001c0ee(void)

{
  char cVar3;
  uint uVar1;
  uint uVar2;
  char cVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  
  cVar3 = FUN_0003eaa4(&DAT_ffff8766,0);
  cVar4 = DAT_ffffaae0;
  uVar1 = FUN_0003eaa4(&DAT_ffff80c4,0);
  uVar2 = FUN_0003eaa4(&DAT_ffff80c6,0);
  if ((((uVar1 & 0xff) == 0) || ((uVar2 & 0xff) == 0)) && (DAT_ffffcd07 == '\x01')) {
    DAT_ffffae05 = '\x01';
  }
  else {
    DAT_ffffae05 = '\0';
  }
  if ((DAT_ffffae05 == '\x01') && (cVar3 == '\0')) {
    DAT_ffffae06 = 9 < DAT_ffffae40;
    DAT_ffffae40 = FUN_00002460((int)(short)DAT_ffffae40,1);
  }
  else {
    DAT_ffffae06 = '\0';
    DAT_ffffae40 = 0;
  }
  if ((DAT_ffffae44 == '\0') && (DAT_ffffae05 == '\x01')) {
    DAT_ffffade0 = DAT_ffffb520;
    DAT_ffffade4 = DAT_ffffb524;
  }
  else if (cVar3 == '\0') {
    fVar5 = 1e-05;
    DAT_ffffade0 = rx8_first_order_filter(DAT_ffffb520,DAT_ffffade0,0.5,1e-05);
    DAT_ffffade4 = rx8_first_order_filter(DAT_ffffb524,DAT_ffffade4,0.5,fVar5);
  }
  if ((DAT_ffffccfa == '\x01') && (DAT_ffffae48 == '\0')) {
    uVar2 = 0;
  }
  DAT_ffffae48 = DAT_ffffccfa;
  if (((DAT_ffffccd8 == '\x01') || (DAT_ffffccd9 == '\x01')) ||
     (cVar3 = FUN_0003eaa4(&DAT_ffff8764,0), cVar3 == '\x01')) {
    uVar1 = 0;
    uVar2 = 0;
    DAT_ffffadd0 = 15.0;
    DAT_ffffadf0 = 15.0;
    FUN_0003ebc0(&DAT_ffff80c8,0);
  }
  else if (DAT_ffffae06 == '\x01') {
    if (cVar4 == '\x01') {
      uVar1 = 1;
    }
    else {
      uVar2 = 1;
    }
    FUN_0003ebc0(&DAT_ffff80c8,1);
    DAT_ffffadd0 = rx8_clamp_float(DAT_ffffade0,10.0,20.0);
    DAT_ffffadf0 = rx8_clamp_float(DAT_ffffade4,10.0,20.0);
  }
  cVar4 = FUN_0003eaa4(&DAT_ffff80c8,0);
  if (cVar4 == '\0') {
    FUN_0003ec20(0x41700000,&DAT_ffff80a4);
    FUN_0003ec20(0x41700000,&DAT_ffff80ac);
  }
  else if ((((uVar1 & 0xff) == 1) || ((uVar2 & 0xff) == 1)) && (DAT_ffffcc9e == '\x01')) {
    uVar7 = 0;
    fVar5 = (float)FUN_0003eb72(0,&DAT_ffff80d4);
    fVar5 = DAT_ffffadd0 + fVar5;
    fVar6 = (float)FUN_0003eb72(uVar7,&DAT_ffff80dc);
    fVar6 = DAT_ffffadf0 + fVar6;
    FUN_0003ec20(fVar5,&DAT_ffff80a4);
    FUN_0003ec20(fVar6,&DAT_ffff80ac);
  }
  FUN_0003ebc0(&DAT_ffff80c4,uVar1);
  FUN_0003ebc0(&DAT_ffff80c6,uVar2);
  DAT_ffffae44 = DAT_ffffae05;
  return;
}


