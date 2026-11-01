/* ROM address: 0x0002c4e8; body bytes: 38; decompiled */

uint FUN_0002c4e8(void)

{
  uint uVar1;
  
  uVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004ea08);
  if ((uVar1 & 0xff) == 0) {
    FUN_0000e038();
    FUN_0002c50e();
    uVar1 = FUN_0002c518();
    return uVar1;
  }
  return uVar1 & 0xff;
}


