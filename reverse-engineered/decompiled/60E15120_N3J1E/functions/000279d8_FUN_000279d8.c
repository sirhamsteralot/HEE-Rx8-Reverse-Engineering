/* ROM address: 0x000279d8; body bytes: 342; decompiled */

uint FUN_000279d8(void)

{
  bool bVar1;
  char cVar3;
  uint uVar2;
  ushort uVar4;
  undefined *puVar5;
  int iVar6;
  undefined *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined1 local_30;
  undefined1 local_2f;
  
  if (engine_running_flag_ffffaa68 == '\x01') {
    DAT_ffffb6c7 = 1;
    DAT_ffffba16 = 0;
    DAT_ffffba21 = 0;
    return 1;
  }
  if (DAT_ffffb6c7 != 1) {
    return (uint)DAT_ffffb6c7;
  }
  bVar1 = true;
  cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff865a,0);
  if (cVar3 != '\x01') {
    if (DAT_ffffba21 != '\x01') {
      DAT_ffffba21 = '\x01';
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8658,1);
      uVar4 = 0;
      puVar5 = &DAT_ffff8548;
      uVar11 = 0;
      puVar7 = &DAT_ffff8108;
      iVar6 = 0;
      uVar9 = 0xc27c0000;
      uVar10 = 0x3f000000;
      do {
        uVar8 = ref_readValue_float_DEFAULTVAL_ADDRESS(uVar11,puVar7);
        local_30 = rx8_encode_u8_affine_saturate(uVar8,uVar10,uVar9);
        local_2f = ref_readValue_8bit_ADDRESS_VAL(puVar5,0);
        e2ram_shadow_byte_write(iVar6 + 0x20,&local_30,2);
        uVar4 = uVar4 + 1;
        iVar6 = iVar6 + 2;
        puVar5 = puVar5 + 2;
        puVar7 = puVar7 + 8;
      } while (uVar4 < 0x22);
      uVar2 = FUN_000378dc(0x20,0x44,3);
      DAT_ffffba1e = (char)uVar2;
      goto LAB_00027b14;
    }
    if (DAT_ffffba1e == '\x01') {
      uVar2 = FUN_000378dc(0x20,0x44,3);
      DAT_ffffba1e = (char)uVar2;
      goto LAB_00027b14;
    }
    if (DAT_ffffc28d != '\x01') {
      uVar2 = (uint)DAT_ffffc28a;
      if (uVar2 == 1) {
        uVar2 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8658,0);
        bVar1 = false;
      }
      goto LAB_00027b14;
    }
  }
  uVar2 = 1;
  bVar1 = false;
LAB_00027b14:
  if ((bVar1) && (DAT_ffffba16 < 0x4e2)) {
    DAT_ffffba16 = DAT_ffffba16 + 1;
  }
  else {
    DAT_ffffb6c7 = 0;
  }
  return uVar2;
}


