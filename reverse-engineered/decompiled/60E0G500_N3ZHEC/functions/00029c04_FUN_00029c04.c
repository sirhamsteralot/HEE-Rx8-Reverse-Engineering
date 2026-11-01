/* ROM address: 0x00029c04; body bytes: 42; decompiled */

uint FUN_00029c04(void)

{
  uint uVar1;
  
  uVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004e708);
  if ((uVar1 & 0xff) == 0) {
    FUN_0000e040();
    FUN_00029c2e();
    FUN_00029c56();
    uVar1 = FUN_00029cc4();
    return uVar1;
  }
  return uVar1 & 0xff;
}


