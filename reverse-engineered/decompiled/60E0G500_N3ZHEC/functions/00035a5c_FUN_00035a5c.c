/* ROM address: 0x00035a5c; body bytes: 110; decompiled */

undefined * FUN_00035a5c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = DAT_ffffc2e0;
  DAT_ffffc27c = 500;
  DAT_ffffc280 = 0xfa;
  DAT_ffffc292 = 1;
  DAT_ffffc28e = 5;
  puVar2 = DAT_ffffc2dc;
  if ((DAT_ffffc2dc == &UNK_ffffffff) && (puVar2 = puVar1, DAT_ffffc2e0 == &UNK_ffffffff)) {
    DAT_ffffc2dc = (undefined *)((int)&DAT_00010000 + 1);
    DAT_ffffc2e0 = (undefined *)0x55aa55aa;
  }
  if (((DAT_ffffc2ea == -1) && (DAT_ffffc2ec == -1)) || ((DAT_ffffc2ea == 0 && (DAT_ffffc2ec == 0)))
     ) {
    puVar2 = (undefined *)0x55aa;
    DAT_ffffc2ea = 0x55aa;
    DAT_ffffc2ec = -0x481d;
  }
  return puVar2;
}


