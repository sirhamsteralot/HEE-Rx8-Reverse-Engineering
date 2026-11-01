/* ROM address: 0x0001e978; body bytes: 228; decompiled */

undefined4 FUN_0001e978(float param_1,float param_2)

{
  undefined4 extraout_r0;
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  
  uVar4 = DAT_ffffaa88;
  fVar1 = (float)FUN_0003eb72(0,&DAT_ffff8114);
  if (DAT_ffffae98 == '\x01') {
    fVar2 = (float)FUN_00002068(uVar4,&DAT_0006a184);
    fVar3 = (float)FUN_00002068(uVar4,&DAT_0006a198);
    DAT_ffffb0fc = fVar1 - fVar2;
    DAT_ffffb100 = fVar1 + fVar3;
  }
  else {
    if (DAT_ffffcb38 == '\x01') {
      fVar2 = (float)FUN_00002068(uVar4,&DAT_0006a1ac);
      fVar3 = (float)FUN_00002068(uVar4,&DAT_0006a1c0);
    }
    else {
      fVar2 = (float)FUN_00002068(uVar4,&DAT_0006a1d4);
      fVar3 = (float)FUN_00002068(uVar4,&DAT_0006a1e8);
    }
    DAT_ffffb0fc = fVar1 - fVar2;
    DAT_ffffb100 = fVar1 + fVar3;
  }
  DAT_ffffb0e4 = rx8_clamp_float(DAT_ffffb11c,DAT_ffffb0fc,DAT_ffffb100);
  if ((DAT_ffffb100 <= DAT_ffffb11c) || (DAT_ffffb11c <= DAT_ffffb0fc)) {
    param_2 = param_2 - DAT_ffffb108;
    param_1 = DAT_ffffb0f8 * param_2;
  }
  DAT_ffffb114 = param_1;
  DAT_ffffb110 = param_2;
  return extraout_r0;
}


