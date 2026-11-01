/* ROM address: 0x00022468; body bytes: 172; decompiled */

uint FUN_00022468(void)

{
  uint uVar1;
  undefined4 extraout_fr0;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  
  DAT_ffffb348 = DAT_ffffbc3c;
  uVar2 = DAT_ffffb3fc;
  uVar3 = DAT_ffffb5b8;
  fVar4 = DAT_ffffbc3c;
  DAT_ffffb354 = FUN_000020dc(DAT_ffffbc3c,DAT_ffffb5b8,&DAT_0006a6d4);
  if (((DAT_ffffbc33 == '\x01') && (fVar4 <= DAT_ffffb330)) || (DAT_ffffa9ea == '\x01')) {
    DAT_ffffb33f = 1;
    DAT_ffffb328 = DAT_ffffb354;
  }
  else {
    DAT_ffffb33f = 0;
    DAT_ffffb328 = uVar2;
  }
  uVar1 = (uint)DAT_ffffbc34;
  if ((uVar1 == 1) && (DAT_ffffbc32 == '\0')) {
    uVar1 = FUN_00002068(uVar3,&DAT_0006a6c0);
    DAT_ffffb340 = 1;
    DAT_ffffb32c = extraout_fr0;
  }
  else {
    DAT_ffffb340 = 0;
    DAT_ffffb32c = uVar2;
  }
  return uVar1;
}


