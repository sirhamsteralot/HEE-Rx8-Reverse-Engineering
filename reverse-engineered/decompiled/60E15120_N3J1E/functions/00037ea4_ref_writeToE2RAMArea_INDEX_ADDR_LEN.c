/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_shadow_byte_write [high]: Indexed shadow write under mask 0x10 (pools 0x37f6c=0x3920, 0x37f8c=0x3934): for len bytes, 0xffffc28e[i] = src byte and 0xffffc38e[i] = ~byte (pools 0x37f7c/0x37f80). Callers: 0x279d8, 0x27d06, 0x35a8c, 0x4b668, 0x5d9d8, 0x5e8a4 (callgraph). Inherited ref_writeToE2RAMArea_INDEX_ADDR_LEN confirmed as the RAM shadow writer (data + complement).
 */
/* ROM address: 0x00037ea4; body bytes: 76; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000385c4 (76 bytes). Names prefixed ref_
   are inherited hypotheses. */

void e2ram_shadow_byte_write(uint param_1,byte *param_2,char param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = sh_raise_interrupt_mask_return_previous(0x10);
  for (; param_3 != '\0'; param_3 = param_3 + -1) {
    uVar3 = param_1 & 0xffff;
    bVar1 = *param_2;
    param_2 = param_2 + 1;
    (&e2ram_shadow_data_ffffc28e)[uVar3] = bVar1;
    param_1 = param_1 + 1;
    (&e2ram_shadow_complement_ffffc38e)[uVar3] = ~(&e2ram_shadow_data_ffffc28e)[uVar3];
  }
  ref_setSR(uVar2);
  return;
}


