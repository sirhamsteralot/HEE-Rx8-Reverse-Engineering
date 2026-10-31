/* ROM address: 0x00028484; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00028dcc (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00028484(short param_1,ushort param_2,ushort param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = &DAT_ffff8108;
  uVar3 = 0;
  if (param_1 != 0) {
    puVar1 = &DAT_ffff8328;
  }
  uVar2 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,puVar1 + (uint)param_2 * 8);
  *param_4 = uVar2;
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(uVar3,puVar1 + (uint)param_3 * 8);
  *param_5 = uVar3;
  return;
}


