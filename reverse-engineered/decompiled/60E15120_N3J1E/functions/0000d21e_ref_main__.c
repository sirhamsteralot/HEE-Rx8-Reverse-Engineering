/* ROM address: 0x0000d21e; body bytes: 68; decompiled_with_warnings */

/* Unique exact-byte match to related 60E0FC00 function at 0000d21e (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_main__(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = ref_interestingCANSomething();
  if (uVar1 == 0xffffffff) {
    uVar1 = FUN_0000d28e();
  }
  uVar2 = uVar1;
  if ((uVar1 != 0xffffffff) && (uVar2 = (uint)DAT_ffff9f8c, uVar2 == 1)) {
    ref_resetHandler_(1,uVar1);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return uVar2;
}


