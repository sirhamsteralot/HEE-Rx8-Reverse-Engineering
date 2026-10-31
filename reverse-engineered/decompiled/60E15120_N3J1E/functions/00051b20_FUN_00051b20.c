/* ROM address: 0x00051b20; body bytes: 144; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004f87c (144 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00051b20(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  sVar1 = DAT_ffffcfaa;
  uVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c4,0x17);
  uVar3 = uVar2;
  if (DAT_ffffd1c5 == '\0') {
    if ((DAT_ffffd0f4 == '\x01') || (uVar3 = (uint)DAT_ffffd0f5, uVar3 == 1)) {
      uVar3 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c4,0);
    }
    else if ((((DAT_ffffd100 == 0x1e) && (sVar1 == 0x1f)) &&
             (uVar3 = (uint)DAT_ffffd0f2, uVar3 == 1)) && ((uVar2 & 0xff) != 0)) {
      uVar3 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c4,uVar2 + 0xff);
    }
  }
  DAT_ffffd100 = sVar1;
  return uVar3;
}


