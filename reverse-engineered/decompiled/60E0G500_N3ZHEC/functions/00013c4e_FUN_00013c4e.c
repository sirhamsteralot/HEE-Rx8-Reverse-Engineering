/* ROM address: 0x00013c4e; body bytes: 56; decompiled */

void FUN_00013c4e(float param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_ffffb5b8;
  DAT_ffffa750 = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006b408);
  DAT_ffffa754 = (float)FUN_00002068(uVar1,&DAT_0006b41c);
  rx8_clamp_float(param_1,DAT_ffffa750,DAT_ffffa754);
  return;
}


