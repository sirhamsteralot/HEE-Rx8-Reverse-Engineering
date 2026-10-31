/* [ADDITIONAL SOURCE REVIEW]
 * can_mailbox_write_payload [high]: FUN_00009e26(len, 0, payload, MD(mb)) - copies payload into mailbox data (TX side of ref_txCAN_EventBased 0x99b0).
 */
/* ROM address: 0x0000ccda; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000ccda (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

void can_mailbox_write_payload(byte param_1,char param_2,char param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = can_mailbox_reg_addr((int)(char)param_1,&HCAN0_MD0_1__B);
  FUN_00009e26((int)param_2,(int)param_3,param_4,iVar1 + (param_1 & 0xf) * 8);
  return;
}


