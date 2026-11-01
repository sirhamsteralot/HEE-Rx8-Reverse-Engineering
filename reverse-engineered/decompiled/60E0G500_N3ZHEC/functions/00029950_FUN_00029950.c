/* ROM address: 0x00029950; body bytes: 42; decompiled */

uint FUN_00029950(void)

{
  uint uVar1;
  
  uVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004e9d8);
  if ((uVar1 & 0xff) == 0) {
    FUN_0000e040();
    can216_unpack_mixed_width_fields();
    FUN_00029a8c();
    uVar1 = FUN_00029bb8();
    return uVar1;
  }
  return uVar1 & 0xff;
}


