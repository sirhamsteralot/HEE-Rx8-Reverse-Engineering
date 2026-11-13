/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_learned_table_load [high]: e2ram_bulk_read_into_shadow(0x20,0x44) then 0x22 iterations of e2ram_cached_byte_read(0x20+2i,..,2): value = rx8_decode_u8_affine(0x3f000000, 0xc27c0000, raw) = -63 + raw*0.5 (pools 0x27c84/0x27c80) -> float cells 0xffff8108+8i (+value) and 0xffff8328+8i (-value), flag byte (0xff->0) -> 0xffff8548+2i and 0xffff85d0+2i via ref_updateMemoryAtAddress_*. Called from 0x2874c/0x288be.
 * RAM 0xffff8108 e2ram_learned_table_value_pos (float[68]): Learned-table decoded float cells (+value = -63 + raw*0.5) from chip pairs 0x20+2i, written by 0x27b8e/0x279d8; cleared in 2x0x44 pattern by 0x27024.
 * RAM 0xffff8328 e2ram_learned_table_value_neg (float[68]): Negated copies of the learned-table floats (0xffff8108 mirrored at -value), written by 0x27b8e.
 * RAM 0xffff8548 e2ram_learned_table_flag_a (uint8[136]): Learned-table flag bytes (chip 0x21+2i, 0xff->0) from 0x27b8e.
 * RAM 0xffff85d0 e2ram_learned_table_flag_b (uint8[136]): Second flag array (0xffff8548+0x88), written by 0x27b8e/0x27024.
 */
/* ROM address: 0x00027b8e; body bytes: 314; decompiled */

void e2ram_learned_table_load(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  ushort uStack_38;
  char local_34;
  char local_33;
  
  if ((((DAT_ffffba23 == '\0') && (DAT_ffffc6b4 == '\x01')) ||
      ((DAT_ffffba22 == '\0' &&
       (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff865c,0), cVar1 == '\0')))) &&
     (cVar1 = e2ram_bulk_read_into_shadow(0x20,0x44), cVar1 == '\0')) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff865a,1);
    fVar7 = 1.0;
    iVar4 = 0;
    uStack_38 = 0;
    iVar5 = 0;
    iVar3 = 0;
    uVar8 = 0xc27c0000;
    uVar9 = 0x3f000000;
    do {
      cVar1 = e2ram_cached_byte_read(iVar3 + 0x20,&local_34,2);
      if (cVar1 == '\0') {
        fVar6 = (float)rx8_decode_u8_affine(uVar9,uVar8,(int)local_34);
        if (local_33 == -1) {
          iVar2 = 0;
        }
        else {
          iVar2 = (int)local_33;
        }
        ref_updateMemoryAtAddress_float_VAL_ADDR(fVar6,&e2ram_learned_table_value_pos_ffff8108 + iVar5);
        ref_updateMemoryAtAddress_8bit_ADDR_VAL(&e2ram_learned_table_flag_a_ffff8548 + iVar4,iVar2);
        ref_updateMemoryAtAddress_float_VAL_ADDR(-(fVar6 * fVar7),&e2ram_learned_table_value_neg_ffff8328 + iVar5);
        ref_updateMemoryAtAddress_8bit_ADDR_VAL(&e2ram_learned_table_flag_b_ffff85d0 + iVar4,iVar2);
      }
      iVar4 = iVar4 + 2;
      uStack_38 = uStack_38 + 1;
      iVar5 = iVar5 + 8;
      iVar3 = iVar3 + 2;
    } while (uStack_38 < 0x22);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff865a,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff865c,1);
  }
  DAT_ffffba23 = 1;
  return;
}


