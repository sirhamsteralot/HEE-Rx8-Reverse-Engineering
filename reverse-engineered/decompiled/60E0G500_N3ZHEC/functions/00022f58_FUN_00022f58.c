/* ROM address: 0x00022f58; body bytes: 274; decompiled */

void FUN_00022f58(void)

{
  ushort uVar1;
  ushort uVar3;
  ushort uVar4;
  int iVar2;
  undefined *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  uVar1 = DAT_ffffa422;
  fVar7 = DAT_ffffaa1c;
  fVar6 = (float)FUN_0003eb72(DAT_ffff9f70,&DAT_ffff8088);
  fVar6 = fVar6 - fVar7;
  DAT_ffffb3be = FUN_000020c4(fVar7,&PTR_DAT_0006a800);
  uVar3 = DAT_ffffb3be + 0xf;
  uVar4 = DAT_ffffb3be + 0x61;
  DAT_ffffb3b8 = (float)FUN_000020dc(DAT_ffffc12c,DAT_ffffb5b8,&DAT_0006a820);
  if (DAT_ffffa428 == '\0') {
    if (12.0 <= fVar6) {
      DAT_ffffb3b0 = '\x01';
    }
    else {
      DAT_ffffb3b0 = '\0';
    }
  }
  fVar6 = 0.0;
  if (DAT_ffffb3a8 == '\0') {
    DAT_ffffb3ac = 0.0;
  }
  else {
    if (DAT_ffffb3b0 == '\x01') {
      if (uVar3 <= uVar1) {
        if (uVar1 < uVar4) {
          puVar5 = &DAT_0006a7d8;
        }
        else {
          puVar5 = &DAT_0006a7ec;
        }
        DAT_ffffb3ac = (float)FUN_00002068(fVar7,puVar5);
        goto LAB_0002306e;
      }
      puVar5 = &DAT_0006a7c4;
    }
    else {
      puVar5 = &DAT_0006a7ec;
    }
    DAT_ffffb3ac = (float)FUN_00002068(fVar7,puVar5);
  }
LAB_0002306e:
  fVar7 = rx8_clamp_float(DAT_ffffb3ac,fVar6,DAT_ffffb3b8);
  fVar8 = 100.0;
  fVar6 = 65536.0;
  iVar2 = FUN_0005cc40((int)((fVar7 / 100.0) * 65536.0));
  DAT_ffffb3a0 = ((float)iVar2 / fVar6) * fVar8;
  return;
}


