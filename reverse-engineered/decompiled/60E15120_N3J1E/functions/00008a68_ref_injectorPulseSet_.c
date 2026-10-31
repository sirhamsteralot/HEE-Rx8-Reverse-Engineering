/* [ADDITIONAL SOURCE REVIEW]
 * injector_pulse_set_channel [high]: Per-channel ATU-II output program: pulse = (injector_latency a094[ch] + injector_fuel_request a010[ch*0x18]) >> 4 (four shar, disasm 0x8a96-0x8a9e) -> DCNT8A via FUN_0000a8a4; start compare = a014[ch*0x18] (or TCNT1A+3 if within 0x7fff) -> GR1A; clears a016/a018 and the channel TIER bit.
 * RAM 0xffffa010 injector_fuel_request_array (int): Per-channel fuel request array, 0x18-byte stride from a010 (= base a004+0xc); pulse = (latency a094[ch] + a010[ch*0x18]) >> 4 per disasm 0x8a8e-0x8aa0.
 * RAM 0xffffa014 injector_start_angle_array (short): Per-channel start compare, 0x18-byte stride from a014; written to ATU-II GR1A.
 */
/* ROM address: 0x00008a68; body bytes: 192; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00008a68 (192 bytes). Names prefixed ref_
   are inherited hypotheses. */

void injector_pulse_set_channel(uint param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_20;
  short sStack_1c;
  undefined *puStack_18;
  
  iVar3 = (param_1 & 0xff) * 0x18;
  puStack_18 = &DAT_ffffa004 + iVar3;
  sStack_1c = (short)((&injector_latency_ch0_ffffa094)[param_1 & 0xff] + *(int *)(&injector_fuel_request_array_ffffa010 + iVar3) >> 4);
  ref_setSR_PARAM(&local_20,0xe0);
  sVar1 = ATUII_TCNT1A_W;
  uVar4 = param_1 & 0xff;
  if (0x7fff < (ushort)(*(short *)(puStack_18 + 0x10) - (sVar1 + 3))) {
    *(short *)(&injector_start_angle_array_ffffa014 + (param_1 & 0xff) * 0x18) = sVar1 + 3;
  }
  iVar3 = (param_1 & 0xff) * 0x18;
  *(undefined2 *)(&PTR_ATUII_GR1A_W_0000d7d8)[uVar4 * 3] = *(undefined2 *)(&injector_start_angle_array_ffffa014 + iVar3);
  FUN_0000a8a4((&PTR_ATUII_DCNT8A_W_0000d7d4)[uVar4 * 3],(int)sStack_1c);
  (&DAT_ffffa016)[iVar3] = 0;
  uVar2 = ATUII_TIER8_W;
  ATUII_TIER8_W = ~*(ushort *)(&PTR_DAT_0000d7dc + uVar4 * 3) & uVar2;
  (&injector_channel_tier_flag_ffffa018)[iVar3] = 0;
  FUN_00002064(local_20);
  return;
}


