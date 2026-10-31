/* ROM address: 0x0000aee8; body bytes: 356; decompiled */

uint FUN_0000aee8(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (uint)DAT_ffffa202;
  if (uVar1 == 1) {
    uVar2 = sh_raise_interrupt_mask_return_previous(0x90);
    DAT_ffffa1f0 = ((float)DAT_ffffa1fa - (float)DAT_ffffa1fc) * 7.6293945e-05;
    if (DAT_ffffa1f0 < 0.0) {
      DAT_ffffa1f0 = -DAT_ffffa1f0;
    }
    DAT_ffffa1e4 = (((float)DAT_ffffa1fa - (float)DAT_ffffa1fe) * 7.6293945e-05) / 200.0;
    DAT_ffffa1e8 = (((float)DAT_ffffa1fc - (float)DAT_ffffa200) * 7.6293945e-05) / 200.0;
    DAT_ffffa1ec = DAT_ffffa1e4 - DAT_ffffa1e8;
    if (DAT_ffffa1ec < 0.0) {
      DAT_ffffa1ec = -DAT_ffffa1ec;
    }
    if (DAT_ffffa1ec == 0.0) {
      DAT_ffffa1d8 = 16383.75;
    }
    else {
      DAT_ffffa1d8 = DAT_ffffa1f0 / DAT_ffffa1ec - 16.25;
    }
    if (DAT_ffffa203 == '\0') {
      DAT_ffffa203 = '\x01';
      DAT_ffffa1d4 = DAT_ffffa1d8;
    }
    else {
      DAT_ffffa1d4 = rx8_first_order_filter(DAT_ffffa1d8,DAT_ffffa1d4,0.25,0.0);
    }
    if (DAT_ffffa1fa < 0xc28f) {
      if (DAT_ffffa1fa < 0x5c29) {
        DAT_ffffa1dc = 2;
      }
      else {
        DAT_ffffa1dc = 0;
      }
    }
    else {
      DAT_ffffa1dc = 1;
    }
    if (DAT_ffffa1e4 < 0.005) {
      if (-0.005 <= DAT_ffffa1e4) {
        DAT_ffffa1dd = 0;
      }
      else {
        DAT_ffffa1dd = 2;
      }
    }
    else {
      DAT_ffffa1dd = 1;
    }
    uVar1 = ref_setSR(uVar2);
  }
  return uVar1;
}


