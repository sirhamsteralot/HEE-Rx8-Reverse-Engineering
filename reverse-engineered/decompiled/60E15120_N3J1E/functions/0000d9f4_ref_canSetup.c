/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffa40e can_setup_retry_counter (uint8): Retry-loop counter of ref_canSetup 0xd9f4 (pool 0xdb10 = 0xffffa40e; incremented at 0xda5c-0xda60, loop bound 2 at 0xda06).
 * RAM 0xffffa410 can_setup_error_flag (uint8): Set to 1 by ref_canSetup 0xd9f4 when the <=2-iteration mailbox-config retry loop still mismatches; 0xffffa411 cleared after the loop.
 */
/* ROM address: 0x0000d9f4; body bytes: 160; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000d9f4 (160 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_canSetup(void)

{
  char cVar1;
  char cVar2;
  undefined *puVar3;
  
  for (can_setup_retry_counter_ffffa40e = 0; can_setup_retry_counter_ffffa40e < 2; can_setup_retry_counter_ffffa40e = can_setup_retry_counter_ffffa40e + 1) {
    if (automatic_transmission_ffffb534 == '\x01') {
      ref_CANControllerSetup(0,&DAT_0004e01c,0x10);
      puVar3 = &DAT_0004e01c;
    }
    else {
      ref_CANControllerSetup(0,&DAT_0004e11c,0x10);
      puVar3 = &DAT_0004e11c;
    }
    cVar1 = hcan_mailbox_config_compare(0,puVar3);
    ref_CANControllerSetup(1,&DAT_0004e21c,6);
    cVar2 = hcan_mailbox_config_compare(1,&DAT_0004e21c);
    if (cVar1 == '\0' && cVar2 == '\0') break;
  }
  if (1 < can_setup_retry_counter_ffffa40e) {
    can_setup_error_flag_ffffa410 = 1;
  }
  DAT_ffffa411 = 0;
  return;
}


