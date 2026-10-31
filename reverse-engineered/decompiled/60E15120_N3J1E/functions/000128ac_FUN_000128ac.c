/* ROM address: 0x000128ac; body bytes: 88; decompiled */

void FUN_000128ac(void)

{
  if (vehicle_speed_ffffbbb4 <= 0.0) {
    if (DAT_ffffa684 != 0) {
      DAT_ffffa684 = DAT_ffffa684 + -1;
    }
  }
  else {
    DAT_ffffa684 = 0xfa;
  }
  if ((DAT_ffffad18 == '\0') || (DAT_ffffa684 == 0)) {
    DAT_ffffa689 = 0;
  }
  else if (DAT_ffffa68a == '\x01') {
    DAT_ffffa689 = 1;
  }
  return;
}


