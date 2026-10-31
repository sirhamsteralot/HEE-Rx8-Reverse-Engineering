/* ROM address: 0x0005a698; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00058e50 (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

int ref_someOBDFunctionCaller(void)

{
  int iVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  
  FUN_0005a802();
  ppuVar3 = &PTR_FUN_0005f69c;
  do {
    puVar4 = ppuVar3[1];
    iVar1 = ref_readValue_32bit_ADDRESS_VAL(&DAT_ffff9110 + (int)puVar4 * 8,0);
    iVar2 = (*(code *)*ppuVar3)(iVar1);
    if (iVar2 != iVar1) {
      ref_updateMemoryAtAddress_32bit_ADDR_VAL(&DAT_ffff9110 + (int)puVar4 * 8);
      iVar2 = FUN_0005aa38(puVar4);
    }
    ppuVar3 = ppuVar3 + 2;
  } while (ppuVar3 < &DAT_0005f6dc);
  return iVar2;
}


