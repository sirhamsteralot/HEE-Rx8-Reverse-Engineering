/* ROM address: 0x0004c62a; body bytes: 66; decompiled */

void FUN_0004c62a(void)

{
  DAT_ffffceac = FUN_00055b02();
  DAT_ffffcead = FUN_00055b7c();
  DAT_ffffceae = diag_read_calc_load_pct();
  DAT_ffffceaf = diag_encode_ect_c();
  DAT_ffffceb0 = diag_encode_stft_lambda();
  DAT_ffffceb1 = diag_encode_ltft();
  DAT_ffffceb2 = 0;
  DAT_ffffceb3 = 0;
  return;
}


