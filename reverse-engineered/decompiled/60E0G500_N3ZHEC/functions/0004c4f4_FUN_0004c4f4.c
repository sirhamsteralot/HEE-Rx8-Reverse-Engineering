/* ROM address: 0x0004c4f4; body bytes: 38; decompiled */

uint FUN_0004c4f4(void)

{
  uint uVar1;
  
  uVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004e788);
  if ((uVar1 & 0xff) == 0) {
    FUN_0000e038();
    FUN_0004c51a();
    uVar1 = FUN_0004c54e();
    return uVar1;
  }
  return uVar1 & 0xff;
}


