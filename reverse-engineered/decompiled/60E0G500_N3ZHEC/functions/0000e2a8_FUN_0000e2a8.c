/* ROM address: 0x0000e2a8; body bytes: 36; decompiled */

void update_injectors_off_flag(void)

{
  if ((DAT_ffffa428 == '\0') && (DAT_ffffa41c == '\0')) {
    DAT_ffffa42c = 1;
  }
  else {
    DAT_ffffa42c = 0;
  }
  return;
}


