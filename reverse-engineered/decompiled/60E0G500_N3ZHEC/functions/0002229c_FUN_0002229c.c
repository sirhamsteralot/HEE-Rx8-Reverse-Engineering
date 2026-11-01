/* ROM address: 0x0002229c; body bytes: 70; decompiled */

void FUN_0002229c(void)

{
  float arg0;
  undefined4 uVar1;
  
  uVar1 = DAT_ffffaa14;
  arg0 = (float)FUN_00002068(DAT_ffffa848,&DAT_0006a788);
  DAT_ffffb318 = (float)FUN_00002068(uVar1,&DAT_0006a7b0);
  DAT_ffffb31c = (float)FUN_00002068(uVar1,&DAT_0006a79c);
  DAT_ffffb314 = rx8_clamp_float(arg0,DAT_ffffb318,DAT_ffffb31c);
  return;
}


