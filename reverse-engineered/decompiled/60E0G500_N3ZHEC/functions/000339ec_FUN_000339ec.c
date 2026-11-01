/* ROM address: 0x000339ec; body bytes: 166; decompiled */

void FUN_000339ec(void)

{
  char cVar1;
  undefined **ppuVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  
  cVar1 = DAT_ffffce6f;
  fVar5 = DAT_ffffaa1c;
  uVar6 = DAT_ffffaa10;
  fVar3 = (float)FUN_00002068(DAT_ffffc12c,&DAT_0006b2a0);
  fVar4 = (float)FUN_000020dc(uVar6,DAT_ffffaa1c,&DAT_0006b2b4);
  if (((cVar1 == '\0') && (5.0 <= fVar5)) || ((cVar1 == '\x01' && (200.0 <= fVar5)))) {
    DAT_ffffc078 = '\x01';
  }
  else {
    DAT_ffffc078 = '\0';
  }
  DAT_ffffc07c = fVar3 * fVar4;
  if (DAT_ffffc078 == '\x01') {
    ppuVar2 = (undefined **)&DAT_0006b2d0;
  }
  else {
    ppuVar2 = &PTR_DAT_0006b2ec;
  }
  DAT_ffffc080 = (float)FUN_000020dc(DAT_ffffb5b8,uVar6,ppuVar2);
  DAT_ffffc074 = DAT_ffffc07c + DAT_ffffc080;
  return;
}


