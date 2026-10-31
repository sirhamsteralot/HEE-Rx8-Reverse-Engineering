/* ROM address: 0x00037ea4; body bytes: 76; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000385c4 (76 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_writeToE2RAMArea_INDEX_ADDR_LEN(uint param_1,byte *param_2,char param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = sh_raise_interrupt_mask_return_previous(0x10);
  for (; param_3 != '\0'; param_3 = param_3 + -1) {
    uVar3 = param_1 & 0xffff;
    bVar1 = *param_2;
    param_2 = param_2 + 1;
    (&DAT_ffffc28e)[uVar3] = bVar1;
    param_1 = param_1 + 1;
    (&DAT_ffffc38e)[uVar3] = ~(&DAT_ffffc28e)[uVar3];
  }
  ref_setSR(uVar2);
  return;
}


