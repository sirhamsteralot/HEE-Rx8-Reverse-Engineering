/* ROM address: 0x00017dec; body bytes: 162; decompiled */

uint FUN_00017dec(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  
  cVar2 = DAT_ffffa90d;
  cVar1 = DAT_ffffa90c;
  if (0.0 <= inferred_battery_voltage_ffffb590) {
    if ((DAT_ffffa90c == '\x01') && (DAT_ffffa918 == '\0')) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff805a,1);
    }
    if ((cVar2 == '\x01') && (DAT_ffffa919 == '\0')) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff805c,1);
    }
  }
  else if (((DAT_ffffa90c == '\x01') && (DAT_ffffa918 == '\0')) ||
          ((DAT_ffffa90d == '\x01' && (DAT_ffffa919 == '\0')))) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8058,1);
  }
  uVar3 = (uint)DAT_ffffa8f9;
  if (uVar3 == 1) {
    uVar3 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff805e,1);
  }
  DAT_ffffa918 = cVar1;
  DAT_ffffa919 = cVar2;
  return uVar3;
}


