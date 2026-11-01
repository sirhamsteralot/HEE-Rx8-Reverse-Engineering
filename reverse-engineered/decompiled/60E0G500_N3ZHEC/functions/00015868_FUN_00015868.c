/* ROM address: 0x00015868; body bytes: 192; decompiled */

undefined4 FUN_00015868(undefined4 param_1)

{
  ushort uVar1;
  ushort uVar3;
  undefined4 uVar2;
  undefined4 extraout_r0;
  float extraout_fr0;
  float arg1;
  
  uVar1 = DAT_ffffa6b4;
  arg1 = 500.0;
  if (DAT_ffffa6b4 == 0) {
    DAT_ffffa7e8 = (float)FUN_00002068(param_1,&DAT_00069a68);
  }
  else if (DAT_ffffa6b4 < 0x76) {
    DAT_ffffa7e8 = rx8_max_float(DAT_ffffa7e8 - 0.16,500.0);
  }
  uVar3 = FUN_00002460(0x75,1);
  if (uVar3 < uVar1) {
    DAT_ffffa7ec = rx8_max_float(DAT_ffffa7ec - 0.16,arg1);
  }
  else if (0x75 < uVar1) {
    DAT_ffffa7ec = (float)FUN_00002068(param_1,&DAT_00069a7c);
  }
  if (uVar1 == 0) {
    uVar2 = FUN_00002068(param_1,&DAT_00069a90);
    DAT_ffffa7f0 = extraout_fr0;
  }
  else {
    DAT_ffffa7f0 = rx8_max_float(DAT_ffffa7f0 - 0.0,arg1);
    uVar2 = extraout_r0;
  }
  return uVar2;
}


