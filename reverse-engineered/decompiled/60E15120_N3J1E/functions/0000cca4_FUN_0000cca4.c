/* [ADDITIONAL SOURCE REVIEW]
 * can_mailbox_read_payload [high]: FUN_00009dfc(len, 0, payload, MD(mb)) - copies mailbox data out (RX side of can_rx_copy_mailbox_to_buffer 0x9890).
 */
/* ROM address: 0x0000cca4; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000cca4 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

void can_mailbox_read_payload(byte param_1,char param_2,char param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = can_mailbox_reg_addr((int)(char)param_1,&HCAN0_MD0_1__B);
  FUN_00009dfc((int)param_2,(int)param_3,param_4,iVar1 + (param_1 & 0xf) * 8);
  return;
}


