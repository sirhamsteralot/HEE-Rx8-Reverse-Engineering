/* ROM address: 0x0000db58; body bytes: 158; decompiled */

undefined * FUN_0000db58(void)

{
  undefined *puVar1;
  
  puVar1 = &DAT_ffffa40f;
  if ((((DAT_ffffa40f < 100) && (DAT_ffffa40a == '\0')) && (DAT_ffffa410 == '\0')) &&
     (((puVar1 = &DAT_ffffa411, DAT_ffffa411 == '\0' &&
       (puVar1 = (undefined *)(uint)DAT_ffffaae0, puVar1 == &UNK_00000001)) &&
      (puVar1 = &UNK_00000001, DAT_ffffb5e8 != '\x01')))) {
    FUN_000390b0();
    FUN_00029d3a();
    FUN_00029faa();
    FUN_0002a81e();
    if (DAT_ffffb5a4 == '\x01') {
      FUN_0002d16a();
    }
    FUN_0004c5c2();
    FUN_0004c6be();
    FUN_00029742();
    FUN_0003379e();
    FUN_000336aa();
    puVar1 = (undefined *)FUN_0002c56e();
  }
  DAT_ffffc241 = 0;
  return puVar1;
}


