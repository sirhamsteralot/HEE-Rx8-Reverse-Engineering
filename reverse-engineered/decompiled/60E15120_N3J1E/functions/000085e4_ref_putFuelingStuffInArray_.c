/* [ADDITIONAL SOURCE REVIEW]
 * injector_channel_disable [high]: Per-channel off: clears channel TIER bit, GR1A = TCNT1A-1, DCNT8A = 0 (FUN_0000a8a4), a017 = 0. Wiring review: six injector channels on 2M/2J/2G/2D/3A/3D; firmware index-to-terminal mapping unresolved.
 * RAM 0xffffa017 injector_channel_enable_flag (uint8): Checked/cleared per channel (0x18 stride) by injector_channel_disable (0x85e4).
 * RAM 0xffffa018 injector_channel_tier_flag (uint8): Per-channel ATU-II TIER enable mirror; cleared when channel disabled or pulsed.
 */
/* ROM address: 0x000085e4; body bytes: 200; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000085e4 (200 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Harness context (pinout v3, 2026-10-30): six injector control wires with colours — 2M Front Primary 1 LG/R, 2J Rear Primary 1 LG/B, 2G Front Secondary G/R, 2D Rear Secondary L/B, 3A Front Primary 2 L/B (HP ³), 3D Rear Primary 2 W/G (HP ³); each injector also has a shared W/L +12V power feed (PCM switches the low side via TO8A-F, pkg pins 195/197-201). Firmware array indices have not been assigned to these terminals (board routing unresolved). */

void injector_channel_disable(uint param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined4 local_20;
  undefined **ppuStack_1c;
  
  iVar3 = (param_1 & 0xff) * 0x18;
  if ((&injector_channel_enable_flag_ffffa017)[iVar3] == '\0') {
    ref_setSR_PARAM(&local_20,0xe0);
    if ((&injector_channel_tier_flag_ffffa018)[iVar3] == '\x01') {
      ppuStack_1c = &PTR_ATUII_DCNT8A_W_0000d7d4 + (param_1 & 0xff) * 3;
      uVar2 = ATUII_TIER8_W;
      ATUII_TIER8_W = ~*(ushort *)(&PTR_DAT_0000d7dc + (param_1 & 0xff) * 3) & uVar2;
      (&injector_channel_tier_flag_ffffa018)[iVar3] = 0;
    }
    else {
      sVar1 = ATUII_TCNT1A_W;
      *(short *)(&PTR_ATUII_GR1A_W_0000d7d8)[(param_1 & 0xff) * 3] = sVar1 + -1;
      uVar2 = ATUII_DSTR_W;
      if ((*(ushort *)(&PTR_DAT_0000d7dc + (param_1 & 0xff) * 3) & uVar2) == 0) {
        FUN_0000a8a4((&PTR_ATUII_DCNT8A_W_0000d7d4)[(param_1 & 0xff) * 3],0);
      }
    }
    FUN_00002064(local_20);
  }
  (&injector_channel_enable_flag_ffffa017)[iVar3] = 0;
  return;
}


