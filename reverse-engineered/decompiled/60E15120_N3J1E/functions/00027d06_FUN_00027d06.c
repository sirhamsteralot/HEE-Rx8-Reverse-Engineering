/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_learned_table_erase [medium]: On engine stop (engine_running_flag_ffffaa68==1 && engine_stopped_latch_ffffa41c==1 && DAT_ffffba20==1) after DAT_ffffba1d reaches 0x14: writes (encode(0.0)=0x7e, flag 0) pairs to shadow 0x20+2i (rx8_encode_u8_affine_saturate(0, 0x3f000000, 0xc27c0000)) i.e. clears the learned table at key-off. Called from 0x288be.
 */
/* ROM address: 0x00027d06; body bytes: 392; decompiled */

undefined1 * candidate_e2ram_learned_table_erase(void)

{
  bool bVar1;
  char cVar2;
  undefined1 *puVar3;
  ushort uVar4;
  short sVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 local_30;
  undefined1 local_2f;
  
  cVar2 = inferred_ram_ad18_ffffad18_ffffad18;
  if ((DAT_ffffba1f == '\0') && (inferred_ram_ad18_ffffad18_ffffad18 == '\x01')) {
    DAT_ffffba20 = '\x01';
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (((engine_running_flag_ffffaa68 == '\x01') && (engine_stopped_latch_ffffa41c == '\x01')) && (DAT_ffffba20 == '\x01')) {
    if ((DAT_ffffba12 < 1000) && (bVar1)) {
      DAT_ffffba1d = rx8_add_u8_saturate((int)DAT_ffffba1d,1);
      if (DAT_ffffba1d == '\x14') {
        DAT_ffffba22 = 1;
        ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff865c,0);
        uVar8 = 0;
        uVar6 = 0xc27c0000;
        uVar4 = 0;
        sVar5 = 0;
        uVar7 = 0x3f000000;
        do {
          local_30 = rx8_encode_u8_affine_saturate(uVar8,uVar7,uVar6);
          local_2f = 0;
          e2ram_shadow_byte_write((int)(short)(sVar5 + 0x20),&local_30,2);
          uVar4 = uVar4 + 1;
          sVar5 = sVar5 + 2;
        } while (uVar4 < 0x22);
        DAT_ffffba1e = e2ram_flush_request(0x20,0x44,3);
      }
    }
    DAT_ffffba12 = rx8_add_u16_saturate((int)(short)DAT_ffffba12,1);
  }
  else {
    DAT_ffffba20 = '\0';
    DAT_ffffba12 = 0;
    DAT_ffffba1d = '\0';
  }
  puVar3 = (undefined1 *)(uint)DAT_ffffba22;
  if (puVar3 == (undefined1 *)0x1) {
    if (DAT_ffffba1e == '\x01') {
      puVar3 = (undefined1 *)e2ram_flush_request(0x20,0x44,3);
      DAT_ffffba1e = (char)puVar3;
    }
    else if (DAT_ffffc28d == '\x01') {
      DAT_ffffba22 = 0;
      puVar3 = (undefined1 *)0x1;
    }
    else {
      puVar3 = (undefined1 *)(uint)DAT_ffffc28a;
      if (puVar3 == (undefined1 *)0x1) {
        DAT_ffffba22 = 0;
        puVar3 = &DAT_ffffb6c8;
        DAT_ffffb6c8 = 1;
        DAT_ffffba14 = -0x80;
      }
    }
  }
  if (DAT_ffffba14 == '\0') {
    DAT_ffffb6c8 = 0;
  }
  else {
    DAT_ffffba14 = DAT_ffffba14 + -1;
  }
  DAT_ffffba1f = cVar2;
  return puVar3;
}


