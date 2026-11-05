/* ROM address: 0x0000b290; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000b290 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000b290(void)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  if (ch7d_pwm_enabled_ffffa214 == '\x01') {
    ATUII_CYLR7D_W = 32000;
    DAT_ffff9f50 = 32000;
  }
  uVar1 = FUN_00002064(local_8[0]);
  return uVar1;
}


