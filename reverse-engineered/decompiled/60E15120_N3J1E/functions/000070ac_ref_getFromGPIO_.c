/* [ADDITIONAL SOURCE REVIEW]
 * sci0_gpio_expander_read [high]: Was ref_getFromGPIO_: external GPIO-expander read over SCI0 - reconfigures SCI0 (regs 0xfffff002/0xfffff000/0xfffff006/0xfffff001, pools 0x7160/0x7164/0x7166/0x7168), selects channel via PHDR_W 0xfffff72c (pool 0x716c=0xf72c) masks 0x4000/0x8000 (pools 0x716a=0x4000, 0x7180=0x8000) through 0x4bbc (pool 0x7170), sends 0xff (pool 0x716e=0xff) via 0x71ea (SCI0 exchange, toggles PGDR_W 0xfffff764 bit 1), returns the received byte; callers 0x6744/0x6796 store it to 0xffff9ecc/9ecd/9ede.
 */
/* ROM address: 0x000070ac; body bytes: 170; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000070ac (170 bytes). Names prefixed ref_
   are inherited hypotheses. */

int sci0_gpio_expander_read(char param_1)

{
  byte bVar1;
  undefined4 uVar2;
  char cVar3;
  
  uVar2 = sh_raise_interrupt_mask_return_previous(0xb0);
  bVar1 = SCI_SCR0_B;
  SCI_SCR0_B = bVar1 & 0xb;
  SCI_SMR0_B = 0x80;
  bVar1 = SCI_SCR0_B;
  SCI_SCR0_B = bVar1 & 0xfc;
  SCI_SDCR0_B = 0xf0;
  SCI_BRR0_B = 4;
  if (param_1 == '\0') {
    ref_setRegister_REG_BIT_VAL(0xfffff72c,0x4000,0);
    ref_setRegister_REG_BIT_VAL(0xfffff72c,0x8000,0);
  }
  else {
    if (param_1 != '\x01') {
      ref_setRegister_REG_BIT_VAL(0xfffff72c,0x4000,0);
    }
    else {
      ref_setRegister_REG_BIT_VAL(0xfffff72c,0x4000,1);
    }
    ref_setRegister_REG_BIT_VAL(0xfffff72c,0x8000,param_1 != '\x01');
  }
  bVar1 = SCI_SCR0_B;
  SCI_SCR0_B = bVar1 & 0xb | 0x30;
  cVar3 = sci0_exchange_byte_wait_rdrf(0xff);
  ref_setSR(uVar2);
  return (int)cVar3;
}


