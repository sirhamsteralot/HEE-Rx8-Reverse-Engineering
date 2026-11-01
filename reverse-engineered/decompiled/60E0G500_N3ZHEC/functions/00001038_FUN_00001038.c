/* ROM address: 0x00001038; body bytes: 66; decompiled_with_warnings */

void FUN_00001038(int param_1)

{
  undefined *puVar1;
  
  FUN_00001364();
  FUN_0000109c();
  FUN_000016dc(param_1);
  if (param_1 == 0) {
    puVar1 = &DAT_0000d204;
  }
  else {
    FUN_000012a2();
    puVar1 = &DAT_00001378;
  }
  FUN_00001090(puVar1);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


