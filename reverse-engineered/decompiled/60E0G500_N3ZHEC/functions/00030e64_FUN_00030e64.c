/* ROM address: 0x00030e64; body bytes: 204; decompiled */

undefined4 FUN_00030e64(void)

{
  undefined4 extraout_r0;
  undefined4 uVar1;
  undefined **ppuVar2;
  
  if (-42.5 <= DAT_ffffaa10) {
    if (-40.0 <= DAT_ffffaa10) {
      DAT_ffffbf12 = '\x01';
    }
  }
  else {
    DAT_ffffbf12 = '\0';
  }
  if ((DAT_ffffa428 == '\0') || (uVar1 = 0, DAT_ffffbea8 != '\0')) {
    DAT_ffffbf08 = ((float)DAT_ffff9f88 * 0.25) / 1000.0;
    if (DAT_ffffce6e == '\x01') {
      ppuVar2 = (undefined **)&DAT_0006af70;
    }
    else {
      ppuVar2 = &PTR_LAB_0006af84;
    }
    DAT_ffffbedc = (float)FUN_00002068(DAT_ffffbf08,ppuVar2);
    DAT_ffffbee0 = (float)FUN_00002068(DAT_ffffbf08,&DAT_0006af98);
    DAT_ffffbed8 = DAT_ffffbee0;
    if (DAT_ffffbf12 == '\x01') {
      DAT_ffffbed8 = DAT_ffffbedc;
    }
    DAT_ffffbee4 = 0x3e4c0003;
    DAT_ffffbee8 = rx8_first_order_filter(DAT_ffffbed8,DAT_ffffbee8,0.1992188,1e-05);
    uVar1 = extraout_r0;
  }
  return uVar1;
}


