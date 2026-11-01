/* ROM address: 0x0000c3ce; body bytes: 114; decompiled */

undefined2 * knock_voltage_sample(void)

{
  undefined2 *puVar1;
  undefined2 *extraout_r0;
  float fVar2;
  
  puVar1 = &DAT_ffffa37a;
  DAT_ffffa37a = DAT_ffff9ef8;
  fVar2 = DAT_ffff9f80;
  if ((200.0 <= DAT_ffff9f80) && (DAT_ffff9f80 < 2000.0)) {
    DAT_ffffa374 = rx8_first_order_filter((float)DAT_ffff9ef8,DAT_ffffa374,0.004,1.0);
    DAT_ffffa378 = (undefined2)(int)DAT_ffffa374;
    puVar1 = extraout_r0;
  }
  if (fVar2 < 10000.0) {
    if (fVar2 < 10000.0) {
      puVar1 = (undefined2 *)0x0;
      DAT_ffffa386 = 0;
    }
  }
  else {
    DAT_ffffa386 = 1;
  }
  return puVar1;
}


