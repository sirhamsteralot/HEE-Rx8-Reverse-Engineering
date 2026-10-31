/* ROM address: 0x000006c8; body bytes: 206; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000006c8 (206 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000006c8(void)

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


