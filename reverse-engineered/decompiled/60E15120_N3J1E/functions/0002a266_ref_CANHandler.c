/* ROM address: 0x0002a266; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002a9ba (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_CANHandler(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  can_rx_main_key_gated();
  ref_setSR(uVar1);
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  can_tx_main_key_gated();
  ref_setSR(uVar1);
  return;
}


