/* [ADDITIONAL SOURCE REVIEW]
 * can_mailbox_dlc [high]: returns MC[mb][0] & 0xf (DLC stored in MC byte 0 by FUN_00001ed0). Emulator: TX of desc 0x4e00c emitted an 8-byte frame on 0x7e8.
 */
/* ROM address: 0x0000cd40; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000cd40 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

byte can_mailbox_dlc(byte param_1)

{
  int iVar1;
  
  iVar1 = can_mailbox_reg_addr((int)(char)param_1,&HCAN0_MC0_1__B);
  return *(byte *)(iVar1 + (param_1 & 0xf) * 8) & 0xf;
}


