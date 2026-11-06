/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_bulk_read_into_shadow [high]: Bulk device->shadow fill (inherited ref_E2IntoRAM_ confirmed): double busy-check 0xbed8 (pool 0x37f70), then for each u16 page p in [start>>1 .. (start+len-1)>>1] read word 0xbdfa(0x6000000 + p*0x10000) (pools 0x37f84/0x37f88) and store high byte at 0xffffc28e[2p], low byte at 0xffffc28f[2p], with complements at 0xffffc38e/0xffffc38f (pools 0x37f7c/0x37f80). Counters 0xffffc492/0xffffc494. Callers: 0x27b8e, 0x35956, 0x4b5b6, 0x5b482.
 */
/* ROM address: 0x00037cd8; body bytes: 460; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00037dc2) */
/* WARNING: Removing unreachable block (ram,0x00037dd2) */
/* WARNING: Removing unreachable block (ram,0x00037dde) */
/* WARNING: Removing unreachable block (ram,0x00037dee) */
/* WARNING: Removing unreachable block (ram,0x00037e10) */
/* WARNING: Removing unreachable block (ram,0x00037dfc) */
/* WARNING: Removing unreachable block (ram,0x00037e12) */
/* WARNING: Removing unreachable block (ram,0x00037e26) */
/* WARNING: Removing unreachable block (ram,0x00037e32) */
/* WARNING: Removing unreachable block (ram,0x00037e48) */
/* WARNING: Removing unreachable block (ram,0x00037e70) */
/* WARNING: Removing unreachable block (ram,0x00037e56) */
/* Unique exact-byte match to related 60E0FC00 function at 000383f8 (460 bytes). Names prefixed ref_
   are inherited hypotheses. */

int e2ram_bulk_read_into_shadow(ushort param_1,byte param_2)

{
  byte bVar1;
  undefined4 uVar2;
  char cVar5;
  int iVar3;
  undefined2 uVar4;
  uint uVar6;
  int iVar7;
  ushort uStack_38;
  
  uVar2 = sh_raise_interrupt_mask_return_previous(0x10);
  iVar7 = 0;
  cVar5 = e2ram_busy_status_read();
  if ((cVar5 == '\x01') && (cVar5 = e2ram_busy_status_read(), cVar5 == '\x01')) {
    iVar7 = 1;
  }
  if (iVar7 == 0) {
    iVar3 = (uint)param_2 + (uint)param_1 + -1;
    DAT_ffffc494 = (ushort)((int)(iVar3 + (uint)(iVar3 < 0)) >> 1);
    uStack_38 = (ushort)((int)(uint)param_1 >> 1);
    DAT_ffffc492 = uStack_38;
    for (; uStack_38 <= DAT_ffffc494; uStack_38 = uStack_38 + 1) {
      uVar4 = e2ram_read_word((uint)(byte)uStack_38 * 0x10000 + 0x6000000);
      bVar1 = (byte)((ushort)uVar4 >> 8);
      uVar6 = (int)(short)uStack_38 << 1;
      (&e2ram_shadow_data_ffffc28e)[uVar6 & 0xffff] = bVar1;
      (&e2ram_shadow_complement_ffffc38e)[uVar6 & 0xffff] = ~bVar1;
      (&DAT_ffffc28f)[uVar6 & 0xffff] = (byte)uVar4;
      (&DAT_ffffc38f)[uVar6 & 0xffff] = ~(byte)uVar4;
    }
  }
  ref_setSR(uVar2);
  return iVar7;
}


