/* ROM address: 0x00022514; body bytes: 306; decompiled */

undefined4 * FUN_00022514(void)

{
  undefined4 *puVar1;
  float fVar2;
  undefined4 uVar3;
  
  if (DAT_ffffb5a4 == '\x01') {
    if (DAT_ffffbcad == '\x01') {
      DAT_ffffb33c = 1;
      DAT_ffffb33d = 0;
    }
    else {
      if (DAT_ffffbcae != '\x01') {
        if (DAT_ffffbcaf == '\x01') {
          DAT_ffffb33c = 0;
          DAT_ffffb33d = 0;
          DAT_ffffb33e = 1;
        }
        else {
          DAT_ffffb33c = 0;
          DAT_ffffb33d = 0;
          DAT_ffffb33e = 0;
        }
        goto LAB_00022624;
      }
      DAT_ffffb33c = 0;
      DAT_ffffb33d = 1;
    }
  }
  else if (((DAT_ffffbcad == '\0') && (DAT_ffffbcae == '\0')) && (DAT_ffffbcaf == '\0')) {
    DAT_ffffb33c = 0;
    DAT_ffffb33d = 0;
  }
  else if (DAT_ffffbcad == '\x01') {
    DAT_ffffb33c = 1;
    DAT_ffffb33d = 0;
  }
  else {
    if (DAT_ffffbcae != '\x01') {
      if (DAT_ffffbcaf == '\x01') {
        DAT_ffffb33c = 0;
        DAT_ffffb33d = 0;
        DAT_ffffb33e = 1;
      }
      goto LAB_00022624;
    }
    DAT_ffffb33c = 0;
    DAT_ffffb33d = 1;
  }
  DAT_ffffb33e = 0;
LAB_00022624:
  DAT_ffffb344 = DAT_ffffb314 + DAT_ffffb3fc;
  fVar2 = DAT_ffffbb30;
  uVar3 = DAT_ffffb5b8;
  DAT_ffffb330 = FUN_000020dc(DAT_ffffb344,DAT_ffffb5b8,&DAT_0006a6f0);
  DAT_ffffb348 = fVar2;
  DAT_ffffb34c = DAT_ffffb330;
  DAT_ffffb334 = FUN_000020dc(fVar2,uVar3,&DAT_0006a6d4);
  DAT_ffffb350 = DAT_ffffb334;
  if ((DAT_ffffb5a4 != '\0') || (puVar1 = &DAT_000226e0, 256.0 < fVar2)) {
    puVar1 = &DAT_000226e4;
    DAT_ffffb334 = 0x42c80000;
  }
  return puVar1;
}


