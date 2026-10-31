/* [CROSS-ECU / RX8DEFS REVIEW]
 * sci0_configure_sync_and_exchange_command [register_dataflow_verified]: Sets SCI_SMR0=0x80, BRR0=4, adjusts SCR0 and pin configuration, exchanges combined RAM command bytes via 0x71ea, restores SR through tail jump. Calls 0x3920 with 0xb0, so transfer can run with mask raised to interrupt level 11. Endpoint purpose is not confirmed.
 */
/* ROM address: 0x00007188; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007188 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

void sci0_configure_sync_and_exchange_command(void)

{
  byte bVar1;
  undefined4 uVar2;
  
  uVar2 = sh_raise_interrupt_mask_return_previous(0xb0);
  bVar1 = SCI_SCR0_B;
  SCI_SCR0_B = bVar1 & 0xb;
  SCI_SMR0_B = 0x80;
  bVar1 = SCI_SCR0_B;
  SCI_SCR0_B = bVar1 & 0xfc;
  SCI_SDCR0_B = 0xf0;
  SCI_BRR0_B = 4;
  ref_setRegister_REG_BIT_VAL(0xfffff72c,0x4000,1);
  ref_setRegister_REG_BIT_VAL(0xfffff72c,0x8000,1);
  bVar1 = SCI_SCR0_B;
  SCI_SCR0_B = bVar1 & 0xb | 0x30;
  sci0_exchange_byte_wait_rdrf((int)(char)(DAT_ffff9f34 | DAT_ffff9f35));
  ref_setSR(uVar2);
  return;
}


