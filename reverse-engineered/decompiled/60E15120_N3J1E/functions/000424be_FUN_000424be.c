/* ROM address: 0x000424be; body bytes: 108; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00041cf2 (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000424be(void)

{
  short sVar1;
  short *unaff_r11;
  short *unaff_r12;
  short *unaff_r13;
  short unaff_r14;
  
  if (adc_pair_correlation_fault_ffffa1dd == '\x01') {
    if (*unaff_r12 == 4) {
      DAT_ffffc97c = 1;
    }
    sVar1 = rx8_add_u16_saturate((int)*unaff_r12,1);
    *unaff_r12 = sVar1;
    *unaff_r11 = unaff_r14;
  }
  else {
    if (adc_pair_correlation_fault_ffffa1dd != '\x02') {
      if (*unaff_r13 == 8) {
        DAT_ffffc97e = 1;
      }
      sVar1 = rx8_add_u16_saturate((int)*unaff_r13,1);
      *unaff_r13 = sVar1;
      *unaff_r12 = unaff_r14;
      *unaff_r11 = unaff_r14;
      return;
    }
    if (*unaff_r11 == 4) {
      DAT_ffffc97d = 1;
    }
    sVar1 = rx8_add_u16_saturate((int)*unaff_r11,1);
    *unaff_r11 = sVar1;
    *unaff_r12 = unaff_r14;
  }
  *unaff_r13 = unaff_r14;
  return;
}


