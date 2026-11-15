/* [ADDITIONAL SOURCE REVIEW]
 * cold_entry_ring_dispatch_loop [high]: Cold entry monitor loop (selected by pool 0x58c=0x6c8 in 0x4e0): zeroes 0xffffdfb8 (pool 0x796=0xdfb8); loop jsr 0x364 (pool 0x7a4=0x364; dispatches on reset cause 0xffffdfa8), remaining-count jsr 0x3e0 (pool 0x79e=0x3e0), ring record ptr jsr 0x3b0 (pool 0x7a6=0x3b0; 100 x 8-byte records at 0xffffd4e0); on pending record dispatches on first byte: 'z' with second byte & 0xf8 (pool 0x7a2=0xf8) -> handlers 0x806/0x4c/0x64/0x7c0/0x7c/0x8a/0xc0 (pools 0x7a8-0x7b6), 0xff/0xc8 -> 0xd8; services WDT via jsr 0x31c (pool 0x7be=0x31c).
 */
/* ROM address: 0x000006c8; body bytes: 206; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000006c8 (206 bytes). Names prefixed ref_
   are inherited hypotheses. */

void cold_entry_ring_dispatch_loop(void)

{
  short sVar2;
  char *pcVar1;
  byte bVar3;
  
  DAT_ffffdfb8 = 0;
  do {
    FUN_00000364();
    sVar2 = FUN_000003e0();
    if (sVar2 != 0) {
      pcVar1 = (char *)FUN_000003b0();
      if (*pcVar1 == 'z') {
        bVar3 = pcVar1[1] & 0xf8;
        if (bVar3 == 0xa8) {
          FUN_00000806();
        }
        else if (bVar3 == 0x88) {
          FUN_0000004c();
        }
        else if (bVar3 == 0x90) {
          FUN_00000064();
        }
        else if (bVar3 == 0x98) {
          FUN_000007c0();
        }
        else if (bVar3 == 0xa0) {
          FUN_0000007c();
        }
        else if (bVar3 == 0xb0) {
          FUN_0000008a();
        }
        else if (bVar3 == 0xc0) {
          FUN_000000c0();
        }
      }
      else if ((*pcVar1 == -1) && ((pcVar1[1] & 0xf8U) == 200)) {
        FUN_000000d8();
      }
    }
    service_wdt_overflow_and_toggle_pb15();
  } while( true );
}


