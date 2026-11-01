/* ROM address: 0x00068b78; body bytes: 24; decompiled */

uint isotp_pci_type_extract(void)

{
  uint uVar1;
  
  uVar1 = (int)DAT_ffffde04 & 0xf0;
  if (0x3f < uVar1) {
    uVar1 = 0x40;
  }
  return uVar1;
}


