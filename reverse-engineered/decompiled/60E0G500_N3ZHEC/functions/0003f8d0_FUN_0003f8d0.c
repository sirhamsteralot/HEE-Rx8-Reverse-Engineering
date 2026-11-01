/* ROM address: 0x0003f8d0; body bytes: 150; decompiled */

undefined4 * FUN_0003f8d0(void)

{
  undefined4 *extraout_r0;
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  float arg1;
  
  if (DAT_ffffa428 == '\0') {
    if (DAT_ffffc70d == '\x01') {
      DAT_ffffc6b4 = DAT_ffffaa1c;
      puVar1 = (undefined4 *)&UNK_00000001;
    }
    else {
      arg1 = DAT_ffffaa1c;
      fVar2 = (float)FUN_0003eb72(DAT_ffffaa1c,&DAT_ffff8738);
      fVar3 = (float)FUN_0003eb72(DAT_ffff9f70,&DAT_ffff8088);
      DAT_ffffc6b4 = rx8_max_float(fVar2 - (fVar3 - arg1) * 10.0,arg1);
      puVar1 = extraout_r0;
    }
  }
  else {
    puVar1 = (undefined4 *)&DAT_ffffc70c;
    if (DAT_ffffc70c == '\0') {
      if (DAT_ffffc656 == '\x01') {
        DAT_ffffc6b4 = 1000.0;
        puVar1 = (undefined4 *)&UNK_00000001;
      }
      else {
        puVar1 = &DAT_ffffc6f4;
        DAT_ffffc6b4 = DAT_ffffc6b4 +
                       (DAT_ffffc6f4 - DAT_ffffc6b4) * DAT_ffffc6e8 * DAT_ffffc6ec * DAT_ffffc6fc;
      }
    }
  }
  return puVar1;
}


