/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffddd0 uds_tx_buffer (uint8[8]): CAN TX buffer; descriptor 0x4e00c (id 0x7e8, mb 15, DLC 8) holds buf=0xffffddd0 at ROM 0x4e014; mov.l pool 0x682b0 in 0x681ba and pool 0x688e8 in 0x68776-0x68868 (ISO-TP TX); written via ref_txCAN_EventBased 0x99b0.
 */
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


