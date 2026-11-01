/* ROM address: 0x00003934; body bytes: 24; decompiled */

void FUN_00003934(int param_1)

{
  if ((param_1 == 0) && (*(char *)(DAT_ffff7650 + 1) != '\x01')) {
    os_wake_check_context_switch();
    return;
  }
  return;
}


