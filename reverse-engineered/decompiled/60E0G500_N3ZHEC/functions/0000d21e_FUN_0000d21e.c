/* ROM address: 0x0000d21e; body bytes: 68; decompiled_with_warnings */

uint FUN_0000d21e(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_0000d262();
  if (uVar1 == 0xffffffff) {
    uVar1 = FUN_0000d28e();
  }
  uVar2 = uVar1;
  if ((uVar1 != 0xffffffff) && (uVar2 = (uint)DAT_ffff9f8c, uVar2 == 1)) {
    FUN_000004e0(1,uVar1);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return uVar2;
}


