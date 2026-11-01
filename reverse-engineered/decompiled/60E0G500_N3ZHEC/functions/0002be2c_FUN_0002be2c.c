/* ROM address: 0x0002be2c; body bytes: 104; decompiled */

void FUN_0002be2c(void)

{
  char cVar1;
  
  cVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004e9c8);
  if (cVar1 == '\0') {
    FUN_0000e038();
    FUN_0002c372();
    FUN_0002c3a6();
    FUN_0002c484();
    DAT_ffffbc56 = 0;
    DAT_ffffbc58 = 0;
  }
  else {
    DAT_ffffbc56 = FUN_00002460((int)(short)DAT_ffffbc56,1);
    if ((DAT_ffffbc56 & 3) == 0) {
      DAT_ffffbc58 = FUN_00002460((int)DAT_ffffbc58,1);
    }
    DAT_ffffbc2f = FUN_00002478((int)DAT_ffffbc2f,1);
  }
  return;
}


