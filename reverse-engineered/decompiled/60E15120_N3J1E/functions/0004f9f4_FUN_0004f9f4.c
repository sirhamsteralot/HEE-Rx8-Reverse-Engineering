/* ROM address: 0x0004f9f4; body bytes: 114; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004d610 (114 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0004f9f4(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  
  uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a0,0);
  uVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a4,0);
  uVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a6,0);
  DAT_ffffd07e = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86dc,4);
  DAT_ffffd083 = uVar1;
  DAT_ffffd084 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a2,0);
  DAT_ffffd081 = uVar2;
  DAT_ffffd082 = uVar3;
  DAT_ffffd085 = uVar2;
  DAT_ffffd086 = uVar3;
  DAT_ffffd087 = uVar1;
  DAT_ffffd088 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c0,0);
  DAT_ffffd089 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c2,0);
  return;
}


