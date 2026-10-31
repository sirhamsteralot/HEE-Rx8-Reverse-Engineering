/* ROM address: 0x00008814; body bytes: 522; decompiled */

void FUN_00008814(uint param_1)

{
  ushort uVar1;
  short sVar2;
  int extraout_r2;
  int iVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_2c;
  undefined *puStack_28;
  
  ref_setSR_PARAM(&local_2c,0xe0);
  uVar6 = DAT_ffff9f9c >> 4;
  FUN_00002064(local_2c);
  iVar8 = (param_1 & 0xff) * 0x18;
  sVar2 = (short)uVar6;
  if (*(int *)(&DAT_ffffa008 + iVar8) < 0) {
    *(short *)(&injector_start_angle_array_ffffa014 + iVar8) = sVar2;
  }
  else {
    ref_LongFunc(DAT_ffff9f84,0x1e0000);
    iVar3 = FUN_0000467a();
    uVar6 = (int)((uint)(extraout_r2 * iVar3) >> 8) >> 4;
    sVar5 = (short)uVar6;
    if (0x7fff < (uVar6 & 0xffff)) {
      sVar5 = 0x7fff;
    }
    *(short *)(&injector_start_angle_array_ffffa014 + iVar8) = sVar2 + sVar5;
  }
  *(undefined4 *)(&injector_fuel_request_array_ffffa010 + iVar8) = *(undefined4 *)(&DAT_ffffa004 + iVar8);
  ref_setSR_PARAM(&local_2c,0xe0);
  uVar6 = param_1 & 0xff;
  uVar1 = ATUII_DSTR_W;
  if ((*(ushort *)(&PTR_DAT_0000d7dc + uVar6 * 3) & uVar1) == 0) {
    iVar4 = (&injector_latency_ch0_ffffa094)[param_1 & 0xff];
    iVar3 = *(int *)(&injector_fuel_request_array_ffffa010 + iVar8);
    sVar2 = ATUII_TCNT1A_W;
    if (0x7fff < (ushort)(*(short *)(&injector_start_angle_array_ffffa014 + iVar8) - (sVar2 + 3))) {
      *(short *)(&injector_start_angle_array_ffffa014 + iVar8) = sVar2 + 3;
    }
    puStack_28 = &DAT_ffffa004 + iVar8;
    *(undefined2 *)(&PTR_ATUII_GR1A_W_0000d7d8)[(param_1 & 0xff) * 3] =
         *(undefined2 *)(&injector_start_angle_array_ffffa014 + iVar8);
    FUN_0000a8a4((&PTR_ATUII_DCNT8A_W_0000d7d4)[(param_1 & 0xff) * 3],iVar3 + iVar4 >> 4);
    puStack_28[0x12] = 0;
  }
  else {
    sVar2 = ATUII_TCNT1A_W;
    if ((ushort)((*(short *)(&PTR_ATUII_DCNT8A_W_0000d7d4)[uVar6 * 3] + sVar2) -
                *(short *)(&injector_start_angle_array_ffffa014 + iVar8)) < 0x8000) {
      if ((&DAT_ffffa016)[iVar8] == '\x01') {
        iVar3 = (*(int *)(&injector_fuel_request_array_ffffa010 + iVar8) >> 4) +
                (int)*(short *)(&PTR_ATUII_DCNT8A_W_0000d7d4)[uVar6 * 3];
      }
      else {
        uVar7 = *(int *)(&injector_fuel_request_array_ffffa010 + iVar8) + (&injector_latency_ch0_ffffa094)[param_1 & 0xff] >> 4;
        sVar2 = ATUII_TCNT1A_W;
        uVar6 = (int)*(short *)(&injector_start_angle_array_ffffa014 + iVar8) - (int)sVar2 & 0xffff;
        if (uVar6 < 0x8000) {
          iVar3 = rx8_add_u16_saturate(uVar7);
        }
        else if ((int)(uVar7 & 0xffff) < (int)-uVar6) {
          iVar3 = 0;
        }
        else {
          iVar3 = uVar7 + ((int)*(short *)(&injector_start_angle_array_ffffa014 + iVar8) - (int)sVar2);
        }
      }
      FUN_0000a8a4((&PTR_ATUII_DCNT8A_W_0000d7d4)[(param_1 & 0xff) * 3],iVar3);
      ATUII_DSTR_W = *(undefined2 *)(&PTR_DAT_0000d7dc + (param_1 & 0xff) * 3);
      (&DAT_ffffa016)[iVar8] = 0;
    }
    else {
      ATUII_TSR8_W = ~*(ushort *)(&PTR_DAT_0000d7dc + uVar6 * 3);
      uVar1 = ATUII_TIER8_W;
      ATUII_TIER8_W =
           ~*(ushort *)(&PTR_DAT_0000d7dc + uVar6 * 3) & uVar1 |
           *(ushort *)(&PTR_DAT_0000d7dc + uVar6 * 3);
      (&injector_channel_tier_flag_ffffa018)[iVar8] = 1;
    }
  }
  FUN_00002064(local_2c);
  return;
}


