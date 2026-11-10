/* ROM address: 0x00054d90; body bytes: 1204; decompiled_with_warnings */

uint FUN_00054d90(char param_1,uint param_2)

{
  bool bVar1;
  undefined4 uVar2;
  char cVar3;
  uint *puVar4;
  undefined *puVar5;
  uint uVar6;
  undefined4 uVar7;
  char *pcVar8;
  byte bVar9;
  int iVar10;
  char acStack_3c [4];
  char acStack_38 [4];
  undefined *puStack_34;
  uint *puStack_30;
  uint auStack_2c [2];
  undefined4 uStack_24;
  undefined1 auStack_23 [3];
  undefined1 uStack_20;
  undefined1 auStack_1f [2];
  undefined1 uStack_1d;
  
  bVar9 = 0;
  while( true ) {
    cVar3 = (&DAT_0005ea08)[(uint)bVar9 * 8];
    if ((cVar3 == param_1) || (cVar3 == '\0')) break;
    bVar9 = bVar9 + 1;
  }
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(bVar9) {
  case 0:
    uVar7 = FUN_00055278();
    uVar7 = ref_updateRAM__(param_2,&stack0xfffffff0,uVar7);
    uVar2 = FUN_000552a0();
    uVar7 = ref_updateRAM__(uVar7,&stack0xfffffff0,uVar2);
    uVar2 = FUN_000552a6();
    uVar7 = ref_updateRAM__(uVar7,&stack0xfffffff0,uVar2);
    uVar2 = FUN_000552ac();
    ref_updateRAM__(uVar7,&stack0xfffffff0,uVar2);
    return 0;
  case 1:
    uVar7 = diag_ol_status_byte();
    uVar7 = ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    uVar2 = diag_ol_status_low_byte();
    ref_updateRAM__(uVar7,&stack0xfffffff4,uVar2);
    return 0;
  case 2:
    uVar7 = diag_read_calc_load_pct();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 3:
    uVar7 = diag_encode_ect_c();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 4:
    uVar7 = diag_encode_stft_lambda();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 5:
    uVar7 = diag_encode_ltft();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 6:
    uVar7 = diag_encode_rpm();
    FUN_000548d0(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 7:
    uVar7 = diag_encode_vss();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 8:
    uVar7 = diag_encode_leading_timing();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 9:
    uVar7 = diag_encode_iat();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 10:
    uVar7 = diag_encode_maf();
    FUN_000548d0(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0xb:
    uVar7 = diag_encode_throttle_pct();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0xc:
    uVar7 = diag_read_secondary_air_status();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0xd:
    uVar7 = diag_read_o2_present_const();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0xe:
    uVar7 = diag_encode_o2s2();
    uVar7 = ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    uVar2 = diag_encode_trim_b074();
    ref_updateRAM__(uVar7,&stack0xfffffff4,uVar2);
    return 0;
  case 0xf:
    uVar7 = diag_read_obd_standard_const();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x10:
    uVar7 = diag_read_runtime_s();
    FUN_000548d0(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x11:
    uVar7 = diag_read_distance_mil();
    FUN_000548d0(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x12:
    uVar7 = diag_encode_b2f0();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x13:
    uVar7 = diag_read_d287();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x14:
    uVar7 = diag_read_gear_byte();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x15:
    uVar7 = diag_read_90fc();
    FUN_000548d0(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x16:
    uVar7 = diag_encode_ad10();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x17:
    uVar7 = diag_read_afr_word_a();
    uVar7 = FUN_000548d0(param_2,&stack0xfffffff4,uVar7);
    uVar2 = diag_read_afr_word_b();
    FUN_000548d0(uVar7,&stack0xfffffff4,uVar2);
    return 0;
  case 0x18:
    uVar7 = diag_encode_c644();
    FUN_000548d0(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x19:
    uVar7 = diag_encode_battery_v();
    FUN_000548d0(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x1a:
    uVar7 = diag_encode_load_g_rev();
    FUN_000548d0(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x1b:
    uVar7 = diag_encode_lambda_target();
    FUN_000548d0(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x1c:
    uVar7 = diag_encode_ad48();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x1d:
    uVar7 = diag_encode_ad5e();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x1e:
    uVar7 = diag_encode_a9c4();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x1f:
    uVar7 = diag_encode_a9c6();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x20:
    uVar7 = diag_encode_b410();
    ref_updateRAM__(param_2,&stack0xfffffff4,uVar7);
    return 0;
  case 0x21:
    return 0;
  case 0x22:
    puStack_30 = (uint *)param_2;
    e2ram_cached_byte_read(0x80,auStack_2c);
    puStack_34 = (undefined *)((uint)puStack_34 & 0xffffff);
    uVar7 = ref_updateRAM__(puStack_30,&puStack_34,1);
    bVar9 = 0;
    puVar4 = auStack_2c;
    do {
      cVar3 = *(char *)puVar4;
      puVar4 = (uint *)((int)puVar4 + 1);
      uVar7 = ref_updateRAM__(uVar7,&puStack_34,(int)cVar3);
      bVar9 = bVar9 + 1;
    } while (bVar9 < 0x11);
    return (int)puStack_34._0_1_;
  case 0x23:
    acStack_38[0] = '\0';
    uVar7 = ref_updateRAM__(param_2,acStack_38,1);
    pcVar8 = "N3ZHEB000.HEX";
    bVar9 = 0;
    puStack_30 = auStack_2c;
    puVar4 = puStack_30;
    do {
      cVar3 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      bVar9 = bVar9 + 1;
      *(char *)puVar4 = cVar3;
      puVar4 = (uint *)((int)puVar4 + 1);
    } while (bVar9 < 9);
    puStack_34 = &DAT_0005f6e8;
    e2ram_cached_byte_read(100,auStack_23,3);
    puStack_34 = &DAT_0005f6f4;
    e2ram_cached_byte_read(0x68,&uStack_20,1);
    puStack_34 = &DAT_0005f700;
    e2ram_cached_byte_read(0x6a,auStack_1f,2);
    puStack_34 = &DAT_0005f70c;
    e2ram_cached_byte_read(0x6c,&uStack_1d,1);
    bVar9 = 0;
    puVar4 = puStack_30;
    do {
      cVar3 = *(char *)puVar4;
      puVar4 = (uint *)((int)puVar4 + 1);
      uVar7 = ref_updateRAM__(uVar7,acStack_38,(int)cVar3);
      bVar9 = bVar9 + 1;
    } while (bVar9 < 0x10);
    return (int)acStack_38[0];
  case 0x24:
    cVar3 = FUN_0005a5a6(&stack0xfffffff4);
    if (cVar3 == '\0') {
      uVar7 = ref_updateRAM__(param_2,&stack0xfffffff0,1);
      FUN_000548ec(uVar7,&stack0xfffffff0,param_2);
    }
    return 0;
  case 0x25:
    uVar7 = ref_updateRAM__(param_2,&stack0xffffffe4,0x10);
    puVar5 = &DAT_ffff9110;
    do {
      uVar2 = ref_readValue_32bit_ADDRESS_VAL(puVar5,0);
      uVar7 = FUN_000548ec(uVar7,&stack0xffffffe4,uVar2);
      puVar5 = puVar5 + 8;
    } while (puVar5 < &inferred_sensor_block_ffff9150_ffff9150);
    return 0;
  case 0x26:
    return 0;
  }
  param_2 = param_2 & 0xffff;
  bVar1 = false;
  if ((param_2 == 0) || (6 < param_2)) {
    bVar1 = true;
  }
  puStack_34._0_1_ = cVar3;
  if (!bVar1) {
    DAT_ffffd816 = 1;
    acStack_38[0] = 'A';
    ref_setupForUdsResponse_(1,acStack_38);
    iVar10 = 0;
    if (param_2 != 0) {
      do {
        ref_udsServiceResponse(1,acStack_3c);
        cVar3 = FUN_00066678(1,(int)acStack_3c[0]);
        if (cVar3 == '\0') {
          cVar3 = FUN_00066718((int)acStack_3c[0]);
          if (cVar3 == '\0') {
            FUN_00065936((int)acStack_3c[0]);
          }
          else {
            FUN_00065980((int)acStack_3c[0]);
          }
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)param_2);
    }
    if (DAT_ffffd816 == 1) {
      bVar1 = false;
    }
  }
  uVar6 = (uint)bVar1;
  if (uVar6 == 0) {
    puStack_30 = (uint *)0x1;
    auStack_2c[0] = (uint)DAT_ffffd816;
    auStack_2c[1] = 8;
    uStack_24 = 0;
    uVar6 = FUN_00068d56();
  }
  else if (uVar6 == 1) {
    if (puStack_34._0_1_ == '\x01') {
      uVar7 = 2;
    }
    else {
      uVar7 = 1;
    }
    uVar6 = FUN_0006672a(1,0x12,uVar7);
  }
  else if (uVar6 == 2) {
    if (puStack_34._0_1_ == '\x01') {
      uVar7 = 2;
    }
    else {
      uVar7 = 1;
    }
    uVar6 = FUN_0006672a(1,0x12,uVar7);
  }
  return uVar6;
}


