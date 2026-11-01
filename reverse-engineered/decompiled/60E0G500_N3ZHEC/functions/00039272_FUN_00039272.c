/* ROM address: 0x00039272; body bytes: 146; decompiled */

uint FUN_00039272(void)

{
  uint uVar1;
  float extraout_fr0;
  
  DAT_ffffc550 = rx8_first_order_filter(DAT_ffffaa88,DAT_ffffc550,0.011799991,1e-05);
  DAT_ffffc588 = (float)FUN_00002068(DAT_ffffbc1c,&DAT_0006b6f4);
  DAT_ffffc54c = (DAT_ffffc538 - DAT_ffffae54) * DAT_ffffc588;
  uVar1 = (uint)DAT_ffffb13a;
  if (uVar1 == 1) {
    DAT_ffffc548 = 0.0;
  }
  else if (DAT_ffffb190 <= 0.0) {
    uVar1 = FUN_00002068(DAT_ffffc12c,&DAT_0006b6e0);
    DAT_ffffc548 = DAT_ffffc550 * 3018.4 * extraout_fr0;
    DAT_ffffc584 = extraout_fr0;
  }
  else {
    DAT_ffffc548 = DAT_ffffc550 * 3018.4 * 0.1328;
  }
  return uVar1;
}


