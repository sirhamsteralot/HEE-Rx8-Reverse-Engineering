/* ROM address: 0x000163d0; body bytes: 118; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000163ea) */

uint FUN_000163d0(void)

{
  uint uVar1;
  uint extraout_r0;
  float arg0;
  float arg1;
  
  uVar1 = (uint)DAT_ffffb366;
  arg1 = 0.0;
  if (uVar1 == 1) {
    DAT_ffffa8b0 = (float)FUN_00002068(DAT_ffffb290,&DAT_0006a6ac);
    arg0 = (float)FUN_0003ea74(DAT_ffffb24c * 0.6345 * DAT_ffffa8b0 * 60.0,DAT_ffffb5b8);
    DAT_ffffa8ac = rx8_clamp_float(arg0,arg1,0.2);
    uVar1 = extraout_r0;
  }
  else {
    DAT_ffffa8ac = 0.0;
  }
  return uVar1;
}


