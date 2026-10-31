/* ROM address: 0x000508ac; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004e4c8 (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 * FUN_000508ac(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 *puVar3;
  int iVar4;
  
  uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff869c,0);
  uVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fbc,0);
  puVar3 = (undefined2 *)(uVar2 & 0xff);
  if (((puVar3 == (undefined2 *)((int)&vector_Poweron_Reset + 1)) &&
      (puVar3 = &DAT_0007d6ea, engine_on_time_counter_ffffa426 == 0x249)) &&
     (puVar3 = (undefined2 *)-(((DAT_ffffcfb5 & 0x20) == 0) - 1),
     puVar3 == (undefined2 *)((int)&vector_Poweron_Reset + 1))) {
    if ((uVar1 & 0xff) == 3) {
      puVar3 = (undefined2 *)ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff869c,0);
    }
    else {
      if ((uVar1 & 0xff) < 3) {
        iVar4 = uVar1 + 1;
      }
      else {
        iVar4 = 3;
      }
      puVar3 = (undefined2 *)ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff869c,iVar4);
    }
  }
  return puVar3;
}


