/* ROM address: 0x00033908; body bytes: 42; decompiled */

uint FUN_00033908(void)

{
  uint uVar1;
  
  uVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004e9e8);
  if ((uVar1 & 0xff) == 0) {
    FUN_0000e048();
    FUN_00033932();
    FUN_00033960();
    uVar1 = FUN_0003397a();
    return uVar1;
  }
  return uVar1 & 0xff;
}


