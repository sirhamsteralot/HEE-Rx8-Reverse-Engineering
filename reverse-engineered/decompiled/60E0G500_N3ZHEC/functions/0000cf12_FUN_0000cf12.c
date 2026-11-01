/* ROM address: 0x0000cf12; body bytes: 14; decompiled */

int can_mailbox_bitmask(uint param_1)

{
  return (int)*(short *)(&DAT_0000d914 + (param_1 & 0xf) * 2);
}


