/* [ADDITIONAL SOURCE REVIEW]
 * reset_handler_warm_cold_select [high]: Warm/cold entry select (was ref_resetHandler_): bsr 0x572; jsr 0x170 (pool 0x586=0x170), 0x41c (0x588=0x41c), 0x3d4 (0x58a=0x3d4); param==0: cmp u32 @0xffffdffc (pool 0x5a0=0xffffdffc) vs 0x5aa5a55a (pool 0x59c=0x5aa5a55a) at 0x508; on mismatch bsr 0x5b0 with r4=7 (WDT overflow count) - magic match or overflow selects warm entry = u32 @ROM 0x1000 (pool 0x58e=0x1000; ROM 0x1000 = 0x1298), else cold 0x6c8 (pool 0x58c=0x6c8); warm branch also tests u32 @0x7fffc (pool 0x5a4=0x7fffc; ROM 0x7fffc = 0x2000) with fallback u32 @0x7fff8 (pool 0x5a8=0x7fff8; ROM 0x7fff8 = 0xd204); writes 0x5aa5a55a to 0xffffdffc at 0x562-0x566, jsr 0x40 (pool 0x594=0x40) with r4 = chosen entry, halt. param!=0 branch stores param_2 byte to 0xffffdfa8 (pool 0x590=0xdfa8) and selects cold 0x6c8.
 * RAM 0xffffdffc warm_boot_magic (uint32): Warm-boot magic 0x5aa5a55a, written on every reset by 0x4e0 (pool 0x5a0=0xffffdffc) and compared at 0x508 to select warm vs cold entry; top-of-RAM protected cell (range-checked in 0x87c).
 */
/* ROM address: 0x000004e0; body bytes: 146; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00000550) */
/* WARNING: Removing unreachable block (ram,0x00000532) */
/* WARNING: Removing unreachable block (ram,0x0000053c) */
/* Unique exact-byte match to related 60E0FC00 function at 000004e0 (146 bytes). Names prefixed ref_
   are inherited hypotheses. */

void reset_handler_warm_cold_select(int param_1,undefined1 param_2)

{
  bool bVar1;
  int iVar2;
  code *unaff_r13;
  
  bVar1 = true;
  wdt_keyed_reset();
  FUN_00000170();
  FUN_0000041c();
  FUN_000003d4();
  if (param_1 == 0) {
    if ((warm_boot_magic_ffffdffc != 0x5aa5a55a) && (iVar2 = wdt_overflow_reset_check(7), iVar2 == 0)) {
      bVar1 = false;
      unaff_r13 = cold_entry_ring_dispatch_loop;
    }
    if (bVar1) {
      unaff_r13 = (code *)&DAT_00001298;
    }
  }
  else {
    reset_cause_ffffdfa8 = param_2;
    FUN_000008f6();
    unaff_r13 = cold_entry_ring_dispatch_loop;
  }
  warm_boot_magic_ffffdffc = 0x5aa5a55a;
  FUN_00000040(unaff_r13);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


