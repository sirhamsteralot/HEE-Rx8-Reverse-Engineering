/* [ADDITIONAL SOURCE REVIEW]
 * fatal_trap_report_halt [high]: Fatal report/halt core called by 0x5348 with the vector code in r4; calls halt loop 0xa4be (bsr at 0xa300/0xa344/0xa382/0xa3d4).
 */
/* ROM address: 0x0000a330; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a330 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 fatal_trap_report_halt(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_c [4];
  undefined4 uStack_8;
  
  uStack_8 = param_1;
  ref_setSR_PARAM(auStack_c,0xe0);
  FUN_0000a438(200,uStack_8);
  uVar1 = FUN_0000a4be();
  return uVar1;
}


