/* ROM address: 0x0002b29c; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002b9f0 (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_CAN212RX_Main(void)

{
  char cVar1;
  
  cVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004e21c);
  if (cVar1 == '\0') {
    FUN_0000e038();
    ref_can212RXUnpack();
    FUN_0002b816();
    FUN_0002b8f4();
    DAT_ffffbbee = 0;
    DAT_ffffbbf0 = 0;
  }
  else {
    DAT_ffffbbee = rx8_add_u16_saturate((int)(short)DAT_ffffbbee,1);
    if ((DAT_ffffbbee & 3) == 0) {
      DAT_ffffbbf0 = rx8_add_u16_saturate((int)DAT_ffffbbf0,1);
    }
    DAT_ffffbbc7 = rx8_add_u8_saturate((int)DAT_ffffbbc7,1);
  }
  return;
}


