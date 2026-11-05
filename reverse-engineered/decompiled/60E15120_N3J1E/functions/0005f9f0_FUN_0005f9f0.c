/* ROM address: 0x0005f9f0; body bytes: 132; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e2fc (132 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005f9f0(uint param_1,char param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  param_1 = param_1 & 0xffff;
  if (param_2 == '\0') {
    if ((&dtc_state_array_ffffd5fc)[param_1] == -0x40) {
      uVar2 = 1;
    }
  }
  else if (param_2 == '\x01') {
    cVar1 = (&dtc_state_array_ffffd5fc)[param_1];
    if (((cVar1 == -0x40) || (cVar1 == -0x3f)) || (cVar1 == 'p')) {
      uVar2 = 1;
    }
  }
  else if (param_2 == '\x02') {
    cVar1 = FUN_00061d1a();
    if (cVar1 == '\x01') {
      uVar2 = 1;
    }
  }
  else if ((param_2 == '\x03') && ((&dtc_ram_flag_table_ffffd570_ffffd570)[param_1] == '\x01')) {
    uVar2 = 1;
  }
  return uVar2;
}


