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

int ref_E2IntoRAM_(ushort param_1,byte param_2)

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
  cVar5 = FUN_0000bed8();
  if ((cVar5 == '\x01') && (cVar5 = FUN_0000bed8(), cVar5 == '\x01')) {
    iVar7 = 1;
  }
  if (iVar7 == 0) {
    iVar3 = (uint)param_2 + (uint)param_1 + -1;
    DAT_ffffc494 = (ushort)((int)(iVar3 + (uint)(iVar3 < 0)) >> 1);
    uStack_38 = (ushort)((int)(uint)param_1 >> 1);
    DAT_ffffc492 = uStack_38;
    for (; uStack_38 <= DAT_ffffc494; uStack_38 = uStack_38 + 1) {
      uVar4 = FUN_0000bdfa((uint)(byte)uStack_38 * 0x10000 + 0x6000000);
      bVar1 = (byte)((ushort)uVar4 >> 8);
      uVar6 = (int)(short)uStack_38 << 1;
      (&DAT_ffffc28e)[uVar6 & 0xffff] = bVar1;
      (&DAT_ffffc38e)[uVar6 & 0xffff] = ~bVar1;
      (&DAT_ffffc28f)[uVar6 & 0xffff] = (byte)uVar4;
      (&DAT_ffffc38f)[uVar6 & 0xffff] = ~(byte)uVar4;
    }
  }
  ref_setSR(uVar2);
  return iVar7;
}


