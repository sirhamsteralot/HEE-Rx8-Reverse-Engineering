/* ROM address: 0x000087a2; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000087a2 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000087a2(byte param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (uint)param_1 * 0x18;
  if ((&injector_channel_enable_flag_ffffa017)[iVar2] != '\0') {
    iVar1 = *(int *)(&DAT_ffffa008 + iVar2);
    *(int *)(&DAT_ffffa008 + iVar2) = iVar1 + -0x1e0000;
    if (iVar1 + -0x1e0000 < 0x230000) {
      FUN_00008814();
      (&injector_channel_enable_flag_ffffa017)[iVar2] = 0;
    }
  }
  return 0x13;
}


