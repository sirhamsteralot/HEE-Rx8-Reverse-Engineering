/* ROM address: 0x0000c276; body bytes: 26; decompiled */

void knock_reference_adc_read(void)

{
  ushort uVar1;
  
  DAT_ffffa326 = adc_read_result_bank2();
  uVar1 = DAT_fffff66c;
  DAT_fffff66c = uVar1 & 0xefff;
  return;
}


