/* ROM address: 0x0002aff0; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002b744 (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_CAN4B0RX_Main(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = can_rx_copy_mailbox_to_buffer(&DAT_0004e24c);
  if (cVar2 == '\0') {
    FUN_0000e038();
    ref_canrx4b0related();
    uVar1 = FUN_0002b220();
    DAT_ffffbbbc = 0;
    DAT_ffffbbbe = 0;
  }
  else {
    DAT_ffffbbbc = rx8_add_u16_saturate((int)(short)DAT_ffffbbbc,1);
    uVar1 = (uint)DAT_ffffbbbc;
    if ((DAT_ffffbbbc & 3) == 0) {
      uVar1 = rx8_add_u16_saturate((int)DAT_ffffbbbe,1);
      DAT_ffffbbbe = (short)uVar1;
    }
  }
  return uVar1;
}


