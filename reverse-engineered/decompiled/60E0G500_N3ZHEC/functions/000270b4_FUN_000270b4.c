/* ROM address: 0x000270b4; body bytes: 238; decompiled */

void FUN_000270b4(void)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  float arg0;
  
  uVar2 = 0x42480000;
  fVar3 = 30.0;
  DAT_ffffb654 = DAT_ffffb614;
  arg0 = DAT_ffffb650;
  DAT_ffffb658 = rx8_first_order_filter(DAT_ffffb650,DAT_ffffb658,1.0,1e-05);
  fVar1 = (float)FUN_0003ea74((arg0 - 0.0) - DAT_ffffb658,uVar2);
  fVar1 = rx8_clamp_float(fVar1,0.0,1.0);
  DAT_ffffb65c = arg0 * fVar1;
  if ((DAT_ffffa428 != '\x01') || (0.0 <= DAT_ffffb5b8)) {
    if (DAT_ffffb685 == 1) {
      DAT_ffffb618 = rx8_max_float(arg0,DAT_ffffb618 - 124.51);
    }
    else {
      DAT_ffffb618 = DAT_ffffb65c + arg0;
    }
    if (DAT_ffffb618 <= arg0) {
      DAT_ffffb685 = 0;
    }
  }
  else {
    DAT_ffffb618 = rx8_max_float(arg0,DAT_ffffb618);
    DAT_ffffb685 = 1;
  }
  if (DAT_ffffb654 < 40.0) {
    if (DAT_ffffb654 < fVar3) {
      DAT_ffffb623 = 0;
    }
  }
  else {
    DAT_ffffb623 = 1;
  }
  return;
}


