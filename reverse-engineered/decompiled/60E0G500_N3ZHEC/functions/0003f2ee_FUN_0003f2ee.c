/* ROM address: 0x0003f2ee; body bytes: 292; decompiled */

void FUN_0003f2ee(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  
  uVar2 = DAT_ffffc12c;
  uVar3 = DAT_ffffb5b8;
  uVar4 = DAT_ffffaa10;
  DAT_ffffc6c4 = rx8_max_float(DAT_ffffa788,DAT_ffffa78c);
  DAT_ffffc6c8 = FUN_00002068(DAT_ffffaa88,&DAT_0006baf8);
  fVar5 = 1.0;
  if (DAT_ffffc6bc == '\x01') {
    DAT_ffffc6cc = 0x3f800000;
  }
  else {
    DAT_ffffc6cc = FUN_00002068(uVar4,&DAT_0006bb0c);
  }
  if (DAT_ffffb19b == '\x01') {
    DAT_ffffc6d0 = DAT_ffffb190;
    DAT_ffffc6d4 = (float)FUN_00002068(DAT_ffffb190,&DAT_0006babc);
  }
  else {
    DAT_ffffc6d4 = 0.0;
  }
  DAT_ffffc6d8 = (DAT_ffffa6ac + DAT_ffffa760 + DAT_ffffa670 + DAT_ffffc6c4) * 2.25;
  if (DAT_ffffb13a == '\x01') {
    DAT_ffffc6dc = 500.0;
  }
  else {
    DAT_ffffc710 = (float)FUN_000020dc(uVar3,uVar2,&DAT_0006bb84);
    DAT_ffffc6dc = DAT_ffffc6d4 + DAT_ffffc6d8 + DAT_ffffc710;
  }
  if ((DAT_ffffa428 == '\0') && (DAT_ffffa41c == '\0')) {
    FUN_0003ec20(DAT_ffffc6b0,&DAT_ffff8730);
  }
  fVar1 = fVar5;
  if (DAT_ffffbfd4 == '\x01') {
    fVar5 = (float)FUN_00002068(DAT_ffffaae4,&DAT_0006bad0);
    fVar1 = DAT_ffffc5a8 * fVar5;
  }
  DAT_ffffc6e4 = fVar1;
  DAT_ffffc6e0 = fVar5;
  FUN_0003f7ee();
  return;
}


