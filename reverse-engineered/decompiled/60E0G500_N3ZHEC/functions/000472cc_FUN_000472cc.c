/* ROM address: 0x000472cc; body bytes: 330; decompiled */

void FUN_000472cc(void)

{
  char cVar2;
  char cVar3;
  uint uVar1;
  uint uVar4;
  float arg1;
  float fVar5;
  
  arg1 = (float)FUN_0003eb72(0x41700000,&DAT_ffff80a4);
  cVar2 = FUN_0003eaa4(&DAT_ffff80c4,0);
  cVar3 = FUN_0003eaa4(&DAT_ffff80c6,0);
  uVar1 = FUN_0003eaa4(&DAT_ffff876c,0);
  fVar5 = (float)FUN_0003eb72(0x41a00000,&DAT_ffff80bc);
  fVar5 = rx8_absolute_difference(fVar5,arg1);
  if ((DAT_ffffcc9c == '\x01') && ((cVar2 == '\x01' || (cVar3 == '\x01')))) {
    if (((arg1 < 9.625) || (20.375 < arg1)) || (fVar5 < 1.8)) {
      DAT_ffffcca2 = 0;
      if (DAT_ffffcca0 != 0) {
        uVar1 = 1;
      }
      DAT_ffffcca0 = FUN_00002460((int)DAT_ffffcca0,1);
    }
    else {
      DAT_ffffcca0 = 0;
      if (DAT_ffffcca2 != 0) {
        DAT_ffffcc9d = '\x01';
      }
      DAT_ffffcca2 = FUN_00002460((int)DAT_ffffcca2,1);
    }
  }
  else {
    DAT_ffffcca2 = 0;
    DAT_ffffcca0 = 0;
  }
  uVar4 = uVar1 & 0xff;
  if (DAT_ffffaae0 == '\x01') {
    if ((cVar2 != '\x01') && (cVar3 != '\x01')) goto LAB_0004741c;
    if (uVar4 != 1) {
      DAT_ffffcc9e = 1;
      goto LAB_0004741c;
    }
  }
  else if (cVar3 != '\0') {
    if (uVar4 == 0) {
      DAT_ffffcc9e = 1;
    }
    goto LAB_0004741c;
  }
  DAT_ffffcc9e = 0;
LAB_0004741c:
  if (uVar4 == 1) {
    FUN_000604dc(99,1);
  }
  else if (DAT_ffffcc9d == '\x01') {
    FUN_000604dc(99,2);
  }
  FUN_0003ebc0(&DAT_ffff876c,uVar1);
  return;
}


