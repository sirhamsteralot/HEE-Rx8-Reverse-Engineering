/* ROM address: 0x00047d9c; body bytes: 916; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000481a4) */
/* WARNING: Removing unreachable block (ram,0x000480f2) */
/* WARNING: Removing unreachable block (ram,0x000481c2) */

undefined1 * FUN_00047d9c(void)

{
  char cVar2;
  undefined1 *puVar1;
  byte bVar3;
  
  bVar3 = 0;
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8740,0);
  if (cVar2 == '\x01') {
    bVar3 = 3;
  }
  if ((DAT_ffffb4f3 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb4f5 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb4f7 == '\x01') && (bVar3 < 2)) {
    bVar3 = 2;
  }
  if ((DAT_ffffb4f9 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb4fd == '\x01') && (bVar3 < 2)) {
    bVar3 = 2;
  }
  if ((DAT_ffffb4fb == '\x01') && (bVar3 < 2)) {
    bVar3 = 2;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8744,0);
  if ((cVar2 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffcc96 == '\x01') && (bVar3 == 0)) {
    bVar3 = 1;
  }
  if ((DAT_ffffcc97 == '\x01') && (bVar3 == 0)) {
    bVar3 = 1;
  }
  if ((DAT_ffffcc9e == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8728,0);
  if ((cVar2 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb50c == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8758,0);
  if ((cVar2 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873c,0);
  if ((cVar2 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8748,0);
  if ((cVar2 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8750,0);
  if ((cVar2 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb4f0 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb518 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffcc93 == '\x01') && (bVar3 < 2)) {
    bVar3 = 2;
  }
  if ((DAT_ffffcc94 == '\x01') && (bVar3 < 2)) {
    bVar3 = 2;
  }
  if ((DAT_ffffcc95 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb514 == '\x01') && (bVar3 < 2)) {
    bVar3 = 2;
  }
  if ((DAT_ffffb50e == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb510 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb512 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  puVar1 = (undefined1 *)(uint)DAT_ffffcc4d;
  if (puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) {
    puVar1 = &DAT_0007c69f;
  }
  DAT_ffffcc92 = bVar3;
  return puVar1;
}


