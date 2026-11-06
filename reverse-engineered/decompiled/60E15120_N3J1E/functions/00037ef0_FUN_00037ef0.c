/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_cached_byte_read [high]: Cached indexed byte read: if shadow 0xffffc28e[i] == ~0xffffc38e[i] (pools 0x37f7c/0x37f80) return shadow; else busy-check 0xbed8 (pool 0x37f70), then device read 0xbdfa (pool 0x37f88) at address 0x6000000 + ((i>>1)&0xff)*0x10000 (base pool 0x37f84 = 0x6000000); even index takes the high byte (big-endian u16). Updates shadow data+complement. Under mask 0x10 (pool 0x37f6c=0x3920, tail 0x3934). Returns error flag.
 * RAM 0xffffc28e e2ram_shadow_data (uint8[256]): E2RAM byte shadow cache: written by 0x37ea4/0x37ef0/0x37cd8, read back for cached reads (0x37ef0 compares against the complement at 0xffffc38e).
 * RAM 0xffffc38e e2ram_shadow_complement (uint8[256]): Complement shadow of 0xffffc28e (0xffffc38e[i] = ~data[i]); match means cache valid, mismatch triggers a device read via 0xbdfa in 0x37ef0.
 */
/* ROM address: 0x00037ef0; body bytes: 190; decompiled */

undefined1 e2ram_cached_byte_read(uint param_1,byte *param_2,char param_3)

{
  undefined4 uVar1;
  char cVar3;
  uint uVar2;
  byte *pbVar4;
  uint uVar5;
  undefined1 uStack_24;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  uStack_24 = 0;
  for (; param_3 != '\0'; param_3 = param_3 + -1) {
    uVar5 = param_1 & 0xffff;
    if ((&e2ram_shadow_data_ffffc28e)[uVar5] == (undefined1)~(&e2ram_shadow_complement_ffffc38e)[uVar5]) {
      *param_2 = (&e2ram_shadow_data_ffffc28e)[uVar5];
    }
    else {
      cVar3 = e2ram_busy_status_read();
      if (cVar3 == '\0') {
        uVar2 = e2ram_read_word(((int)(param_1 & 0xffff) >> 1 & 0xffU) * 0x10000 + 0x6000000);
        if ((param_1 & 1) == 0) {
          uVar2 = (uVar2 & 0xffff) >> 8;
        }
        pbVar4 = &e2ram_shadow_data_ffffc28e + uVar5;
        *pbVar4 = (byte)uVar2;
        (&e2ram_shadow_complement_ffffc38e)[uVar5] = ~*pbVar4;
        *param_2 = *pbVar4;
      }
      else {
        uStack_24 = 1;
      }
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  ref_setSR(uVar1);
  return uStack_24;
}


