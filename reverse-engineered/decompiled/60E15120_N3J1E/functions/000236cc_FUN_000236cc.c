/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffb440 e2ram_staging_block (uint16[28]): E2RAM staging block: u16[0] = magic 0xa55a (mov.w via pool 0x23734 at 0x236ec), payload u16[1..26], u16[27] at +0x36 = checksum (sum of 0x1b u16, loop 0x236f0-0x236fe); 0x1c u16 written to E2RAM via 0xb886.
 * RAM 0xffffb466 e2ram_payload_reserved (uint16): Payload u16[22..26] cells 0xffffb466-0xffffb474: never written by e2ram_block_encode 0x244bc and no pool references in ROM; retained staging bytes. Full-ROM pool scan this pass.
 */
/* ROM address: 0x000236cc; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00023f40 (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000236cc(void)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  byte bVar4;
  
  e2ram_save_encode_entry();
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  DAT_ffffb476 = 0;
  bVar4 = 0;
  e2ram_staging_block_ffffb440 = 0xa55a;
  iVar3 = 0;
  do {
    bVar4 = bVar4 + 1;
    DAT_ffffb476 = DAT_ffffb476 + *(short *)((int)&e2ram_staging_block_ffffb440 + iVar3);
    iVar3 = iVar3 + 2;
  } while (bVar4 < 0x1b);
  cVar2 = FUN_0000b886(&e2ram_staging_block_ffffb440,0x1c);
  if (cVar2 != '\0') {
    DAT_ffffb43b = 1;
  }
  ref_setSR(uVar1);
  return;
}


