/* ROM address: 0x0001d5c2; body bytes: 146; decompiled */

undefined2 * FUN_0001d5c2(void)

{
  undefined2 *puVar1;
  
  if (diag_afr_word_a_ffffaa6c < 1.2) {
    if ((DAT_ffffb01d == '\x01') && (diag_afr_word_a_ffffaa6c < lambda_target_ffffadfc + 0.05)) {
      DAT_ffffb01d = '\0';
      DAT_ffffb01c = '\x01';
    }
  }
  else {
    DAT_ffffb01d = '\x01';
    DAT_ffffb01c = '\0';
  }
  puVar1 = (undefined2 *)(uint)DAT_ffffb0ca;
  if (puVar1 == (undefined2 *)((int)&vector_Poweron_Reset + 1)) {
    DAT_ffffae18 = 0x90;
  }
  else if (DAT_ffffb01c == '\0') {
    if (inferred_throttle_position_ffffad44 < 3.5) {
      if (DAT_ffffae18 != 0) {
        DAT_ffffae18 = DAT_ffffae18 - 1;
      }
    }
    else {
      puVar1 = &DAT_0006f614;
      if (DAT_ffffae18 < 5) {
        DAT_ffffae18 = 0;
      }
      else {
        DAT_ffffae18 = DAT_ffffae18 - 5;
      }
    }
  }
  else {
    DAT_ffffae18 = 0;
    DAT_ffffb01c = '\0';
  }
  return puVar1;
}


