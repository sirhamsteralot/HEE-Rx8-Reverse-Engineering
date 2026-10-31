/* ROM address: 0x000070ac; body bytes: 170; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000070ac (170 bytes). Names prefixed ref_
   are inherited hypotheses. */

int ref_getFromGPIO_(char param_1)

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


