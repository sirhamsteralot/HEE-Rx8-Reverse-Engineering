/* ROM address: 0x000345f4; body bytes: 42; decompiled */

void FUN_000345f4(void)

{
  if (7000.0 <= DAT_ffffb5b8) {
    reset_knock_state_on_mode_change(1);
    return;
  }
  if (DAT_ffffb5b8 < 6500.0) {
    reset_knock_state_on_mode_change(0);
    return;
  }
  return;
}


