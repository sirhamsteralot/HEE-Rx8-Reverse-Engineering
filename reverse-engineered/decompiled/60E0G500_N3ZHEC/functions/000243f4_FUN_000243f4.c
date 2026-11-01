/* ROM address: 0x000243f4; body bytes: 1562; decompiled */

void FUN_000243f4(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = 0x3cfa0000;
  DAT_ffffb520 = FUN_000024c0(0x3cfa0000,0,(int)DAT_ffffb4ea);
  DAT_ffffb524 = FUN_000024c0(uVar2,uVar3,(int)DAT_ffffb4ec);
  DAT_ffffb53c = DAT_ffffb4ee;
  DAT_ffffb53e = DAT_ffffb4f0;
  DAT_ffffb540 = DAT_ffffb4f2;
  DAT_ffffb542 = DAT_ffffb4f4;
  DAT_ffffb544 = DAT_ffffb4f6;
  DAT_ffffb528 = FUN_00002500(0x3da00000,uVar3,(int)DAT_ffffb4f8);
  if (DAT_ffffb4f9 < 0x80) {
    DAT_ffffb52c = (float)FUN_00002500(0x3f480000,uVar3);
  }
  else {
    fVar1 = (float)FUN_00002500(0x3f480000,uVar3,~(int)(char)DAT_ffffb4f9 + 1);
    DAT_ffffb52c = -fVar1;
  }
  FUN_000256c4((int)DAT_ffffb4fa,&DAT_ffffb59d,&DAT_ffffb596);
  DAT_ffffb55c = (DAT_ffffb596 & 1) == 1;
  DAT_ffffb55d = (DAT_ffffb596 & 2) != 0;
  DAT_ffffb55e = (DAT_ffffb596 & 4) != 0;
  DAT_ffffb55f = (DAT_ffffb596 & 8) != 0;
  DAT_ffffb560 = (DAT_ffffb596 & 0x10) != 0;
  DAT_ffffb561 = (DAT_ffffb596 & 0x20) != 0;
  DAT_ffffb562 = (DAT_ffffb596 & 0x40) != 0;
  FUN_000256c4((int)DAT_ffffb4fb,&DAT_ffffb59e,&DAT_ffffb597);
  DAT_ffffb563 = (DAT_ffffb597 & 1) == 1;
  DAT_ffffb564 = (DAT_ffffb597 & 2) != 0;
  DAT_ffffb565 = (DAT_ffffb597 & 0x40) != 0;
  DAT_ffffb566 = ((int)(char)DAT_ffffb597 & 0x80U) != 0;
  FUN_000256c4((int)DAT_ffffb4fc,&DAT_ffffb59f,&DAT_ffffb598);
  DAT_ffffb567 = (DAT_ffffb598 & 1) == 1;
  DAT_ffffb568 = (DAT_ffffb598 & 2) != 0;
  DAT_ffffb569 = (DAT_ffffb598 & 4) != 0;
  DAT_ffffb56a = (DAT_ffffb598 & 8) != 0;
  DAT_ffffb56b = (DAT_ffffb598 & 0x10) != 0;
  DAT_ffffb56c = (DAT_ffffb598 & 0x20) != 0;
  DAT_ffffb56d = (DAT_ffffb598 & 0x40) != 0;
  DAT_ffffb56e = ((int)(char)DAT_ffffb598 & 0x80U) != 0;
  FUN_000256c4((int)DAT_ffffb4fd,&DAT_ffffb5a0,&DAT_ffffb599);
  DAT_ffffb56f = (DAT_ffffb599 & 1) == 1;
  DAT_ffffb570 = (DAT_ffffb599 & 2) != 0;
  DAT_ffffb571 = (DAT_ffffb599 & 4) != 0;
  DAT_ffffb572 = (DAT_ffffb599 & 8) != 0;
  DAT_ffffb573 = (DAT_ffffb599 & 0x10) != 0;
  DAT_ffffb574 = (DAT_ffffb599 & 0x20) != 0;
  DAT_ffffb575 = (DAT_ffffb599 & 0x40) != 0;
  DAT_ffffb576 = ((int)(char)DAT_ffffb599 & 0x80U) != 0;
  FUN_000256c4((int)DAT_ffffb4fe,&DAT_ffffb5a1,&DAT_ffffb59a);
  DAT_ffffb577 = (DAT_ffffb59a & 1) == 1;
  DAT_ffffb578 = (DAT_ffffb59a & 2) != 0;
  DAT_ffffb579 = (DAT_ffffb59a & 4) != 0;
  DAT_ffffb57a = (DAT_ffffb59a & 8) != 0;
  DAT_ffffb57b = (DAT_ffffb59a & 0x10) != 0;
  FUN_000256c4((int)DAT_ffffb4ff,&DAT_ffffb5a2,&DAT_ffffb59b);
  DAT_ffffb57c = (DAT_ffffb59b & 1) == 1;
  DAT_ffffb57d = (DAT_ffffb59b & 2) != 0;
  DAT_ffffb57e = (DAT_ffffb59b & 4) != 0;
  DAT_ffffb57f = (DAT_ffffb59b & 8) != 0;
  DAT_ffffb580 = (DAT_ffffb59b & 0x10) != 0;
  DAT_ffffb581 = (DAT_ffffb59b & 0x20) != 0;
  DAT_ffffb582 = (DAT_ffffb59b & 0x40) != 0;
  DAT_ffffb583 = ((int)(char)DAT_ffffb59b & 0x80U) != 0;
  FUN_000256c4((int)DAT_ffffb500,&DAT_ffffb5a3,&DAT_ffffb59c);
  DAT_ffffb584 = (DAT_ffffb59c & 1) == 1;
  DAT_ffffb585 = (DAT_ffffb59c & 2) != 0;
  DAT_ffffb586 = (DAT_ffffb59c & 4) != 0;
  DAT_ffffb587 = (DAT_ffffb59c & 8) != 0;
  DAT_ffffb588 = (DAT_ffffb59c & 0x10) != 0;
  DAT_ffffb589 = (DAT_ffffb59c & 0x20) != 0;
  DAT_ffffb58a = (DAT_ffffb59c & 0x40) != 0;
  DAT_ffffb58b = ((int)(char)DAT_ffffb59c & 0x80U) != 0;
  DAT_ffffb546 = DAT_ffffb502;
  DAT_ffffb547 = DAT_ffffb503;
  DAT_ffffb548 = DAT_ffffb504;
  DAT_ffffb549 = DAT_ffffb505;
  DAT_ffffb54a = DAT_ffffb506;
  DAT_ffffb54b = DAT_ffffb507;
  uVar2 = 0x38a00000;
  DAT_ffffb530 = FUN_000024c0(0x38a00000,uVar3,(int)DAT_ffffb508);
  DAT_ffffb534 = FUN_000024c0(uVar2,uVar3,(int)DAT_ffffb50a);
  DAT_ffffb538 = FUN_000024c0(uVar2,uVar3,(int)DAT_ffffb50c);
  return;
}


