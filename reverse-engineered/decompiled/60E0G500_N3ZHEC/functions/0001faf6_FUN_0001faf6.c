/* ROM address: 0x0001faf6; body bytes: 458; decompiled */

ushort FUN_0001faf6(void)

{
  undefined4 uVar1;
  float fVar2;
  ushort uVar3;
  undefined **ppuVar4;
  undefined *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  float fVar8;
  undefined4 uVar9;
  
  fVar2 = DAT_ffffb18c;
  uVar1 = DAT_ffffadbc;
  if (DAT_ffffb19c != 1) {
    DAT_ffffb190 = 0.0;
    return (ushort)DAT_ffffb19c;
  }
  fVar8 = DAT_ffffaa10;
  uVar6 = DAT_ffffc12c;
  uVar9 = DAT_ffffad8c;
  uVar7 = DAT_ffffb5b8;
  if (DAT_ffffcda0 == '\0') {
    DAT_ffffb1e0 = (float)FUN_00002068(DAT_ffffad8c,&DAT_0006a2e8);
    DAT_ffffb200 = (float)FUN_000020dc(uVar7,uVar1,&DAT_0006a4bc);
    ppuVar4 = (undefined **)&DAT_0006a4d8;
  }
  else {
    DAT_ffffb1e0 = (float)FUN_00002068(DAT_ffffad8c,&PTR_LAB_0006a2fc);
    DAT_ffffb200 = (float)FUN_000020dc(uVar7,uVar1,&PTR_DAT_00010000_1_0006a4f4);
    ppuVar4 = &PTR_DAT_00010000_1_0006a510;
  }
  DAT_ffffb204 = (float)FUN_000020dc(uVar6,uVar7,ppuVar4);
  DAT_ffffb1a0 = rx8_max_float(DAT_ffffb1e0 * DAT_ffffb200,DAT_ffffb204);
  DAT_ffffb1a4 = (float)FUN_00002068(fVar8,&PTR_DAT_0006a310);
  if (DAT_ffffb5a4 == '\x01') {
    if (4 < DAT_ffffbca9) {
      DAT_ffffb19d = '\0';
      goto LAB_0001fc3e;
    }
  }
  else if (3 < DAT_ffffbb55) {
    DAT_ffffb19d = '\0';
    goto LAB_0001fc3e;
  }
  DAT_ffffb19d = '\x01';
LAB_0001fc3e:
  if (DAT_ffffb19d == '\x01') {
    DAT_ffffb1e4 = (float)FUN_00002068(uVar9,&DAT_0006a324);
    DAT_ffffb208 = (float)FUN_000020dc(uVar7,uVar1,&DAT_0006a52c);
    puVar5 = &DAT_0006a548;
  }
  else {
    DAT_ffffb1e4 = (float)FUN_00002068(uVar9,&DAT_0006a338);
    DAT_ffffb208 = (float)FUN_000020dc(uVar7,uVar1,&DAT_0006a564);
    puVar5 = &DAT_0006a580;
  }
  DAT_ffffb20c = (float)FUN_000020dc(uVar6,uVar7,puVar5);
  DAT_ffffb1a8 = rx8_max_float(DAT_ffffb1e4 * DAT_ffffb208,DAT_ffffb20c);
  DAT_ffffb1ac = (float)FUN_00002068(fVar8,&PTR_DAT_0006a34c);
  if (fVar8 < -40.0) {
    if (fVar8 < -43.0) {
      DAT_ffffb249 = '\0';
    }
  }
  else {
    DAT_ffffb249 = '\x01';
  }
  if ((DAT_ffffb249 == '\x01') && (DAT_ffffb1c0 != 0)) {
    DAT_ffffb190 = DAT_ffffb1a0 * DAT_ffffb1a4;
    uVar3 = DAT_ffffb1c0;
  }
  else {
    uVar3 = 4;
    DAT_ffffb190 = DAT_ffffb1a8 * DAT_ffffb1ac * fVar2 + (1.0 - fVar2) * DAT_ffffb1a0 * DAT_ffffb1a4
    ;
  }
  return uVar3;
}


