/* ROM address: 0x0002d682; body bytes: 88; decompiled */

void FUN_0002d682(void)

{
  undefined *puVar1;
  
  if (DAT_ffffa9b8 == 0.0) {
    DAT_ffffbce0 = 0;
  }
  else if (DAT_ffffbcef == '\0') {
    DAT_ffffbce0 = FUN_000020dc(DAT_ffffb5b8,DAT_ffffc12c,&DAT_0006ac10);
  }
  else {
    if (DAT_ffffbcf5 == '\x01') {
      puVar1 = &DAT_0006ac2c;
    }
    else {
      puVar1 = &DAT_0006ac48;
    }
    DAT_ffffbce0 = FUN_000020dc(puVar1);
  }
  return;
}


