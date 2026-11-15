/* [ADDITIONAL SOURCE REVIEW]
 * warm_reset_dispatcher [high]: Was ref_reset_ZERO: jsr 0x1364 (pool 0x107a=0x1364), 0x109c (0x107c=0x109c, ref_resetOBDCAN_), 0x16dc (0x107e=0x16dc); param!=0 -> jsr 0x12a2 (pool 0x1080=0x12a2) then entry 0x1378 (pool 0x1082=0x1378); param==0 -> flash-pointer check u32 @0x7fffc (pool 0x1088=0x7fffc) with fallback u32 @0x7fff8 (pool 0x108c=0x7fff8; ROM 0x7fff8 = 0xd204); jsr 0x1090 (pool 0x1084=0x1090; mov.l pool 0x1098 to r15, jmp @r4) then halt at 0x1076.
 */
/* ROM address: 0x00001038; body bytes: 66; decompiled_with_warnings */

/* Unique exact-byte match to related 60E0FC00 function at 00001038 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void warm_reset_dispatcher(int param_1)

{
  code *pcVar1;
  
  ref_resetWatchdog_00001364();
  ref_resetOBDCAN_();
  ref_handleException_(param_1);
  if (param_1 == 0) {
    pcVar1 = (code *)&LAB_0000d204;
  }
  else {
    FUN_000012a2();
    pcVar1 = FUN_00001378;
  }
  FUN_00001090(pcVar1);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


