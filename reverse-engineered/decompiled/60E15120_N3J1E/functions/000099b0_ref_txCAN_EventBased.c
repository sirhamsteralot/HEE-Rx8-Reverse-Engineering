/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000099b0; body bytes: 134; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000099b0 (134 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool ref_txCAN_EventBased(const Rx8CanMessageDescriptor *message)

{
  ushort pending_bits;
  bool already_pending;
  undefined4 saved_interrupt_mask;
  ushort *pending_register;
  ushort mailbox_mask;
  undefined2 *control_register;
  undefined2 request_mask;
  
  saved_interrupt_mask = sh_raise_interrupt_mask_return_previous(0x90);
  pending_register = (ushort *)can_mailbox_reg_addr((int)(int8_t)message->mailbox_selector,&HCAN0_TXPR_W);
  pending_bits = *pending_register;
  mailbox_mask = can_mailbox_bitmask((int)(int8_t)message->mailbox_selector);
  already_pending = (mailbox_mask & pending_bits) != 0;
  if (!already_pending) {
    control_register = (undefined2 *)can_mailbox_reg_addr((int)(int8_t)message->mailbox_selector,&HCAN0_TXACK_W);
    request_mask = can_mailbox_bitmask((int)(int8_t)message->mailbox_selector);
    *control_register = request_mask;
    can_mailbox_write_payload((int)(int8_t)message->mailbox_selector,(int)(int8_t)message->payload_length,0,
                 message->payload_address);
    control_register = (undefined2 *)can_mailbox_reg_addr((int)(int8_t)message->mailbox_selector,&HCAN0_TXPR_W);
    request_mask = can_mailbox_bitmask((int)(int8_t)message->mailbox_selector);
    *control_register = request_mask;
  }
  ref_setSR(saved_interrupt_mask);
  return already_pending;
}


