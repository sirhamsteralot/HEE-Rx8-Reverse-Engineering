/* [ADDITIONAL SOURCE REVIEW]
 * can_mailbox_reg_addr [high]: reg + 0x200 if mb > 0x1f (HCAN1 block at 0xffffe600); else reg. Used by all mailbox accessors.
 */
/* ROM address: 0x0000cee8; body bytes: 22; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000cee8 (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

int can_mailbox_reg_addr(byte param_1,int param_2)

{
  if (0x1f < param_1) {
    param_2 = param_2 + 0x200;
  }
  return param_2;
}


