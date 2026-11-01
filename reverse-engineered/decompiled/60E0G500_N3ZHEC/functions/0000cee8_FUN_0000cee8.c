/* ROM address: 0x0000cee8; body bytes: 22; decompiled */

int can_mailbox_reg_addr(byte param_1,int param_2)

{
  if (0x1f < param_1) {
    param_2 = param_2 + 0x200;
  }
  return param_2;
}


