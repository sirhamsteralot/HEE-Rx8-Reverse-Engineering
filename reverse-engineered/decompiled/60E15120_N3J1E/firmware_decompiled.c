#include "rx8_analysis_types.h"
/* [EXPORT CLEANUP]
 * jmp @r4 at 0x42 is an indirect tail jump through register r4, preceded only by
 * a PC-relative constant load into r15. No ROM switch or index data is read, so
 * the decompiler warning is expected; the parameter formerly named
 * UNRECOVERED_JUMPTABLE has been renamed indirect_target. The producer of r4
 * is not established in this dump.
 */
/* Decompiled from 60E15120_N3J1E.bin using Ghidra.
 * Analysis C: not original source and not a buildable replacement firmware.
 * ref_ names are inferred from unique exact-byte matches to 60E0FC00.
 * CAL_ labels come from local RX8Defs; see metadata and README.
 */

/* [INTEGRATED REVIEWED NAMES]
 * Canonical analysis C includes wiring, Denso, RX8Defs, G-ROM and CAN reviews.
 * inferred_ and candidate_ names remain hypotheses; address suffixes preserve identity.
 * Provenance comments retain historical symbols. This is not buildable firmware.
 * Saved Ghidra database has not been updated; see metadata/integrated_names.json.
 */
/* ROM address: 0x00000040; body bytes: 6; decompiled_with_warnings */

void FUN_00000040(code *indirect_target)

{
                    /* WARNING: Could not recover jumptable at 0x00000042. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*indirect_target)();
  return;
}


/* ROM address: 0x0000004c; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000004c (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0000004c(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 1) & 7) == 0) {
    uVar1 = FUN_00000338(0x88,6,0xfec);
    return uVar1;
  }
  return (uint)*(byte *)(param_1 + 1);
}


/* ROM address: 0x00000064; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00000064 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00000064(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 1) & 7) == 0) {
    uVar1 = FUN_00000338(0x90,6,0xff8);
    return uVar1;
  }
  return (uint)*(byte *)(param_1 + 1);
}


/* ROM address: 0x0000007c; body bytes: 14; decompiled */

void FUN_0000007c(int param_1)

{
  DAT_ffffdfa4 = param_1 + 2;
  FUN_00000040(immo_diag_bit_ffffdfa0);
  return;
}


/* ROM address: 0x0000008a; body bytes: 54; decompiled */

uint FUN_0000008a(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 local_c [4];
  int iStack_8;
  
  uVar1 = *(byte *)(param_1 + 1) & 0xffffff07;
  if (uVar1 == 4) {
    iStack_8 = param_1;
    uVar2 = FUN_000000f4(param_1 + 2);
    local_c[0] = FUN_0000011a(immo_diag_bit_ffffdfa0,uVar2);
    uVar1 = FUN_00000338(0xb0,1,local_c);
  }
  return uVar1;
}


/* ROM address: 0x000000c0; body bytes: 24; decompiled */

uint FUN_000000c0(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 1) & 7) == 0) {
    uVar1 = FUN_00000338(0xc0,6,0xfe4);
    return uVar1;
  }
  return (uint)*(byte *)(param_1 + 1);
}


/* ROM address: 0x000000d8; body bytes: 28; decompiled_with_warnings */

byte FUN_000000d8(int param_1)

{
  if ((*(byte *)(param_1 + 1) & 7) != 0) {
    return *(byte *)(param_1 + 1);
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ROM address: 0x000000f4; body bytes: 38; decompiled */

int FUN_000000f4(byte *param_1)

{
  return (uint)param_1[1] * 0x10000 + (uint)param_1[2] * 0x100 + (uint)*param_1 * 0x1000000 +
         (uint)param_1[3];
}


/* ROM address: 0x0000011a; body bytes: 56; decompiled */

uint FUN_0000011a(byte *param_1,byte *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    uVar1 = (uVar1 + *param_1 >> 8) + uVar1 + *param_1 & 0xff;
    service_wdt_overflow_and_toggle_pb15();
  }
  return uVar1;
}


/* ROM address: 0x00000170; body bytes: 160; decompiled */

void FUN_00000170(void)

{
  can_enter_reset_mode(&HCAN0_MCR_B);
  HCAN0_TXPR_W = 0;
  HCAN0_TXCR_W = 0;
  HCAN0_TXACK_W = 0xfeff;
  HCAN0_ABACK_W = 0xfeff;
  HCAN0_RXPR_W = 0xffff;
  HCAN0_RFPR_W = 0xffff;
  HCAN0_UMSR_W = 0xffff;
  HCAN0_BCR_W = 0x803e;
  INT_ATU102_IMI10AG(0,1,8,1,0xffffe,1,&HCAN0_MBCR_W,&HCAN0_MBIMR_W,&HCAN0_MD0_1__B,&HCAN0_MC0_1__B)
  ;
  INT_ATU102_IMI10AG(1,0,8,1,0x21,1,&HCAN0_MBCR_W,&HCAN0_MBIMR_W,&HCAN0_MD1_1__B,&HCAN0_MC1_1__B);
  can_exit_reset_mode(&HCAN0_MCR_B);
  HCAN0_IMR_W = 0xfeff;
  HCAN0_LAFMH_W = 0;
  HCAN0_LAFML_W = 0;
  return;
}


/* ROM address: 0x00000210; body bytes: 70; decompiled */

undefined4 FUN_00000210(undefined4 param_1)

{
  ushort uVar1;
  
  uVar1 = HCAN0_RXPR_W;
  if ((uVar1 & 0x100) == 0) {
    return 0;
  }
  uVar1 = HCAN0_UMSR_W;
  if ((uVar1 & 0x100) != 0) {
    HCAN0_UMSR_W = 0x100;
    return 0xffffffff;
  }
  HCAN0_RXPR_W = 0x100;
  FUN_00000ace(8,0,param_1,&HCAN0_MD0_1__B);
  return 1;
}


/* ROM address: 0x00000256; body bytes: 110; decompiled */

void FUN_00000256(char param_1,byte param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  uint uVar3;
  byte bVar4;
  
  bVar4 = 0;
  if (param_2 != 0) {
    do {
      uVar3 = (uint)bVar4;
      uVar1 = *param_3;
      param_3 = param_3 + 1;
      bVar4 = bVar4 + 1;
      (&DAT_ffffdfae)[uVar3] = uVar1;
    } while (bVar4 < param_2);
  }
  DAT_ffffdfad = param_1 + param_2;
  if ((param_1 == -0x20) || (param_1 == -0x28)) {
    DAT_ffffdfac = 0;
  }
  else {
    DAT_ffffdfac = 0x7a;
  }
  do {
    uVar2 = HCAN0_TXPR_W;
  } while ((uVar2 & 0x200) != 0);
  HCAN0_TXACK_W = 0x200;
  FUN_00000ae8(8,0,&DAT_ffffdfac,&HCAN0_MD1_1__B);
  HCAN0_TXPR_W = 0x200;
  return;
}


/* [CROSS-ECU / RX8DEFS REVIEW]
 * service_wdt_overflow_and_toggle_pb15 [behavior_verified_role_candidate]: On WDT status bit 0x80, writes keyed value 0xa53c then toggles PBDR bit15. Matches external-watchdog heartbeat idiom documented by npkern; external chip/pin routing remains unverified. Boot-path evidence, not yet the running-engine heartbeat.
 */
/* ROM address: 0x0000031c; body bytes: 28; decompiled */

byte service_wdt_overflow_and_toggle_pb15(void)

{
  byte bVar1;
  ushort uVar2;
  
  bVar1 = WDT_TCSR_RW__B;
  if ((bVar1 & 0x80) != 0) {
    Ramffffec10 = 0xa53c;
    uVar2 = PBDR_W;
    PBDR_W = uVar2 ^ 0x8000;
  }
  return bVar1;
}


/* ROM address: 0x00000338; body bytes: 44; decompiled */

void FUN_00000338(char param_1,char param_2)

{
  if (reset_cause_ffffdfa8 == '\0') {
    FUN_00000256((int)param_1,(int)param_2);
    return;
  }
  FUN_0000047c(param_1,param_2);
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffdfa8 reset_cause (uint8): Reset-cause selector: written by the param!=0 branch of 0x4e0 (pool 0x590=0xdfa8) and by 0x5b0; selects the 0x210 vs 0x450 dispatch in 0x364/0x338.
 */
/* ROM address: 0x00000364; body bytes: 76; decompiled */

void FUN_00000364(void)

{
  int iVar1;
  
  if (reset_cause_ffffdfa8 == '\0') {
    iVar1 = FUN_00000210();
  }
  else {
    iVar1 = FUN_00000450(&DAT_ffffd4e0 + (uint)DAT_ffffdfb4 * 8);
  }
  if ((iVar1 == 1) && (DAT_ffffdfb4 = DAT_ffffdfb4 + 1, 99 < DAT_ffffdfb4)) {
    DAT_ffffdfb4 = 0;
  }
  return;
}


/* ROM address: 0x000003b0; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000003b0 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined * FUN_000003b0(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffdfb6;
  DAT_ffffdfb6 = DAT_ffffdfb6 + 1;
  if (99 < DAT_ffffdfb6) {
    DAT_ffffdfb6 = 0;
  }
  return &DAT_ffffd4e0 + uVar1 * 8;
}


/* ROM address: 0x000003d4; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000003d4 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000003d4(void)

{
  DAT_ffffdfb6 = 0;
  DAT_ffffdfb4 = 0;
  return;
}


/* ROM address: 0x000003e0; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000003e0 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000003e0(void)

{
  int iVar1;
  
  iVar1 = (uint)DAT_ffffdfb4 - (uint)DAT_ffffdfb6;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 100;
  }
  return iVar1;
}


/* ROM address: 0x0000041c; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000041c (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000041c(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  
  iVar5 = 8;
  puVar1 = &DAT_ffffdfe4;
  puVar2 = &DAT_ffffdff0;
  do {
    puVar4 = puVar2;
    puVar3 = puVar1;
    *puVar3 = 0;
    iVar5 = iVar5 + -1;
    *puVar4 = 0;
    puVar1 = puVar3 + 1;
    puVar2 = puVar4 + 1;
  } while (iVar5 != 0);
  puVar3[1] = 0xaa;
  puVar3 = puVar3 + 2;
  puVar4[1] = 0xaa;
  puVar4 = puVar4 + 2;
  iVar5 = 3;
  do {
    iVar5 = iVar5 + -1;
    *puVar3 = 0;
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar5 != 0);
  return;
}


/* ROM address: 0x00000450; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00000450 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00000450(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  puVar2 = &DAT_ffffdfe4;
  if (DAT_ffffdfec != 'U') {
    return 0xffffffff;
  }
  uVar3 = 0;
  do {
    uVar3 = uVar3 + 1;
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
    *param_1 = uVar1;
    param_1 = param_1 + 1;
  } while (uVar3 < 8);
  DAT_ffffdfec = 0xaa;
  return 1;
}


/* ROM address: 0x0000047c; body bytes: 86; decompiled */

void FUN_0000047c(char param_1,byte param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  byte bVar3;
  
  do {
  } while (DAT_ffffdff8 != -0x56);
  if ((param_1 == -0x20) || (param_1 == -0x28)) {
    DAT_ffffdff0 = 0;
  }
  else {
    DAT_ffffdff0 = 0x7a;
  }
  DAT_ffffdff1 = param_1 + param_2;
  puVar2 = &DAT_ffffdff2;
  bVar3 = 0;
  if (param_2 != 0) {
    do {
      uVar1 = *param_3;
      param_3 = param_3 + 1;
      bVar3 = bVar3 + 1;
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
    } while (bVar3 < param_2);
  }
  DAT_ffffdff8 = 0x55;
  return;
}


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


/* [ADDITIONAL SOURCE REVIEW]
 * wdt_keyed_reset [high]: Was ref_resetWatchdog_: RSTCSR_W 0xffffec12 = 0x5a1f (pools 0x596=0x5a1f, 0x598=0xec12), then TCSR 0xffffec10 = 0x5a00 and keyed write 0xa53c (pools 0x59a=0xec10, 0x5ac=0xa53c) - SH keyed WDT/RSTCSR write idiom (0x5a/0xa5 upper bytes).
 */
/* ROM address: 0x00000572; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00000572 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void wdt_keyed_reset(void)

{
  WDT_RSTCSR_W__B = 0x5a1f;
  Ramffffec10 = 0x5a00;
  Ramffffec10 = 0xa53c;
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * wdt_overflow_reset_check [high]: Was ref_checkWatchdogTimer_OVRCOUNT: loops param times - stores 0x624() result into reset cause 0xffffdfa8 (pool 0x6b6=0xdfa8), jsr 0x364 (pool 0x6ba=0x364), remaining 0x3e0 (0x6bc), ring 0x3b0 (0x6be); returns 0 when a record was processed; otherwise counts WDT TCSR 0xffffec10 (pool 0x6b8=0xec10) OVF bit 0x80, servicing via 0x31c (pool 0x6c0). Called from 0x4e0 with r4=7: any overflow => warm reset.
 */
/* ROM address: 0x000005b0; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000005b0 (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 wdt_overflow_reset_check(ushort param_1)

{
  byte bVar1;
  short sVar4;
  undefined4 uVar2;
  int iVar3;
  ushort uVar5;
  
  uVar5 = 0;
  if (param_1 != 0) {
    do {
      reset_cause_ffffdfa8 = FUN_00000624();
      FUN_00000364();
      sVar4 = FUN_000003e0();
      if (sVar4 != 0) {
        uVar2 = FUN_000003b0();
        iVar3 = FUN_00000636(uVar2);
        if (iVar3 != 0) {
          return 0;
        }
      }
      bVar1 = WDT_TCSR_RW__B;
      if ((bVar1 & 0x80) != 0) {
        uVar5 = uVar5 + 1;
        service_wdt_overflow_and_toggle_pb15();
      }
    } while (uVar5 < param_1);
  }
  return 1;
}


/* ROM address: 0x00000624; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00000624 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_00000624(void)

{
  return DAT_ffffdfec == 'U';
}


/* ROM address: 0x00000636; body bytes: 128; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00000636 (128 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00000636(char *param_1)

{
  if (((((*param_1 == -1) && (param_1[1] == -0x7a)) && (param_1[2] == '\0')) &&
      ((param_1[3] == '\0' && (param_1[4] == '\0')))) &&
     ((param_1[5] == '\0' && ((param_1[6] == '\0' && (param_1[7] == '\0')))))) {
    return 1;
  }
  return 0;
}


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


/* ROM address: 0x000007c0; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000007c0 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000007c0(int param_1)

{
  uint uVar1;
  
  uVar1 = *(byte *)(param_1 + 1) & 0xffffff07;
  if (uVar1 == 4) {
    immo_diag_bit_ffffdfa0 = FUN_000000f4();
    if (DAT_ffffdfb8 == '\x01') {
      DAT_ffffdfb8 = '\0';
    }
    uVar1 = FUN_00000338(0x98,4,param_1 + 2);
    return uVar1;
  }
  return uVar1;
}


/* ROM address: 0x00000806; body bytes: 94; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00000806 (94 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00000806(int param_1)

{
  int iVar1;
  undefined1 local_18 [4];
  int iStack_14;
  byte bStack_10;
  uint uStack_c;
  
  bStack_10 = *(byte *)(param_1 + 1) & 7;
  if (DAT_ffffdfb8 == '\0') {
    DAT_ffffdfb8 = '\x01';
    DAT_ffffdfbc = immo_diag_bit_ffffdfa0;
  }
  uStack_c = (uint)bStack_10;
  iStack_14 = param_1;
  iVar1 = FUN_0000087c(param_1 + 2,uStack_c,DAT_ffffdfbc);
  DAT_ffffdfbc = uStack_c + DAT_ffffdfbc;
  if (iVar1 == -1) {
    local_18[0] = 2;
    FUN_00000338(0xa8,1,local_18);
  }
  return;
}


/* ROM address: 0x0000087c; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000087c (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000087c(undefined1 *param_1,int param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  if ((param_3 < &DAT_ffff6000) || ((int)&warm_boot_magic_ffffdffc + 3U < (uint)((int)param_3 + param_2 + -1)))
  {
    uVar2 = 0xffffffff;
  }
  else {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      uVar1 = *param_1;
      param_1 = param_1 + 1;
      *(undefined1 *)param_3 = uVar1;
      param_3 = (undefined4 *)((int)param_3 + 1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


/* ROM address: 0x000008b4; body bytes: 4; decompiled_with_warnings */

void Illegal_instr(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ROM address: 0x000008b8; body bytes: 20; decompiled_with_warnings */

/* Unique exact-byte match to related 60E0FC00 function at 000008b8 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_Manual_Reset(void)

{
  boot_wait_nmi_pin_high();
  FUN_000008f6();
  reset_handler_warm_cold_select(0);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* [ADDITIONAL SOURCE REVIEW]
 * boot_wait_nmi_pin_high [high]: Contains the poll at 0x8ea: mov.w @(0xffffed18) & 0x8000 (ICR_W bit15 = NMI pin level, Sh7055h.pdf 7.3.2) until set. Emulator: with NMI modeled low, boot hangs exactly here (pc 0x8ea, 1 mmio write); with SYSC nmi_level=1 boot reaches idle 0x3dac.
 */
/* ROM address: 0x000008cc; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000008cc (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 boot_wait_nmi_pin_high(void)

{
  ushort uVar1;
  
  BSC_BCR1_W = 0xf;
  BSC_BCR2_W = 0xffff;
  BSC_WCR_W = 0xffff;
  BSC_RAMER_W = 0;
  MSTCR__W__W = 0x3c04;
  ICR_W = 0;
  do {
    uVar1 = ICR_W;
  } while ((uVar1 & 0x8000) == 0);
  return 0;
}


/* ROM address: 0x000008f6; body bytes: 166; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000008f6 (166 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000008f6(void)

{
  PADR_W = 0xffff;
  PACRH_W = 0;
  PACRL_W = 0;
  PAIOR_W = 0;
  PBDR_W = 0xefff;
  PBCRH_W = 0;
  PBCRL_W = 0;
  PBIR_W = 0;
  PBIOR_W = 0x9000;
  PCDR_W = 0x1f;
  PCCR_W = 0;
  PCIOR_W = 0;
  PDDR_W = 0x3eff;
  PDCRH_W = 0;
  PDCRL_W = 0;
  PDIOR_W = 0x2000;
  PEDR_W = 0xffff;
  PECR_W = 0;
  PEIOR_W = 0;
  PFDR_W = 0xffff;
  PFCRH_W = 0x8000;
  PFCRL_W = 0;
  PFIOR_W = 0;
  PGDR_W = 0xf;
  PGCR_W = 0;
  PGIOR_W = 0;
  PHDR_W = 0xffff;
  PHCR_W = 0;
  PHIOR_W = 0;
  PJDR_W = 0xffff;
  PJCRH_W = 0;
  PJCRL_W = 0;
  PJIOR_W = 0;
  PKDR_W = 0xffff;
  PKCRH_W = 0;
  PKCRL_W = 0;
  PKIR_W = 0;
  PKIOR_W = 0;
  PLDR_W = 0x3fff;
  PLCRH_W = 0x50;
  PLCRL_W = 0;
  PLIR_W = 0;
  PLIOR_W = 0;
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * can_enter_reset_mode [high]: MCR |= 1 then waits GSR bit3 (0x08) set, 4000-iteration timeout. Emulator: with the GSR handshake modeled, boot passes; without it boot spun here forever.
 */
/* ROM address: 0x000009c0; body bytes: 30; decompiled */

uint can_enter_reset_mode(char *param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (int)*param_1 | 1;
  *param_1 = (char)uVar1;
  iVar2 = 4000;
  do {
    if ((*param_2 & 8) != 0) {
      return uVar1;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return uVar1;
}


/* [ADDITIONAL SOURCE REVIEW]
 * can_exit_reset_mode [high]: MCR &= ~1, waits GSR bit3 clear. Pairs with 0x9c0 (HCAN1 copies at 0x1e94/0x1eb2).
 */
/* ROM address: 0x000009de; body bytes: 30; decompiled */

byte can_exit_reset_mode(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *param_1 & 0xfe;
  *param_1 = bVar1;
  iVar2 = 4000;
  do {
    if ((*param_2 & 8) == 0) {
      return bVar1;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return bVar1;
}


/* ROM address: 0x000009fc; body bytes: 210; decompiled */

void INT_ATU102_IMI10AG(uint param_1,ushort param_2,undefined1 param_3,char param_4,uint param_5,
                       byte param_6,ushort *param_7,ushort *param_8,undefined1 *param_9,
                       undefined1 *param_10)

{
  ushort uVar2;
  int iVar1;
  uint uVar4;
  short sVar3;
  
  sVar3 = 1;
  uVar2 = 1;
  for (uVar4 = (param_1 & 0xff) + 8 & 0xf; uVar4 != 0; uVar4 = uVar4 - 1) {
    sVar3 = sVar3 << 1;
    uVar2 = uVar2 << 1;
  }
  *param_7 = ~uVar2 & *param_7 | (param_2 & 0xff) * sVar3;
  *param_8 = *param_8 & ~uVar2 | param_6 * uVar2;
  *param_10 = param_3;
  if (param_4 == '\0') {
    param_10[4] = (char)param_5 * ' ';
    param_10[5] = (char)(param_5 >> 3);
  }
  else {
    param_10[4] = ((byte)(param_5 >> 0x10) & 3) + (char)(param_5 >> 0x12) * ' ' + param_4 * '\b';
    param_10[5] = (char)(param_5 >> 0x15);
    param_10[6] = (char)param_5;
    param_10[7] = (char)(param_5 >> 8);
  }
  iVar1 = 8;
  do {
    iVar1 = iVar1 + -1;
    *param_9 = 0;
    param_9 = param_9 + 1;
  } while (iVar1 != 0);
  return;
}


/* ROM address: 0x00000ace; body bytes: 26; decompiled */

byte FUN_00000ace(byte param_1,byte param_2,undefined1 *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  
  for (; param_2 < param_1; param_2 = param_2 + 1) {
    uVar1 = *param_4;
    param_4 = param_4 + 1;
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  return param_1;
}


/* ROM address: 0x00000ae8; body bytes: 36; decompiled */

uint FUN_00000ae8(byte param_1,uint param_2,char *param_3,char *param_4)

{
  char cVar1;
  
  for (; (param_2 & 0xff) < (uint)param_1; param_2 = param_2 + 1) {
    cVar1 = *param_3;
    do {
      *param_4 = cVar1;
    } while (*param_4 != cVar1);
    param_4 = param_4 + 1;
    param_3 = param_3 + 1;
  }
  return param_2;
}


/* ROM address: 0x00001008; body bytes: 36; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00001026) */
/* WARNING: Removing unreachable block (ram,0x0000101c) */
/* Unique exact-byte match to related 60E0FC00 function at 00001008 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00001008(void)

{
  return 2;
}


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


/* [EXPORT CLEANUP]
 * jmp @r4 at 0x1092 is an indirect tail jump through register r4, preceded only
 * by a PC-relative constant load into r15. No ROM switch or index data is read,
 * so the decompiler warning is expected; the parameter formerly named
 * UNRECOVERED_JUMPTABLE has been renamed indirect_target. The producer of r4
 * is not established in this dump.
 */
/* ROM address: 0x00001090; body bytes: 6; decompiled_with_warnings */

void FUN_00001090(code *indirect_target)

{
                    /* WARNING: Could not recover jumptable at 0x00001092. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*indirect_target)();
  return;
}


/* ROM address: 0x0000109c; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000109c (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_resetOBDCAN_(void)

{
  FUN_00001e94(&HCAN0_MCR_B);
  FUN_00001ed0(0xe,1,8,0,0x7e0,1,&HCAN0_MBCR_W,&HCAN0_MBIMR_W,&HCAN0_MD14_1__B,&HCAN0_MC14_1__B);
  FUN_00001ed0(0xf,0,8,0,0x7e8,1,&HCAN0_MBCR_W,&HCAN0_MBIMR_W,&HCAN0_MD15_1__B,&HCAN0_MC15_1__B);
  FUN_00001eb2(&HCAN0_MCR_B);
  return;
}


/* ROM address: 0x000010fe; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000010fe (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000010fe(undefined4 param_1)

{
  ushort uVar1;
  char cVar2;
  
  uVar1 = HCAN0_RXPR_W;
  if ((uVar1 & 0x40) != 0) {
    uVar1 = HCAN0_UMSR_W;
    if ((uVar1 & 0x40) != 0) {
      HCAN0_UMSR_W = 0x40;
      return 0xffffffff;
    }
    cVar2 = FUN_00001fe2(0);
    if (cVar2 == '\b') {
      HCAN0_RXPR_W = 0x40;
      FUN_00001fa2(8,0,param_1,&HCAN0_MD14_1__B);
      return 1;
    }
    HCAN0_RXPR_W = 0x40;
  }
  return 0;
}


/* ROM address: 0x00001150; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001150 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001150(undefined4 param_1)

{
  ushort uVar1;
  
  do {
    uVar1 = HCAN0_TXPR_W;
  } while ((uVar1 & 0x80) != 0);
  HCAN0_TXACK_W = 0x80;
  FUN_00001fbc(8,0,param_1,&HCAN0_MD15_1__B);
  HCAN0_TXPR_W = 0x80;
  return;
}


/* ROM address: 0x00001182; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001182 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001182(void)

{
  HCAN0_RXPR_W = 0x40;
  HCAN0_UMSR_W = 0x40;
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * immo_diag_bit_clear [medium]: 8 B 'writeImmoBitZero?' (inherited name), called from 0x1378. mov.l pool 0x1284 = 0xffffdfa0; stores byte 0 to it (clears the immo diag bit at boot). Pool word re-read from ROM.
 * RAM 0xffffdfa0 immo_diag_bit (u16): pool 0x1284 = 0xffffdfa0 stored as a word in 0x11c4 (0x11ca mov.w); 0x11cc increments it as u16 when the WDT overflow bit is set; 0x16b20 tests the whole byte; 0x169d4 writes 1 while ROM[0x6e224] == 0xff (0x00 in this ROM). Dual-labeled with the SBL counter (ROADMAP D14).
 */
/* ROM address: 0x000011c4; body bytes: 8; decompiled */

void candidate_immo_diag_bit_clear(void)

{
  immo_diag_bit_ffffdfa0._0_2_ = 0;
  return;
}


/* [CROSS-ECU / RX8DEFS REVIEW]
 * service_wdt_overflow_toggle_pb15_and_count [behavior_verified_role_candidate]: Same PB15 toggle with a saturating event counter. Existing name checkWatchdogForOverflowandReset overstates reset behavior: the visible action is servicing/toggling, not issuing a reset.
 */
/* ROM address: 0x000011cc; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000011cc (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

int service_wdt_overflow_toggle_pb15_and_count(void)

{
  byte bVar1;
  ushort uVar2;
  
  bVar1 = WDT_TCSR_RW__B;
  if ((bVar1 & 0x80) != 0) {
    Ramffffec10 = 0xa53c;
    uVar2 = PBDR_W;
    PBDR_W = uVar2 ^ 0x8000;
    if (immo_diag_bit_ffffdfa0._0_2_ != -1) {
      immo_diag_bit_ffffdfa0._0_2_ = immo_diag_bit_ffffdfa0._0_2_ + 1;
    }
  }
  return (int)immo_diag_bit_ffffdfa0._0_2_;
}


/* ROM address: 0x000011fa; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000011fa (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000011fa(undefined1 *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  short sVar3;
  byte bVar4;
  char local_18;
  undefined1 uStack_17;
  undefined1 local_16 [10];
  
  bVar4 = 2;
  sVar3 = *(short *)(param_1 + 2);
  local_18 = (char)sVar3 + '\x01';
  puVar1 = local_16;
  uStack_17 = *param_1;
  param_1 = param_1 + 4;
  puVar2 = puVar1;
  do {
    bVar4 = bVar4 + 1;
    if (sVar3 == 0) {
      *puVar2 = 0;
    }
    else {
      *puVar1 = *param_1;
      sVar3 = sVar3 + -1;
    }
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
    puVar1 = puVar1 + 1;
  } while (bVar4 < 8);
  FUN_00001150(&local_18);
  FUN_00001182();
  return;
}


/* ROM address: 0x0000125c; body bytes: 22; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000125c (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_0000125c(void)

{
  int iVar1;
  
  iVar1 = FUN_000010fe(0xffffdfa2);
  return iVar1 == 1;
}


/* ROM address: 0x00001272; body bytes: 6; decompiled */

undefined4 FUN_00001272(void)

{
  return 0xffffdfa2;
}


/* ROM address: 0x000012a2; body bytes: 166; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000012a2 (166 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000012a2(void)

{
  PADR_W = 0xffff;
  PACRH_W = 0;
  PACRL_W = 0;
  PAIOR_W = 0;
  PBDR_W = 0xefff;
  PBCRH_W = 0;
  PBCRL_W = 0;
  PBIR_W = 0;
  PBIOR_W = 0x9000;
  PCDR_W = 0x1f;
  PCCR_W = 0;
  PCIOR_W = 0;
  PDDR_W = 0x3eff;
  PDCRH_W = 0;
  PDCRL_W = 0;
  PDIOR_W = 0x2000;
  PEDR_W = 0xffff;
  PECR_W = 0;
  PEIOR_W = 0;
  PFDR_W = 0xffff;
  PFCRH_W = 0x8000;
  PFCRL_W = 0;
  PFIOR_W = 0;
  PGDR_W = 0xf;
  PGCR_W = 0;
  PGIOR_W = 0;
  PHDR_W = 0xffff;
  PHCR_W = 0;
  PHIOR_W = 0;
  PJDR_W = 0xffff;
  PJCRH_W = 0;
  PJCRL_W = 0;
  PJIOR_W = 0;
  PKDR_W = 0xffff;
  PKCRH_W = 0;
  PKCRL_W = 0;
  PKIR_W = 0;
  PKIOR_W = 0;
  PLDR_W = 0x3fff;
  PLCRH_W = 0x50;
  PLCRL_W = 0;
  PLIR_W = 0;
  PLIOR_W = 0;
  return;
}


/* ROM address: 0x00001364; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001364 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_resetWatchdog_00001364(void)

{
  WDT_RSTCSR_W__B = 0x5a1f;
  Ramffffec10 = 0x5a00;
  Ramffffec10 = 0xa53c;
  return;
}


/* ROM address: 0x00001378; body bytes: 422; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001378 (156 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001378(void)

{
  byte bVar1;
  bool bVar2;
  char cVar6;
  byte *pbVar3;
  int iVar4;
  ushort uVar5;
  char unaff_r10;
  
  candidate_immo_diag_bit_clear();
  bVar2 = false;
  do {
    cVar6 = FUN_0000125c();
    if (cVar6 != '\0') {
      pbVar3 = (byte *)FUN_00001272();
      bVar1 = *pbVar3 >> 4;
      unaff_r10 = '\0';
      if (bVar1 == 0) {
        iVar4 = FUN_0000154c();
        if (iVar4 == 0) {
          unaff_r10 = '\x01';
          bVar2 = false;
          candidate_immo_diag_bit_clear();
        }
      }
      else if (bVar1 == 1) {
        iVar4 = FUN_000015a6();
        if (iVar4 == 0) {
          bVar2 = true;
          FUN_00001624();
          candidate_immo_diag_bit_clear();
        }
      }
      else if ((bVar1 == 2) && (bVar2)) {
        iVar4 = FUN_00001654();
        if (iVar4 == 0) {
          bVar2 = false;
          unaff_r10 = '\x01';
        }
        else if (iVar4 != -2) {
          if (iVar4 == -1) {
            bVar2 = false;
          }
          goto LAB_00001414;
        }
        candidate_immo_diag_bit_clear();
      }
    }
LAB_00001414:
    uVar5 = service_wdt_overflow_toggle_pb15_and_count();
    if (bVar2) {
      if (0x2d < uVar5) {
        bVar2 = false;
        candidate_immo_diag_bit_clear();
      }
    }
    else if (0x5f5 < uVar5) {
      ref_handleException_(0);
    }
    if (unaff_r10 == '\x01') {
      if (DAT_ffffd3f0 == '(') {
        FUN_0000170a(&DAT_ffffd3f0);
      }
      else if (DAT_ffffd3f0 == -0x7b) {
        FUN_00001774(&DAT_ffffd3f0);
      }
      else if (DAT_ffffd3f0 == '\x10') {
        FUN_000017f0(&DAT_ffffd3f0);
      }
      else if (DAT_ffffd3f0 == '\'') {
        FUN_00001858(&DAT_ffffd3f0);
      }
      else if (DAT_ffffd3f0 == '>') {
        FUN_0000197a(&DAT_ffffd3f0);
      }
      else if (DAT_ffffd3f0 == '\x11') {
        FUN_000019ce(&DAT_ffffd3f0);
      }
      else if (DAT_ffffd3f0 == '\"') {
        FUN_00001a50(&DAT_ffffd3f0);
      }
      else if (DAT_ffffd3f0 == ';') {
        FUN_00001ac0(&DAT_ffffd3f0);
      }
      else if (DAT_ffffd3f0 == '4') {
        FUN_00001ad6(&DAT_ffffd3f0);
      }
      else if (DAT_ffffd3f0 == '6') {
        FUN_00001c04(&DAT_ffffd3f0);
      }
      else if (DAT_ffffd3f0 == '7') {
        FUN_00001d30(&DAT_ffffd3f0);
      }
      else if (DAT_ffffd3f0 == -0x4f) {
        FUN_00001d78(&DAT_ffffd3f0);
      }
      else {
        FUN_00001e34(&DAT_ffffd3f0);
      }
      candidate_immo_diag_bit_clear();
      unaff_r10 = '\0';
    }
  } while( true );
}


/* ROM address: 0x0000154c; body bytes: 90; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 0000154c (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000154c(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  ushort uVar3;
  byte bVar4;
  byte *pbVar5;
  
  uVar3 = *param_1 & 0xf;
  if (((*param_1 & 0xf) == 0) || (7 < uVar3)) {
    uVar2 = 0xffffffff;
  }
  else {
    bVar4 = 2;
    DAT_ffffd3f2 = uVar3 - 1;
    pbVar5 = param_1 + 2;
    DAT_ffffd3f0 = param_1[1];
    _DAT_ffffdfac = 0;
    do {
      bVar4 = bVar4 + 1;
      bVar1 = *pbVar5;
      pbVar5 = pbVar5 + 1;
      (&DAT_ffffd3f4)[_DAT_ffffdfac] = bVar1;
      _DAT_ffffdfac = _DAT_ffffdfac + 1;
    } while (bVar4 < 8);
    uVar2 = 0;
  }
  return uVar2;
}


/* ROM address: 0x000015a6; body bytes: 98; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 000015a6 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000015a6(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  ushort uVar3;
  byte bVar4;
  
  uVar3 = (*param_1 & 0xf) * 0x100 + (ushort)param_1[1];
  if (uVar3 < 8) {
    uVar2 = 0xffffffff;
  }
  else {
    bVar4 = 3;
    DAT_ffffd3f2 = uVar3 - 1;
    DAT_ffffd3f0 = param_1[2];
    _DAT_ffffdfac = 0;
    param_1 = param_1 + 3;
    do {
      bVar4 = bVar4 + 1;
      bVar1 = *param_1;
      param_1 = param_1 + 1;
      (&DAT_ffffd3f4)[_DAT_ffffdfac] = bVar1;
      _DAT_ffffdfac = _DAT_ffffdfac + 1;
    } while (bVar4 < 8);
    _DAT_ffffdfae = 0;
    uVar2 = 0;
  }
  return uVar2;
}


/* ROM address: 0x00001624; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001624 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001624(void)

{
  undefined1 *puVar1;
  byte bVar2;
  undefined1 local_10;
  undefined1 local_f [11];
  
  bVar2 = 1;
  puVar1 = &local_10;
  local_10 = 0x30;
  do {
    puVar1 = puVar1 + 1;
    bVar2 = bVar2 + 1;
    *puVar1 = 0;
  } while (bVar2 < 8);
  FUN_00001150(&local_10);
  return;
}


/* ROM address: 0x00001654; body bytes: 116; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00001654 (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00001654(byte *param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  _DAT_ffffdfae = _DAT_ffffdfae + 1;
  if ((_DAT_ffffdfae & 0xf) == (*param_1 & 0xf)) {
    bVar2 = 1;
    for (; (bVar2 < 8 && (_DAT_ffffdfac < DAT_ffffd3f2)); _DAT_ffffdfac = _DAT_ffffdfac + 1) {
      if (_DAT_ffffdfac < 0x400) {
        (&DAT_ffffd3f4)[_DAT_ffffdfac] = param_1[bVar2];
      }
      bVar2 = bVar2 + 1;
    }
    if (_DAT_ffffdfac < DAT_ffffd3f2) {
      uVar1 = 0xfffffffe;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


/* ROM address: 0x000016dc; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000016dc (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * ref_handleException_(undefined1 *param_1)

{
  DAT_ffffdfb3 = param_1 == (undefined1 *)((int)&vector_Poweron_Reset + 1);
  DAT_ffffdfb2 = 0;
  DAT_ffffdfb4._0_1_ = 0;
  DAT_ffffdfb4._1_1_ = 0;
  if (DAT_ffffdfb3) {
    param_1 = &DAT_ffffdfb1;
  }
  DAT_ffffdfb1 = DAT_ffffdfb3;
  DAT_ffffdfb0 = DAT_ffffdfb3;
  return param_1;
}


/* ROM address: 0x0000170a; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000170a (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000170a(int param_1)

{
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x28;
  DAT_ffffdfc8 = 2;
  if (DAT_ffffdfb0 == '\x01') {
    DAT_ffffdfcb = 0x22;
  }
  else if ((*(short *)(param_1 + 2) == 3) && (*(char *)(param_1 + 4) == '\x01')) {
    if (*(char *)(param_1 + 6) == '\x01') {
      if ((*(char *)(param_1 + 5) == '\0') || (*(char *)(param_1 + 5) == '\x01')) {
        DAT_ffffdfc6 = 0x68;
        DAT_ffffdfc8 = 0;
      }
      else {
        DAT_ffffdfcb = 0x31;
      }
    }
    else {
      DAT_ffffdfcb = 0x31;
    }
  }
  else {
    DAT_ffffdfcb = 0x12;
  }
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}


/* ROM address: 0x00001774; body bytes: 88; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001774 (88 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001774(int param_1)

{
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x85;
  DAT_ffffdfc8 = 2;
  if (DAT_ffffdfb0 == '\x01') {
    DAT_ffffdfcb = 0x22;
  }
  else if (*(short *)(param_1 + 2) == 1) {
    if ((*(char *)(param_1 + 4) == '\x01') || (*(char *)(param_1 + 4) == '\x02')) {
      DAT_ffffdfc6 = 0xc5;
      DAT_ffffdfca = *(undefined1 *)(param_1 + 4);
      DAT_ffffdfc8 = 1;
    }
    else {
      DAT_ffffdfcb = 0x12;
    }
  }
  else {
    DAT_ffffdfcb = 0x12;
  }
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}


/* ROM address: 0x000017f0; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000017f0 (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000017f0(int param_1)

{
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x10;
  DAT_ffffdfc8 = 2;
  if (*(short *)(param_1 + 2) == 1) {
    if (*(char *)(param_1 + 4) == -0x7f) {
      ref_handleException_(0);
      DAT_ffffdfca = 0x81;
    }
    else {
      if (*(char *)(param_1 + 4) != -0x7b) {
        DAT_ffffdfcb = 0x12;
        goto LAB_0000184c;
      }
      DAT_ffffdfca = 0x85;
      DAT_ffffdfb0 = 1;
    }
    DAT_ffffdfc6 = 0x50;
    DAT_ffffdfc8 = 1;
  }
  else {
    DAT_ffffdfcb = 0x12;
  }
LAB_0000184c:
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}


/* ROM address: 0x00001858; body bytes: 266; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000018aa) */

void FUN_00001858(int param_1)

{
  byte bVar1;
  short sVar2;
  
  sVar2 = *(short *)(param_1 + 2);
  bVar1 = *(byte *)(param_1 + 4);
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x27;
  DAT_ffffdfc8 = 2;
  if (DAT_ffffdfb0 == '\0') {
    DAT_ffffdfcb = 0x22;
    goto LAB_0000196a;
  }
  if ((sVar2 != 0) && (bVar1 != 0)) {
    if ((bVar1 & 1) == 1) {
      if (sVar2 == 1) {
        DAT_ffffdfb2 = '\0';
        if (bVar1 == 1) {
          DAT_ffffdfc6 = 0x67;
          DAT_ffffdfca = 1;
          DAT_ffffdfc8 = 4;
          if (DAT_ffffdfb1 == '\x01') {
            DAT_ffffdfcb = 0;
            DAT_ffffdfcc = 0;
            DAT_ffffdfcd = 0;
          }
          else {
            DAT_ffffdfcb = 0x55;
            DAT_ffffdfcc = 0xaa;
            DAT_ffffdfcd = 0x55;
            DAT_ffffdfb2 = '\x01';
          }
        }
        else {
          DAT_ffffdfcb = 0x31;
        }
        goto LAB_0000196a;
      }
    }
    else if (sVar2 == 4) {
      if ((DAT_ffffdfb2 == '\0') || (bVar1 != 2)) {
        DAT_ffffdfcb = 0x22;
      }
      else if (((*(char *)(param_1 + 5) == 'M') && (*(char *)(param_1 + 6) == -0x54)) &&
              (*(char *)(param_1 + 7) == -0x33)) {
        DAT_ffffdfb1 = '\x01';
        DAT_ffffdfc6 = 0x67;
        DAT_ffffdfca = 2;
        DAT_ffffdfc8 = 1;
      }
      else {
        DAT_ffffdfcb = 0x35;
      }
      DAT_ffffdfb2 = '\0';
      goto LAB_0000196a;
    }
  }
  DAT_ffffdfcb = 0x12;
LAB_0000196a:
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}


/* ROM address: 0x0000197a; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000197a (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000197a(int param_1)

{
  undefined4 uVar1;
  
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x3e;
  DAT_ffffdfcb = 0x12;
  DAT_ffffdfc8 = 0xff;
  if (*(short *)(param_1 + 2) == 1) {
    if (*(char *)(param_1 + 4) == '\x01') {
      DAT_ffffdfc6 = 0x7e;
      DAT_ffffdfc8 = 0;
    }
    else if (*(char *)(param_1 + 4) != '\x02') {
      DAT_ffffdfc8 = 2;
    }
  }
  else {
    DAT_ffffdfc8 = 2;
  }
  if (DAT_ffffdfc8 == 0xff) {
    return 0xff;
  }
  uVar1 = FUN_000011fa(&DAT_ffffdfc6);
  return uVar1;
}


/* ROM address: 0x000019ce; body bytes: 106; decompiled_with_warnings */

void FUN_000019ce(int param_1)

{
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x11;
  DAT_ffffdfc8 = 2;
  if (DAT_ffffdfb0 == '\0') {
    DAT_ffffdfcb = 0x22;
  }
  else if (DAT_ffffdfb1 == '\0') {
    DAT_ffffdfcb = 0x33;
  }
  else {
    if ((*(short *)(param_1 + 2) == 1) && (*(char *)(param_1 + 4) == '\x01')) {
      DAT_ffffdfc6 = 0x51;
      DAT_ffffdfc8 = 0;
      FUN_000011fa(&DAT_ffffdfc6);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    DAT_ffffdfcb = 0x12;
  }
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}


/* ROM address: 0x00001a50; body bytes: 112; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001a50 (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001a50(int param_1)

{
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x22;
  DAT_ffffdfc8 = 2;
  if (*(short *)(param_1 + 2) == 2) {
    if ((*(char *)(param_1 + 4) == -0x2f) && (*(char *)(param_1 + 5) == '\0')) {
      DAT_ffffdfc6 = 0x62;
      DAT_ffffdfca = 0xd1;
      DAT_ffffdfcb = 0;
      DAT_ffffdfc8 = 3;
      if (DAT_ffffdfb0 == '\x01') {
        DAT_ffffdfcc = 0x85;
      }
      else {
        DAT_ffffdfcc = 0x81;
      }
    }
    else {
      DAT_ffffdfcb = 0x31;
    }
  }
  else {
    DAT_ffffdfcb = 0x12;
  }
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}


/* ROM address: 0x00001ac0; body bytes: 22; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001ac0 (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001ac0(void)

{
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x3b;
  DAT_ffffdfcb = 0x22;
  DAT_ffffdfc8 = 2;
  FUN_000011fa();
  return;
}


/* ROM address: 0x00001ad6; body bytes: 230; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00001ad6(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x34;
  DAT_ffffdfc8 = 2;
  if (DAT_ffffdfb0 == '\0') {
    DAT_ffffdfcb = 0x22;
  }
  else if (DAT_ffffdfb1 == '\0') {
    DAT_ffffdfcb = 0x33;
  }
  else if (*(short *)(param_1 + 2) == 8) {
    if (DAT_ffffdfb3 == '\0') {
      DAT_ffffdfcb = 0x10;
    }
    else if (*(char *)(param_1 + 8) == '\0') {
      _DAT_ffffdfb8 = FUN_00001e4c(param_1 + 4);
      _DAT_ffffdfb8 = (int)&DAT_ffff6000 + _DAT_ffffdfb8;
      iVar1 = FUN_00001e72(param_1 + 9);
      DAT_ffffdfbc = iVar1 - 0x7e000;
      DAT_ffffdfc0 = _DAT_ffffdfb8;
      if ((0 < (int)DAT_ffffdfbc) && ((uint)(_DAT_ffffdfb8 + iVar1 + -0x7e001) < param_1)) {
        if ((int)DAT_ffffdfbc < 0) {
          uVar2 = ~(~DAT_ffffdfbc + 1 & 0x3ff) + 1;
        }
        else {
          uVar2 = DAT_ffffdfbc & 0x3ff;
        }
        if (uVar2 == 0) {
          DAT_ffffdfb3 = '\0';
          DAT_ffffdfb4._0_1_ = 1;
          DAT_ffffdfc6 = 0x74;
          DAT_ffffdfca = 4;
          DAT_ffffdfcb = 1;
          DAT_ffffdfc8 = 2;
          DAT_ffffdfc4 = 0;
          DAT_ffffdfc5 = 1;
          goto LAB_00001bc4;
        }
      }
      DAT_ffffdfcb = 0x31;
    }
    else {
      DAT_ffffdfcb = 0x31;
    }
  }
  else {
    DAT_ffffdfcb = 0x12;
  }
LAB_00001bc4:
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}


/* ROM address: 0x00001c04; body bytes: 256; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00001c04 (256 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001c04(int param_1)

{
  ushort uVar1;
  char *local_24;
  
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x36;
  DAT_ffffdfc8 = 2;
  if ((DAT_ffffdfb0 == '\0') || (DAT_ffffdfb4._0_1_ == '\0')) {
    DAT_ffffdfcb = 0x22;
  }
  else if (*(short *)(param_1 + 2) == 0x400) {
    uVar1 = 0;
    local_24 = (char *)(param_1 + 4);
    do {
      *DAT_ffffdfc0 = *local_24;
      if (*DAT_ffffdfc0 == (&DAT_00001ff4)[DAT_ffffdfc5]) {
        DAT_ffffdfc5 = DAT_ffffdfc5 + 1;
        if (DAT_ffffdfc5 == 8) {
          DAT_ffffdfc4 = '\x01';
        }
      }
      else {
        DAT_ffffdfc5 = 1;
      }
      uVar1 = uVar1 + 1;
      DAT_ffffdfc0 = DAT_ffffdfc0 + 1;
      local_24 = local_24 + 1;
    } while (uVar1 < 0x400);
    DAT_ffffdfbc = DAT_ffffdfbc + -0x400;
    if (DAT_ffffdfbc < 1) {
      if (DAT_ffffdfc4 == '\0') {
        DAT_ffffdfcb = 0x72;
        DAT_ffffdfb4._0_1_ = '\0';
      }
      else {
        DAT_ffffdfcb = 0x78;
        FUN_000011fa(&DAT_ffffdfc6);
        FUN_00001090(_DAT_ffffdfb8);
      }
    }
    else if (DAT_ffffdfc4 == '\x01') {
      DAT_ffffdfb4._0_1_ = '\0';
      DAT_ffffdfcb = 0x72;
    }
    else {
      DAT_ffffdfc6 = 0x76;
      DAT_ffffdfc8 = 0;
    }
  }
  else {
    DAT_ffffdfb4._0_1_ = '\0';
    DAT_ffffdfcb = 0x72;
  }
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}


/* ROM address: 0x00001d30; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001d30 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001d30(int param_1)

{
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x37;
  DAT_ffffdfc8 = 2;
  if ((DAT_ffffdfb0 == '\0') || (DAT_ffffdfb4._0_1_ == '\0')) {
    DAT_ffffdfcb = 0x22;
  }
  else if (*(short *)(param_1 + 2) == 0) {
    DAT_ffffdfb4._0_1_ = '\0';
    DAT_ffffdfb4._1_1_ = 0;
    DAT_ffffdfcb = 0x79;
  }
  else {
    DAT_ffffdfcb = 0x12;
  }
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}


/* ROM address: 0x00001d78; body bytes: 152; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001d78 (152 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001d78(int param_1)

{
  ushort uVar1;
  
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0xb1;
  DAT_ffffdfc8 = 2;
  if (DAT_ffffdfb0 == '\0') {
    DAT_ffffdfcb = 0x22;
  }
  else if (DAT_ffffdfb1 == '\0') {
    DAT_ffffdfcb = 0x33;
  }
  else if (*(short *)(param_1 + 2) == 3) {
    if (((*(char *)(param_1 + 4) == '\0') && (*(char *)(param_1 + 5) == -0x4e)) &&
       (*(char *)(param_1 + 6) == '\0')) {
      uVar1 = FUN_00001008();
      if (uVar1 < 100) {
        DAT_ffffdfb4._0_1_ = 0;
        DAT_ffffdfb3 = 1;
        DAT_ffffdfc6 = 0xf1;
        DAT_ffffdfca = 0;
        DAT_ffffdfcb = 0xb2;
        DAT_ffffdfc8 = 2;
      }
      else {
        DAT_ffffdfcb = 0x10;
      }
    }
    else {
      DAT_ffffdfcb = 0x31;
    }
  }
  else {
    DAT_ffffdfcb = 0x12;
  }
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}


/* ROM address: 0x00001e34; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001e34 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00001e34(undefined1 *param_1)

{
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = *param_1;
  DAT_ffffdfcb = 0x11;
  DAT_ffffdfc8 = 2;
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}


/* ROM address: 0x00001e4c; body bytes: 38; decompiled */

int FUN_00001e4c(byte *param_1)

{
  return (uint)param_1[1] * 0x10000 + (uint)param_1[2] * 0x100 + (uint)*param_1 * 0x1000000 +
         (uint)param_1[3];
}


/* ROM address: 0x00001e72; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001e72 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00001e72(byte *param_1)

{
  return (uint)param_1[1] * 0x100 + (uint)*param_1 * 0x10000 + (uint)param_1[2];
}


/* ROM address: 0x00001e94; body bytes: 30; decompiled */

uint FUN_00001e94(char *param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (int)*param_1 | 1;
  *param_1 = (char)uVar1;
  iVar2 = 4000;
  do {
    if ((*param_2 & 8) != 0) {
      return uVar1;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return uVar1;
}


/* ROM address: 0x00001eb2; body bytes: 30; decompiled */

byte FUN_00001eb2(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *param_1 & 0xfe;
  *param_1 = bVar1;
  iVar2 = 4000;
  do {
    if ((*param_2 & 8) == 0) {
      return bVar1;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return bVar1;
}


/* ROM address: 0x00001ed0; body bytes: 210; decompiled */

void FUN_00001ed0(uint param_1,ushort param_2,undefined1 param_3,char param_4,uint param_5,
                 byte param_6,ushort *param_7,ushort *param_8,undefined1 *param_9,
                 undefined1 *param_10)

{
  ushort uVar2;
  int iVar1;
  uint uVar4;
  short sVar3;
  
  sVar3 = 1;
  uVar2 = 1;
  for (uVar4 = (param_1 & 0xff) + 8 & 0xf; uVar4 != 0; uVar4 = uVar4 - 1) {
    sVar3 = sVar3 << 1;
    uVar2 = uVar2 << 1;
  }
  *param_7 = ~uVar2 & *param_7 | (param_2 & 0xff) * sVar3;
  *param_8 = *param_8 & ~uVar2 | param_6 * uVar2;
  *param_10 = param_3;
  if (param_4 == '\0') {
    param_10[4] = (char)param_5 * ' ';
    param_10[5] = (char)(param_5 >> 3);
  }
  else {
    param_10[4] = ((byte)(param_5 >> 0x10) & 3) + (char)(param_5 >> 0x12) * ' ' + param_4 * '\b';
    param_10[5] = (char)(param_5 >> 0x15);
    param_10[6] = (char)param_5;
    param_10[7] = (char)(param_5 >> 8);
  }
  iVar1 = 8;
  do {
    iVar1 = iVar1 + -1;
    *param_9 = 0;
    param_9 = param_9 + 1;
  } while (iVar1 != 0);
  return;
}


/* ROM address: 0x00001fa2; body bytes: 26; decompiled */

byte FUN_00001fa2(byte param_1,byte param_2,undefined1 *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  
  for (; param_2 < param_1; param_2 = param_2 + 1) {
    uVar1 = *param_4;
    param_4 = param_4 + 1;
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  return param_1;
}


/* ROM address: 0x00001fbc; body bytes: 36; decompiled */

uint FUN_00001fbc(byte param_1,uint param_2,char *param_3,char *param_4)

{
  char cVar1;
  
  for (; (param_2 & 0xff) < (uint)param_1; param_2 = param_2 + 1) {
    cVar1 = *param_3;
    do {
      *param_4 = cVar1;
    } while (*param_4 != cVar1);
    param_4 = param_4 + 1;
    param_3 = param_3 + 1;
  }
  return param_2;
}


/* ROM address: 0x00001fe2; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00001fe2 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

byte FUN_00001fe2(uint param_1)

{
  return (&HCAN0_MC0_1__B)[(param_1 & 0xf) * 8] & 0xf;
}


/* ROM address: 0x00002034; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002034 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00002034(uint *param_1)

{
  return ~*param_1 - (*param_1 >> 0x10) & 0xffff;
}


/* ROM address: 0x00002044; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002044 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_invertAndReturn_8bit_ADDR(short *param_1)

{
  return ~(int)*param_1 - ((uint)(int)*param_1 >> 8) & 0xff;
}


/* ROM address: 0x00002054; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002054 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_setSR_PARAM(uint *param_1)

{
  uint in_sr;
  
  *param_1 = in_sr & 0xf0;
  return;
}


/* ROM address: 0x00002064; body bytes: 4; decompiled */

void FUN_00002064(void)

{
  return;
}


/* [CROSS-ECU / RX8DEFS REVIEW]
 * lookup_2d_descriptor_scaled [layout_correlated]: Descriptor access matches ScoobyRom Denso layout: type byte +2, optional scale +12 and offset +16; this ROM uses indirect interpolation dispatch. Raw signature/register-derived temporaries remain unresolved. Layout compatibility does not transfer Subaru table names or units.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002068; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002068 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * Dispatch pointers verified directly at 0x2098/0x210c. Type values are byte offsets 0,4,8,12,16. Unknown dispatch values remain an unresolved operation, not an invented error/default value.
 * Explicit register-result structs are an analysis representation.
 */
float lookup_2d_descriptor_scaled(float axis_value, const Rx8Table2D *table)
{
  Rx8AxisPosition position = rx8_find_axis_index_fraction(table->axis_count, RX8_ROM_PTR(float, table->axis_address), axis_value);
  float interpolated;
  switch (table->type_code) {
    case 0: interpolated = rx8_interpolate_1d_f32(position.index, RX8_ROM_PTR(float, table->data_address), position.fraction); break;
    case 4: interpolated = rx8_interpolate_1d_u8(position.index, RX8_ROM_PTR(uint8_t, table->data_address), position.fraction); break;
    case 8: interpolated = rx8_interpolate_1d_u16(position.index, RX8_ROM_PTR(uint16_t, table->data_address), position.fraction); break;
    case 12: interpolated = rx8_interpolate_1d_s8(position.index, RX8_ROM_PTR(int8_t, table->data_address), position.fraction); break;
    case 16: interpolated = rx8_interpolate_1d_s16(position.index, RX8_ROM_PTR(int16_t, table->data_address), position.fraction); break;
    default: return rx8_unresolved_table_dispatch_2d(table->type_code);
  }
  if (table->type_code == 0) return interpolated;
  return rx8_sh_fmac_model(table->multiplier, interpolated, table->offset);
}


/* ROM address: 0x000020ac; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000020ac (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * Wrapper uses FTRC then EXTU.B/W. Exceptional conversion left to explicitly unresolved SH operation; no C undefined float-to-int replacement.
 * Explicit register-result structs are an analysis representation.
 */
uint32_t rx8_lookup_2d_raw_u8(float axis_value, const Rx8Table2D *table)
{
  Rx8AxisPosition position = rx8_find_axis_index_fraction(table->axis_count, RX8_ROM_PTR(float, table->axis_address), axis_value);
  float interpolated = rx8_interpolate_1d_u8(position.index, RX8_ROM_PTR(uint8_t, table->data_address), position.fraction);
  return (uint8_t)rx8_sh_ftrc_model(interpolated);
}


/* ROM address: 0x000020c4; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000020c4 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * Wrapper uses FTRC then EXTU.B/W. Exceptional conversion left to explicitly unresolved SH operation; no C undefined float-to-int replacement.
 * Explicit register-result structs are an analysis representation.
 */
uint32_t rx8_lookup_2d_raw_u16(float axis_value, const Rx8Table2D *table)
{
  Rx8AxisPosition position = rx8_find_axis_index_fraction(table->axis_count, RX8_ROM_PTR(float, table->axis_address), axis_value);
  float interpolated = rx8_interpolate_1d_u16(position.index, RX8_ROM_PTR(uint16_t, table->data_address), position.fraction);
  return (uint16_t)rx8_sh_ftrc_model(interpolated);
}


/* [CROSS-ECU / RX8DEFS REVIEW]
 * lookup_3d_descriptor_scaled [layout_correlated]: Descriptor access matches ScoobyRom Denso layout: type byte +16, optional scale +20 and offset +24. This is structural evidence, not proof of calibration meaning or complete ABI recovery.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000020dc; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000020dc (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * Dispatch pointers verified directly at 0x2098/0x210c. Type values are byte offsets 0,4,8,12,16. Unknown dispatch values remain an unresolved operation, not an invented error/default value.
 * Explicit register-result structs are an analysis representation.
 */
float lookup_3d_descriptor_scaled(float x_value, float y_value, const Rx8Table3D *table)
{
  Rx8MapPosition position = rx8_find_xy_axis_positions(x_value, y_value, table);
  float interpolated;
  switch (table->type_code) {
    case 0: interpolated = rx8_interpolate_2axis_f32(table->x_count, RX8_ROM_PTR(float, table->data_address), position); break;
    case 4: interpolated = rx8_interpolate_2axis_u8(table->x_count, RX8_ROM_PTR(uint8_t, table->data_address), position); break;
    case 8: interpolated = rx8_interpolate_2axis_u16(table->x_count, RX8_ROM_PTR(uint16_t, table->data_address), position); break;
    case 12: interpolated = rx8_interpolate_2axis_s8(table->x_count, RX8_ROM_PTR(int8_t, table->data_address), position); break;
    case 16: interpolated = rx8_interpolate_2axis_s16(table->x_count, RX8_ROM_PTR(int16_t, table->data_address), position); break;
    default: return rx8_unresolved_table_dispatch_3d(table->type_code);
  }
  if (table->type_code == 0) return interpolated;
  return rx8_sh_fmac_model(table->multiplier, interpolated, table->offset);
}


/* ROM address: 0x00002120; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002120 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * Wrapper uses FTRC then EXTU.B/W. Exceptional conversion left to explicitly unresolved SH operation; no C undefined float-to-int replacement.
 * Explicit register-result structs are an analysis representation.
 */
uint32_t rx8_lookup_3d_raw_u8(float x_value, float y_value, const Rx8Table3D *table)
{
  Rx8MapPosition position = rx8_find_xy_axis_positions(x_value, y_value, table);
  float interpolated = rx8_interpolate_2axis_u8(table->x_count, RX8_ROM_PTR(uint8_t, table->data_address), position);
  return (uint8_t)rx8_sh_ftrc_model(interpolated);
}


/* ROM address: 0x0000213c; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000213c (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * Wrapper uses FTRC then EXTU.B/W. Exceptional conversion left to explicitly unresolved SH operation; no C undefined float-to-int replacement.
 * Explicit register-result structs are an analysis representation.
 */
uint32_t rx8_lookup_3d_raw_u16(float x_value, float y_value, const Rx8Table3D *table)
{
  Rx8MapPosition position = rx8_find_xy_axis_positions(x_value, y_value, table);
  float interpolated = rx8_interpolate_2axis_u16(table->x_count, RX8_ROM_PTR(uint16_t, table->data_address), position);
  return (uint16_t)rx8_sh_ftrc_model(interpolated);
}


/* ROM address: 0x00002158; body bytes: 420; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002158 (420 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined8 ref_LongFunc(uint param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  int in_r1;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar12;
  uint uVar13;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  uint uVar11;
  uint uVar14;
  
  iVar7 = 0;
  if (param_1 != 0) {
    if (param_2 == 0) {
      iVar7 = ((param_1 & 0x80000000) != 0) + 0x7fffffff;
      in_r1 = 0x7fffffff;
    }
    else if (((param_1 & 0x7fffffff) != 0) || (in_r1 = -1, iVar7 = 0x7fffffff, param_2 != -1)) {
      uVar8 = -(uint)((param_1 & 0x80000000) != 0);
      uVar15 = param_1 - ((uVar8 & 0x80000000) != 0);
      uVar8 = uVar8 - (param_1 < uVar15);
      bVar1 = param_2 < 0;
      uVar2 = (uint)bVar1 << 9;
      uVar13 = uVar15 * 2;
      uVar15 = uVar8 * 2 | (uint)((uVar15 & 0x80000000) != 0);
      bVar4 = (int)uVar8 < 0 == bVar1;
      bVar5 = bVar1 == ((uVar8 & 0x80000000) != 0);
      uVar9 = (uint)bVar4 * (uVar15 - param_2) + (uint)!bVar4 * (uVar15 + param_2);
      cVar3 = bVar4 * (uVar15 < uVar9) + !bVar4 * (uVar9 < uVar15);
      uVar15 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar14 = uVar2 | uVar15;
      uVar10 = uVar9 * 2 | (uint)((uVar13 & 0x80000000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar10 - param_2) + (uint)!bVar4 * (uVar10 + param_2);
      cVar3 = bVar4 * (uVar10 < uVar11) + !bVar4 * (uVar11 < uVar10);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar17 = uVar2 | uVar15 & 0xfffffeff | uVar14;
      uVar10 = uVar2 | uVar15 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x40000000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar18 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x20000000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar19 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x10000000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar20 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x8000000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar21 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x4000000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar22 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x2000000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar23 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x1000000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar24 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x800000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar25 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x400000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar26 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x200000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar27 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x100000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar28 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x80000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar29 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x40000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar30 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x20000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar31 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x10000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar32 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x8000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar33 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x4000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar34 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x2000) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar35 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x1000) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar36 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x800) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar37 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x400) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar38 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x200) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar39 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x100) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar40 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x80) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar41 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x40) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar42 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x20) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar43 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x10) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar44 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 8) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar45 = uVar10 | uVar9 & 0xfffffeff | uVar14;
      uVar10 = uVar10 | uVar9 & 0xfffffefe;
      uVar9 = uVar10 | uVar14;
      uVar12 = uVar11 * 2 | (uint)((uVar13 & 4) != 0);
      bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
      cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
      uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      uVar12 = uVar10 | uVar14 & 0xfffffeff | uVar9;
      uVar10 = uVar10 | uVar14 & 0xfffffefe;
      uVar14 = uVar10 | uVar9;
      uVar13 = uVar11 * 2 | (uint)((uVar13 & 2) != 0);
      bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
      bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
      uVar14 = (uint)bVar4 * (uVar13 - param_2) + (uint)!bVar4 * (uVar13 + param_2);
      cVar3 = bVar4 * (uVar13 < uVar14) + !bVar4 * (uVar14 < uVar13);
      uVar14 = uVar10 | uVar9 & 0xfffffeff |
               (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
      iVar16 = ((((((((((((((((((((((((((((((((uint)(((byte)((uVar2 | uVar15) >> 8) & 1) ==
                                                    ((byte)((uVar2 | uVar15) >> 9) & 1)) << 1 |
                                             (uint)(((byte)(uVar17 >> 8) & 1) ==
                                                   ((byte)(uVar17 >> 9) & 1))) << 1 |
                                            (uint)(((byte)(uVar18 >> 8) & 1) ==
                                                  ((byte)(uVar18 >> 9) & 1))) << 1 |
                                           (uint)(((byte)(uVar19 >> 8) & 1) ==
                                                 ((byte)(uVar19 >> 9) & 1))) << 1 |
                                          (uint)(((byte)(uVar20 >> 8) & 1) ==
                                                ((byte)(uVar20 >> 9) & 1))) << 1 |
                                         (uint)(((byte)(uVar21 >> 8) & 1) ==
                                               ((byte)(uVar21 >> 9) & 1))) << 1 |
                                        (uint)(((byte)(uVar22 >> 8) & 1) ==
                                              ((byte)(uVar22 >> 9) & 1))) << 1 |
                                       (uint)(((byte)(uVar23 >> 8) & 1) == ((byte)(uVar23 >> 9) & 1)
                                             )) << 1 |
                                      (uint)(((byte)(uVar24 >> 8) & 1) == ((byte)(uVar24 >> 9) & 1))
                                      ) << 1 | (uint)(((byte)(uVar25 >> 8) & 1) ==
                                                     ((byte)(uVar25 >> 9) & 1))) << 1 |
                                    (uint)(((byte)(uVar26 >> 8) & 1) == ((byte)(uVar26 >> 9) & 1)))
                                    << 1 | (uint)(((byte)(uVar27 >> 8) & 1) ==
                                                 ((byte)(uVar27 >> 9) & 1))) << 1 |
                                  (uint)(((byte)(uVar28 >> 8) & 1) == ((byte)(uVar28 >> 9) & 1))) <<
                                  1 | (uint)(((byte)(uVar29 >> 8) & 1) == ((byte)(uVar29 >> 9) & 1))
                                 ) << 1 | (uint)(((byte)(uVar30 >> 8) & 1) ==
                                                ((byte)(uVar30 >> 9) & 1))) << 1 |
                               (uint)(((byte)(uVar31 >> 8) & 1) == ((byte)(uVar31 >> 9) & 1))) << 1
                              | (uint)(((byte)(uVar32 >> 8) & 1) == ((byte)(uVar32 >> 9) & 1))) << 1
                             | (uint)(((byte)(uVar33 >> 8) & 1) == ((byte)(uVar33 >> 9) & 1))) << 1
                            | (uint)(((byte)(uVar34 >> 8) & 1) == ((byte)(uVar34 >> 9) & 1))) << 1 |
                           (uint)(((byte)(uVar35 >> 8) & 1) == ((byte)(uVar35 >> 9) & 1))) << 1 |
                          (uint)(((byte)(uVar36 >> 8) & 1) == ((byte)(uVar36 >> 9) & 1))) << 1 |
                         (uint)(((byte)(uVar37 >> 8) & 1) == ((byte)(uVar37 >> 9) & 1))) << 1 |
                        (uint)(((byte)(uVar38 >> 8) & 1) == ((byte)(uVar38 >> 9) & 1))) << 1 |
                       (uint)(((byte)(uVar39 >> 8) & 1) == ((byte)(uVar39 >> 9) & 1))) << 1 |
                      (uint)(((byte)(uVar40 >> 8) & 1) == ((byte)(uVar40 >> 9) & 1))) << 1 |
                     (uint)(((byte)(uVar41 >> 8) & 1) == ((byte)(uVar41 >> 9) & 1))) << 1 |
                    (uint)(((byte)(uVar42 >> 8) & 1) == ((byte)(uVar42 >> 9) & 1))) << 1 |
                   (uint)(((byte)(uVar43 >> 8) & 1) == ((byte)(uVar43 >> 9) & 1))) << 1 |
                  (uint)(((byte)(uVar44 >> 8) & 1) == ((byte)(uVar44 >> 9) & 1))) << 1 |
                 (uint)(((byte)(uVar45 >> 8) & 1) == ((byte)(uVar45 >> 9) & 1))) << 1 |
                (uint)(((byte)(uVar12 >> 8) & 1) == ((byte)(uVar12 >> 9) & 1))) << 1 |
               (uint)(((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1))) +
               (uint)(bVar1 != (int)uVar8 < 0);
      iVar6 = 0x7fffffff;
      iVar7 = 0x7fff;
      if (iVar16 < 0x8000) {
        iVar6 = -0x80000000;
        iVar7 = -0x8000;
        if (-0x8001 < iVar16) {
          iVar7 = param_1 << 1;
          uVar2 = (uint)((param_1 & 0x80000000) != 0) * -2;
          uVar15 = param_1 * 0x10000 - (uint)((uVar2 & 0x10000) != 0);
          uVar10 = ((((((((((((((((uVar2 | (param_1 & 0x80000000) != 0) << 1 |
                                 (uint)((param_1 & 0x40000000) != 0)) << 1 |
                                (uint)((param_1 & 0x20000000) != 0)) << 1 |
                               (uint)((param_1 & 0x10000000) != 0)) << 1 |
                              (uint)((param_1 & 0x8000000) != 0)) << 1 |
                             (uint)((param_1 & 0x4000000) != 0)) << 1 |
                            (uint)((param_1 & 0x2000000) != 0)) << 1 |
                           (uint)((param_1 & 0x1000000) != 0)) << 1 |
                          (uint)((param_1 & 0x800000) != 0)) << 1 |
                         (uint)((param_1 & 0x400000) != 0)) << 1 | (uint)((param_1 & 0x200000) != 0)
                        ) << 1 | (uint)((param_1 & 0x100000) != 0)) << 1 |
                      (uint)((param_1 & 0x80000) != 0)) << 1 | (uint)((param_1 & 0x40000) != 0)) <<
                     1 | (uint)((param_1 & 0x20000) != 0)) << 1 | (uint)((param_1 & 0x10000) != 0))
                   - (uint)(param_1 * 0x10000 < uVar15);
          bVar1 = param_2 < 0;
          uVar2 = (uint)bVar1 << 9;
          uVar13 = uVar15 * 2;
          uVar15 = uVar10 * 2 | (uint)((uVar15 & 0x80000000) != 0);
          bVar4 = (int)uVar10 < 0 == bVar1;
          bVar5 = bVar1 == ((uVar10 & 0x80000000) != 0);
          uVar9 = (uint)bVar4 * (uVar15 - param_2) + (uint)!bVar4 * (uVar15 + param_2);
          cVar3 = bVar4 * (uVar15 < uVar9) + !bVar4 * (uVar9 < uVar15);
          uVar15 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar14 = uVar2 | uVar15;
          uVar8 = uVar9 * 2 | (uint)((uVar13 & 0x80000000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar8 - param_2) + (uint)!bVar4 * (uVar8 + param_2);
          cVar3 = bVar4 * (uVar8 < uVar11) + !bVar4 * (uVar11 < uVar8);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar17 = uVar2 | uVar15 & 0xfffffeff | uVar14;
          uVar8 = uVar2 | uVar15 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x40000000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar18 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x20000000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar19 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x10000000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar20 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x8000000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar21 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x4000000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar22 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x2000000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar23 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x1000000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar24 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x800000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar25 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x400000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar26 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x200000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar27 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x100000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar28 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x80000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar29 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x40000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar30 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x20000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar31 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x10000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar32 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x8000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar33 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x4000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar34 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x2000) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar35 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x1000) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar36 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x800) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar37 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x400) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar38 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x200) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar39 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x100) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar40 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x80) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar41 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x40) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar42 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x20) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar43 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 0x10) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar44 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 8) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar14 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar45 = uVar8 | uVar9 & 0xfffffeff | uVar14;
          uVar8 = uVar8 | uVar9 & 0xfffffefe;
          uVar9 = uVar8 | uVar14;
          uVar12 = uVar11 * 2 | (uint)((uVar13 & 4) != 0);
          bVar4 = ((byte)(uVar9 >> 8) & 1) == ((byte)(uVar9 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar9 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar11 = (uint)bVar4 * (uVar12 - param_2) + (uint)!bVar4 * (uVar12 + param_2);
          cVar3 = bVar4 * (uVar12 < uVar11) + !bVar4 * (uVar11 < uVar12);
          uVar9 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          uVar12 = uVar8 | uVar14 & 0xfffffeff | uVar9;
          uVar8 = uVar8 | uVar14 & 0xfffffefe;
          uVar14 = uVar8 | uVar9;
          uVar13 = uVar11 * 2 | (uint)((uVar13 & 2) != 0);
          bVar4 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
          bVar5 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar11 & 0x80000000) != 0);
          uVar14 = (uint)bVar4 * (uVar13 - param_2) + (uint)!bVar4 * (uVar13 + param_2);
          cVar3 = bVar4 * (uVar13 < uVar14) + !bVar4 * (uVar14 < uVar13);
          uVar14 = uVar8 | uVar9 & 0xfffffeff |
                   (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
          iVar6 = ((((((((((((((((((((((((((((((((uint)(((byte)((uVar2 | uVar15) >> 8) & 1) ==
                                                       ((byte)((uVar2 | uVar15) >> 9) & 1)) << 1 |
                                                (uint)(((byte)(uVar17 >> 8) & 1) ==
                                                      ((byte)(uVar17 >> 9) & 1))) << 1 |
                                               (uint)(((byte)(uVar18 >> 8) & 1) ==
                                                     ((byte)(uVar18 >> 9) & 1))) << 1 |
                                              (uint)(((byte)(uVar19 >> 8) & 1) ==
                                                    ((byte)(uVar19 >> 9) & 1))) << 1 |
                                             (uint)(((byte)(uVar20 >> 8) & 1) ==
                                                   ((byte)(uVar20 >> 9) & 1))) << 1 |
                                            (uint)(((byte)(uVar21 >> 8) & 1) ==
                                                  ((byte)(uVar21 >> 9) & 1))) << 1 |
                                           (uint)(((byte)(uVar22 >> 8) & 1) ==
                                                 ((byte)(uVar22 >> 9) & 1))) << 1 |
                                          (uint)(((byte)(uVar23 >> 8) & 1) ==
                                                ((byte)(uVar23 >> 9) & 1))) << 1 |
                                         (uint)(((byte)(uVar24 >> 8) & 1) ==
                                               ((byte)(uVar24 >> 9) & 1))) << 1 |
                                        (uint)(((byte)(uVar25 >> 8) & 1) ==
                                              ((byte)(uVar25 >> 9) & 1))) << 1 |
                                       (uint)(((byte)(uVar26 >> 8) & 1) == ((byte)(uVar26 >> 9) & 1)
                                             )) << 1 |
                                      (uint)(((byte)(uVar27 >> 8) & 1) == ((byte)(uVar27 >> 9) & 1))
                                      ) << 1 | (uint)(((byte)(uVar28 >> 8) & 1) ==
                                                     ((byte)(uVar28 >> 9) & 1))) << 1 |
                                    (uint)(((byte)(uVar29 >> 8) & 1) == ((byte)(uVar29 >> 9) & 1)))
                                    << 1 | (uint)(((byte)(uVar30 >> 8) & 1) ==
                                                 ((byte)(uVar30 >> 9) & 1))) << 1 |
                                  (uint)(((byte)(uVar31 >> 8) & 1) == ((byte)(uVar31 >> 9) & 1))) <<
                                  1 | (uint)(((byte)(uVar32 >> 8) & 1) == ((byte)(uVar32 >> 9) & 1))
                                 ) << 1 | (uint)(((byte)(uVar33 >> 8) & 1) ==
                                                ((byte)(uVar33 >> 9) & 1))) << 1 |
                               (uint)(((byte)(uVar34 >> 8) & 1) == ((byte)(uVar34 >> 9) & 1))) << 1
                              | (uint)(((byte)(uVar35 >> 8) & 1) == ((byte)(uVar35 >> 9) & 1))) << 1
                             | (uint)(((byte)(uVar36 >> 8) & 1) == ((byte)(uVar36 >> 9) & 1))) << 1
                            | (uint)(((byte)(uVar37 >> 8) & 1) == ((byte)(uVar37 >> 9) & 1))) << 1 |
                           (uint)(((byte)(uVar38 >> 8) & 1) == ((byte)(uVar38 >> 9) & 1))) << 1 |
                          (uint)(((byte)(uVar39 >> 8) & 1) == ((byte)(uVar39 >> 9) & 1))) << 1 |
                         (uint)(((byte)(uVar40 >> 8) & 1) == ((byte)(uVar40 >> 9) & 1))) << 1 |
                        (uint)(((byte)(uVar41 >> 8) & 1) == ((byte)(uVar41 >> 9) & 1))) << 1 |
                       (uint)(((byte)(uVar42 >> 8) & 1) == ((byte)(uVar42 >> 9) & 1))) << 1 |
                      (uint)(((byte)(uVar43 >> 8) & 1) == ((byte)(uVar43 >> 9) & 1))) << 1 |
                     (uint)(((byte)(uVar44 >> 8) & 1) == ((byte)(uVar44 >> 9) & 1))) << 1 |
                    (uint)(((byte)(uVar45 >> 8) & 1) == ((byte)(uVar45 >> 9) & 1))) << 1 |
                   (uint)(((byte)(uVar12 >> 8) & 1) == ((byte)(uVar12 >> 9) & 1))) << 1 |
                  (uint)(((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1))) +
                  (uint)(bVar1 != (int)uVar10 < 0);
        }
      }
      return CONCAT44(iVar7,iVar6);
    }
  }
  return CONCAT44(in_r1,iVar7);
}


/* ROM address: 0x00002304; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002304 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00002304(int param_1,int param_2)

{
  char cVar1;
  
  cVar1 = (param_1 < 0) + (param_2 < 0);
  param_1 = param_2 + param_1;
  if ((cVar1 == '\0' || cVar1 == '\x02') && (char)((param_1 < 0) + (param_2 < 0)) == '\x01') {
    param_1 = (-1 < param_1) + 0x7fffffff;
  }
  return param_1;
}


/* [MATH AND UNITS REVIEW]
 * rx8_mul_s32_shift16_saturate: DMULS.L forms signed 64-bit product; 16 SHAR/ROTCR pairs perform arithmetic >>16; range check clamps to INT32_MIN/MAX. Equivalent to saturate_s32(floor((int64)a*b/65536)). Compatible with Q16.16 multiplication if both inputs use that format; actual operand units depend on callers. Not GCC __mulsi3, which returns an ordinary integer product.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0000231c; body bytes: 114; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000231c (114 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint rx8_mul_s32_shift16_saturate(int multiplicand,int multiplier)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)((ulonglong)((longlong)multiplier * (longlong)multiplicand) >> 0x20);
  iVar2 = (int)uVar3 >> 0x10;
  uVar1 = (uint)(((int)uVar3 >> 0xf & 1U) == 1);
  uVar3 = ((((((((((((((((uint)((longlong)multiplier * (longlong)multiplicand) >> 1 |
                        (uint)((uVar3 & 1) == 1) * -0x80000000) >> 1 |
                       (uint)(((int)uVar3 >> 1 & 1U) == 1) * -0x80000000) >> 1 |
                      (uint)(((int)uVar3 >> 2 & 1U) == 1) * -0x80000000) >> 1 |
                     (uint)(((int)uVar3 >> 3 & 1U) == 1) * -0x80000000) >> 1 |
                    (uint)(((int)uVar3 >> 4 & 1U) == 1) * -0x80000000) >> 1 |
                   (uint)(((int)uVar3 >> 5 & 1U) == 1) * -0x80000000) >> 1 |
                  (uint)(((int)uVar3 >> 6 & 1U) == 1) * -0x80000000) >> 1 |
                 (uint)(((int)uVar3 >> 7 & 1U) == 1) * -0x80000000) >> 1 |
                (uint)(((int)uVar3 >> 8 & 1U) == 1) * -0x80000000) >> 1 |
               (uint)(((int)uVar3 >> 9 & 1U) == 1) * -0x80000000) >> 1 |
              (uint)(((int)uVar3 >> 10 & 1U) == 1) * -0x80000000) >> 1 |
             (uint)(((int)uVar3 >> 0xb & 1U) == 1) * -0x80000000) >> 1 |
            (uint)(((int)uVar3 >> 0xc & 1U) == 1) * -0x80000000) >> 1 |
           (uint)(((int)uVar3 >> 0xd & 1U) == 1) * -0x80000000) >> 1 |
          (uint)(((int)uVar3 >> 0xe & 1U) == 1) * -0x80000000) >> 1 | uVar1 * -0x80000000;
  if (iVar2 < 0) {
    if ((iVar2 != -1) || (uVar1 == 0)) {
      uVar3 = 0x80000000;
    }
  }
  else if ((iVar2 != 0) || (uVar1 != 0)) {
    uVar3 = 0x7fffffff;
  }
  return uVar3;
}


/* [MATH AND UNITS REVIEW]
 * sh_busy_wait_count_times_8: Unsigned loop bound is input bits shifted left three modulo 2^32. No elapsed-time unit is established; do not call this delay_us without clock and instruction timing evidence.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0000239c; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000239c (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void sh_busy_wait_count_times_8(int delay_count)

{
  uint uVar1;
  
  uVar1 = 0;
  if (delay_count << 3 != 0) {
    do {
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(delay_count << 3));
  }
  return;
}


/* [MATH AND UNITS REVIEW]
 * First-order filter: current+(previous-current)*(1-coefficient), with invalid previous exponent rejection and snap-to-current threshold. Units of current/previous/threshold agree; coefficient is dimensionless. The raw C (uint)arg1 is an FPU bit reinterpretation in assembly, not a numeric uint conversion.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000023b0; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000023b0 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

float rx8_first_order_filter(float current,float previous,float coefficient,float snap_threshold)

{
  float filtered;
  
  if ((((uint)previous & 0x7f800000) == 0x7f800000) ||
     (filtered = current + (previous - current) * (1.0 - coefficient), ABS(current - filtered) < snap_threshold)) {
    filtered = current;
  }
  return filtered;
}


/* [MATH AND UNITS REVIEW]
 * Absolute difference is fabsf(a-b) behavior for ordinary values, implemented with SH FPU arithmetic. This is not a one-argument fabsf routine and does not establish a libm origin.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000023dc; body bytes: 8; decompiled */

float rx8_absolute_difference(float left,float right)

{
  return ABS(left - right);
}


/* [MATH AND UNITS REVIEW]
 * Ordered max: a>b ? a:b. With NaN second argument it returns that NaN, unlike newlib fmaxf which selects the numeric operand. Equal inputs choose the second operand, affecting signed zero.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000023e4; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000023e4 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

float rx8_max_float(float left,float right)

{
  if (right < left) {
    right = left;
  }
  return right;
}


/* [MATH AND UNITS REVIEW]
 * Ordered min: b>a ? a:b. With NaN second argument it returns that NaN, unlike newlib fminf. Equal inputs choose the second operand.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000023f4; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000023f4 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

float rx8_min_float(float left,float right)

{
  if (left < right) {
    right = left;
  }
  return right;
}


/* [MATH AND UNITS REVIEW]
 * Assembly clamp is !(value>lower) ? lower : (upper>value ? value:upper). Raw C simplification using upper<=value is not equivalent for NaN upper. Reconstructed/rx8_math.c preserves the assembly ordering.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002404; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002404 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

float rx8_clamp_float(float value,float lower,float upper)

{
  if ((lower < value) && (lower = value, upper <= value)) {
    lower = upper;
  }
  return lower;
}


/* [MATH AND UNITS REVIEW]
 * rx8_pack_u8_with_complement: Returns ((x & 255)<<8) | ((~x)&255). Redundant value/complement encoding, not byte swapping or a CRC.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002420; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002420 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

int rx8_pack_u8_with_complement(uint value)

{
  return (value & 0xff) * 0x100 + (~value & 0xff);
}


/* [MATH AND UNITS REVIEW]
 * rx8_pack_u16_with_complement: Returns ((uint32)(uint16)x<<16) | (uint16)~x. Redundant value/complement encoding; raw signed return type can obscure bit-pattern semantics.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002430; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002430 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

int rx8_pack_u16_with_complement(ushort value)

{
  return (uint)value * 0x10000 + (uint)(ushort)~value;
}


/* [MATH AND UNITS REVIEW]
 * rx8_is_outside_tolerance_band: Returns value < center-tolerance || value > center+tolerance. Inclusive endpoints are inside. Strict comparisons can both be false for NaN. Existing divide-by-zero-related name is too narrow: this helper itself performs no division.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002440; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002440 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 rx8_is_outside_tolerance_band(float value,float center,float tolerance)

{
  undefined4 outside_band;
  
  if ((value < center - tolerance) || (center + tolerance < value)) {
    outside_band = 1;
  }
  else {
    outside_band = 0;
  }
  return outside_band;
}


/* [MATH AND UNITS REVIEW]
 * rx8_add_u16_saturate: Inputs are truncated to uint16 before addition; output min(a+b,65535). Saturation, not ordinary wrapping unsigned-short arithmetic.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002460; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002460 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint rx8_add_u16_saturate(uint left,uint right)

{
  uint sum;
  
  sum = (left & 0xffff) + (right & 0xffff);
  if (0xfffe < sum) {
    sum = 0xffff;
  }
  return sum;
}


/* [MATH AND UNITS REVIEW]
 * rx8_add_u8_saturate: Inputs are truncated to uint8 before addition; output min(a+b,255).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002478; body bytes: 22; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002478 (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint rx8_add_u8_saturate(uint left,uint right)

{
  uint sum;
  
  sum = (left & 0xff) + (right & 0xff);
  if (0xfe < sum) {
    sum = 0xff;
  }
  return sum;
}


/* [MATH AND UNITS REVIEW]
 * rx8_encode_u16_affine_saturate: For finite in-range intermediate t=(signal-offset)/step, performs trunc(t+0.5), then clamps integer to 0..65535. Physical decode is raw*step+offset. Step is units/count, not an encode multiplier. NaN, zero step and out-of-range FTRC require SH-specific analysis; do not model by an unrestricted C float-to-int cast. Not roundf: that has a signed floating result and halfway-away-from-zero rules.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002490; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002490 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

int rx8_encode_u16_affine_saturate(float signal,float units_per_count,float offset)

{
  int encoded_value;
  int rounded_counts;
  
  encoded_value = RX8_U16_MAX;
  rounded_counts = (int)((signal - offset) / units_per_count + 0.5);
  if ((rounded_counts < 0x10000) && (encoded_value = rounded_counts, rounded_counts < 0)) {
    encoded_value = 0;
  }
  return encoded_value;
}


/* [MATH AND UNITS REVIEW]
 * rx8_decode_u16_affine: Returns offset+(uint16 raw)*step. Float args are scale,offset; integer arg is raw. This is affine scaling, not evidence of a specific sensor unit.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000024c0; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000024c0 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

float rx8_decode_u16_affine(float units_per_count,float offset,ushort raw_value)

{
  return offset + (float)raw_value * units_per_count;
}


/* [MATH AND UNITS REVIEW]
 * rx8_encode_u8_affine_saturate: For finite in-range intermediate t=(signal-offset)/step, performs trunc(t+0.5), then clamps integer to 0..255. Decode is raw*step+offset. Exceptional FTRC behavior is not established by raw C.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000024d0; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000024d0 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

int rx8_encode_u8_affine_saturate(float signal,float units_per_count,float offset)

{
  int encoded_value;
  int rounded_counts;
  
  encoded_value = RX8_U8_MAX;
  rounded_counts = (int)((signal - offset) / units_per_count + 0.5);
  if ((rounded_counts < 0x100) && (encoded_value = rounded_counts, rounded_counts < 0)) {
    encoded_value = 0;
  }
  return encoded_value;
}


/* [MATH AND UNITS REVIEW]
 * rx8_decode_u8_affine: Returns offset+(uint8 raw)*step. Float args are scale,offset; integer arg is raw.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002500; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002500 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

float rx8_decode_u8_affine(float units_per_count,float offset,byte raw_value)

{
  return offset + (float)raw_value * units_per_count;
}


/* [MATH AND UNITS REVIEW]
 * rx8_blend_s32_u16_weight_over_256: Returns a+trunc((1-weight/256)*(float(b)-float(a))). weight is uint16, not restricted to 0..256; values above 256 extrapolate. Floating arithmetic and truncation matter; not generic integer lerp with unrestricted overflow guarantees.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00002510; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002510 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

int rx8_blend_s32_u16_weight_over_256(int endpoint_a,int endpoint_b,ushort weight_256)

{
  return endpoint_a + (int)((1.0 - (float)weight_256 * 0.00390625) * ((float)endpoint_b - (float)endpoint_a));
}


/* ROM address: 0x0000253c; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000253c (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 0000253c: signed low-word row offset, two calls to 00002678, second only if Y fraction nonzero; final FR2. No row-bound checks added.
 * Explicit register-result structs are an analysis representation.
 */
float rx8_interpolate_2axis_f32(uint32_t column_count, const float *values, Rx8MapPosition position)
{
  /* MULS.W multiplies signed LOW 16-bit operands, not unrestricted size_t. */
  uint32_t row_bytes = column_count * 4u;
  int32_t signed_row_offset = (int32_t)(int16_t)row_bytes * (int32_t)(int16_t)position.y.index;
  const float *row = (const float *)((uintptr_t)values + (uint32_t)signed_row_offset);
  float lower_row = rx8_interpolate_1d_f32(position.x.index, row, position.x.fraction);
  if (position.y.fraction == 0.0f) return lower_row;
  const float *next_row = (const float *)((uintptr_t)row + row_bytes);
  float difference = rx8_interpolate_1d_f32(position.x.index, next_row, position.x.fraction) - lower_row;
  return rx8_sh_fmac_model(position.y.fraction, difference, lower_row);
}


/* ROM address: 0x0000256c; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000256c (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 0000256c: signed low-word row offset, two calls to 000026f4, second only if Y fraction nonzero; final FR2. No row-bound checks added.
 * Explicit register-result structs are an analysis representation.
 */
float rx8_interpolate_2axis_s8(uint32_t column_count, const int8_t *values, Rx8MapPosition position)
{
  /* MULS.W multiplies signed LOW 16-bit operands, not unrestricted size_t. */
  uint32_t row_bytes = column_count * 1u;
  int32_t signed_row_offset = (int32_t)(int16_t)row_bytes * (int32_t)(int16_t)position.y.index;
  const int8_t *row = (const int8_t *)((uintptr_t)values + (uint32_t)signed_row_offset);
  float lower_row = rx8_interpolate_1d_s8(position.x.index, row, position.x.fraction);
  if (position.y.fraction == 0.0f) return lower_row;
  const int8_t *next_row = (const int8_t *)((uintptr_t)row + row_bytes);
  float difference = rx8_interpolate_1d_s8(position.x.index, next_row, position.x.fraction) - lower_row;
  return rx8_sh_fmac_model(position.y.fraction, difference, lower_row);
}


/* ROM address: 0x00002598; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002598 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 00002598: signed low-word row offset, two calls to 00002690, second only if Y fraction nonzero; final FR2. No row-bound checks added.
 * Explicit register-result structs are an analysis representation.
 */
float rx8_interpolate_2axis_s16(uint32_t column_count, const int16_t *values, Rx8MapPosition position)
{
  /* MULS.W multiplies signed LOW 16-bit operands, not unrestricted size_t. */
  uint32_t row_bytes = column_count * 2u;
  int32_t signed_row_offset = (int32_t)(int16_t)row_bytes * (int32_t)(int16_t)position.y.index;
  const int16_t *row = (const int16_t *)((uintptr_t)values + (uint32_t)signed_row_offset);
  float lower_row = rx8_interpolate_1d_s16(position.x.index, row, position.x.fraction);
  if (position.y.fraction == 0.0f) return lower_row;
  const int16_t *next_row = (const int16_t *)((uintptr_t)row + row_bytes);
  float difference = rx8_interpolate_1d_s16(position.x.index, next_row, position.x.fraction) - lower_row;
  return rx8_sh_fmac_model(position.y.fraction, difference, lower_row);
}


/* ROM address: 0x000025c8; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000025c8 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 000025c8: signed low-word row offset, two calls to 000026b0, second only if Y fraction nonzero; final FR2. No row-bound checks added.
 * Explicit register-result structs are an analysis representation.
 */
float rx8_interpolate_2axis_u8(uint32_t column_count, const uint8_t *values, Rx8MapPosition position)
{
  /* MULS.W multiplies signed LOW 16-bit operands, not unrestricted size_t. */
  uint32_t row_bytes = column_count * 1u;
  int32_t signed_row_offset = (int32_t)(int16_t)row_bytes * (int32_t)(int16_t)position.y.index;
  const uint8_t *row = (const uint8_t *)((uintptr_t)values + (uint32_t)signed_row_offset);
  float lower_row = rx8_interpolate_1d_u8(position.x.index, row, position.x.fraction);
  if (position.y.fraction == 0.0f) return lower_row;
  const uint8_t *next_row = (const uint8_t *)((uintptr_t)row + row_bytes);
  float difference = rx8_interpolate_1d_u8(position.x.index, next_row, position.x.fraction) - lower_row;
  return rx8_sh_fmac_model(position.y.fraction, difference, lower_row);
}


/* ROM address: 0x000025f4; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000025f4 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 000025f4: signed low-word row offset, two calls to 000026d0, second only if Y fraction nonzero; final FR2. No row-bound checks added.
 * Explicit register-result structs are an analysis representation.
 */
float rx8_interpolate_2axis_u16(uint32_t column_count, const uint16_t *values, Rx8MapPosition position)
{
  /* MULS.W multiplies signed LOW 16-bit operands, not unrestricted size_t. */
  uint32_t row_bytes = column_count * 2u;
  int32_t signed_row_offset = (int32_t)(int16_t)row_bytes * (int32_t)(int16_t)position.y.index;
  const uint16_t *row = (const uint16_t *)((uintptr_t)values + (uint32_t)signed_row_offset);
  float lower_row = rx8_interpolate_1d_u16(position.x.index, row, position.x.fraction);
  if (position.y.fraction == 0.0f) return lower_row;
  const uint16_t *next_row = (const uint16_t *)((uintptr_t)row + row_bytes);
  float difference = rx8_interpolate_1d_u16(position.x.index, next_row, position.x.fraction) - lower_row;
  return rx8_sh_fmac_model(position.y.fraction, difference, lower_row);
}


/* ROM address: 0x00002624; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002624 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 0x2624-2656: R0 count/index, R1 axis, FR0 value/fraction. Endpoint paths set FR0=0; interior path divides breakpoint differences. No empty-axis guard is present. Struct return models two hardware outputs, not a native C ABI claim.
 * Explicit register-result structs are an analysis representation.
 */
Rx8AxisPosition rx8_find_axis_index_fraction(uint32_t count, const float *axis, float value)
{
  uint32_t byte_offset = (count - 1u) * 4u;
  float lower = *(const float *)((uintptr_t)axis + byte_offset);
  /* BF after FCMP/GT includes unordered comparisons: do not replace with <=. */
  if (!(lower > value)) return (Rx8AxisPosition){byte_offset >> 2, 0.0f};
  for (;;) {
    if (byte_offset == 0) return (Rx8AxisPosition){0, 0.0f};
    byte_offset -= 4u;
    lower = *(const float *)((uintptr_t)axis + byte_offset);
    if (!(lower > value)) break;
  }
  float upper = *(const float *)((uintptr_t)axis + byte_offset + 4u);
  return (Rx8AxisPosition){byte_offset >> 2, (value - lower) / (upper - lower)};
}


/* ROM address: 0x00002658; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002658 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 0x2658-2676: first search FR4/X/count+0/axis+4, second FR5/Y/count+2/axis+8; results R2/R3 and FR0/FR1. Both calls required.
 * Explicit register-result structs are an analysis representation.
 */
Rx8MapPosition rx8_find_xy_axis_positions(float x_value, float y_value, const Rx8Table3D *table)
{
  Rx8MapPosition position;
  position.x = rx8_find_axis_index_fraction(table->x_count, RX8_ROM_PTR(float, table->x_axis_address), x_value);
  position.y = rx8_find_axis_index_fraction(table->y_count, RX8_ROM_PTR(float, table->y_axis_address), y_value);
  return position;
}


/* ROM address: 0x00002678; body bytes: 22; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002678 (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 00002678: integer extension distinguishes float; R0 index, R1 data, FR0 fraction, FR2 result. FMAC retained as explicit model operation.
 * Explicit register-result structs are an analysis representation.
 */
float rx8_interpolate_1d_f32(uint32_t lower_index, const float *values, float fraction)
{
  float lower_value = (float)values[lower_index];
  /* Zero fraction avoids reading past the last endpoint. Preserve this branch. */
  if (fraction == 0.0f) return lower_value;
  float difference = (float)values[lower_index + 1u] - lower_value;
  return rx8_sh_fmac_model(fraction, difference, lower_value);
}


/* ROM address: 0x00002690; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00002690 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 00002690: integer extension distinguishes int16_t; R0 index, R1 data, FR0 fraction, FR2 result. FMAC retained as explicit model operation.
 * Explicit register-result structs are an analysis representation.
 */
float rx8_interpolate_1d_s16(uint32_t lower_index, const int16_t *values, float fraction)
{
  float lower_value = (float)values[lower_index];
  /* Zero fraction avoids reading past the last endpoint. Preserve this branch. */
  if (fraction == 0.0f) return lower_value;
  float difference = (float)values[lower_index + 1u] - lower_value;
  return rx8_sh_fmac_model(fraction, difference, lower_value);
}


/* ROM address: 0x000026b0; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000026b0 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 000026b0: integer extension distinguishes uint8_t; R0 index, R1 data, FR0 fraction, FR2 result. FMAC retained as explicit model operation.
 * Explicit register-result structs are an analysis representation.
 */
float rx8_interpolate_1d_u8(uint32_t lower_index, const uint8_t *values, float fraction)
{
  float lower_value = (float)values[lower_index];
  /* Zero fraction avoids reading past the last endpoint. Preserve this branch. */
  if (fraction == 0.0f) return lower_value;
  float difference = (float)values[lower_index + 1u] - lower_value;
  return rx8_sh_fmac_model(fraction, difference, lower_value);
}


/* ROM address: 0x000026d0; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000026d0 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 000026d0: integer extension distinguishes uint16_t; R0 index, R1 data, FR0 fraction, FR2 result. FMAC retained as explicit model operation.
 * Explicit register-result structs are an analysis representation.
 */
float rx8_interpolate_1d_u16(uint32_t lower_index, const uint16_t *values, float fraction)
{
  float lower_value = (float)values[lower_index];
  /* Zero fraction avoids reading past the last endpoint. Preserve this branch. */
  if (fraction == 0.0f) return lower_value;
  float difference = (float)values[lower_index + 1u] - lower_value;
  return rx8_sh_fmac_model(fraction, difference, lower_value);
}


/* ROM address: 0x000026f4; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000026f4 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [LOOKUP FAMILY RECONSTRUCTION]
 * 000026f4: integer extension distinguishes int8_t; R0 index, R1 data, FR0 fraction, FR2 result. FMAC retained as explicit model operation.
 * Explicit register-result structs are an analysis representation.
 */
float rx8_interpolate_1d_s8(uint32_t lower_index, const int8_t *values, float fraction)
{
  float lower_value = (float)values[lower_index];
  /* Zero fraction avoids reading past the last endpoint. Preserve this branch. */
  if (fraction == 0.0f) return lower_value;
  float difference = (float)values[lower_index + 1u] - lower_value;
  return rx8_sh_fmac_model(fraction, difference, lower_value);
}


/* ROM address: 0x000029f8; body bytes: 16; decompiled */

/* Function candidate recovered from ROM pointer at 7fe10 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_000029f8(void)

{
  interrupt_entry_save_context();
  FUN_000055d6();
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * interrupt_entry_save_context [high]: jsr target of every IVT trampoline at 0x28c0-0x30d0 (literals all = 0x3238). Dynamically executed on every cpu.interrupt in the emulator: saves r2-r7, fr0-fr11, fpscr, fpul (0x324a-0x326e), raises SR mask from ctrl block field +0x10, bumps counter at +0x8, rts to LAB_00003280 restore path.
 * RAM 0xffff7640 os_state_flags (uint16): u16 at ctrl+8; mov.l pool 0x3674 in 0x3588/0x35cc/0x35ee, pool 0x3758 in 0x36d4; incremented in interrupt_entry_save_context 0x3238; bit 0x1000 tested and 0x100 set in the 0x3db0 context-switch check.
 */
/* ROM address: 0x00003238; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003238 (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * interrupt_entry_save_context(void)

{
  os_state_flags_ffff7640 = os_state_flags_ffff7640 + 1;
  return &LAB_00003280;
}


/* ROM address: 0x000033b6; body bytes: 2; decompiled_with_warnings */

/* WARNING: Control flow encountered bad instruction data */
/* Unique exact-byte match to related 60E0FC00 function at 000033b6 (190 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000033b6(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00003490; body bytes: 218; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000034fa) */
/* WARNING: Removing unreachable block (ram,0x00003542) */
/* Unique exact-byte match to related 60E0FC00 function at 00003490 (218 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00003490(char param_1)

{
  char cVar1;
  int snapshot_os_current_task_record_ptr_ffff764c;
  int snapshot_os_task_table_ptr_ffff7650;
  int iVar4;
  uint in_sr;
  uint uVar5;
  
  snapshot_os_current_task_record_ptr_ffff764c = os_current_task_record_ptr_ffff764c;
  uVar5 = in_sr & 0xfffffffe | (uint)(param_1 == '\0');
  if (((byte)uVar5 & 1) == 1) {
    if ((os_scheduled_count_ffff763c == os_dispatched_count_ffff763e) || (*(char *)(os_task_table_ptr_ffff7650 + 1) != '\0')) {
      os_state_flags_ffff7640 = 0;
    }
    else {
      os_state_flags_ffff7640 = 0x100;
      os_context_switch(&os_ctrl_block_ffff7638,uVar5,os_task_table_ptr_ffff7650);
    }
  }
  else {
    iVar4 = *(char *)(os_current_task_record_ptr_ffff764c + 2) * 2;
    *(undefined *)(os_current_task_record_ptr_ffff764c + 2) = (&DAT_ffff762c)[iVar4];
    snapshot_os_task_table_ptr_ffff7650 = os_task_table_ptr_ffff7650;
    if ((&DAT_ffff762d)[iVar4] != *(char *)(snapshot_os_current_task_record_ptr_ffff764c + 1)) {
      cVar1 = *(char *)(snapshot_os_current_task_record_ptr_ffff764c + 1);
      *(undefined *)(snapshot_os_current_task_record_ptr_ffff764c + 1) = (&DAT_ffff762d)[iVar4];
      os_state_flags_ffff7640 = os_state_flags_ffff7640 + 0x100;
      ref_consistencyCheck(&os_ctrl_block_ffff7638,(int)cVar1);
      if (((*(char *)(snapshot_os_task_table_ptr_ffff7650 + 1) == '\0') && (os_scheduled_count_ffff763c != os_dispatched_count_ffff763e)) &&
         ((os_state_flags_ffff7640 & 0x1000) == 0)) {
        os_context_switch(&os_ctrl_block_ffff7638,uVar5,snapshot_os_task_table_ptr_ffff7650);
      }
      else {
        os_state_flags_ffff7640 = os_state_flags_ffff7640 - 0x100;
      }
    }
  }
  return 0;
}


/* ROM address: 0x00003588; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003588 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00003588(void)

{
  os_state_flags_ffff7640 = os_state_flags_ffff7640 | (uint)&DAT_00010000;
  (*(code *)0x0)();
  os_state_flags_ffff7640 = os_state_flags_ffff7640 & 0xfffeffff;
  return;
}


/* ROM address: 0x000035cc; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000035cc (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000035cc(void)

{
  os_state_flags_ffff7640 = os_state_flags_ffff7640 | 0x4000;
  FUN_00009e58();
  os_state_flags_ffff7640 = os_state_flags_ffff7640 & 0xffffbfff;
  return;
}


/* ROM address: 0x000035ee; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000035ee (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000035ee(void)

{
  os_state_flags_ffff7640 = os_state_flags_ffff7640 | 0x8000;
  (*(code *)0x0)();
  os_state_flags_ffff7640 = os_state_flags_ffff7640 & (uint)&DAT_ffff7fff;
  return;
}


/* ROM address: 0x00003610; body bytes: 138; decompiled */

void FUN_00003610(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  uint in_sr;
  
  if ((param_3 & 0x2000) == 0) {
    if ((param_3 & 0x4000) == 0) {
      if ((param_3 & 0x8000) == 0) {
        if ((param_3 & 0x20000) == 0) {
          if ((param_3 & (uint)&DAT_00010000) == 0) {
            if (((param_3 & 0xf) == 0) && ((in_sr & 0xf0) == 0)) {
              if ((param_3 & 0xf00) == 0) {
                if ((param_3 & 0x80000000) == 0) {
                  uVar1 = 2;
                }
                else {
                  uVar1 = 1;
                }
              }
              else {
                uVar1 = 0;
              }
            }
            else {
              uVar1 = 3;
            }
          }
          else {
            uVar1 = 8;
          }
        }
        else {
          uVar1 = 7;
        }
      }
      else {
        uVar1 = 6;
      }
    }
    else {
      uVar1 = 5;
    }
    os_state_flags_ffff7640 = os_state_flags_ffff7640 | 0x2000;
    (*(code *)0x0)(param_1,param_2,uVar1);
    os_state_flags_ffff7640 = os_state_flags_ffff7640 & 0xffffdfff;
  }
  return;
}


/* ROM address: 0x000036d4; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000036d4 (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000036d4(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  
  if ((param_3 & 0x2000) == 0) {
    if ((param_3 & 0x4000) == 0) {
      if ((param_3 & 0x8000) == 0) {
        if ((param_3 & 0x20000) == 0) {
          if ((param_3 & (uint)&DAT_00010000) == 0) {
            if (((param_3 & 0xf) == 0) && ((param_4 & 0xf0) == 0)) {
              uVar1 = 2;
            }
            else {
              uVar1 = 3;
            }
          }
          else {
            uVar1 = 8;
          }
        }
        else {
          uVar1 = 7;
        }
      }
      else {
        uVar1 = 6;
      }
    }
    else {
      uVar1 = 5;
    }
    os_state_flags_ffff7640 = os_state_flags_ffff7640 | 0x2000;
    (*(code *)0x0)(param_1,param_2,uVar1);
    os_state_flags_ffff7640 = os_state_flags_ffff7640 & 0xffffdfff;
  }
  return;
}


/* [EXPORT CLEANUP]
 * Computed indirect jump at 0x37ac: slot = incoming r2 + ROM32[0x37c0] (=0x4b34)
 * - zero-extended byte at [r13]; target = ROM32[slot]. The sibling path at
 * 0x3794-0x379a tail-jumps to ROM32[0x37bc] (=0x3848). Index bounds, record
 * layout and pointer-table extent are not established; this stays a computed
 * dispatch, not a recovered switch.
 */
/* [ADDITIONAL SOURCE REVIEW]
 * os_switch_to_task [high]: Sets ctrl+4 = task index, ctrl+0x18 = task record (0x4990 + idx*0x10), ctrl+0x14 = stack ptr from PTR_DAT_00004994[idx], then computed jump via PTR_FUN_00004998[idx] (task table 0x4998). Emulator: vec-0x378 handler reaches it via 0x9630.
 * RAM 0xffff7638 os_ctrl_block (uint8[0x20]): OS ctrl block base; mov.l pool 0x3278/0x32ec/0x3388 in 0x3238, pool 0x3e00 in 0x3db0, pool 0x3e80 in 0x3e10 (os_init) among 11 pool refs; members +4/+6/+8/+0x14/+0x18 are the count/flags/ptr cells; os_switch_to_task 0x375c writes ctrl+4, ctrl+0x14, ctrl+0x18.
 */
/* ROM address: 0x0000375c; body bytes: 96; decompiled_with_warnings */

int os_switch_to_task(int param_1,short param_2)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  char *pcVar5;
  
  iVar4 = (int)param_2;
  pcVar5 = (&PTR_DAT_00004994)[iVar4 * 4];
  *(short *)(param_1 + 4) = param_2;
  *(undefined **)(param_1 + 0x18) = &DAT_00004990 + iVar4 * 0x10;
  *(char **)(param_1 + 0x14) = pcVar5;
  FUN_000035cc();
  *(undefined4 *)(param_1 + 8) = 0;
  if (*pcVar5 == 0) {
    cVar1 = (&DAT_00004992)[iVar4 * 0x10];
    pcVar5[1] = cVar1;
    iVar2 = *(int *)(param_1 + 0xc);
    *(int *)(pcVar5 + 4) = iVar2;
    puVar3 = (&PTR_FUN_00004998)[iVar4 * 4];
    *(undefined4 *)(iVar2 + -4) = 0;
    *(undefined **)(iVar2 + -8) = puVar3;
    return (int)cVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x000037ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar4 = (**(code **)((int)&tbl_os_resume_jumptable_00004b34 +
                      ((int)*pcVar5 - (uint)(byte)(&DAT_00004990)[iVar4 * 0x10])))
                    (*(undefined4 *)(param_1 + 0xc));
  return iVar4;
}


/* [ADDITIONAL SOURCE REVIEW]
 * os_wake_posted_task [high]: Decrements credit byte ctx[3] of target task (PTR_DAT_00004994[slot*4][3]; disasm 0x3878-0x3888) then calls 0x39ba; may context-switch via 0x3bf4. Dynamic: task[3] ctx[3] 0x1e -> 0x1d on post.
 */
/* ROM address: 0x00003854; body bytes: 166; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000038e0) */
/* WARNING: Removing unreachable block (ram,0x000038b8) */
/* Unique exact-byte match to related 60E0FC00 function at 00003854 (166 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 os_wake_posted_task(short param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint in_sr;
  
  uVar3 = 0;
  cVar1 = (&PTR_DAT_00004994)[param_1 * 4][3];
  if (cVar1 == '\0') {
    uVar3 = 4;
  }
  else {
    (&PTR_DAT_00004994)[param_1 * 4][3] = cVar1 + -1;
    iVar2 = os_mark_task_ready(&os_ctrl_block_ffff7638,(int)param_1,(int)(char)(&DAT_00004992)[param_1 * 0x10]);
    if (((iVar2 != 0) && ((in_sr & 0xf0) == 0 && os_state_flags_ffff7640 == 0)) &&
       (*(char *)(os_task_table_ptr_ffff7650 + 1) == '\0')) {
      os_state_flags_ffff7640 = 0x100;
      os_context_switch(&os_ctrl_block_ffff7638);
    }
  }
  return uVar3;
}


/* [CROSS-ECU / RX8DEFS REVIEW]
 * sh_raise_interrupt_mask_return_previous [assembly_verified]: 0x3922 reads SR; saves SR&0xf0; if requested mask is greater, delay-slot instruction 0x392c loads argument into SR. Raw C omits this side effect. This is not a pure function despite the exported C body.
 */
/* ROM address: 0x00003920; body bytes: 18; decompiled */

uint sh_raise_interrupt_mask_return_previous(uint param_1)

{
  uint uVar1;
  uint in_sr;
  
  uVar1 = in_sr & 0xf0;
  if (uVar1 < param_1) {
    return uVar1;
  }
  return uVar1;
}


/* ROM address: 0x00003934; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003934 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_setSR(int param_1)

{
  if ((param_1 == 0) && (*(char *)(os_task_table_ptr_ffff7650 + 1) != '\x01')) {
    os_wake_check_context_switch();
    return;
  }
  return;
}


/* ROM address: 0x00003954; body bytes: 10; decompiled */

undefined4 FUN_00003954(undefined2 *param_1)

{
  *param_1 = os_scheduled_count_ffff763c;
  return 0;
}


/* ROM address: 0x00003964; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003964 (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00003964(undefined1 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)&os_ready_bitmap_ffff7668;
  uVar3 = 0;
  *param_1 = 0xff;
  *(undefined2 *)(param_1 + 6) = 0xffff;
  *(undefined **)(param_1 + 0x20) = (&PTR_DAT_00004aec)[(char)param_1[1]];
  *(undefined **)(param_1 + 0x24) = &os_ready_ring_ffff74a0;
  do {
    *puVar1 = 0;
    uVar3 = uVar3 + 2;
    puVar1[1] = 0;
    puVar1 = puVar1 + 2;
  } while (uVar3 < 4);
  iVar4 = 0;
  iVar2 = *(int *)(param_1 + 0x20);
  do {
    puVar1 = (undefined4 *)(iVar2 + 4);
    iVar2 = iVar2 + 8;
    if ((undefined2 *)*puVar1 != (undefined2 *)0x0) {
      *(undefined2 *)*puVar1 = 0xffff;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 5);
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * os_mark_task_ready [high]: Appends task id to ready ring at ctrl+0x24 (0xffff74a0)[tail], sets class bitmap 0xffff7668 (bit tbl 0x3d48[class&7] in byte class>>3), and if class > ctrl[0] (cmp/hi, unsigned) sets ctrl[0]=class, ctrl+6=task (disasm 0x39f6-0x3a00). Dynamic: bitmap 0x11000000 -> 0x15000000 on post to slot 2 (class 2).
 * RAM 0xffff7668 os_ready_bitmap (uint32): 0x39ba sets bit tbl 0x3d48[class&7] in byte (class>>3); after boot 0x11000000 (classes 0 and 4 = init tasks {0,17}); after post to queue slot 2 observed 0x15000000 (class 2 added).
 * RAM 0xffff74a0 os_ready_ring (uint16[]): ctrl+0x24 (0xffff765c) points here; 0x39ba appends the task id at ring[tail] when marking ready.
 */
/* ROM address: 0x000039ba; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000039ba (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 os_mark_task_ready(char *param_1,undefined2 param_2,uint param_3)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  
  psVar2 = (short *)(param_3 * 8 + *(int *)(param_1 + 0x20));
  psVar3 = *(short **)(psVar2 + 2);
  if (*psVar3 == -1) {
    psVar3[1] = *psVar2;
    *psVar3 = *psVar2;
    (&os_ready_bitmap_ffff7668)[(int)param_3 >> 3] =
         (&os_ready_bitmap_ffff7668)[(int)param_3 >> 3] | (&tbl_os_class_bit_00003d48)[param_3 & 7];
    *(undefined2 *)(*(int *)(param_1 + 0x24) + psVar3[1] * 2) = param_2;
    if ((int)*param_1 < (int)param_3) {
      *param_1 = (char)param_3;
      *(undefined2 *)(param_1 + 6) = param_2;
      return 1;
    }
  }
  else {
    if (psVar3[1] == psVar2[1]) {
      sVar1 = *psVar2;
    }
    else {
      sVar1 = psVar3[1] + 1;
    }
    psVar3[1] = sVar1;
    *(undefined2 *)(*(int *)(param_1 + 0x24) + psVar3[1] * 2) = param_2;
  }
  return 0;
}


/* ROM address: 0x00003a28; body bytes: 124; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003a28 (124 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_consistencyCheck(char *param_1,char param_2)

{
  short *psVar1;
  short *psVar2;
  uint uVar3;
  
  psVar2 = (short *)(param_2 * 8 + *(int *)(param_1 + 0x20));
  psVar1 = *(short **)(psVar2 + 2);
  uVar3 = (uint)param_2;
  if (*psVar1 == psVar1[1]) {
    *psVar1 = -1;
    (&os_ready_bitmap_ffff7668)[(int)uVar3 >> 3] = (&os_ready_bitmap_ffff7668)[(int)uVar3 >> 3] & (&DAT_00003d50)[uVar3 & 7]
    ;
    if (uVar3 != (int)*param_1) {
      return 0;
    }
    FUN_00003c80();
  }
  else {
    if (*psVar1 == psVar2[1]) {
      *psVar1 = *psVar2;
    }
    else {
      *psVar1 = *psVar1 + 1;
    }
    if (uVar3 != (int)*param_1) {
      return 0;
    }
    *(undefined2 *)(param_1 + 6) = *(undefined2 *)(&os_ready_ring_ffff74a0 + *psVar1 * 2);
  }
  return 1;
}


/* ROM address: 0x00003ac0; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003ac0 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00003ac0(int param_1)

{
  DAT_ffff7678 = (&PTR_DAT_00004b24)[*(char *)(param_1 + 1)];
  return;
}


/* ROM address: 0x00003ad8; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003ad8 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00003ad8(char param_1)

{
  undefined4 uVar1;
  uint in_sr;
  undefined1 local_8 [4];
  uint local_4;
  
  local_4 = in_sr & 0xfffffffe | (uint)(param_1 != '\0');
  if ((param_1 != '\0') != 0) {
    return 0;
  }
  DAT_ffff7660 = local_8;
  os_state_flags_ffff7640 = 0x100;
  uVar1 = os_init();
  return uVar1;
}


/* [ADDITIONAL SOURCE REVIEW]
 * os_context_switch [high]: Saves ctx ptr to ctrl+0xc, writes state 4, calls os_dispatch_next_task (0x3c68); called from 0x3db0 (ISR-exit wake) and 0x3854.
 */
/* ROM address: 0x00003bf4; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003bf4 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

void os_context_switch(int param_1,undefined4 param_2,char *param_3)

{
  undefined1 *puVar1;
  undefined1 local_44 [16];
  undefined1 local_34 [4];
  
  puVar1 = local_34;
  if (*param_3 == '\x04') {
    puVar1 = local_44;
  }
  **(undefined1 **)(param_3 + 4) = 4;
  *(undefined1 **)(param_1 + 0xc) = puVar1;
  os_dispatch_next_task();
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * os_dispatch [high]: If ctrl+6 (0xffff763e) != -1 then 0x3c68 runs a task; else inits ctrl block (0x80000000, 0xffff, task table 0x4990) and enters idle loop 0x3dac. Emulator: harness.call(0x3c2a, stop_at=0x3dac) reaches idle.
 */
/* ROM address: 0x00003c2a; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003c2a (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void os_dispatch(int param_1)

{
  if (*(short *)(param_1 + 6) != -1) {
    os_dispatch_next_task();
    return;
  }
  *(undefined4 *)(param_1 + 8) = 0x80000000;
  *(undefined2 *)(param_1 + 4) = 0xffff;
  *(undefined **)(param_1 + 0x18) = &DAT_00004990;
  *(undefined1 **)(param_1 + 0x14) = &os_task_stack_base_ffff7408;
  FUN_00003dac(param_1,0);
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * os_dispatch_next_task [high]: Tail-calls 0x375c(ctrl, *(short*)(ctrl+6)).
 */
/* ROM address: 0x00003c68; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003c68 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void os_dispatch_next_task(int param_1)

{
  os_switch_to_task(param_1,(int)*(short *)(param_1 + 6));
  return;
}


/* ROM address: 0x00003c80; body bytes: 190; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00003c80(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  char cVar4;
  uint uVar3;
  int iVar5;
  
  if (DAT_ffff7674 == 0) {
    if (DAT_ffff7670 == 0) {
      if (DAT_ffff766c == 0) {
        iVar2 = 0;
        if (_DAT_ffff7668 == 0) {
          *param_1 = 0xff;
          *(undefined2 *)(param_1 + 6) = 0xffff;
          return;
        }
        iVar5 = 0;
      }
      else {
        iVar2 = 4;
        iVar5 = 0x20;
      }
    }
    else {
      iVar2 = 8;
      iVar5 = 0x40;
    }
  }
  else {
    iVar2 = 0xc;
    iVar5 = 0x60;
  }
  puVar1 = &os_ready_bitmap_ffff7668;
  if (*(short *)(&DAT_ffff766a + iVar2) == 0) {
    cVar4 = (&DAT_ffff7669)[iVar2];
  }
  else {
    puVar1 = &DAT_ffff766a;
    iVar5 = iVar5 + 0x10;
    cVar4 = (&DAT_ffff766b)[iVar2];
  }
  if (cVar4 == '\0') {
    cVar4 = puVar1[iVar2];
  }
  else {
    iVar5 = iVar5 + 8;
    cVar4 = (puVar1 + iVar2)[1];
  }
  uVar3 = (uint)cVar4;
  if ((uVar3 & 0x80) == 0) {
    if ((uVar3 & 0x40) == 0) {
      if ((uVar3 & 0x20) == 0) {
        if ((uVar3 & 0x10) == 0) {
          if ((uVar3 & 8) == 0) {
            if ((uVar3 & 4) == 0) {
              if ((uVar3 & 2) != 0) {
                iVar5 = iVar5 + 1;
              }
            }
            else {
              iVar5 = iVar5 + 2;
            }
          }
          else {
            iVar5 = iVar5 + 3;
          }
        }
        else {
          iVar5 = iVar5 + 4;
        }
      }
      else {
        iVar5 = iVar5 + 5;
      }
    }
    else {
      iVar5 = iVar5 + 6;
    }
  }
  else {
    iVar5 = iVar5 + 7;
  }
  *param_1 = (char)iVar5;
  *(undefined2 *)(param_1 + 6) =
       *(undefined2 *)
        (*(int *)(param_1 + 0x24) + **(short **)(*(int *)(param_1 + 0x20) + iVar5 * 8 + 4) * 2);
  return;
}


/* ROM address: 0x00003d58; body bytes: 60; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00003d6a) */
/* Unique exact-byte match to related 60E0FC00 function at 00003d58 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_taskEndRoutine_(void)

{
  undefined1 *puVar1;
  
  puVar1 = os_current_task_record_ptr_ffff764c;
  os_current_task_record_ptr_ffff764c[3] = os_current_task_record_ptr_ffff764c[3] + '\x01';
  os_state_flags_ffff7640 = 0x100;
  ref_consistencyCheck(&os_ctrl_block_ffff7638,(int)(char)puVar1[1]);
  *puVar1 = 0;
  DAT_ffff7644 = *(undefined4 *)(puVar1 + 4);
  os_dispatch(&os_ctrl_block_ffff7638);
  return;
}


/* ROM address: 0x00003dac; body bytes: 4; decompiled_with_warnings */

void FUN_00003dac(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* [ADDITIONAL SOURCE REVIEW]
 * os_wake_check_context_switch [high]: Called from ref_setSR (0x3934, call-site literal 0x3950). If DAT_ffff763c != DAT_ffff763e and (DAT_ffff7640 & 0x1000)==0: sets 0xffff7640=0x100, calls 0x3bf4 (context switch). Task-dispatch wake on ISR exit.
 * RAM 0xffff763c os_scheduled_count (uint16): u16 at ctrl+4; direct mov.l pool 0x3960 in 0x3954; compared with 0xffff763e in os_wake_check_context_switch 0x3db0; initialized to 0xffff by os_init 0x3e10.
 * RAM 0xffff763e os_dispatched_count (uint16): u16 at ctrl+6 (base 0xffff7638 pool-referenced in 0x3db0 via pool 0x3e00); compared with 0xffff763c in the 0x3db0 wake check.
 */
/* ROM address: 0x00003db0; body bytes: 76; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00003ddc) */
/* Unique exact-byte match to related 60E0FC00 function at 00003db0 (76 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 os_wake_check_context_switch(void)

{
  if ((os_scheduled_count_ffff763c != os_dispatched_count_ffff763e) && ((os_state_flags_ffff7640 & 0x1000) == 0)) {
    os_state_flags_ffff7640 = 0x100;
    os_context_switch(&os_ctrl_block_ffff7638);
  }
  return 0;
}


/* [ADDITIONAL SOURCE REVIEW]
 * os_init [high]: Called via literal at 0x9f38 during boot. Sets DAT_ffff7648=0xb0, task table ptr DAT_ffff7650=&DAT_00004990, current task DAT_ffff764c=&DAT_ffff7408, then calls dispatcher 0x3c2a. Emulator boot trace passes through it before reaching idle 0x3dac.
 * RAM 0xffff764c os_current_task_record_ptr (ptr): ptr at ctrl+0x14 (base 0xffff7638); os_init 0x3e10 stores &DAT_ffff7408 into it; os_switch_to_task 0x375c stores task record 0x4990+idx*0x10 at ctrl+0x18.
 * RAM 0xffff7650 os_task_table_ptr (ptr): ptr at ctrl+0x18 (base 0xffff7638); os_init 0x3e10 stores &DAT_00004990 (task record base, pool refs in 0x375c/0x3854/0x3c2a/0x3e10/0x3ec0).
 * RAM 0xffff7408 os_task_stack_base (ptr): task stack base; raw u32 0xffff7408 at ROM 0x4938 and 0x4994 (stack field of task record 0x4990); stored to ctrl+0x14 and DAT_ffff7644 by os_init 0x3e10.
 */
/* ROM address: 0x00003e10; body bytes: 110; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00003e6a) */
/* Unique exact-byte match to related 60E0FC00 function at 00003e10 (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

void os_init(undefined1 param_1)

{
  DAT_ffff7648 = 0xb0;
  DAT_ffff7644 = &os_task_stack_base_ffff7408;
  os_scheduled_count_ffff763c = 0xffff;
  os_task_table_ptr_ffff7650 = &DAT_00004990;
  os_current_task_record_ptr_ffff764c = &os_task_stack_base_ffff7408;
  DAT_ffff7639 = param_1;
  FUN_00003964(&os_ctrl_block_ffff7638);
  FUN_00003ec0(&os_ctrl_block_ffff7638);
  FUN_00003f10(&os_ctrl_block_ffff7638);
  FUN_00003ac0(&os_ctrl_block_ffff7638);
  FUN_00003f8c();
  FUN_00003f88();
  FUN_00003f90(&os_ctrl_block_ffff7638);
  FUN_00003f9c(&os_ctrl_block_ffff7638);
  FUN_00003fa8();
  os_dispatch(&os_ctrl_block_ffff7638);
  return;
}


/* ROM address: 0x00003ec0; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003ec0 (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00003ec0(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar3 = &DAT_00004990;
  do {
    iVar1 = FUN_00003fb0(iVar4);
    if (iVar1 == 0) {
      puVar2 = *(undefined1 **)(puVar3 + 4);
      puVar2[2] = 0xff;
      *puVar2 = 0;
      puVar2[3] = puVar3[0xc];
    }
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 0x10;
  } while ((short)iVar4 < 0x13);
  return;
}


/* ROM address: 0x00003f10; body bytes: 94; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003f10 (94 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00003f10(int param_1)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  
  psVar2 = (short *)(&PTR_DAT_00004af4)[*(char *)(param_1 + 1)];
  for (iVar3 = (int)*(short *)(&DAT_00004af8 + *(char *)(param_1 + 1) * 2); 0 < iVar3;
      iVar3 = iVar3 + -1) {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
    (&PTR_DAT_00004994)[sVar1 * 4][3] = (&PTR_DAT_00004994)[sVar1 * 4][3] + -1;
    os_mark_task_ready(param_1,(int)sVar1,(int)(char)(&DAT_00004992)[sVar1 * 0x10]);
  }
  return;
}


/* ROM address: 0x00003f88; body bytes: 4; decompiled */

void FUN_00003f88(void)

{
  return;
}


/* ROM address: 0x00003f8c; body bytes: 4; decompiled */

void FUN_00003f8c(void)

{
  return;
}


/* ROM address: 0x00003f90; body bytes: 8; decompiled */

void FUN_00003f90(void)

{
  DAT_ffff7664 = 0;
  return;
}


/* ROM address: 0x00003f9c; body bytes: 8; decompiled */

void FUN_00003f9c(void)

{
  DAT_ffff7665 = 0;
  return;
}


/* ROM address: 0x00003fa8; body bytes: 4; decompiled */

void FUN_00003fa8(void)

{
  return;
}


/* ROM address: 0x00003fb0; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003fb0 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00003fb0(short param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((0x12 < param_1) ||
     ((*(uint *)(&DAT_00004b44 + DAT_ffff7639 * 4) & *(uint *)(&DAT_00004940 + param_1 * 4)) == 0))
  {
    uVar1 = 3;
  }
  return uVar1;
}


/* ROM address: 0x00003fe8; body bytes: 170; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003fe8 (170 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00003fe8(void)

{
  bool bVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  int in_r0;
  int in_r1;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar11;
  uint uVar12;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar10;
  uint uVar13;
  
  if (in_r0 != 0) {
    uVar6 = -(uint)(in_r1 < 0);
    uVar7 = in_r1 - (uint)(uVar6 != 0);
    bVar1 = in_r0 < 0;
    uVar2 = (uint)bVar1 << 9;
    uVar12 = uVar7 * 2;
    uVar7 = (uint)(in_r1 < 0) * -2 | (uint)((uVar7 & 0x80000000) != 0);
    bVar4 = (int)uVar6 < 0 == bVar1;
    bVar5 = bVar1 == ((uVar6 & 0x80000000) != 0);
    uVar8 = (uint)bVar4 * (uVar7 - in_r0) + (uint)!bVar4 * (uVar7 + in_r0);
    cVar3 = bVar4 * (uVar7 < uVar8) + !bVar4 * (uVar8 < uVar7);
    uVar7 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar13 = uVar2 | uVar7;
    uVar9 = uVar8 * 2 | (uint)((uVar12 & 0x80000000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar8 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar9 - in_r0) + (uint)!bVar4 * (uVar9 + in_r0);
    cVar3 = bVar4 * (uVar9 < uVar10) + !bVar4 * (uVar10 < uVar9);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar14 = uVar2 | uVar7 & 0xfffffeff | uVar13;
    uVar9 = uVar2 | uVar7 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x40000000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar15 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x20000000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar16 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x10000000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar17 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x8000000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar18 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x4000000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar19 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x2000000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar20 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x1000000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar21 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x800000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar22 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x400000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar23 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x200000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar24 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x100000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar25 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x80000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar26 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x40000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar27 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x20000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar28 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x10000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar29 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x8000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar30 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x4000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar31 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x2000) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar32 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x1000) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar33 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x800) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar34 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x400) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar35 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x200) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar36 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x100) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar37 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x80) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar38 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x40) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar39 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x20) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar40 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 0x10) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar41 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 8) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar13 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar42 = uVar9 | uVar8 & 0xfffffeff | uVar13;
    uVar9 = uVar9 | uVar8 & 0xfffffefe;
    uVar8 = uVar9 | uVar13;
    uVar11 = uVar10 * 2 | (uint)((uVar12 & 4) != 0);
    bVar4 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar10 = (uint)bVar4 * (uVar11 - in_r0) + (uint)!bVar4 * (uVar11 + in_r0);
    cVar3 = bVar4 * (uVar11 < uVar10) + !bVar4 * (uVar10 < uVar11);
    uVar8 = (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    uVar11 = uVar9 | uVar13 & 0xfffffeff | uVar8;
    uVar9 = uVar9 | uVar13 & 0xfffffefe;
    uVar13 = uVar9 | uVar8;
    uVar12 = uVar10 * 2 | (uint)((uVar12 & 2) != 0);
    bVar4 = ((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1);
    bVar5 = (bool)((byte)(uVar13 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar13 = (uint)bVar4 * (uVar12 - in_r0) + (uint)!bVar4 * (uVar12 + in_r0);
    cVar3 = bVar4 * (uVar12 < uVar13) + !bVar4 * (uVar13 < uVar12);
    uVar13 = uVar9 | uVar8 & 0xfffffeff |
             (uint)(byte)(bVar5 * cVar3 + (!bVar5 && cVar3 == '\0')) << 8;
    return ((((((((((((((((((((((((((((((((uint)(((byte)((uVar2 | uVar7) >> 8) & 1) ==
                                                ((byte)((uVar2 | uVar7) >> 9) & 1)) << 1 |
                                         (uint)(((byte)(uVar14 >> 8) & 1) ==
                                               ((byte)(uVar14 >> 9) & 1))) << 1 |
                                        (uint)(((byte)(uVar15 >> 8) & 1) ==
                                              ((byte)(uVar15 >> 9) & 1))) << 1 |
                                       (uint)(((byte)(uVar16 >> 8) & 1) == ((byte)(uVar16 >> 9) & 1)
                                             )) << 1 |
                                      (uint)(((byte)(uVar17 >> 8) & 1) == ((byte)(uVar17 >> 9) & 1))
                                      ) << 1 | (uint)(((byte)(uVar18 >> 8) & 1) ==
                                                     ((byte)(uVar18 >> 9) & 1))) << 1 |
                                    (uint)(((byte)(uVar19 >> 8) & 1) == ((byte)(uVar19 >> 9) & 1)))
                                    << 1 | (uint)(((byte)(uVar20 >> 8) & 1) ==
                                                 ((byte)(uVar20 >> 9) & 1))) << 1 |
                                  (uint)(((byte)(uVar21 >> 8) & 1) == ((byte)(uVar21 >> 9) & 1))) <<
                                  1 | (uint)(((byte)(uVar22 >> 8) & 1) == ((byte)(uVar22 >> 9) & 1))
                                 ) << 1 | (uint)(((byte)(uVar23 >> 8) & 1) ==
                                                ((byte)(uVar23 >> 9) & 1))) << 1 |
                               (uint)(((byte)(uVar24 >> 8) & 1) == ((byte)(uVar24 >> 9) & 1))) << 1
                              | (uint)(((byte)(uVar25 >> 8) & 1) == ((byte)(uVar25 >> 9) & 1))) << 1
                             | (uint)(((byte)(uVar26 >> 8) & 1) == ((byte)(uVar26 >> 9) & 1))) << 1
                            | (uint)(((byte)(uVar27 >> 8) & 1) == ((byte)(uVar27 >> 9) & 1))) << 1 |
                           (uint)(((byte)(uVar28 >> 8) & 1) == ((byte)(uVar28 >> 9) & 1))) << 1 |
                          (uint)(((byte)(uVar29 >> 8) & 1) == ((byte)(uVar29 >> 9) & 1))) << 1 |
                         (uint)(((byte)(uVar30 >> 8) & 1) == ((byte)(uVar30 >> 9) & 1))) << 1 |
                        (uint)(((byte)(uVar31 >> 8) & 1) == ((byte)(uVar31 >> 9) & 1))) << 1 |
                       (uint)(((byte)(uVar32 >> 8) & 1) == ((byte)(uVar32 >> 9) & 1))) << 1 |
                      (uint)(((byte)(uVar33 >> 8) & 1) == ((byte)(uVar33 >> 9) & 1))) << 1 |
                     (uint)(((byte)(uVar34 >> 8) & 1) == ((byte)(uVar34 >> 9) & 1))) << 1 |
                    (uint)(((byte)(uVar35 >> 8) & 1) == ((byte)(uVar35 >> 9) & 1))) << 1 |
                   (uint)(((byte)(uVar36 >> 8) & 1) == ((byte)(uVar36 >> 9) & 1))) << 1 |
                  (uint)(((byte)(uVar37 >> 8) & 1) == ((byte)(uVar37 >> 9) & 1))) << 1 |
                 (uint)(((byte)(uVar38 >> 8) & 1) == ((byte)(uVar38 >> 9) & 1))) << 1 |
                (uint)(((byte)(uVar39 >> 8) & 1) == ((byte)(uVar39 >> 9) & 1))) << 1 |
               (uint)(((byte)(uVar40 >> 8) & 1) == ((byte)(uVar40 >> 9) & 1))) << 1 |
              (uint)(((byte)(uVar41 >> 8) & 1) == ((byte)(uVar41 >> 9) & 1))) << 1 |
             (uint)(((byte)(uVar42 >> 8) & 1) == ((byte)(uVar42 >> 9) & 1))) << 1 |
            (uint)(((byte)(uVar11 >> 8) & 1) == ((byte)(uVar11 >> 9) & 1))) << 1 |
           (uint)(((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1))) +
           (uint)(bVar1 != (int)uVar6 < 0);
  }
  DAT_ffff768c = 0x44e;
  return 0;
}


/* ROM address: 0x0000409c; body bytes: 158; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000409c (158 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0000409c(void)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  uint uVar6;
  int in_r0;
  uint in_r1;
  uint uVar7;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar8;
  
  if (in_r0 != 0) {
    uVar7 = (uint)((in_r1 & 0x80000000) != 0);
    uVar8 = uVar7 - in_r0;
    bVar4 = uVar8 <= uVar7;
    uVar11 = in_r1 << 2;
    bVar3 = (uVar8 & 0x80000000) == 0;
    uVar7 = uVar8 * 2 | (uint)((in_r1 & 0x40000000) != 0);
    uVar8 = (uint)bVar4 * (uVar7 - in_r0) + (uint)!bVar4 * (uVar7 + in_r0);
    cVar1 = bVar4 * (uVar7 < uVar8) + !bVar4 * (uVar8 < uVar7);
    bVar5 = bVar3 * cVar1 + (!bVar3 && cVar1 == '\0');
    uVar7 = uVar8 * 2 | (uint)((uVar11 & 0x80000000) != 0);
    bVar3 = (bVar5 & 1) == (bVar5 >> 1 & 1);
    bVar2 = (bool)(bVar5 >> 1 & 1) == ((uVar8 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar7 - in_r0) + (uint)!bVar3 * (uVar7 + in_r0);
    cVar1 = bVar3 * (uVar7 < uVar9) + !bVar3 * (uVar9 < uVar7);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar12 = (uint)bVar5 << 8 & 0xfffffeff | uVar7;
    uVar6 = (uint)bVar5 << 8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x40000000) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar13 = uVar6 | uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar7 & 0xfffffefe;
    uVar7 = uVar6 | uVar8;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x20000000) != 0);
    bVar3 = ((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar14 = uVar6 | uVar8 & 0xfffffeff | uVar7;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x10000000) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar15 = uVar6 | uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar7 & 0xfffffefe;
    uVar7 = uVar6 | uVar8;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x8000000) != 0);
    bVar3 = ((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar16 = uVar6 | uVar8 & 0xfffffeff | uVar7;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x4000000) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar17 = uVar6 | uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar7 & 0xfffffefe;
    uVar7 = uVar6 | uVar8;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x2000000) != 0);
    bVar3 = ((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar18 = uVar6 | uVar8 & 0xfffffeff | uVar7;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x1000000) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar19 = uVar6 | uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar7 & 0xfffffefe;
    uVar7 = uVar6 | uVar8;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x800000) != 0);
    bVar3 = ((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar20 = uVar6 | uVar8 & 0xfffffeff | uVar7;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x400000) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar21 = uVar6 | uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar7 & 0xfffffefe;
    uVar7 = uVar6 | uVar8;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x200000) != 0);
    bVar3 = ((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar22 = uVar6 | uVar8 & 0xfffffeff | uVar7;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x100000) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar23 = uVar6 | uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar7 & 0xfffffefe;
    uVar7 = uVar6 | uVar8;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x80000) != 0);
    bVar3 = ((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar24 = uVar6 | uVar8 & 0xfffffeff | uVar7;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x40000) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar25 = uVar6 | uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar7 & 0xfffffefe;
    uVar7 = uVar6 | uVar8;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x20000) != 0);
    bVar3 = ((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar26 = uVar6 | uVar8 & 0xfffffeff | uVar7;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x10000) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar27 = uVar6 | uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar7 & 0xfffffefe;
    uVar7 = uVar6 | uVar8;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x8000) != 0);
    bVar3 = ((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar28 = uVar6 | uVar8 & 0xfffffeff | uVar7;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x4000) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar29 = uVar6 | uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar7 & 0xfffffefe;
    uVar7 = uVar6 | uVar8;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x2000) != 0);
    bVar3 = ((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar30 = uVar6 | uVar8 & 0xfffffeff | uVar7;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x1000) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar31 = uVar6 | uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar7 & 0xfffffefe;
    uVar7 = uVar6 | uVar8;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x800) != 0);
    bVar3 = ((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar32 = uVar6 | uVar8 & 0xfffffeff | uVar7;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x400) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar33 = uVar6 | uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar7 & 0xfffffefe;
    uVar7 = uVar6 | uVar8;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x200) != 0);
    bVar3 = ((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar34 = uVar6 | uVar8 & 0xfffffeff | uVar7;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x100) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar35 = uVar6 | uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar7 & 0xfffffefe;
    uVar7 = uVar6 | uVar8;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x80) != 0);
    bVar3 = ((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar36 = uVar6 | uVar8 & 0xfffffeff | uVar7;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x40) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar37 = uVar6 | uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar7 & 0xfffffefe;
    uVar7 = uVar6 | uVar8;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x20) != 0);
    bVar3 = ((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar38 = uVar6 | uVar8 & 0xfffffeff | uVar7;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 0x10) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar8 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar39 = uVar6 | uVar7 & 0xfffffeff | uVar8;
    uVar6 = uVar6 | uVar7 & 0xfffffefe;
    uVar7 = uVar6 | uVar8;
    uVar10 = uVar9 * 2 | (uint)((uVar11 & 8) != 0);
    bVar3 = ((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar7 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar9 = (uint)bVar3 * (uVar10 - in_r0) + (uint)!bVar3 * (uVar10 + in_r0);
    cVar1 = bVar3 * (uVar10 < uVar9) + !bVar3 * (uVar9 < uVar10);
    uVar7 = (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    uVar10 = uVar6 | uVar8 & 0xfffffeff | uVar7;
    uVar6 = uVar6 | uVar8 & 0xfffffefe;
    uVar8 = uVar6 | uVar7;
    uVar11 = uVar9 * 2 | (uint)((uVar11 & 4) != 0);
    bVar3 = ((byte)(uVar8 >> 8) & 1) == ((byte)(uVar8 >> 9) & 1);
    bVar2 = (bool)((byte)(uVar8 >> 9) & 1) == ((uVar9 & 0x80000000) != 0);
    uVar8 = (uint)bVar3 * (uVar11 - in_r0) + (uint)!bVar3 * (uVar11 + in_r0);
    cVar1 = bVar3 * (uVar11 < uVar8) + !bVar3 * (uVar8 < uVar11);
    uVar7 = uVar6 | uVar7 & 0xfffffeff |
            (uint)(byte)(bVar2 * cVar1 + (!bVar2 && cVar1 == '\0')) << 8;
    return (((((((((((((((((((((((((((((((uint)bVar4 << 1 | (uint)((bVar5 & 1) == (bVar5 >> 1 & 1)))
                                        << 1 | (uint)(((byte)(uVar12 >> 8) & 1) ==
                                                     ((byte)(uVar12 >> 9) & 1))) << 1 |
                                      (uint)(((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1))
                                      ) << 1 | (uint)(((byte)(uVar14 >> 8) & 1) ==
                                                     ((byte)(uVar14 >> 9) & 1))) << 1 |
                                    (uint)(((byte)(uVar15 >> 8) & 1) == ((byte)(uVar15 >> 9) & 1)))
                                    << 1 | (uint)(((byte)(uVar16 >> 8) & 1) ==
                                                 ((byte)(uVar16 >> 9) & 1))) << 1 |
                                  (uint)(((byte)(uVar17 >> 8) & 1) == ((byte)(uVar17 >> 9) & 1))) <<
                                  1 | (uint)(((byte)(uVar18 >> 8) & 1) == ((byte)(uVar18 >> 9) & 1))
                                 ) << 1 | (uint)(((byte)(uVar19 >> 8) & 1) ==
                                                ((byte)(uVar19 >> 9) & 1))) << 1 |
                               (uint)(((byte)(uVar20 >> 8) & 1) == ((byte)(uVar20 >> 9) & 1))) << 1
                              | (uint)(((byte)(uVar21 >> 8) & 1) == ((byte)(uVar21 >> 9) & 1))) << 1
                             | (uint)(((byte)(uVar22 >> 8) & 1) == ((byte)(uVar22 >> 9) & 1))) << 1
                            | (uint)(((byte)(uVar23 >> 8) & 1) == ((byte)(uVar23 >> 9) & 1))) << 1 |
                           (uint)(((byte)(uVar24 >> 8) & 1) == ((byte)(uVar24 >> 9) & 1))) << 1 |
                          (uint)(((byte)(uVar25 >> 8) & 1) == ((byte)(uVar25 >> 9) & 1))) << 1 |
                         (uint)(((byte)(uVar26 >> 8) & 1) == ((byte)(uVar26 >> 9) & 1))) << 1 |
                        (uint)(((byte)(uVar27 >> 8) & 1) == ((byte)(uVar27 >> 9) & 1))) << 1 |
                       (uint)(((byte)(uVar28 >> 8) & 1) == ((byte)(uVar28 >> 9) & 1))) << 1 |
                      (uint)(((byte)(uVar29 >> 8) & 1) == ((byte)(uVar29 >> 9) & 1))) << 1 |
                     (uint)(((byte)(uVar30 >> 8) & 1) == ((byte)(uVar30 >> 9) & 1))) << 1 |
                    (uint)(((byte)(uVar31 >> 8) & 1) == ((byte)(uVar31 >> 9) & 1))) << 1 |
                   (uint)(((byte)(uVar32 >> 8) & 1) == ((byte)(uVar32 >> 9) & 1))) << 1 |
                  (uint)(((byte)(uVar33 >> 8) & 1) == ((byte)(uVar33 >> 9) & 1))) << 1 |
                 (uint)(((byte)(uVar34 >> 8) & 1) == ((byte)(uVar34 >> 9) & 1))) << 1 |
                (uint)(((byte)(uVar35 >> 8) & 1) == ((byte)(uVar35 >> 9) & 1))) << 1 |
               (uint)(((byte)(uVar36 >> 8) & 1) == ((byte)(uVar36 >> 9) & 1))) << 1 |
              (uint)(((byte)(uVar37 >> 8) & 1) == ((byte)(uVar37 >> 9) & 1))) << 1 |
             (uint)(((byte)(uVar38 >> 8) & 1) == ((byte)(uVar38 >> 9) & 1))) << 1 |
            (uint)(((byte)(uVar39 >> 8) & 1) == ((byte)(uVar39 >> 9) & 1))) << 1 |
           (uint)(((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1))) << 1 |
           (uint)(((byte)(uVar7 >> 8) & 1) == ((byte)(uVar7 >> 9) & 1));
  }
  DAT_ffff768c = 0x44e;
  return 0;
}


/* ROM address: 0x00004144; body bytes: 190; decompiled */

undefined8 FUN_00004144(void)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  uint uVar8;
  int in_r0;
  int in_r1;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar12;
  
  if (in_r0 != 0) {
    bVar1 = in_r1 < 0;
    uVar8 = -(uint)bVar1;
    uVar9 = in_r1 - (uint)(uVar8 != 0);
    bVar2 = in_r0 < 0;
    uVar3 = (uint)bVar2 << 9;
    uVar7 = uVar9 * 2;
    uVar9 = (uint)bVar1 * -2 | (uint)((uVar9 & 0x80000000) != 0);
    bVar5 = (int)uVar8 < 0 == bVar2;
    bVar6 = bVar2 == ((uVar8 & 0x80000000) != 0);
    uVar10 = (uint)bVar5 * (uVar9 - in_r0) + (uint)!bVar5 * (uVar9 + in_r0);
    cVar4 = bVar5 * (uVar9 < uVar10) + !bVar5 * (uVar10 < uVar9);
    uVar9 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar14 = uVar3 | uVar9;
    uVar11 = uVar10 * 2 | (uint)((uVar7 & 0x80000000) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar10 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar11 - in_r0) + (uint)!bVar5 * (uVar11 + in_r0);
    cVar4 = bVar5 * (uVar11 < uVar12) + !bVar5 * (uVar12 < uVar11);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar15 = uVar3 | uVar9 & 0xfffffeff | uVar14;
    uVar11 = uVar3 | uVar9 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x40000000) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar16 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar11 = uVar11 | uVar14 & 0xfffffefe;
    uVar14 = uVar11 | uVar10;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x20000000) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar17 = uVar11 | uVar10 & 0xfffffeff | uVar14;
    uVar11 = uVar11 | uVar10 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x10000000) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar18 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar11 = uVar11 | uVar14 & 0xfffffefe;
    uVar14 = uVar11 | uVar10;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x8000000) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar19 = uVar11 | uVar10 & 0xfffffeff | uVar14;
    uVar11 = uVar11 | uVar10 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x4000000) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar20 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar11 = uVar11 | uVar14 & 0xfffffefe;
    uVar14 = uVar11 | uVar10;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x2000000) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar21 = uVar11 | uVar10 & 0xfffffeff | uVar14;
    uVar11 = uVar11 | uVar10 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x1000000) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar22 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar11 = uVar11 | uVar14 & 0xfffffefe;
    uVar14 = uVar11 | uVar10;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x800000) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar23 = uVar11 | uVar10 & 0xfffffeff | uVar14;
    uVar11 = uVar11 | uVar10 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x400000) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar24 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar11 = uVar11 | uVar14 & 0xfffffefe;
    uVar14 = uVar11 | uVar10;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x200000) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar25 = uVar11 | uVar10 & 0xfffffeff | uVar14;
    uVar11 = uVar11 | uVar10 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x100000) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar26 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar11 = uVar11 | uVar14 & 0xfffffefe;
    uVar14 = uVar11 | uVar10;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x80000) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar27 = uVar11 | uVar10 & 0xfffffeff | uVar14;
    uVar11 = uVar11 | uVar10 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x40000) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar28 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar11 = uVar11 | uVar14 & 0xfffffefe;
    uVar14 = uVar11 | uVar10;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x20000) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar29 = uVar11 | uVar10 & 0xfffffeff | uVar14;
    uVar11 = uVar11 | uVar10 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x10000) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar30 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar11 = uVar11 | uVar14 & 0xfffffefe;
    uVar14 = uVar11 | uVar10;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x8000) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar31 = uVar11 | uVar10 & 0xfffffeff | uVar14;
    uVar11 = uVar11 | uVar10 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x4000) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar32 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar11 = uVar11 | uVar14 & 0xfffffefe;
    uVar14 = uVar11 | uVar10;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x2000) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar33 = uVar11 | uVar10 & 0xfffffeff | uVar14;
    uVar11 = uVar11 | uVar10 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x1000) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar34 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar11 = uVar11 | uVar14 & 0xfffffefe;
    uVar14 = uVar11 | uVar10;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x800) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar35 = uVar11 | uVar10 & 0xfffffeff | uVar14;
    uVar11 = uVar11 | uVar10 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x400) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar36 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar11 = uVar11 | uVar14 & 0xfffffefe;
    uVar14 = uVar11 | uVar10;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x200) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar37 = uVar11 | uVar10 & 0xfffffeff | uVar14;
    uVar11 = uVar11 | uVar10 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x100) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar38 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar11 = uVar11 | uVar14 & 0xfffffefe;
    uVar14 = uVar11 | uVar10;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x80) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar39 = uVar11 | uVar10 & 0xfffffeff | uVar14;
    uVar11 = uVar11 | uVar10 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x40) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar40 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar11 = uVar11 | uVar14 & 0xfffffefe;
    uVar14 = uVar11 | uVar10;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x20) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar41 = uVar11 | uVar10 & 0xfffffeff | uVar14;
    uVar11 = uVar11 | uVar10 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 0x10) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar42 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar11 = uVar11 | uVar14 & 0xfffffefe;
    uVar14 = uVar11 | uVar10;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 8) != 0);
    bVar5 = ((byte)(uVar14 >> 8) & 1) == ((byte)(uVar14 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar14 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar14 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar43 = uVar11 | uVar10 & 0xfffffeff | uVar14;
    uVar11 = uVar11 | uVar10 & 0xfffffefe;
    uVar10 = uVar11 | uVar14;
    uVar13 = uVar12 * 2 | (uint)((uVar7 & 4) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    bVar6 = (bool)((byte)(uVar10 >> 9) & 1) == ((uVar12 & 0x80000000) != 0);
    uVar12 = (uint)bVar5 * (uVar13 - in_r0) + (uint)!bVar5 * (uVar13 + in_r0);
    cVar4 = bVar5 * (uVar13 < uVar12) + !bVar5 * (uVar12 < uVar13);
    uVar10 = (uint)(byte)(bVar6 * cVar4 + (!bVar6 && cVar4 == '\0')) << 8;
    uVar13 = uVar11 | uVar14 & 0xfffffeff | uVar10;
    uVar10 = uVar11 | uVar14 & 0xfffffefe | uVar10;
    uVar14 = uVar12 * 2 | (uint)((uVar7 & 2) != 0);
    bVar5 = ((byte)(uVar10 >> 8) & 1) == ((byte)(uVar10 >> 9) & 1);
    uVar14 = (uint)bVar5 * (uVar14 - in_r0) + (uint)!bVar5 * (uVar14 + in_r0);
    if ((int)uVar14 < 0 != bVar1) {
      uVar10 = ((int)uVar14 >> 1) << 1 | (uint)((uVar14 & 1) == 1);
      bVar5 = (int)uVar14 < 0 == in_r0 < 0;
      uVar14 = (uint)bVar5 * (uVar10 - in_r0) + (uint)!bVar5 * (uVar10 + in_r0);
    }
    return CONCAT44((((((((((((((((((((((((((((((((uint)(bVar2 != (int)uVar8 < 0) << 1 |
                                                 (uint)(((byte)((uVar3 | uVar9) >> 8) & 1) ==
                                                       ((byte)((uVar3 | uVar9) >> 9) & 1))) << 1 |
                                                (uint)(((byte)(uVar15 >> 8) & 1) ==
                                                      ((byte)(uVar15 >> 9) & 1))) << 1 |
                                               (uint)(((byte)(uVar16 >> 8) & 1) ==
                                                     ((byte)(uVar16 >> 9) & 1))) << 1 |
                                              (uint)(((byte)(uVar17 >> 8) & 1) ==
                                                    ((byte)(uVar17 >> 9) & 1))) << 1 |
                                             (uint)(((byte)(uVar18 >> 8) & 1) ==
                                                   ((byte)(uVar18 >> 9) & 1))) << 1 |
                                            (uint)(((byte)(uVar19 >> 8) & 1) ==
                                                  ((byte)(uVar19 >> 9) & 1))) << 1 |
                                           (uint)(((byte)(uVar20 >> 8) & 1) ==
                                                 ((byte)(uVar20 >> 9) & 1))) << 1 |
                                          (uint)(((byte)(uVar21 >> 8) & 1) ==
                                                ((byte)(uVar21 >> 9) & 1))) << 1 |
                                         (uint)(((byte)(uVar22 >> 8) & 1) ==
                                               ((byte)(uVar22 >> 9) & 1))) << 1 |
                                        (uint)(((byte)(uVar23 >> 8) & 1) ==
                                              ((byte)(uVar23 >> 9) & 1))) << 1 |
                                       (uint)(((byte)(uVar24 >> 8) & 1) == ((byte)(uVar24 >> 9) & 1)
                                             )) << 1 |
                                      (uint)(((byte)(uVar25 >> 8) & 1) == ((byte)(uVar25 >> 9) & 1))
                                      ) << 1 | (uint)(((byte)(uVar26 >> 8) & 1) ==
                                                     ((byte)(uVar26 >> 9) & 1))) << 1 |
                                    (uint)(((byte)(uVar27 >> 8) & 1) == ((byte)(uVar27 >> 9) & 1)))
                                    << 1 | (uint)(((byte)(uVar28 >> 8) & 1) ==
                                                 ((byte)(uVar28 >> 9) & 1))) << 1 |
                                  (uint)(((byte)(uVar29 >> 8) & 1) == ((byte)(uVar29 >> 9) & 1))) <<
                                  1 | (uint)(((byte)(uVar30 >> 8) & 1) == ((byte)(uVar30 >> 9) & 1))
                                 ) << 1 | (uint)(((byte)(uVar31 >> 8) & 1) ==
                                                ((byte)(uVar31 >> 9) & 1))) << 1 |
                               (uint)(((byte)(uVar32 >> 8) & 1) == ((byte)(uVar32 >> 9) & 1))) << 1
                              | (uint)(((byte)(uVar33 >> 8) & 1) == ((byte)(uVar33 >> 9) & 1))) << 1
                             | (uint)(((byte)(uVar34 >> 8) & 1) == ((byte)(uVar34 >> 9) & 1))) << 1
                            | (uint)(((byte)(uVar35 >> 8) & 1) == ((byte)(uVar35 >> 9) & 1))) << 1 |
                           (uint)(((byte)(uVar36 >> 8) & 1) == ((byte)(uVar36 >> 9) & 1))) << 1 |
                          (uint)(((byte)(uVar37 >> 8) & 1) == ((byte)(uVar37 >> 9) & 1))) << 1 |
                         (uint)(((byte)(uVar38 >> 8) & 1) == ((byte)(uVar38 >> 9) & 1))) << 1 |
                        (uint)(((byte)(uVar39 >> 8) & 1) == ((byte)(uVar39 >> 9) & 1))) << 1 |
                       (uint)(((byte)(uVar40 >> 8) & 1) == ((byte)(uVar40 >> 9) & 1))) << 1 |
                      (uint)(((byte)(uVar41 >> 8) & 1) == ((byte)(uVar41 >> 9) & 1))) << 1 |
                     (uint)(((byte)(uVar42 >> 8) & 1) == ((byte)(uVar42 >> 9) & 1))) << 1 |
                    (uint)(((byte)(uVar43 >> 8) & 1) == ((byte)(uVar43 >> 9) & 1))) << 1 |
                    (uint)(((byte)(uVar13 >> 8) & 1) == ((byte)(uVar13 >> 9) & 1)),uVar14 + bVar1);
  }
  DAT_ffff768c = 0x44e;
  return 0xffff768c00000000;
}


/* [EXPORT CLEANUP]
 * Indirect jump at 0x4214: target = ROM32[0x426c + r0] (table base constant at
 * 0x4224 = 0x426c). r0 is decremented by 4 before the jump and the delay slot
 * loads the next table word through r2, so consecutive calls walk a chained
 * pointer table. Entry count, terminator and incoming-register ABI are not
 * established.
 */
/* ROM address: 0x0000420c; body bytes: 12; decompiled_with_warnings */

/* Unique exact-byte match to related 60E0FC00 function at 0000420c (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000420c(void)

{
  int in_r0;
  
                    /* WARNING: Could not recover jumptable at 0x00004214. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)&PTR_LAB_0000426c + in_r0))();
  return;
}


/* [EXPORT CLEANUP]
 * Indirect jump at 0x4220: target = ROM32[0x426c + r0] (table base constant at
 * 0x4224 = 0x426c). r0 is decremented by 4 before the jump and the delay slot
 * loads the next table word through r3, so consecutive calls walk a chained
 * pointer table. Entry count, terminator and incoming-register ABI are not
 * established.
 */
/* ROM address: 0x00004218; body bytes: 12; decompiled_with_warnings */

/* Unique exact-byte match to related 60E0FC00 function at 00004218 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004218(void)

{
  int in_r0;
  
                    /* WARNING: Could not recover jumptable at 0x00004220. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)&PTR_LAB_0000426c + in_r0))();
  return;
}


/* [MATH AND UNITS REVIEW]
 * sh_copy_bytes_forward_r0_r1_r2: Assembly ABI: R0=count, R1=destination, R2=source. Forward byte copy unrolled four times; zero count returns. Does not return original destination in R0 (R0 receives byte loads), so not a standard memcpy signature. No overlap-aware backwards path; do not call memmove. Looks like a runtime copy primitive, but compiler/library provenance is unproven.
 */
/* ROM address: 0x000042b0; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000042b0 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

void sh_copy_bytes_forward_r0_r1_r2(void)

{
  int in_r0;
  undefined1 *in_r1;
  undefined1 *in_r2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (in_r0 != 0) {
    puVar2 = in_r2 + in_r0;
    do {
      *in_r1 = *in_r2;
      if (puVar2 <= in_r2 + 1) {
        return;
      }
      in_r1[1] = in_r2[1];
      if (puVar2 <= in_r2 + 2) {
        return;
      }
      puVar1 = in_r2 + 3;
      in_r1[2] = in_r2[2];
      if (puVar2 <= puVar1) {
        return;
      }
      in_r2 = in_r2 + 4;
      in_r1[3] = *puVar1;
      in_r1 = in_r1 + 4;
    } while (in_r2 < puVar2);
  }
  return;
}


/* ROM address: 0x00004308; body bytes: 148; decompiled */

uint FUN_00004308(void)

{
  uint uVar1;
  uint uVar2;
  uint in_r0;
  int in_r1;
  
  if (-1 < in_r1) {
    switch(in_r1) {
    case 0:
      break;
    case 7:
      in_r0 = in_r0 << 1;
    case 6:
      in_r0 = in_r0 << 1;
    case 5:
      in_r0 = in_r0 << 1;
    case 4:
      in_r0 = in_r0 << 1;
    case 3:
      in_r0 = in_r0 << 1;
    case 2:
      in_r0 = in_r0 << 1;
    case 1:
      in_r0 = in_r0 << 1;
      break;
    case 0xf:
      in_r0 = in_r0 << 1;
    case 0xe:
      in_r0 = in_r0 << 1;
    case 0xd:
      in_r0 = in_r0 << 1;
    case 0xc:
      in_r0 = in_r0 << 1;
    case 0xb:
      in_r0 = in_r0 << 1;
    case 10:
      in_r0 = in_r0 << 1;
    case 9:
      in_r0 = in_r0 << 1;
    case 8:
      return in_r0 << 8;
    case 0x17:
      in_r0 = in_r0 << 1;
    case 0x16:
      in_r0 = in_r0 << 1;
    case 0x15:
      in_r0 = in_r0 << 1;
    case 0x14:
      in_r0 = in_r0 << 1;
    case 0x13:
      in_r0 = in_r0 << 1;
    case 0x12:
      in_r0 = in_r0 << 1;
    case 0x11:
      in_r0 = in_r0 << 1;
    case 0x10:
      return in_r0 << 0x10;
    case 0x1b:
      in_r0 = in_r0 << 1;
    case 0x1a:
      in_r0 = in_r0 << 1;
    case 0x19:
      in_r0 = in_r0 << 1;
    case 0x18:
      return in_r0 << 0x18;
    case 0x1c:
      uVar1 = (in_r0 & 0xf) >> 1;
      uVar2 = (uVar1 | in_r0 << 0x1f) >> 1;
      uVar1 = (uVar2 | uVar1 << 0x1f) >> 1;
      return (uVar1 | uVar2 << 0x1f) >> 1 | uVar1 << 0x1f;
    case 0x1d:
      uVar1 = (in_r0 & 7) >> 1;
      uVar2 = (uVar1 | in_r0 << 0x1f) >> 1;
      return (uVar2 | uVar1 << 0x1f) >> 1 | uVar2 << 0x1f;
    case 0x1e:
      return (in_r0 & 1) << 0x1e | ((in_r0 & 3) >> 1) << 0x1f;
    case 0x1f:
      return in_r0 << 0x1f;
    default:
      return 0;
    }
  }
  return in_r0;
}


/* [EXPORT CLEANUP]
 * Jump-table dispatch at 0x43e6 recovered from ROM data. Cases r1 = 0x00-0x1f
 * (range checks at 0x43ca-0x43d2); index byte at ROM[0x43a8 + r1] (32 signed
 * bytes at 0x43a8-0x43c7), target = 0x4446 + (signed)byte. Cases 0x00-0x17 land
 * in a shar r0 sled (ROM 0x4414-0x4440, byte pair 40 21 repeated, ending in
 * rts at 0x4442; the sled lies outside this export's decoded instructions),
 * giving an arithmetic right shift of r0 by r1 (0-23). Cases 0x18-0x1f land
 * in byte/word manipulation stubs at 0x4446-0x44b8. Consistent with a
 * variable-shift helper plus extension operations; stub semantics were not
 * re-derived.
 */
/* ROM address: 0x000043c8; body bytes: 66; decompiled_with_warnings */

uint FUN_000043c8(void)

{
  uint in_r0;
  uint uVar1;
  int in_r1;
  
  if (in_r1 < 0) {
    return in_r0;
  }
  if (0x1f < in_r1) {
    if ((in_r0 & 0x80000000) != 0) {
      return 0xffffffff;
    }
    return 0;
  }
  if (((in_r0 & 0x80000000) == 0) && (8 < in_r1)) {
                    /* WARNING: Could not recover jumptable at 0x000044f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)((undefined *)0x450a + (char)(&switchD_000044f6::switchdataD_000044c0)[in_r1])
            )();
    return uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x000043e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(&LAB_00004446 + (char)(&DAT_000043a8)[in_r1]))();
  return uVar1;
}


/* [EXPORT CLEANUP]
 * Jump-table dispatch at 0x44f6 recovered from ROM data. Cases r1 = 0x00-0x1f
 * (range checks at 0x44e2-0x44ea); index byte at ROM[0x44c0 + r1] (32 signed
 * bytes at 0x44c0-0x44df), target = 0x450a + (signed)byte. All 32 targets
 * (0x450a-0x4576) are decoded instructions forming shlr r0 sleds with periodic
 * rts, giving a logical right shift of r0 by r1 (0-31). Out-of-range r1 >= 0x20
 * is handled by the branch at 0x4504, not the table.
 */
/* ROM address: 0x000044e0; body bytes: 148; decompiled */

uint FUN_000044e0(void)

{
  uint uVar1;
  uint in_r0;
  int in_r1;
  
  if (-1 < in_r1) {
    switch(in_r1) {
    case 0:
      break;
    case 7:
      in_r0 = in_r0 >> 1;
    case 6:
      in_r0 = in_r0 >> 1;
    case 5:
      in_r0 = in_r0 >> 1;
    case 4:
      in_r0 = in_r0 >> 1;
    case 3:
      in_r0 = in_r0 >> 1;
    case 2:
      in_r0 = in_r0 >> 1;
    case 1:
      in_r0 = in_r0 >> 1;
      break;
    case 0xf:
      in_r0 = in_r0 >> 1;
    case 0xe:
      in_r0 = in_r0 >> 1;
    case 0xd:
      in_r0 = in_r0 >> 1;
    case 0xc:
      in_r0 = in_r0 >> 1;
    case 0xb:
      in_r0 = in_r0 >> 1;
    case 10:
      in_r0 = in_r0 >> 1;
    case 9:
      in_r0 = in_r0 >> 1;
    case 8:
      return in_r0 >> 8;
    case 0x17:
      in_r0 = in_r0 >> 1;
    case 0x16:
      in_r0 = in_r0 >> 1;
    case 0x15:
      in_r0 = in_r0 >> 1;
    case 0x14:
      in_r0 = in_r0 >> 1;
    case 0x13:
      in_r0 = in_r0 >> 1;
    case 0x12:
      in_r0 = in_r0 >> 1;
    case 0x11:
      in_r0 = in_r0 >> 1;
    case 0x10:
      return in_r0 >> 0x10;
    case 0x1b:
      in_r0 = in_r0 >> 1;
    case 0x1a:
      in_r0 = in_r0 >> 1;
    case 0x19:
      in_r0 = in_r0 >> 1;
    case 0x18:
      return in_r0 >> 0x18;
    case 0x1c:
      uVar1 = in_r0 << 1;
      return (((uint)((in_r0 & 0x80000000) != 0) << 1 | (uint)((uVar1 & 0x80000000) != 0)) << 1 |
             (uint)((uVar1 & 0x40000000) != 0)) << 1 | (uint)((uVar1 & 0x20000000) != 0);
    case 0x1d:
      return ((uint)((in_r0 & 0x80000000) != 0) << 1 | (uint)((in_r0 << 1 & 0x80000000) != 0)) << 1
             | (uint)((in_r0 << 1 & 0x40000000) != 0);
    case 0x1e:
      return (uint)((in_r0 & 0x80000000) != 0) << 1 | (uint)((in_r0 & 0x40000000) != 0);
    case 0x1f:
      return (uint)((in_r0 & 0x80000000) != 0);
    default:
      return 0;
    }
  }
  return in_r0;
}


/* ROM address: 0x0000467a; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000467a (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_0000467a(void)

{
  int in_r0;
  
  return in_r0 >> 8;
}


/* ROM address: 0x000046cc; body bytes: 88; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000046cc (88 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_checkFloatValidity_(undefined4 param_1)

{
  undefined4 uVar1;
  uint extraout_fr0;
  undefined1 *local_20 [3];
  undefined1 auStack_14 [12];
  undefined4 uStack_8;
  
  local_20[0] = (undefined1 *)local_20;
  uStack_8 = param_1;
  FUN_000048c8();
  local_20[0] = auStack_14;
  FUN_00004740();
  uVar1 = FUN_0000481c();
  if ((extraout_fr0 & 0x7f800000) == 0x7f800000) {
    if ((extraout_fr0 & 0x7fffff) == 0) {
      DAT_ffff768c = 0x44c;
    }
    else {
      uVar1 = 0x44d;
      DAT_ffff768c = 0x44d;
    }
  }
  return uVar1;
}


/* ROM address: 0x00004740; body bytes: 210; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004740 (210 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004740(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint *in_stack_00000000;
  uint in_stack_00000004;
  uint in_stack_00000008;
  
  uVar5 = (uint)(short)in_stack_00000004;
  if ((int)uVar5 < -0x7ffe) {
    uVar6 = (uint)((in_stack_00000004 & 0x80000000) != 0) * -0x80000000 | 0x8001;
    uVar5 = 0;
    goto LAB_000047e8;
  }
  if ((in_stack_00000004 & 0x80000000) == 0) {
    if ((int)uVar5 < 0x7fff) {
      uVar7 = 0;
      uVar3 = 0;
      uVar2 = 0;
      iVar9 = 0x1d;
      uVar6 = uVar5 >> 1;
      if ((uVar5 & 1) == 1) {
        uVar5 = in_stack_00000008 & 0x80000000;
        in_stack_00000008 = in_stack_00000008 << 1;
        uVar7 = (uint)(uVar5 != 0);
      }
      uVar7 = uVar7 << 1 | (uint)((in_stack_00000008 & 0x80000000) != 0);
      uVar5 = in_stack_00000008 << 1;
      do {
        uVar4 = uVar5;
        uVar2 = uVar2 << 1 | 1;
        bVar1 = uVar2 <= uVar7;
        if (bVar1) {
          uVar3 = uVar3 << 1 | (uint)bVar1;
          uVar7 = uVar7 - uVar2;
          uVar2 = uVar2 + 1;
        }
        else {
          uVar2 = uVar2 ^ 1;
          uVar3 = uVar3 << 1 | (uint)bVar1;
        }
        uVar7 = (uVar7 << 1 | (uint)((uVar4 & 0x80000000) != 0)) << 1 |
                (uint)((uVar4 & 0x40000000) != 0);
        iVar9 = iVar9 + -1;
        uVar5 = uVar4 << 2;
      } while (0 < iVar9);
      uVar5 = uVar2 << 1 | 1;
      bVar1 = uVar5 <= uVar7;
      if (bVar1) {
        uVar2 = uVar3 << 1 | (uint)bVar1;
        uVar7 = uVar7 - uVar5;
        uVar5 = uVar5 + 1;
      }
      else {
        uVar5 = uVar5 ^ 1;
        uVar2 = uVar3 << 1 | (uint)bVar1;
      }
      uVar8 = (uVar7 << 1 | (uint)((uVar4 << 2 & 0x80000000) != 0)) << 1 |
              (uint)((uVar4 & 0x10000000) != 0);
      uVar10 = (uint)((uVar7 & 0x80000000) != 0) << 1 | (uint)((uVar7 << 1 & 0x80000000) != 0);
      uVar7 = uVar5 << 1 | 1;
      uVar3 = (uint)((uVar5 & 0x80000000) != 0);
      if ((uVar3 < uVar10) || ((uVar3 <= uVar10 && (uVar7 <= uVar8)))) {
        uVar5 = uVar2 << 1 | 1;
        uVar7 = uVar8 - uVar7;
        uVar2 = uVar7 - ((uVar2 & 0x80000000) != 0);
        uVar10 = (uVar10 - uVar3) - (uint)(uVar8 < uVar7 || uVar7 < uVar2);
        uVar8 = uVar2;
      }
      else {
        uVar5 = uVar2 << 1;
      }
      uVar5 = uVar5 << 1;
      if ((((uVar10 & 0x3fffffff) != 0 || (uVar8 & 0x80000000) != 0) ||
           (uVar8 << 1 & 0x80000000) != 0) ||
         (((uVar8 << 1 & 0x7fffffff) != 0 || (uVar4 & 0x8000000) != 0) || (uVar4 & 0x4000000) != 0))
      {
        uVar5 = uVar5 | 1;
      }
    }
    else {
      if (in_stack_00000008 != 0) goto LAB_0000480c;
      uVar6 = 0x7fff;
      uVar5 = 0;
    }
  }
  else {
LAB_0000480c:
    uVar6 = 0x7fff;
    uVar5 = 0xffffffff;
  }
  uVar6 = uVar6 & 0xffff;
LAB_000047e8:
  *in_stack_00000000 = uVar6;
  in_stack_00000000[1] = uVar5;
  return;
}


/* ROM address: 0x0000481c; body bytes: 82; decompiled */

uint FUN_0000481c(void)

{
  int iVar1;
  uint in_stack_00000000;
  uint in_stack_00000004;
  
  if ((short)in_stack_00000000 < 0x7fff) {
    iVar1 = (short)in_stack_00000000 + 0x7f;
    if (iVar1 < 0xff) {
      if (iVar1 < 1) {
        iVar1 = 0;
        in_stack_00000004 = 0;
      }
      goto LAB_00004880;
    }
  }
  else if (in_stack_00000004 != 0) {
    iVar1 = 0xff;
    in_stack_00000000 = 0;
    in_stack_00000004 = 0x100;
    goto LAB_00004880;
  }
  iVar1 = 0xff;
  in_stack_00000004 = 0;
LAB_00004880:
  return ((in_stack_00000004 & 0x7fffffff) >> 7 | iVar1 << 0x18) >> 1 |
         (uint)((in_stack_00000000 & 0x80000000) != 0) * -0x80000000;
}


/* ROM address: 0x000048c8; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000048c8 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000048c8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *in_stack_00000000;
  
  uVar2 = (param_1 & 0x7fffffff) >> 0x17;
  uVar3 = param_1 << 9;
  if (uVar2 == 0xff) {
    if (uVar3 == 0) {
      uVar2 = 0x7fff;
      uVar3 = 0;
    }
    else {
      uVar2 = 0x7fff;
      param_1 = 0;
      uVar3 = 0xffffffff;
    }
  }
  else {
    if (uVar2 == 0) {
      if (uVar3 == 0) {
        uVar2 = 0xffff8001;
        uVar3 = 0;
        goto LAB_000048ec;
      }
      uVar1 = param_1 << 10;
      uVar4 = uVar3;
      while (uVar3 = uVar1, (uVar4 & 0x80000000) == 0) {
        uVar2 = uVar2 - 1;
        uVar1 = uVar3 << 1;
        uVar4 = uVar3;
      }
    }
    uVar2 = uVar2 - 0x7f;
    uVar3 = uVar3 >> 1 | 0x80000000;
  }
LAB_000048ec:
  *in_stack_00000000 = uVar2 & 0xffff | (uint)((param_1 & 0x80000000) != 0) * -0x80000000;
  in_stack_00000000[1] = uVar3;
  return;
}


/* ROM address: 0x00004b64; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004b64 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004b64(byte *param_1,byte param_2,short param_3)

{
  if (param_3 == 0) {
    *param_1 = *param_1 & ~param_2;
    return;
  }
  *param_1 = *param_1 | param_2;
  return;
}


/* ROM address: 0x00004b84; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004b84 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004b84(ushort *param_1,ushort param_2,short param_3)

{
  if (param_3 == 0) {
    *param_1 = *param_1 & ~param_2;
    return;
  }
  *param_1 = *param_1 | param_2;
  return;
}


/* ROM address: 0x00004bbc; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004bbc (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_setRegister_REG_BIT_VAL(ushort *param_1,ushort param_2,short param_3)

{
  if (param_3 == 0) {
    *param_1 = *param_1 & ~param_2;
    return;
  }
  *param_1 = *param_1 | param_2;
  return;
}


/* ROM address: 0x00004bd4; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004bd4 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004bd4(byte *param_1,byte param_2)

{
  *param_1 = *param_1 ^ param_2;
  return;
}


/* ROM address: 0x00004be4; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004be4 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004be4(ushort *param_1,ushort param_2)

{
  *param_1 = *param_1 ^ param_2;
  return;
}


/* [CROSS-ECU / RX8DEFS REVIEW]
 * sh_delay_20_nops [assembly_verified]: 20 NOP instructions before RTS, plus one delay-slot NOP. Raw C returns immediately because timing has no C-level side effect; preserve this distinction when analyzing peripheral timing.
 */
/* ROM address: 0x00004c14; body bytes: 44; decompiled */

void sh_delay_20_nops(void)

{
  return;
}


/* ROM address: 0x00004c70; body bytes: 6; decompiled */

void FUN_00004c70(int param_1)

{
  *(BADSPACEBASE **)(param_1 + -4) = register0x0000003c;
  return;
}


/* ROM address: 0x00004c76; body bytes: 4; decompiled */

void FUN_00004c76(void)

{
  return;
}


/* ROM address: 0x00004c7a; body bytes: 4; decompiled */

void FUN_00004c7a(void)

{
  return;
}


/* ROM address: 0x00004c80; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004c80 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004c80(void)

{
  FUN_00005292();
  ICR_W = 0xff;
  FUN_00004dee();
  FUN_00004e0e();
  FUN_00004e6c();
  FUN_00004fd6();
  ref_writeWatchdog_disable_00005024();
  FUN_00005036();
  FUN_0000503e();
  FUN_0000505a();
  FUN_00005062();
  FUN_000050aa();
  ref_callsFlash_0000527e();
  return;
}


/* ROM address: 0x00004cb6; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004cb6 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004cb6(void)

{
  FUN_00004dea();
  jump_to_FUN_00004dee();
  FUN_00004e0a();
  FUN_00004e12();
  FUN_00004f00();
  FUN_00005020();
  ref_writeWatchdog_disable_00005032();
  FUN_0000503a();
  FUN_00005056();
  FUN_0000505e();
  FUN_000050a6();
  FUN_0000522a();
  ref_callsFlash_0000528e();
  FUN_000052b0();
  return;
}


/* ROM address: 0x00004cf0; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004cf0 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004cf0(void)

{
  IPRA_W = 0;
  IPRB_W = 0;
  IPRC_W = 0;
  IPRD_W = 0;
  IPRE_W = 0;
  IPRF_W = 0;
  IPRG_W = 0;
  IPRH_W = 0;
  IPRI_W = 0;
  IPRJ_W = 0;
  IPRK_W = 0;
  IPRL_W = 0;
  return;
}


/* ROM address: 0x00004d2e; body bytes: 188; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004d2e (188 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_setRegisters(void)

{
  FUN_000051c8();
  ATUII_TSR0_W = 0;
  ATUII_TSR1A_W = 0;
  ATUII_TSR1B_W = 0;
  ATUII_TSR2A_W = 0;
  ATUII_TSR2B_W = 0;
  ATUII_TSR3_W = 0;
  ATUII_TSR6_W = 0;
  ATUII_TSR7_W = 0;
  ATUII_TSR8_W = 0;
  ATUII_TSR9_W = 0;
  ATUII_TSR10_W = 0;
  ATUII_TSR11_W = 0;
  HCAN0_IRR_W = 0x100;
  HCAN1_IRR_W = 0x100;
  ISR_W = 0;
  CMCSR0_W = 0;
  CMCSR1_W = 0x40;
  IPRA_W = 0;
  IPRB_W = 0x9000;
  IPRC_W = 0xb;
  IPRD_W = 0x9099;
  IPRE_W = 0x990;
  IPRF_W = 0x9090;
  IPRG_W = 0x9099;
  IPRH_W = 0x9999;
  IPRI_W = 0x99b0;
  IPRJ_W = 0x999;
  IPRK_W = 0x9999;
  IPRL_W = 0x9909;
  ICR_W = 0xff;
  return;
}


/* ROM address: 0x00004dea; body bytes: 4; decompiled */

void FUN_00004dea(void)

{
  IPRA_W = 0;
  IPRB_W = 0x9000;
  IPRC_W = 0xb;
  IPRD_W = 0x9099;
  IPRE_W = 0x990;
  IPRF_W = 0x9090;
  IPRG_W = 0x9099;
  IPRH_W = 0x9999;
  IPRI_W = 0x99b0;
  IPRJ_W = 0x999;
  IPRK_W = 0x9999;
  IPRL_W = 0x9909;
  ICR_W = 0xff;
  return;
}


/* ROM address: 0x00004dee; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004dee (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004dee(void)

{
  UBC_UBARH_W = 0x7fffffff;
  UBC_UBAMRH_W = 0x7fffffff;
  UBC_UBBR_W = 0xe8;
  UBC_UBCR_W = 0;
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00004dee [high]: 4-byte body: word 0xaff2 = `bra 0x4dee` + delay-slot word 0x0009 (ROM-verified at 0x00004e06). Direct tail-jump to `FUN_00004dee` 0x00004dee; callers in callgraph: 0x00004cb6. Upstream name `thunk_FUN_00004dee` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00004e06; body bytes: 4; decompiled */

void jump_to_FUN_00004dee(void)

{
  UBC_UBARH_W = 0x7fffffff;
  UBC_UBAMRH_W = 0x7fffffff;
  UBC_UBBR_W = 0xe8;
  UBC_UBCR_W = 0;
  return;
}


/* ROM address: 0x00004e0a; body bytes: 4; decompiled */

void FUN_00004e0a(void)

{
  return;
}


/* ROM address: 0x00004e0e; body bytes: 4; decompiled */

void FUN_00004e0e(void)

{
  return;
}


/* ROM address: 0x00004e12; body bytes: 4; decompiled */

void FUN_00004e12(void)

{
  return;
}


/* ROM address: 0x00004e6c; body bytes: 148; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004e6c (148 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004e6c(void)

{
  ATUII_TSTR1_B = 0;
  ATUII_TSTR2_B = 0;
  ATUII_TSTR3_B = 0;
  ATUII_DSTR_W = 0;
  ATUII_PSCR1_B = 4;
  ATUII_PSCR2_B = 4;
  ATUII_PSCR3_B = 4;
  ATUII_PSCR4_B = 4;
  ATUII_ITVRR1_B = 0;
  ATUII_ITVRR2A_B = 0;
  ATUII_ITVRR2B_B = 0;
  ATUII_TCR1A_B = 4;
  ATUII_TCR1B_B = 4;
  ATUII_TRGMDR_B = 0x80;
  ATUII_TCR2A_B = 4;
  ATUII_TCR2B_B = 4;
  ATUII_TMDR_B = 0;
  ATUII_TCR3_B = 4;
  ATUII_TCR4_W = 4;
  ATUII_TCR5_W = 4;
  ATUII_TCR6A_B = 0x44;
  ATUII_TCR6B_B = 0x44;
  ATUII_PMDR6_B = 0;
  ATUII_TCR7A_B = 0x44;
  ATUII_TCR7B_B = 0x41;
  ATUII_TCNR_W = 0x9fff;
  ATUII_OTR_W = 0x1f00;
  ATUII_TCR8_B = 0x44;
  ATUII_RLDENR_B = 0;
  ATUII_TCR11_B = 1;
  ATUII_TSTR1_B = 0xff;
  ATUII_TSTR2_B = 0xff;
  ATUII_TSTR3_B = 1;
  return;
}


/* ROM address: 0x00004f00; body bytes: 214; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004f00 (214 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004f00(void)

{
  byte bVar1;
  undefined4 local_c [2];
  
  ATUII_TSTR1_B = 0xff;
  ATUII_TSTR2_B = 0xff;
  ATUII_TSTR3_B = 1;
  ATUII_PSCR1_B = 4;
  ATUII_PSCR2_B = 4;
  ATUII_PSCR3_B = 4;
  ATUII_PSCR4_B = 4;
  ATUII_ITVRR1_B = 0;
  ATUII_ITVRR2A_B = 0;
  ATUII_ITVRR2B_B = 0;
  ATUII_TRGMDR_B = 0x80;
  ATUII_TMDR_B = 0;
  ATUII_TCR3_B = 4;
  ATUII_TCR4_W = 4;
  ATUII_TCR5_W = 4;
  ref_setSR_PARAM(local_c,0xe0);
  bVar1 = ATUII_TIOR3A_B;
  ATUII_TIOR3A_B = bVar1 & 0x77;
  bVar1 = ATUII_TIOR3B_B;
  ATUII_TIOR3B_B = bVar1 & 0x77;
  bVar1 = ATUII_TIOR4A_B;
  ATUII_TIOR4A_B = bVar1 & 0x77;
  bVar1 = ATUII_TIOR4B_B;
  ATUII_TIOR4B_B = bVar1 & 0x77;
  bVar1 = ATUII_TIOR5A_B;
  ATUII_TIOR5A_B = bVar1 & 0x77;
  bVar1 = ATUII_TIOR5B_B;
  ATUII_TIOR5B_B = bVar1 & 0x77;
  FUN_00002064(local_c[0]);
  ATUII_TCR6A_B = 0x44;
  ATUII_TCR6B_B = 0x44;
  ATUII_PMDR6_B = 0;
  ATUII_TCR7A_B = 0x44;
  ATUII_TCR7B_B = 0x41;
  ATUII_TCR8_B = 0x44;
  ATUII_RLDENR_B = 0;
  ref_setSR_PARAM(local_c,0xe0);
  bVar1 = ATUII_TCR9A_B;
  ATUII_TCR9A_B = bVar1 & 0xbb;
  bVar1 = ATUII_TCR9B_B;
  ATUII_TCR9B_B = bVar1 & 0xbb;
  FUN_00002064(local_c[0]);
  ATUII_TCR11_B = 1;
  return;
}


/* ROM address: 0x00004fd6; body bytes: 4; decompiled */

void FUN_00004fd6(void)

{
  return;
}


/* ROM address: 0x00005020; body bytes: 4; decompiled */

void FUN_00005020(void)

{
  return;
}


/* ROM address: 0x00005024; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005024 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_writeWatchdog_disable_00005024(void)

{
  WDT_RSTCSR_W__B = 0x5a1f;
  Ramffffec10 = 0xa518;
  return;
}


/* ROM address: 0x00005032; body bytes: 4; decompiled */

void ref_writeWatchdog_disable_00005032(void)

{
  WDT_RSTCSR_W__B = 0x5a1f;
  Ramffffec10 = 0xa518;
  return;
}


/* ROM address: 0x00005036; body bytes: 4; decompiled */

void FUN_00005036(void)

{
  return;
}


/* ROM address: 0x0000503a; body bytes: 4; decompiled */

void FUN_0000503a(void)

{
  return;
}


/* ROM address: 0x0000503e; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000503e (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000503e(void)

{
  SCI_SMR0_B = 0x80;
  SCI_SMR1_B = 0x80;
  SCI_SMR2_B = 0x80;
  SCI_SMR3_B = 0x80;
  SCI_SMR4_B = 0x80;
  return;
}


/* ROM address: 0x00005056; body bytes: 4; decompiled */

void FUN_00005056(void)

{
  return;
}


/* ROM address: 0x0000505a; body bytes: 4; decompiled */

void FUN_0000505a(void)

{
  return;
}


/* ROM address: 0x0000505e; body bytes: 4; decompiled */

void FUN_0000505e(void)

{
  return;
}


/* ROM address: 0x00005062; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005062 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005062(void)

{
  PADR_W = 0x4200;
  PBDR_W = 0xe000;
  PCDR_W = 1;
  PDDR_W = 0x2800;
  PEDR_W = 0x41;
  PFDR_W = 0x2200;
  PGDR_W = 5;
  PHDR_W = 0xc180;
  PJDR_W = 0;
  PKDR_W = 0x9f3f;
  PLDR_W = 0x420;
  return;
}


/* ROM address: 0x000050a6; body bytes: 4; decompiled */

void FUN_000050a6(void)

{
  return;
}


/* ROM address: 0x000050aa; body bytes: 164; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000050aa (164 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000050aa(void)

{
  PBIR_W = 0;
  PKIR_W = 0x9f3f;
  PLIR_W = 0;
  PAIOR_W = 0x6200;
  PBIOR_W = 0xf484;
  PCIOR_W = 1;
  PDIOR_W = 0x29ff;
  PEIOR_W = 0xff7;
  PFIOR_W = 0x2788;
  PGIOR_W = 5;
  PHIOR_W = 0xc180;
  PJIOR_W = 0x80;
  PKIOR_W = 0x9fff;
  PLIOR_W = 0x720;
  PACRH_W = 0x5000;
  PACRL_W = 0;
  PBCRH_W = 0x1450;
  PBCRL_W = 0;
  PCCR_W = 5;
  PDCRH_W = 0;
  PDCRL_W = 0;
  PECR_W = 0;
  PFCRH_W = 0x8000;
  PFCRL_W = 0;
  PGCR_W = 0;
  PHCR_W = 0;
  PJCRH_W = 0;
  PJCRL_W = 0;
  PKCRH_W = 0;
  PKCRL_W = 0;
  PLCRH_W = 500;
  PLCRL_W = 0;
  return;
}


/* ROM address: 0x000051c8; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000051c8 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000051c8(void)

{
  PACRH_W = 0x5445;
  PACRL_W = 0x5401;
  PBCRH_W = 0x1450;
  PBCRL_W = 0x4000;
  PCCR_W = 5;
  PDCRH_W = 0;
  PDCRL_W = 0;
  PECR_W = 0;
  PFCRH_W = 0x8000;
  PFCRL_W = 0;
  PGCR_W = 0;
  PHCR_W = 0;
  PJCRH_W = 0x1000;
  PJCRL_W = 0;
  PKCRH_W = 0x4155;
  PKCRL_W = 0x5555;
  PLCRH_W = 500;
  PLCRL_W = 0x101;
  return;
}


/* ROM address: 0x0000522a; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000522a (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000522a(void)

{
  PBIR_W = 0;
  PKIR_W = 0x9f3f;
  PLIR_W = 0;
  PAIOR_W = 0x6200;
  PBIOR_W = 0xf484;
  PCIOR_W = 1;
  PDIOR_W = 0x29ff;
  PEIOR_W = 0xff7;
  PFIOR_W = 0x2788;
  PGIOR_W = 5;
  PHIOR_W = 0xc180;
  PJIOR_W = 0x80;
  PKIOR_W = 0x9fff;
  PLIOR_W = 0x720;
  FUN_000051c8();
  return;
}


/* ROM address: 0x0000527e; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000527e (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_callsFlash_0000527e(void)

{
  DAT_ffffe800 = 0;
  DAT_ffffe801 = 0;
  BSC_RAMER_W = 0;
  return;
}


/* ROM address: 0x0000528e; body bytes: 4; decompiled */

void ref_callsFlash_0000528e(void)

{
  DAT_ffffe800 = 0;
  DAT_ffffe801 = 0;
  BSC_RAMER_W = 0;
  return;
}


/* ROM address: 0x00005292; body bytes: 30; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000052a4) */
/* Unique exact-byte match to related 60E0FC00 function at 00005292 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005292(void)

{
  SYSCR_B = 1;
  MSTCR__W__W = 0x3c04;
  return;
}


/* ROM address: 0x000052b0; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000052b0 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000052b0(void)

{
  byte bVar1;
  uint uVar2;
  
  SYSCR_B = 1;
  bVar1 = MSTCR__W__W._1_1_;
  if ((bVar1 & 2) != 0) {
    uVar2 = FUN_0000a370();
    return uVar2;
  }
  return (uint)bVar1;
}


/* [ADDITIONAL SOURCE REVIEW]
 * fatal_interrupt_trap [high]: Fatal trap for reserved/unexpected vectors: raises SR mask to 0xe0 (ref_setSR_PARAM), calls 0xa330(code), spins at 0x535a (disasm 0x5348-0x535c). 99 of 119 real-trampoline IVT handlers + vec 0-63 stubs 0x53a0-0x53c2 call it; the 20 real handlers incl. vec-231 0x5ef4 (harness-verified) do not.
 */
/* ROM address: 0x00005348; body bytes: 22; decompiled_with_warnings */

/* Unique exact-byte match to related 60E0FC00 function at 00005348 (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

void fatal_interrupt_trap(undefined4 param_1)

{
  undefined1 auStack_8 [4];
  undefined4 uStack_4;
  
  uStack_4 = param_1;
  ref_setSR_PARAM(auStack_8,0xe0);
  fatal_trap_report_halt(uStack_4);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ROM address: 0x000053c6; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000053c6 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000053c6(void)

{
  ISR_W = 0x7f;
  fatal_interrupt_trap(0x40);
  return;
}


/* ROM address: 0x000053d2; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000053d2 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000053d2(void)

{
  ISR_W = 0xbf;
  fatal_interrupt_trap(0x41);
  return;
}


/* ROM address: 0x000053de; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000053de (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000053de(void)

{
  ISR_W = 0xdf;
  fatal_interrupt_trap(0x42);
  return;
}


/* ROM address: 0x000053ea; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000053ea (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000053ea(void)

{
  ISR_W = 0xef;
  fatal_interrupt_trap(0x43);
  return;
}


/* ROM address: 0x000053f6; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000053f6 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000053f6(void)

{
  ISR_W = 0xf7;
  FUN_0000b6b2();
  return;
}


/* ROM address: 0x00005402; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005402 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005402(void)

{
  ISR_W = 0xfb;
  fatal_interrupt_trap(0x45);
  return;
}


/* ROM address: 0x0000540e; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000540e (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000540e(void)

{
  ISR_W = 0xfd;
  fatal_interrupt_trap(0x46);
  return;
}


/* ROM address: 0x0000541a; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000541a (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000541a(void)

{
  ISR_W = 0xfe;
  fatal_interrupt_trap(0x47);
  return;
}


/* ROM address: 0x00005426; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005426 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005426(void)

{
  uint uVar1;
  
  uVar1 = DMAC_CHCR0_L;
  DMAC_CHCR0_L = uVar1 & 0xfffffffd;
  fatal_interrupt_trap(0x48);
  return;
}


/* ROM address: 0x00005434; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005434 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005434(void)

{
  uint uVar1;
  
  uVar1 = DMAC_CHCR1_L;
  DMAC_CHCR1_L = uVar1 & 0xfffffffd;
  fatal_interrupt_trap(0x4a);
  return;
}


/* ROM address: 0x00005474; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005474 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005474(void)

{
  uint uVar1;
  
  uVar1 = DMAC_CHCR2_L;
  DMAC_CHCR2_L = uVar1 & 0xfffffffd;
  fatal_interrupt_trap(0x4c);
  return;
}


/* ROM address: 0x00005482; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005482 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005482(void)

{
  uint uVar1;
  
  uVar1 = DMAC_CHCR3_L;
  DMAC_CHCR3_L = uVar1 & 0xfffffffd;
  fatal_interrupt_trap(0x4e);
  return;
}


/* ROM address: 0x00005490; body bytes: 10; decompiled */

void FUN_00005490(void)

{
  ATUII_TSR0_W = 0x1f;
  fatal_interrupt_trap(0x50);
  return;
}


/* ROM address: 0x0000549a; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000549a (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000549a(void)

{
  ATUII_TSR0_W = 0xfe;
  fatal_interrupt_trap(0x54);
  return;
}


/* ROM address: 0x000054a6; body bytes: 12; decompiled */

/* Unique exact-byte match to

[... 2,441,884 of 2,966,172 bytes of stdout omitted. Narrow the command, or send its output to a file and search that. ...]

ADDRESS__(&DAT_ffff917a);
  ref_validateAddressCopy_8bit_ADDRESS__(&DAT_ffff917c);
  ref_validateAddressCopy_8bit_ADDRESS__(&DAT_ffff917e);
  return;
}


/* ROM address: 0x0005e34e; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005cb5a (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0005e34e(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  ref_updateMemoryAtAddress_float_VAL_ADDR(0,&inferred_sensor_block_ffff9150_ffff9150);
  ref_updateMemoryAtAddress_float_VAL_ADDR(uVar1,&DAT_ffff9158);
  ref_updateMemoryAtAddress_float_VAL_ADDR(uVar1,&DAT_ffff9160);
  ref_updateMemoryAtAddress_float_VAL_ADDR(uVar1,&DAT_ffff9168);
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff9170,0xff);
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff9172,0xff);
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff9174,1);
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff9176,1);
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff9178,0);
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff917a,0);
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff917c,0);
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff917e,0);
  return;
}


/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005e3ae; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005cbba (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005e3ae(void)

{
  undefined4 uVar1;
  float extraout_fr0;
  float snapshot_vehicle_speed_ffffbbb4;
  
  snapshot_vehicle_speed_ffffbbb4 = vehicle_speed_ffffbbb4;
  uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&inferred_sensor_block_ffff9150_ffff9150);
  if (extraout_fr0 < snapshot_vehicle_speed_ffffbbb4) {
    uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(snapshot_vehicle_speed_ffffbbb4,&inferred_sensor_block_ffff9150_ffff9150);
    return uVar1;
  }
  return uVar1;
}


/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005e3d8; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005cbe4 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005e3d8(void)

{
  undefined4 uVar1;
  float extraout_fr0;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff9158);
  if (extraout_fr0 < snapshot_inferred_coolant_temperature_ffffa98c) {
    uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(snapshot_inferred_coolant_temperature_ffffa98c,&DAT_ffff9158);
    return uVar1;
  }
  return uVar1;
}


/* ROM address: 0x0005e402; body bytes: 114; decompiled */

uint FUN_0005e402(void)

{
  uint uVar1;
  float arg1;
  float arg2;
  float fVar2;
  
  uVar1 = (uint)DAT_ffffd252;
  fVar2 = (inferred_lambda_actual_ffffadec_ffffadec + inferred_ltft_bank1_ffffb0d0_ffffb0d0 + -1.0) * 100.0;
  if (uVar1 == 0x30) {
    uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar2,&DAT_ffff9160);
    return uVar1;
  }
  if (uVar1 == 0x40) {
    arg2 = 0.004999995;
    arg1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff9160);
    fVar2 = rx8_first_order_filter(fVar2,arg1,arg2,1e-05);
    uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar2,&DAT_ffff9160);
    return uVar1;
  }
  return uVar1;
}


/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005e4b2; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ccbe (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005e4b2(void)

{
  byte bVar1;
  byte snapshot_DAT_ffffd388;
  byte snapshot_DAT_ffffd389;
  char cVar5;
  undefined4 uVar4;
  
  cVar5 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff9170,0xff);
  uVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff9172,0xff);
  snapshot_DAT_ffffd389 = DAT_ffffd389;
  snapshot_DAT_ffffd388 = DAT_ffffd388;
  if (DAT_ffffd392 == '\0') {
    bVar1 = DAT_ffffd391 ^ DAT_ffffd389;
    ref_updateMemoryAtAddress_8bit_ADDR_VAL
              (&DAT_ffff9170,~(int)(char)(DAT_ffffd390 ^ DAT_ffffd388) & (int)cVar5);
    uVar4 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff9172,(int)(char)(~bVar1 & (byte)uVar4))
    ;
  }
  else {
    DAT_ffffd392 = DAT_ffffd392 + -1;
  }
  DAT_ffffd390 = snapshot_DAT_ffffd388;
  DAT_ffffd391 = snapshot_DAT_ffffd389;
  return uVar4;
}


/* ROM address: 0x0005e520; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005cd2c (104 bytes). Names prefixed ref_
   are inherited hypotheses.
   
   [WIRING REVIEW 2026-09-08]
   Harness context: manual-transmission neutral switch is PCM 2O and opens in neutral (pp18-19).
   Brake switch is PCM 4P (p10). Input electrical polarity at the MCU and the interpretation of
   internal flags remain unverified. */

void ref_getBrakingOrInNeutral(void)

{
  undefined1 *puVar1;
  
  DAT_ffffd388 = inferred_ram_ad18_ffffad18_ffffad18 == '\x01';
  if (inferred_ram_bf3c_ffffbf3c_ffffbf3c == '\x01') {
    DAT_ffffd388 = DAT_ffffd388 + '\x04';
  }
  if (inferred_ram_bf9c_ffffbf9c_ffffbf9c == '\x01') {
    DAT_ffffd388 = DAT_ffffd388 + ' ';
  }
  if (inferred_ram_b53b_ffffb53b_ffffb53b == '\x01') {
    DAT_ffffd388 = DAT_ffffd388 + '@';
  }
  DAT_ffffd389 = 0;
  if (automatic_transmission_ffffb534 == '\x01') {
    puVar1 = &DAT_0007df1a;
    DAT_ffffd38a = 0x65;
  }
  else {
    puVar1 = &DAT_0007df1b;
    DAT_ffffd38a = 5;
  }
  DAT_ffffd38b = *puVar1;
  return;
}


/* ROM address: 0x0005e5dc; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005cde8 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0005e5dc(void)

{
  DAT_ffffd390 = DAT_ffffd388;
  DAT_ffffd391 = DAT_ffffd389;
  DAT_ffffd392 = 0x10;
  return;
}


/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005e5f4; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ce00 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005e5f4(void)

{
  uint uVar1;
  float snapshot_DAT_ffffad20;
  
  uVar1 = (uint)DAT_ffffaa81;
  if (uVar1 == 1) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff9174,0);
  }
  snapshot_DAT_ffffad20 = DAT_ffffad20;
  if ((0.55 <= DAT_ffffad20) && (DAT_ffffd38c < 0.55)) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff9176,0);
  }
  DAT_ffffd38c = snapshot_DAT_ffffad20;
  return uVar1;
}


/* ROM address: 0x0005e636; body bytes: 10; decompiled */

void FUN_0005e636(void)

{
  DAT_ffffd38c = DAT_ffffad20;
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_ecu_id_read [high]: Reads chip 0x64 (len 3) -> DAT_ffffd394 (+0x20), 0x68 (1) -> DAT_ffffd39a, 0x6a (2) -> DAT_ffffd398 (u16), 0x6c (1) -> DAT_ffffd39b via e2ram_cached_byte_read 0x37ef0. RX8 dump: 0x64-0x66='13H', 0x68='6', 0x6a-0x6b='02', 0x6c='0'.
 */
/* ROM address: 0x0005e664; body bytes: 206; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ce70 (206 bytes). Names prefixed ref_
   are inherited hypotheses. */

char e2ram_ecu_id_read(void)

{
  char cVar1;
  byte local_14;
  byte bStack_13;
  byte bStack_12;
  byte bStack_11;
  
  cVar1 = e2ram_cached_byte_read(100,&local_14,3);
  if (cVar1 == '\0') {
    DAT_ffffd394 = ((uint)local_14 * 0x100 + (uint)bStack_13) * 0x10000 +
                   ((uint)bStack_12 * 0x100 + (uint)bStack_11 & (uint)&PTR_ref_LongFunc_0000ff00) +
                   0x20;
  }
  cVar1 = e2ram_cached_byte_read(0x68,&local_14,1);
  if (cVar1 == '\0') {
    DAT_ffffd39a = local_14;
  }
  cVar1 = e2ram_cached_byte_read(0x6a,&local_14,2);
  if (cVar1 == '\0') {
    DAT_ffffd398 = (ushort)local_14 * 0x100 + (ushort)bStack_13;
  }
  cVar1 = e2ram_cached_byte_read(0x6c,&local_14,1);
  if (cVar1 == '\0') {
    DAT_ffffd39b = local_14;
  }
  return cVar1;
}


/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_config_bit_9f_read [medium]: e2ram_cached_byte_read(0x9f, local, 1); (val & 1) == 0 && DAT_ffffd1b5 == 0 && DAT_ffffd1b8 == 0 -> DAT_ffffd39c = 1. RX8 dump 0x9f = 0xfe, SE3P = 0xff.
 */
/* ROM address: 0x0005e748; body bytes: 74; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005cf54 (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint candidate_e2ram_config_bit_9f_read(void)

{
  uint uVar1;
  char local_8 [8];
  
  uVar1 = e2ram_cached_byte_read(0x9f,local_8,1);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 0) {
    uVar1 = (int)local_8[0] & 1;
    if (((uVar1 == 0) && (DAT_ffffd1b5 == '\0')) && (uVar1 = (uint)DAT_ffffd1b8, uVar1 == 0)) {
      DAT_ffffd39c = 1;
    }
    else {
      DAT_ffffd39c = 0;
    }
  }
  return uVar1;
}


/* ROM address: 0x0005e7a0; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005cfac (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0005e7a0(void)

{
  char cVar1;
  undefined2 local_c;
  
  cVar1 = e2ram_cached_byte_read(0x78,&local_c,2);
  if (cVar1 == '\0') {
    cVar1 = (char)local_c;
  }
  else {
    local_c = 0xffff;
  }
  inferred_ram_d3a0_ffffd3a0_ffffd3a0 = local_c;
  DAT_ffffd3a8 = local_c;
  DAT_ffffd3af = 0;
  DAT_ffffd3ae = 0;
  return cVar1;
}


/* ROM address: 0x0005e7e4; body bytes: 150; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005cff0 (150 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005e7e4(void)

{
  uint uVar1;
  
  uVar1 = (uint)engine_running_flag_ffffaa68;
  DAT_ffffd3a4 = inferred_ram_c6ac_ffffc6ac_ffffc6ac;
  if (uVar1 == 1) {
    if (inferred_ram_c6ac_ffffc6ac_ffffc6ac < 1.374) {
      uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffd3aa,1);
      DAT_ffffd3aa = (ushort)uVar1;
      if ((0x18 < DAT_ffffd3aa) && (DAT_ffffd3aa = 0, DAT_ffffd3a8 != 0)) {
        uVar1 = (int)(short)DAT_ffffd3a8 - 1;
        DAT_ffffd3a8 = (ushort)uVar1;
      }
    }
    DAT_ffffd3af = 1;
  }
  else {
    if ((DAT_ffffd3aa != 0) && (uVar1 = (uint)(short)DAT_ffffd3a8, uVar1 != 0)) {
      DAT_ffffd3aa = 0;
      DAT_ffffd3a8 = DAT_ffffd3a8 - 1;
    }
    if (DAT_ffffd3a8 < inferred_ram_d3a0_ffffd3a0_ffffd3a0) {
      DAT_ffffd3af = 2;
    }
    else {
      uVar1 = 3;
      DAT_ffffd3af = 3;
    }
  }
  return uVar1;
}


/* ROM address: 0x0005e8a4; body bytes: 316; decompiled */

int FUN_0005e8a4(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_28;
  undefined1 local_24;
  undefined1 uStack_23;
  
  iVar2 = 0;
  if (DAT_ffffd3ae == '\0') {
    if (DAT_ffffd3af == '\x01') {
      DAT_ffffd3ae = '\x01';
      iVar2 = 1;
    }
  }
  else if (DAT_ffffd3ae == '\x01') {
    if (DAT_ffffd3af != '\x01') {
      if (DAT_ffffd3af == '\x02') {
        local_24 = (undefined1)((ushort)DAT_ffffd3a8 >> 8);
        uStack_23 = (undefined1)DAT_ffffd3a8;
        e2ram_shadow_byte_write(0x78,&local_24,2);
        DAT_ffffd3b0 = e2ram_flush_request(0x78,2);
        DAT_ffffd3ae = '\x02';
      }
      else {
        iVar2 = 2;
        DAT_ffffd3ae = '\x03';
      }
    }
    DAT_ffffd3ac = 0;
  }
  else if (DAT_ffffd3ae == '\x02') {
    if (DAT_ffffd3b0 == '\x01') {
      DAT_ffffd3b0 = e2ram_flush_request(0x78,2);
    }
    else if ((DAT_ffffc28c == '\x01') || (DAT_ffffc289 == '\x01')) {
      iVar2 = 2;
      DAT_ffffd3ae = '\x03';
    }
    DAT_ffffd3ac = DAT_ffffd3ac + 1;
    if ((0x4e1 < DAT_ffffd3ac) || (DAT_ffffd3ae == '\x03')) {
      DAT_ffffd3ae = '\x03';
      iVar2 = 2;
    }
  }
  else if (DAT_ffffd3ae != '\x03') {
    DAT_ffffd3ae = '\x03';
    iVar2 = 2;
  }
  local_28 = 0;
  if (iVar2 == 1) {
    uVar1 = 2;
  }
  else {
    if (iVar2 != 2) {
      return iVar2;
    }
    uVar1 = 3;
  }
  iVar2 = os_schedule_task_event(0,uVar1,&local_28);
  return iVar2;
}


/* ROM address: 0x0005f8cc; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e1d8 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005f8cc(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = '\0';
  uVar2 = 1;
  do {
    if ((param_1 & 1) != 0) {
      cVar1 = cVar1 + '\x01';
      param_4 = uVar2;
    }
    param_1 = (param_1 & 0xffff) >> 1;
    uVar2 = uVar2 + 1;
  } while ((uVar2 & 0xffff) < 3);
  if (cVar1 != '\x01') {
    param_4 = 0;
  }
  return param_4;
}


/* ROM address: 0x0005f8fa; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e206 (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_0005f8fa(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = FUN_00061800(0);
  if (((cVar1 == -0x40) || (cVar1 == -0x3f)) || (cVar1 == 'p')) {
    iVar2 = 1;
  }
  cVar1 = FUN_00061800(1);
  if (((cVar1 == -0x40) || (cVar1 == -0x3f)) || (cVar1 == 'p')) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


/* ROM address: 0x0005f950; body bytes: 10; decompiled */

int FUN_0005f950(ushort param_1)

{
  return (int)(short)(&DAT_0007e560)[param_1];
}


/* ROM address: 0x0005f95a; body bytes: 10; decompiled */

int FUN_0005f95a(ushort param_1)

{
  return (int)(short)(&DAT_0007e55a)[param_1];
}


/* ROM address: 0x0005f964; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e270 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_lookupCodeTypeAll(short param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; ((&DAT_0007e560)[uVar1 & 0xffff] != param_1 && ((uVar1 & 0xffff) < 0x8c));
      uVar1 = uVar1 + 1) {
  }
  return uVar1;
}


/* ROM address: 0x0005f98a; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e296 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_lookupCodeTypeMisfire(short param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; ((&DAT_0007e55a)[uVar1 & 0xffff] != param_1 && ((uVar1 & 0xffff) < 3));
      uVar1 = uVar1 + 1) {
  }
  return uVar1;
}


/* ROM address: 0x0005f9b0; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e2bc (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool ref_faultEnableStatus2(uint param_1,byte param_2)

{
  return (param_2 & (&DAT_0007e790)[param_1 & 0xffff]) == 0;
}


/* ROM address: 0x0005f9c2; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e2ce (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool ref_faultConfirmationSomething_(uint param_1,ushort param_2)

{
  return (param_2 & *(ushort *)(&DAT_0007e81c + (param_1 & 0xffff) * 2)) == 0;
}


/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffd5fc dtc_state_array (uint8[0x8c]): Per-slot DTC state mirror (0xc0/0xc1/0x70/0x60/0); cleared by 0x6028c, written by 0x602c8/0x602a4/0x6020e.
 */
/* ROM address: 0x0005f9f0; body bytes: 132; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e2fc (132 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005f9f0(uint param_1,char param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  param_1 = param_1 & 0xffff;
  if (param_2 == '\0') {
    if ((&dtc_state_array_ffffd5fc)[param_1] == -0x40) {
      uVar2 = 1;
    }
  }
  else if (param_2 == '\x01') {
    cVar1 = (&dtc_state_array_ffffd5fc)[param_1];
    if (((cVar1 == -0x40) || (cVar1 == -0x3f)) || (cVar1 == 'p')) {
      uVar2 = 1;
    }
  }
  else if (param_2 == '\x02') {
    cVar1 = FUN_00061d1a();
    if (cVar1 == '\x01') {
      uVar2 = 1;
    }
  }
  else if ((param_2 == '\x03') && ((&dtc_ram_flag_table_ffffd570_ffffd570)[param_1] == '\x01')) {
    uVar2 = 1;
  }
  return uVar2;
}


/* ROM address: 0x0005fa74; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e380 (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_faultSomething0x2(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00061450(0x80);
  if ((uVar1 & 0xffff) != 0) {
    uVar2 = FUN_0005f8fa();
    if ((uVar2 & 0xffff) != 0) {
      uVar1 = (uVar1 - uVar2) + 1;
    }
    if (0x7f < (uVar1 & 0xffff)) {
      uVar1 = 0x7f;
    }
  }
  return uVar1;
}


/* [ADDITIONAL SOURCE REVIEW]
 * dtc_count_stored [high]: 0x61450(0x80,0) - 0x5f8fa() + 1 clamp 0xff (was ref_faultSomething0x0) | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x0005fab2; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e3be (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint dtc_count_stored(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00061450(0x80,0);
  if ((uVar1 & 0xffff) != 0) {
    uVar2 = FUN_0005f8fa();
    if ((uVar2 & 0xffff) != 0) {
      uVar1 = (uVar1 - uVar2) + 1;
    }
    if (0xff < (uVar1 & 0xffff)) {
      uVar1 = 0xff;
    }
  }
  return uVar1;
}


/* [ADDITIONAL SOURCE REVIEW]
 * dtc_count_ram_table [high]: counts DAT_ffffd570[0..0x8b]==1, rotor-0/1 adjust, clamp 0xff
 * RAM 0xffffd570 dtc_ram_flag_table_ffffd570 (uint8[0x8c]): PID 0x0202 counts set bytes (140 DTC slots)
 */
/* ROM address: 0x0005fb08; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e414 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint dtc_count_ram_table(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar1 = 0;
  uVar3 = 0;
  do {
    if ((&dtc_ram_flag_table_ffffd570_ffffd570)[uVar1] == '\x01') {
      uVar2 = uVar2 + 1;
      if ((uVar1 == 0) || (uVar1 == 1)) {
        uVar3 = uVar3 + 1;
      }
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x8c);
  if ((uVar3 & 0xffff) != 0) {
    uVar2 = (uVar2 - uVar3) + 1;
  }
  if (0xff < (uVar2 & 0xffff)) {
    uVar2 = 0xff;
  }
  return uVar2;
}


/* ROM address: 0x0005fb68; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e474 (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_0005fb68(ushort param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  undefined **ppuVar5;
  
  ppuVar5 = &PTR_FUN_000604f8;
  uVar3 = 0x80;
  uVar2 = 0;
  bVar4 = 0;
  do {
    cVar1 = (*(code *)*ppuVar5)();
    if (cVar1 == '\0') {
      uVar2 = uVar2 | uVar3;
    }
    uVar3 = uVar3 >> 1;
    bVar4 = bVar4 + 1;
    ppuVar5 = ppuVar5 + 1;
  } while (bVar4 < 8);
  return (uVar2 & (byte)(&DAT_0007e29e)[param_1]) != (uint)(byte)(&DAT_0007e29e)[param_1];
}


/* ROM address: 0x0005fbd2; body bytes: 4; decompiled */

undefined4 FUN_0005fbd2(void)

{
  return 1;
}


/* ROM address: 0x0005fbd6; body bytes: 22; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e4e2 (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_0005fbd6(void)

{
  return DAT_ffffd1ad != '\0';
}


/* ROM address: 0x0005fc18; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e524 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_checkIfDeviceControl_(void)

{
  diag_permission_mask_ffffd3b4_ffffd3b4 = 0x40;
  if (security_unlocked_flag_ffffd1ce == '\x01') {
    diag_permission_mask_ffffd3b4_ffffd3b4 = 0xfffd;
  }
  return security_unlocked_flag_ffffd1ce;
}


/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069370: Idle Target - Base (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x000693e8: Idle Target G (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0005fc40; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e54c (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0005fc40(void)

{
  undefined **ppuVar1;
  float fVar2;
  
  if (automatic_transmission_ffffb534 == '\0') {
    ppuVar1 = &tbl_idle_target_g_000693e8;
  }
  else {
    ppuVar1 = &tbl_idle_target_base_00069370;
  }
  fVar2 = (float)lookup_2d_descriptor_scaled(0x42a00000,ppuVar1);
  DAT_ffffd3b8 = fVar2 + -150.0;
  return;
}


/* ROM address: 0x0005fc6c; body bytes: 6; decompiled */

undefined4 FUN_0005fc6c(void)

{
  return DAT_ffffd3b8;
}


/* ROM address: 0x0005fc72; body bytes: 6; decompiled */

undefined4 FUN_0005fc72(void)

{
  return engine_speed_rpm_ffffb548;
}


/* ROM address: 0x0005fc78; body bytes: 6; decompiled */

undefined4 FUN_0005fc78(void)

{
  return inferred_coolant_temperature_ffffa98c;
}


/* ROM address: 0x0005fc7e; body bytes: 6; decompiled */

undefined4 FUN_0005fc7e(void)

{
  return inferred_coolant_temperature_catalyst_temp_model_ffffa998;
}


/* ROM address: 0x0005fc84; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e590 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_0005fc84(void)

{
  return engine_stopped_latch_ffffa41c != '\0';
}


/* ROM address: 0x0005fc98; body bytes: 22; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e5a4 (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_0005fc98(void)

{
  return DAT_ffffbaa1 != '\x01';
}


/* ROM address: 0x0005fcae; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e5ba (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_0005fcae(void)

{
  return DAT_ffffcb86 == '\x01';
}


/* ROM address: 0x0005fcbc; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e5c8 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_getCoolantTempConditional(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_0005fd30;
  if (inferred_coolant_temperature_ffffa98c < 71.0) {
    puVar1 = &DAT_0005fd34;
    if (inferred_coolant_temperature_ffffa98c < 66.0) {
      DAT_ffffd3bc = 0;
    }
  }
  else {
    DAT_ffffd3bc = 1;
  }
  return puVar1;
}


/* ROM address: 0x0005fce4; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e5f0 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool ref_returnCoolantTempGreaterThan71(void)

{
  return DAT_ffffd3bc == '\x01';
}


/* ROM address: 0x0005fcf2; body bytes: 6; decompiled */

undefined4 FUN_0005fcf2(void)

{
  return engine_load_ffffc0b4;
}


/* ROM address: 0x0005fcf8; body bytes: 6; decompiled */

undefined4 FUN_0005fcf8(void)

{
  return engine_speed_rpm_ffffb548;
}


/* ROM address: 0x0005fcfe; body bytes: 6; decompiled */

undefined4 FUN_0005fcfe(void)

{
  return inferred_coolant_temperature_ffffa98c;
}


/* [ADDITIONAL SOURCE REVIEW]
 * dtc_set_fault_x0 [high]: Body is `bra 0x5fe20` with delay slot `mov #0,r6` (words a072/e600 at 0x5fd38/0x5fd3a, ROM-verified): a direct tail-call trampoline to dtc_set_fault 0x5fe20 with param_3 (r6, the x ORed into first-stored-code 0xffffd3c0 by 0x601cc) fixed to 0. 0x5fe20's only callers are the two trampolines 0x5fd38/0x5fd3c (callgraph); 0x5fd38 has 71 monitor callers. Not an indirect call, so no candidate_ prefix: the target is proven exact.
 */
/* ROM address: 0x0005fd38; body bytes: 4; decompiled */

void dtc_set_fault_x0(undefined4 param_1,undefined4 param_2)

{
  FUN_0005fe20(param_1,param_2,0);
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * dtc_set_fault_xdefault [high]: Entry 0x5fd3c: extu.w r6,r3; tst r3,r3; bf/s skip; mov.l @(0x5fe0c,pc),r6 where pool 0x5fe0c = 0x0000ffff; then bra 0x5fe20 (a06b at 0x5fd46): trampoline to dtc_set_fault with x defaulted to 0xffff when the caller passes r6==0. 2 callers (0x44724, 0x44cec), both computing r6 from flag bits before the call (jsr via pool words 0x447ac/0x44d54). Inherited ref_updateFaultStatusTHUNKNoR6_ is a misnomer: the body is set_fault, not a fault-status update; 'NoR6' = trampoline for callers that leave r6 unset.
 */
/* ROM address: 0x0005fd3c; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e648 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void dtc_set_fault_xdefault(undefined4 param_1,undefined4 param_2,uint param_3)

{
  if ((param_3 & 0xffff) == 0) {
    param_3 = 0xffff;
  }
  FUN_0005fe20(param_1,param_2,param_3);
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * dtc_set_eval_enable [high]: Entry 0x5fd4a: extu.b r4; r5 = pool 0x5fe10 = 0xffffd688 (dtc_eval_enable RAM); r4==1 -> mov.b #1,@r5; r4==0 -> mov.b #0,@r5; rts (000b at 0x5fd68). Plain setter of the global DTC eval-enable flag, not a thunk. Callers: 0x5fd6c (boot DTC RAM init sets 1) and 0x5dde8 (UDS 0x85 control-DTC-setting path, handler 0x5dc44).
 * RAM 0xffffd688 dtc_eval_enable (uint8): 1 = fault evaluation active; set at init by 0x5fd6c via 0x5fd4a(1); selects path in 0x5fe20.
 */
/* ROM address: 0x0005fd4a; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e656 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

char dtc_set_eval_enable(char param_1)

{
  if (param_1 == '\x01') {
    dtc_eval_enable_ffffd688 = 1;
  }
  else if (param_1 == '\0') {
    dtc_eval_enable_ffffd688 = 0;
  }
  return param_1;
}


/* ROM address: 0x0005fd6c; body bytes: 24; decompiled */

void FUN_0005fd6c(void)

{
  FUN_0005ff30();
  FUN_0006004a();
  FUN_000601b2();
  FUN_0006020e();
  dtc_set_eval_enable(1);
  return;
}


/* ROM address: 0x0005fd84; body bytes: 14; decompiled */

void FUN_0005fd84(void)

{
  FUN_0005ff30();
  FUN_0006004a();
  FUN_0006028c();
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_000601b2 [high]: 4-byte body: word 0xa20e = `bra 0x601b2` + delay-slot word 0x0009 (ROM-verified at 0x0005fd92). Direct tail-jump to `FUN_000601b2` 0x000601b2; callers in callgraph: 0x00059852. Upstream name `thunk_FUN_000601b2` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x0005fd92; body bytes: 4; decompiled */

void jump_to_FUN_000601b2(void)

{
  FUN_000601b2();
  return;
}


/* ROM address: 0x0005fd96; body bytes: 94; decompiled */

uint FUN_0005fd96(void)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  uint uVar4;
  uint uVar5;
  short local_44 [22];
  
  psVar3 = local_44;
  uVar2 = FUN_000615c6(0xf0,0);
  uVar5 = 0;
  uVar4 = uVar2 & 0xffff;
  if (uVar4 != 0) {
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
      uVar2 = ref_faultEnableStatus2((int)sVar1,0x20);
      uVar2 = uVar2 & 0xff;
      if (uVar2 == 0) {
        uVar2 = FUN_00061b28((int)sVar1);
      }
      uVar5 = uVar5 + 1;
    } while ((uVar5 & 0xffff) < uVar4);
  }
  return uVar2;
}


/* ROM address: 0x0005fe20; body bytes: 242; decompiled */

uint FUN_0005fe20(uint param_1,undefined4 param_2,short param_3)

{
  bool bVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  
  sVar2 = diag_permission_mask_ffffd3b4_ffffd3b4;
  iVar6 = (int)*(short *)(&DAT_0007df42 + (param_1 & 0xffff) * 2);
  if ((DAT_ffffd1c5 == '\x01') || (DAT_ffffd958 == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0005ff5a(param_1);
  }
  uVar4 = (uint)dtc_eval_enable_ffffd688;
  if (uVar4 == 1) {
    uVar4 = ref_faultConfirmationSomething_(iVar6,(int)sVar2);
    uVar4 = uVar4 & 0xff;
    if (uVar4 == 0) {
      if (DAT_ffffd25d == '\0') {
        uVar4 = ref_faultEnableStatus2(iVar6,2);
        uVar4 = uVar4 & 0xff;
        if ((uVar4 == 0) && (!bVar1)) {
          uVar4 = FUN_00060062(param_1,uVar3,(int)param_3);
          return uVar4;
        }
      }
      else {
        cVar5 = ref_faultEnableStatus2(iVar6,4);
        if (cVar5 != '\0') {
          uVar4 = ref_faultEnableStatus2(iVar6,8);
          if ((uVar4 & 0xff) != 0) {
            return uVar4 & 0xff;
          }
        }
        uVar4 = 0;
        if (DAT_ffffd25a == '\0') {
          uVar4 = FUN_000601cc(param_1,uVar3,(int)param_3);
          return uVar4;
        }
      }
    }
  }
  return uVar4;
}


/* ROM address: 0x0005ff30; body bytes: 42; decompiled */

void FUN_0005ff30(void)

{
  undefined1 *puVar1;
  ushort uVar2;
  
  puVar1 = &dtc_eval_state_cache_ffffd3c2;
  uVar2 = 0;
  do {
    *puVar1 = 0;
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x96);
  uVar2 = 0;
  puVar1 = &dtc_eval_state_array_ffffd458;
  do {
    uVar2 = uVar2 + 1;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x8c);
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffd458 dtc_eval_state_array (uint8[0x8c]): Per-slot eval state (1/2/4) written by 0x5ff5a; read by 0x60478.
 * RAM 0xffffd3c2 dtc_eval_state_cache (uint8[0x8c]): Per-fault-id cached eval-state argument written by 0x5ff5a.
 */
/* ROM address: 0x0005ff5a; body bytes: 218; decompiled */

int FUN_0005ff5a(uint param_1,char param_2)

{
  ushort uVar1;
  uint uVar2;
  char cVar3;
  ushort uVar4;
  
  uVar1 = *(ushort *)(&DAT_0007df42 + (param_1 & 0xffff) * 2);
  if (param_2 != (&dtc_eval_state_cache_ffffd3c2)[param_1 & 0xffff]) {
    (&dtc_eval_state_cache_ffffd3c2)[param_1 & 0xffff] = param_2;
    uVar4 = *(ushort *)(&DAT_0007e06e + (uint)uVar1 * 4);
    if ((param_2 == '\x02') || (param_2 == '\x04')) {
      uVar2 = (int)(char)(&DAT_0007e070)[(uint)uVar1 * 4] & 0xf0;
    }
    else if (param_2 == '\x01') {
      uVar2 = (int)(char)(&DAT_0007e070)[(uint)uVar1 * 4] & 0xf;
    }
    else {
      uVar2 = 0;
    }
    cVar3 = param_2;
    if ((((uVar2 != 0x10) && (uVar2 != 1)) && (uVar2 != 0x40)) && (uVar2 != 4)) {
      if ((uVar2 == 0x20) || (uVar2 == 2)) {
        while (cVar3 != '\0') {
          if ((*(ushort *)(&DAT_0007df42 + (uint)uVar4 * 2) != uVar1) || (0x95 < uVar4))
          goto LAB_0006002e;
          uVar2 = (uint)uVar4;
          uVar4 = uVar4 + 1;
          if ((&dtc_eval_state_cache_ffffd3c2)[uVar2] != param_2) {
            cVar3 = '\0';
          }
        }
        goto LAB_0006003c;
      }
      cVar3 = '\0';
    }
LAB_0006002e:
    if (cVar3 != '\0') {
      (&dtc_eval_state_array_ffffd458)[uVar1] = cVar3;
    }
  }
LAB_0006003c:
  return (int)(char)(&dtc_eval_state_array_ffffd458)[uVar1];
}


/* ROM address: 0x0006004a; body bytes: 24; decompiled */

void FUN_0006004a(void)

{
  undefined1 *puVar1;
  ushort uVar2;
  
  uVar2 = 0;
  puVar1 = &dtc_transition_state_array_ffffd4e4;
  do {
    uVar2 = uVar2 + 1;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x8c);
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffd4e4 dtc_transition_state_array (uint8[0x8c]): Per-slot transition state written by 0x60062 on mode 1/2/4.
 */
/* ROM address: 0x00060062; body bytes: 272; decompiled */

uint FUN_00060062(uint param_1,uint param_2,short param_3)

{
  byte bVar1;
  char cVar3;
  uint uVar2;
  int iVar4;
  uint uVar5;
  
  iVar4 = (int)(short)*(ushort *)(&DAT_0007df42 + (param_1 & 0xffff) * 2);
  uVar5 = (uint)*(ushort *)(&DAT_0007df42 + (param_1 & 0xffff) * 2);
  bVar1 = (&DAT_0007e32a)[uVar5];
  param_2 = param_2 & 0xff;
  if (param_2 == 2) {
    cVar3 = ref_faultEnableStatus2(iVar4,0x10);
    if (cVar3 == '\0') {
      cVar3 = FUN_00061800(iVar4);
      param_2 = 0;
      if (cVar3 != '\0') {
        FUN_00061b28(iVar4);
        FUN_000602c8(iVar4,0);
        (&dtc_transition_state_array_ffffd4e4)[uVar5] = 2;
        param_2 = uVar5;
      }
    }
    else {
      param_2 = (uint)(byte)(&dtc_transition_state_array_ffffd4e4)[uVar5];
      if ((byte)(&dtc_transition_state_array_ffffd4e4)[uVar5] != 2) {
        FUN_00060190(param_1,0x10,0);
        (&dtc_transition_state_array_ffffd4e4)[uVar5] = 2;
        param_2 = uVar5;
      }
    }
  }
  else if (param_2 == 4) {
    param_2 = (uint)(byte)(&dtc_transition_state_array_ffffd4e4)[uVar5];
    if (((byte)(&dtc_transition_state_array_ffffd4e4)[uVar5] != 4) &&
       (((bVar1 == 3 || (bVar1 == 1)) || (param_2 = (uint)bVar1, bVar1 == 2)))) {
      FUN_00060190(param_1,0x11,0);
      (&dtc_transition_state_array_ffffd4e4)[uVar5] = 4;
      param_2 = uVar5;
    }
  }
  else if ((param_2 == 1) &&
          ((((&dtc_transition_state_array_ffffd4e4)[uVar5] != '\x01' || (bVar1 == 1)) ||
           (param_2 = (uint)bVar1, bVar1 == 2)))) {
    uVar2 = FUN_0005fb68(iVar4);
    param_2 = uVar2 & 0xff;
    if ((uVar2 & 0xff) == 0) {
      FUN_00060190(param_1,0x20,(int)param_3);
      (&dtc_transition_state_array_ffffd4e4)[uVar5] = 1;
      param_2 = uVar5;
    }
  }
  return param_2;
}


/* ROM address: 0x00060190; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ea80 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00060190(uint param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  uint local_10;
  uint uStack_c;
  uint uStack_8;
  
  local_10 = param_1 & 0xffff;
  uStack_c = param_2 & 0xff;
  uStack_8 = param_3 & 0xffff;
  uVar1 = os_schedule_task_event(2,2,&local_10);
  return uVar1;
}


/* ROM address: 0x000601b2; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005eaa2 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000601b2(void)

{
  undefined1 *puVar1;
  ushort uVar2;
  
  uVar2 = 0;
  puVar1 = &dtc_ram_flag_table_ffffd570_ffffd570;
  do {
    uVar2 = uVar2 + 1;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x8c);
  dtc_first_stored_code_ffffd3c0 = 0;
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffd3c0 dtc_first_stored_code (uint16): First stored DTC code, recorded by 0x601cc when flag table goes 0->1.
 */
/* ROM address: 0x000601cc; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005eabc (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined * FUN_000601cc(uint param_1,byte param_2,short param_3)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(uint)param_2;
  if (((puVar1 != (undefined *)((int)&vector_Poweron_Reset + 2)) && (puVar1 != &UNK_00000004)) &&
     (puVar1 == (undefined *)((int)&vector_Poweron_Reset + 1))) {
    puVar1 = &dtc_ram_flag_table_ffffd570_ffffd570;
    (&dtc_ram_flag_table_ffffd570_ffffd570)[*(ushort *)(&DAT_0007df42 + (param_1 & 0xffff) * 2)] = 1;
    if (dtc_first_stored_code_ffffd3c0 == 0) {
      dtc_first_stored_code_ffffd3c0 = param_3;
    }
  }
  return puVar1;
}


/* ROM address: 0x0006020e; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005eafe (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006020e(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 uVar3;
  ushort *puVar4;
  ushort auStack_44 [22];
  
  uVar2 = FUN_000615c6(0xf0,0,auStack_44);
  FUN_0006028c();
  puVar4 = auStack_44 + uVar2;
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    puVar4 = puVar4 + -1;
    uVar1 = *puVar4;
    uVar3 = FUN_00061800((int)(short)uVar1);
    (&dtc_state_array_ffffd5fc)[uVar1] = uVar3;
  }
  return;
}


/* ROM address: 0x0006028c; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005eb7c (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006028c(void)

{
  undefined1 *puVar1;
  ushort uVar2;
  
  puVar1 = &dtc_state_array_ffffd5fc;
  uVar2 = 0;
  do {
    *puVar1 = 0;
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x8c);
  return;
}


/* ROM address: 0x000602a4; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005eb94 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000602a4(uint param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  
  uVar1 = *(ushort *)(&DAT_0007df42 + (param_1 & 0xffff) * 2);
  uVar2 = FUN_00061800((int)(short)uVar1);
  (&dtc_state_array_ffffd5fc)[uVar1] = uVar2;
  return;
}


/* ROM address: 0x000602c8; body bytes: 8; decompiled */

void FUN_000602c8(uint param_1,undefined1 param_2)

{
  (&dtc_state_array_ffffd5fc)[param_1 & 0xffff] = param_2;
  return;
}


/* ROM address: 0x000602e0; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ebd0 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000602e0(void)

{
  char cVar2;
  undefined4 uVar1;
  
  cVar2 = FUN_0006229c();
  if (cVar2 != '\0') {
    uVar1 = FUN_0003df7c();
    return uVar1;
  }
  return 0;
}


/* ROM address: 0x000602fc; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ebec (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000602fc(void)

{
  char cVar2;
  undefined4 uVar1;
  
  cVar2 = FUN_0006229c();
  if (cVar2 != '\0') {
    uVar1 = FUN_0003de68();
    return uVar1;
  }
  return 0;
}


/* ROM address: 0x00060318; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ec08 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00060318(void)

{
  FUN_000622e0();
  FUN_0006106e();
  FUN_00065616();
  FUN_00064512();
  FUN_0006057e();
  FUN_00060518();
  FUN_00060a86();
  FUN_0005fd84();
  return;
}


/* ROM address: 0x00060378; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ec68 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_setFaultEvalState_(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if (DAT_ffffd1ad == '\x01') {
    uVar1 = 3;
  }
  if ((vehicle_inputs_pfdr_latch_ffff9ec8 & 1) == 0) {
    uVar1 = uVar1 | 4;
  }
  if (DAT_ffffd198 == '\x01') {
    uVar1 = uVar1 | 8;
  }
  return uVar1;
}


/* ROM address: 0x000603b2; body bytes: 172; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005eca2 (172 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000603b2(uint param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = 1;
  pcVar3 = (&PTR_DAT_0007f500)[param_1 & 0xffff];
  for (uVar2 = 0; ((*pcVar3 != '\x1f' && (iVar4 == 1)) && ((char)uVar2 != -1));
      uVar2 = rx8_add_u8_saturate(uVar2,1)) {
    cVar1 = *pcVar3;
    if ((cVar1 == '\x1b') || (cVar1 == '\x1c')) {
      if (DAT_ffffd26e == '\x01') {
        iVar4 = 0;
      }
    }
    else if (cVar1 == '\x1d') {
      if (DAT_ffffd26b == '\x01') {
        iVar4 = 0;
      }
    }
    else if ((cVar1 != '\x1e') && (cVar1 = FUN_0005bffe((int)*pcVar3), cVar1 == '\x01')) {
      iVar4 = 0;
    }
    pcVar3 = pcVar3 + 1;
  }
  return iVar4;
}


/* ROM address: 0x00060478; body bytes: 74; decompiled */

undefined4 FUN_00060478(ushort param_1)

{
  char cVar1;
  
  cVar1 = ref_faultEnableStatus2((int)(short)param_1,0x20);
  if (cVar1 == '\0') {
    if ((&dtc_eval_state_array_ffffd458)[param_1] != '\x01') {
      return 0;
    }
  }
  else if ((&dtc_state_array_ffffd5fc)[param_1] != -0x40) {
    return 0;
  }
  return 1;
}


/* ROM address: 0x000604c2; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005edb2 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000604c2(char param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(short)diag_permission_mask_ffffd3b4_ffffd3b4;
  if (param_1 == '\0') {
    uVar1 = (uint)(diag_permission_mask_ffffd3b4_ffffd3b4 >> 8);
  }
  else if (param_1 != '\x01') {
    uVar1 = 0;
  }
  return uVar1;
}


/* ROM address: 0x00060518; body bytes: 4; decompiled */

void FUN_00060518(void)

{
  return;
}


/* ROM address: 0x0006051c; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ee0c (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006051c(void)

{
  undefined2 *puVar1;
  
  puVar1 = &DAT_ffffd68c;
  do {
    *puVar1 = 0xffff;
    puVar1 = puVar1 + 2;
  } while (puVar1 < &DAT_ffffd694);
  return;
}


/* ROM address: 0x00060534; body bytes: 4; decompiled */

void FUN_00060534(void)

{
  return;
}


/* ROM address: 0x00060538; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ee28 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined2 * FUN_00060538(undefined2 param_1,char param_2)

{
  if (param_2 == ' ') {
    DAT_ffffd68e = 3;
    DAT_ffffd690 = 0xffff;
    DAT_ffffd68c = param_1;
  }
  else {
    DAT_ffffd68c = 0xffff;
  }
  return &DAT_ffffd68c;
}


/* ROM address: 0x00060560; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ee50 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_00060560(void)

{
  char cVar1;
  
  cVar1 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff877c);
  return cVar1 != '\0';
}


/* ROM address: 0x0006057e; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ee6e (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006057e(void)

{
  DAT_ffff877c = rx8_pack_u8_with_complement(0);
  return;
}


/* ROM address: 0x0006058e; body bytes: 4; decompiled */

void FUN_0006058e(void)

{
  return;
}


/* ROM address: 0x00060592; body bytes: 4; decompiled */

void FUN_00060592(void)

{
  return;
}


/* ROM address: 0x00060596; body bytes: 272; decompiled */

void FUN_00060596(void)

{
  char cVar2;
  undefined4 uVar1;
  int iVar3;
  undefined4 uVar4;
  short sStack00000000;
  short sStack00000002;
  char cStack00000004;
  char cStack00000006;
  
  cVar2 = FUN_00062570((int)cStack00000004);
  if (cVar2 != '\x01') goto LAB_000606ae;
  uVar4 = 0xc0;
  if (cStack00000006 == '\x01') {
    uVar4 = FUN_000609fe((int)sStack00000000);
    FUN_00060872(uVar4,(int)sStack00000000,(int)cStack00000004,0x10);
  }
  else if (cStack00000006 == '\x02') {
    uVar4 = FUN_000609fe((int)sStack00000000);
    FUN_00060872(uVar4,(int)sStack00000000,(int)cStack00000004,0xc0);
  }
  else {
    if (cStack00000006 != '\x03') {
      if (cStack00000006 == '\x04') {
        uVar1 = FUN_00063998();
        uVar4 = 0x10;
LAB_00060688:
        iVar3 = (int)cStack00000004;
      }
      else {
        if (cStack00000006 == '\x05') {
          uVar1 = FUN_00063998();
          goto LAB_00060688;
        }
        if (cStack00000006 == '\x06') {
          uVar1 = FUN_00063998();
          goto LAB_00060688;
        }
        if (cStack00000006 != '\a') {
          if ((cStack00000006 != '\b') && (cStack00000006 == '\t')) {
            uVar4 = FUN_00063998();
            FUN_00060872(uVar4,(int)sStack00000000,7,1);
          }
          goto LAB_000606ae;
        }
        uVar1 = FUN_00063998();
        uVar4 = 1;
        iVar3 = 7;
      }
      FUN_00060872(uVar1,(int)sStack00000000,iVar3,uVar4);
      goto LAB_000606ae;
    }
    uVar4 = FUN_00063998();
    FUN_00060872(uVar4,(int)sStack00000000,(int)cStack00000004,0xc0);
  }
  FUN_000608c8(uVar4,(int)sStack00000000,(int)sStack00000002);
LAB_000606ae:
  FUN_000628d6();
  return;
}


/* ROM address: 0x000606be; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005efae (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000606be(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_ffff87b6)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10];
  if ((uVar1 != 0x50) && (uVar1 != 0)) {
    return uVar1;
  }
  FUN_00062570(8);
  FUN_0006381c();
  uVar1 = FUN_000628d6();
  return uVar1;
}


/* ROM address: 0x000606f6; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005efe6 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_000606f6(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = FUN_00063998();
  bVar1 = (uVar2 & 0xff) != 0;
  if (bVar1) {
    FUN_00063c1c(uVar2,param_2);
  }
  return !bVar1;
}


/* ROM address: 0x0006071e; body bytes: 184; decompiled */

int FUN_0006071e(undefined4 param_1)

{
  char cVar1;
  int unaff_r9;
  ushort uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  ushort auStack_2c [2];
  ushort uStack_28;
  char cStack_25;
  byte bStack_24;
  
  uVar2 = 0xffff;
  bVar3 = 0xff;
  iVar4 = 1;
  iVar5 = 1;
  do {
    cVar1 = FUN_00063b60(iVar5,auStack_2c);
    if (cVar1 != '\x01') break;
    if (((&DAT_0007e704)[auStack_2c[0]] == '\x01') && (cStack_25 == -0x40)) {
      if (bStack_24 < bVar3) {
        iVar4 = 0;
        unaff_r9 = iVar5;
        bVar3 = bStack_24;
        uVar2 = uStack_28;
      }
      else if ((bVar3 == bStack_24) && (uStack_28 < uVar2)) {
        iVar4 = 0;
        unaff_r9 = iVar5;
        bVar3 = bStack_24;
        uVar2 = uStack_28;
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x15);
  if (iVar4 == 0) {
    FUN_00063c1c(unaff_r9,param_1);
  }
  return iVar4;
}


/* ROM address: 0x00060872; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f162 (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00060872(char param_1,short param_2,char param_3,char param_4)

{
  short sVar1;
  
  FUN_00063862((int)param_2);
  FUN_00063972((int)param_1);
  FUN_000638e2((int)param_4);
  FUN_000639dc((int)param_3);
  sVar1 = (&DAT_ffff87b4)[(uint)dtc_master_current_index_ffff8900._0_2_ * 8];
  FUN_00063a54((int)(short)(&DAT_ffff87b2)[(uint)dtc_master_current_index_ffff8900._0_2_ * 8]);
  FUN_00063ada((int)sVar1);
  return;
}


/* ROM address: 0x000608c8; body bytes: 176; decompiled */

void FUN_000608c8(undefined4 param_1,uint param_2,short param_3)

{
  undefined2 uVar1;
  char cVar2;
  uint uVar3;
  byte bVar4;
  
  uVar3 = 0;
  for (bVar4 = 0; ((&DAT_0005edbc)[(uVar3 & 0xff) * 2] != -1 && (bVar4 < 0x28));
      bVar4 = bVar4 + cVar2) {
    if ((&DAT_0005edbc)[(uVar3 & 0xff) * 2] == '\x02') {
      if (((param_2 & 0xffff) == 0) || ((param_2 & 0xffff) == 1)) {
        uVar1 = FUN_000609ae((int)param_3);
      }
      else {
        uVar1 = (&DAT_0007e560)[param_2 & 0xffff];
      }
      (&DAT_ffffd694)[bVar4] = (char)((ushort)uVar1 >> 8);
      (&DAT_ffffd695)[bVar4] = (char)uVar1;
      cVar2 = '\x02';
    }
    else {
      cVar2 = FUN_00054d28(param_2,(int)(char)(&DAT_0005edbc)[(uVar3 & 0xff) * 2],
                           &DAT_ffffd694 + bVar4);
    }
    uVar3 = uVar3 + 1;
  }
  FUN_00063bd4(&DAT_ffffd694);
  return;
}


/* ROM address: 0x000609ae; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f29e (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000609ae(ushort param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  short *psVar2;
  byte bVar3;
  ushort uVar4;
  
  uVar4 = 1;
  bVar3 = 0;
  uVar1 = FUN_00067c78(0);
  psVar2 = &DAT_0007e55c;
  do {
    if ((uVar4 & (param_1 | uVar1)) != 0) {
      param_3 = (int)*psVar2;
      bVar3 = bVar3 + 1;
    }
    uVar4 = uVar4 << 1;
    psVar2 = psVar2 + 1;
  } while (psVar2 < &UNK_0007e567);
  if (1 < bVar3) {
    param_3 = 0x300;
  }
  return param_3;
}


/* ROM address: 0x000609fe; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f2ee (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000609fe(void)

{
  uint uVar1;
  
  uVar1 = FUN_00063998();
  if ((uVar1 & 0xff) == 0) {
    if (DAT_ffff8794._0_2_ == -1) {
      uVar1 = (int)DAT_ffff877c._0_1_ + 1;
      DAT_ffff877c = rx8_pack_u8_with_complement(uVar1);
    }
    else {
      uVar1 = FUN_00063998();
    }
  }
  return uVar1;
}


/* ROM address: 0x00060a68; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f358 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_00060a68(void)

{
  char cVar1;
  
  cVar1 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8780);
  return cVar1 != '\0';
}


/* ROM address: 0x00060a86; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f376 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00060a86(void)

{
  DAT_ffff8780 = rx8_pack_u8_with_complement(0);
  return;
}


/* ROM address: 0x00060a96; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f386 (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00060a96(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = FUN_0006328a(0);
  while (cVar1 == '\x01') {
    if (DAT_ffffd797 == -0x40) {
      if (iVar2 == 0) {
        iVar2 = 0xc0;
      }
    }
    else if (DAT_ffffd797 == -0x80) {
      iVar2 = 0x80;
    }
    cVar1 = FUN_0006328a(1);
  }
  DAT_ffff8780 = rx8_pack_u8_with_complement(iVar2);
  return;
}


/* ROM address: 0x00060b14; body bytes: 318; decompiled */

void FUN_00060b14(uint param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = 8;
  uVar2 = param_2 & 0xff;
  uVar4 = 0;
  if (uVar2 == 3) {
    uVar4 = FUN_00060cd6(param_1);
    uVar3 = FUN_000618f8(param_1,uVar4,param_2);
    cVar1 = FUN_00062420(uVar3);
    if (cVar1 == '\x01') {
      FUN_00060ddc(param_1,uVar4);
      FUN_00060f58();
      FUN_00062138(param_1);
      FUN_00060f02(param_1,0x20);
      FUN_0006310a(uVar3);
      FUN_00063026(param_2);
      FUN_00063098(1);
    }
  }
  else {
    if (uVar2 != 1) {
      if (uVar2 == 2) {
        uVar4 = FUN_00062df8(param_1);
        uVar3 = FUN_000618f8(param_1,uVar4,param_2);
        cVar1 = FUN_00062420(uVar3);
        if (cVar1 == '\x01') {
          FUN_00063026(param_2);
        }
        FUN_000628b8();
      }
      goto LAB_00060c38;
    }
    uVar4 = FUN_00062df8(param_1);
    if (((byte)uVar4 & 0x80) != 0x80) {
      uVar4 = 0;
    }
    uVar3 = FUN_000618f8(param_1,uVar4,param_2);
    cVar1 = FUN_00062420(uVar3);
    if (cVar1 == '\x01') {
      if (((byte)uVar4 & 0x80) != 0x80) {
        FUN_00062dd8(uVar4);
        FUN_0006310a(uVar3);
      }
      FUN_00063026(param_2);
    }
  }
  FUN_000628b8();
LAB_00060c38:
  DAT_ffffd6c0 = (undefined1)uVar3;
  DAT_ffffd6c3 = (undefined1)uVar4;
  FUN_000623b0();
  if ((uint)DAT_ffffd6c4 == (param_1 & 0xffff)) {
    FUN_00062080(param_1,0x20);
  }
  FUN_000620e8(param_1,0x20,uVar4);
  FUN_0006289a();
  return;
}


/* ROM address: 0x00060c7a; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f56a (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00060c7a(short param_1,char param_2)

{
  FUN_000623b0();
  FUN_00062080((int)param_1,(int)param_2);
  FUN_000620e8((int)param_1,(int)param_2,0);
  FUN_0006289a();
  return;
}


/* ROM address: 0x00060ca6; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f596 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00060ca6(short *param_1)

{
  FUN_00062420(8);
  FUN_00060fa4(param_1);
  FUN_0006217c(param_1);
  FUN_00060fe6(param_1);
  FUN_00060e10(param_1);
  FUN_00060f36(param_1);
  FUN_00060534((int)*param_1);
  FUN_000628b8();
  return;
}


/* ROM address: 0x00060cd6; body bytes: 162; decompiled */

uint FUN_00060cd6(undefined4 param_1)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  
  uVar1 = FUN_00062df8();
  uVar3 = uVar1 & 0xff;
  if (uVar3 != 0) {
    if ((uVar3 == 0) || (0x3f < uVar3)) {
      if ((0x80 < uVar3) && (uVar3 < 0xc0)) {
        cVar2 = FUN_000630b8(param_1);
        if (cVar2 == '\x01') {
          uVar1 = FUN_00060dae(param_1,uVar1);
          return uVar1;
        }
        return 0x81;
      }
      if (uVar3 == 0xc0) {
        return uVar1;
      }
      if (uVar3 == 0xc1) {
        return 0xc0;
      }
      if (uVar3 != 0x50) {
        return uVar1;
      }
      uVar1 = FUN_00060dae(param_1,0);
      return uVar1;
    }
    cVar2 = FUN_000630b8(param_1);
    if (cVar2 != '\x01') {
      return 1;
    }
  }
  uVar1 = FUN_00060dae(param_1,uVar1);
  return uVar1;
}


/* ROM address: 0x00060dae; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f69e (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00060dae(uint param_1,uint param_2)

{
  if (((&DAT_ffff8d54)[(param_1 & 0xffff) * 2] != ' ') &&
     (param_2 = param_2 + 1, (uint)(byte)(&DAT_0007e3b6)[param_1 & 0xffff] <= (param_2 & 0x7f))) {
    param_2 = 0xc0;
  }
  return param_2;
}


/* ROM address: 0x00060ddc; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f6cc (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00060ddc(undefined4 param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00062df8();
  if ((param_2 & 0xff) != (uVar1 & 0xff)) {
    FUN_00062dd8(param_2);
    uVar1 = FUN_000621d8(uVar1,param_2);
    return uVar1;
  }
  return uVar1;
}


/* ROM address: 0x00060e10; body bytes: 204; decompiled */

undefined ** FUN_00060e10(ushort *param_1)

{
  byte bVar1;
  undefined **ppuVar2;
  
  bVar1 = *(byte *)(param_1 + 3);
  ppuVar2 = (undefined **)&DAT_ffff8d54;
  if (((bVar1 != 0) && (bVar1 < 0x40)) &&
     (ppuVar2 = (undefined **)(uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2],
     ppuVar2 == &vector_Illegal_instr)) {
    FUN_00062dd8(0);
    ppuVar2 = (undefined **)FUN_0006310a(8);
    return ppuVar2;
  }
  if (((bVar1 < 0x81) || (0xbf < bVar1)) ||
     (ppuVar2 = (undefined **)(uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2],
     ppuVar2 != &vector_Illegal_instr)) {
    if (bVar1 == 0xc0) {
      ppuVar2 = (undefined **)(uint)(byte)(&DAT_ffff87b8)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10];
      if ((undefined **)(uint)(byte)(&DAT_0007e442)[*param_1] <= ppuVar2) {
        ppuVar2 = (undefined **)FUN_00062dd8(0xc1);
      }
    }
    else if ((bVar1 == 0xc1) &&
            (ppuVar2 = (undefined **)(uint)(byte)(&DAT_ffff87b9)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10],
            (undefined **)(uint)(byte)(&DAT_0007e4ce)[*param_1] <= ppuVar2)) {
      FUN_00062dd8(0);
      ppuVar2 = (undefined **)FUN_0006310a(8);
      return ppuVar2;
    }
  }
  else {
    ppuVar2 = (undefined **)FUN_00062dd8(0xc1);
  }
  return ppuVar2;
}


/* ROM address: 0x00060f02; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f7f2 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00060f02(uint param_1)

{
  if (((&DAT_ffff87b6)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10] == -0x40) &&
     ((&CAL_DTC_0300_Enable_Disable_1_1129)[param_1 & 0xffff] == '\x01')) {
    FUN_00062e4a(0xc0);
    return;
  }
  return;
}


/* ROM address: 0x00060f36; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f826 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00060f36(void)

{
  undefined1 *puVar1;
  
  if ((&DAT_ffff87b6)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10] == -0x3f) {
    puVar1 = (undefined1 *)FUN_00062e4a(0);
    return puVar1;
  }
  return &DAT_ffff87b6;
}


/* ROM address: 0x00060f58; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f848 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00060f58(void)

{
  undefined1 *puVar1;
  
  if ((&DAT_ffff87b6)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10] == -0x40) {
    puVar1 = (undefined1 *)FUN_00062ebc(0);
    return puVar1;
  }
  return &DAT_ffff87b6;
}


/* ROM address: 0x00060fa4; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f894 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined ** FUN_00060fa4(ushort *param_1)

{
  undefined **ppuVar1;
  
  ppuVar1 = (undefined **)(uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2];
  if ((ppuVar1 == &vector_Illegal_instr) ||
     (ppuVar1 == (undefined **)((int)&vector_Illegal_instr + 1))) {
    ppuVar1 = (undefined **)&DAT_0007e442;
    if (*(byte *)((int)param_1 + 9) < (byte)(&DAT_0007e442)[*param_1]) {
      ppuVar1 = (undefined **)FUN_00062ebc((char)*(byte *)((int)param_1 + 9) + 1);
      return ppuVar1;
    }
  }
  return ppuVar1;
}


/* ROM address: 0x00060fe6; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f8d6 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00060fe6(ushort *param_1)

{
  uint uVar1;
  
  if ((byte)(&DAT_ffff8d54)[(uint)*param_1 * 2] == 0x10) {
    uVar1 = FUN_00063098(0);
    return uVar1;
  }
  return (uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2];
}


/* ROM address: 0x00061014; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f904 (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00061014(void)

{
  char cVar2;
  short sVar1;
  undefined4 uVar3;
  
  uVar3 = 0;
  cVar2 = FUN_000655e4();
  if ((((cVar2 != '\0') || (cVar2 = FUN_000644e4(), cVar2 != '\0')) ||
      (sVar1 = FUN_00002034(&inferred_ram_8788_ffff8788_ffff8788), sVar1 != 0)) ||
     ((cVar2 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff878c), cVar2 != '\0' ||
      (sVar1 = FUN_00002034(&DAT_ffff8784), sVar1 != 0)))) {
    uVar3 = 1;
  }
  return uVar3;
}


/* ROM address: 0x0006106e; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005f95e (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006106e(void)

{
  DAT_ffff878c = rx8_pack_u8_with_complement(0);
  DAT_ffff8784 = rx8_pack_u16_with_complement(0);
  inferred_ram_8788_ffff8788_ffff8788 = rx8_pack_u16_with_complement(0);
  return;
}


/* [EXPORT CLEANUP]
 * The two call sites formerly named thunk_FUN_00060c7a were resolved to
 * distinct thunks from the disassembly: the jsr at 0x61132 loads
 * ROM32[0x61254] = 0x64912 and the jsr at 0x61146 loads ROM32[0x61258] =
 * 0x64004. Both tail-jump to FUN_00060c7a; the call-site names now carry the
 * thunk addresses.
 */
/* ROM address: 0x00061092; body bytes: 458; decompiled */

/* Function candidate recovered from ROM pointer at 67d14 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00061092(uint *param_1)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined **ppuVar8;
  
  uVar3 = *param_1;
  uVar5 = param_1[1];
  uVar6 = param_1[2];
  ppuVar8 = (undefined **)(uVar5 & 0xff);
  uVar2 = *(ushort *)(&DAT_0007df42 + (uVar3 & 0xffff) * 2);
  iVar7 = (int)(short)uVar2;
  DAT_ffffd6c4 = uVar2;
  if ((ppuVar8 == &vector_Illegal_instr) ||
     (ppuVar8 == (undefined **)((int)&vector_Illegal_instr + 1))) {
    ppuVar8 = (undefined **)FUN_00060538(iVar7,0x10);
    cVar1 = (&DAT_0007e32a)[uVar2];
    FUN_000623a0(iVar7);
    if (*(ushort *)ppuVar8 == uVar2) {
      FUN_00062420(8);
      FUN_00063026(0);
      FUN_000628b8();
      ppuVar8 = ppuVar8 + 1;
    }
    if (cVar1 == '\0') {
      FUN_00060c7a(iVar7,0x10);
    }
    else if (cVar1 == '\x01') {
      FUN_000648cc(iVar7,uVar5);
    }
    else if (cVar1 == '\x02') {
      jump_to_FUN_00060c7a(iVar7,uVar5);
    }
    else if (cVar1 == '\x03') {
      jump_to_FUN_00060c7a(iVar7,uVar5);
    }
    FUN_000627a0();
  }
  else if (ppuVar8 == (undefined **)&UNK_00000020) {
    ppuVar8 = (undefined **)FUN_00060538(iVar7,0x20);
  }
  for (uVar4 = 0; (*(ushort *)ppuVar8 != 0xffff && (uVar4 < 2)); uVar4 = uVar4 + 1) {
    FUN_000623a0((int)(short)*(ushort *)ppuVar8);
    DAT_ffffd6bc = *(ushort *)ppuVar8;
    cVar1 = (&DAT_0007e32a)[DAT_ffffd6bc];
    if (cVar1 == '\0') {
      FUN_00060b14((int)(short)*(ushort *)ppuVar8,(int)*(char *)((int)ppuVar8 + 2));
    }
    else if (cVar1 == '\x01') {
      FUN_00064620((int)(short)*(ushort *)ppuVar8,(int)*(char *)((int)ppuVar8 + 2),uVar6);
    }
    else if (cVar1 == '\x02') {
      FUN_0006477c((int)(short)*(ushort *)ppuVar8,(int)*(char *)((int)ppuVar8 + 2),uVar6);
    }
    else if (cVar1 == '\x03') {
      FUN_00063f64((int)(short)*(ushort *)ppuVar8,(int)*(char *)((int)ppuVar8 + 2));
    }
    if (*(ushort *)ppuVar8 == uVar2) {
      FUN_00061eb0((int)(short)*(ushort *)ppuVar8,(int)*(char *)((int)ppuVar8 + 2),uVar6);
      sh_copy_bytes_forward_r0_r1_r2();
    }
    else {
      FUN_00061fc0((int)(short)*(ushort *)ppuVar8,(int)*(char *)((int)ppuVar8 + 2));
      sh_copy_bytes_forward_r0_r1_r2();
    }
    FUN_00060596();
    FUN_000627a0();
    ppuVar8 = ppuVar8 + 1;
  }
  FUN_00060a96();
  *param_1 = uVar3 & 0xffff;
  FUN_000602a4(*param_1,(int)*(char *)((int)param_1 + 7),param_1[2]);
  return;
}


/* ROM address: 0x000612ee; body bytes: 266; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 0005fbde (266 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000612ee(void)

{
  char cVar1;
  
  FUN_00064530();
  if ((DAT_ffff8e7c == '\x01') && (DAT_ffff878c._0_1_ == '\0')) {
    DAT_ffff878c = rx8_pack_u8_with_complement(1);
    cVar1 = FUN_0006328a(0);
    while (cVar1 == '\x01') {
      FUN_000623a0((int)(short)DAT_ffffd790);
      cVar1 = (&DAT_0007e32a)[DAT_ffffd790];
      if (cVar1 == '\0') {
        FUN_00060ca6(&DAT_ffffd790);
      }
      else if (cVar1 == '\x01') {
        FUN_00064918(&DAT_ffffd790);
      }
      else if (cVar1 == '\x02') {
        FUN_00064972(&DAT_ffffd790);
      }
      else if (cVar1 == '\x03') {
        FUN_0006400a(&DAT_ffffd790);
      }
      FUN_000606be();
      FUN_000627a0();
      cVar1 = FUN_0006328a(1);
    }
    FUN_00060a96();
  }
  FUN_0006455c();
  _DAT_ffff8e7c = rx8_pack_u8_with_complement(0);
  FUN_00063efc();
  cVar1 = DAT_ffff8e7e;
  _DAT_ffff8e7e = rx8_pack_u8_with_complement(0);
  FUN_00062040((int)cVar1);
  FUN_00060592();
  DAT_ffff878c = rx8_pack_u8_with_complement(0);
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffff87b0 dtc_master_table_21 (uint8[0x150]): 21 x 0x10 B master DTC table: u16 slot at +0, state byte at +6, priority at +0x0d; scanned by 0x61450/0x615c6, iterated by 0x6328a.
 * RAM 0xffff8900 dtc_master_current_index (uint16): Current master-table index; excluded from every scan (0x61450/0x615c6/0x62df8).
 */
/* ROM address: 0x00061450; body bytes: 342; decompiled */

int FUN_00061450(char param_1,char param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  do {
    if (uVar3 != dtc_master_current_index_ffff8900._0_2_) {
      bVar1 = (&DAT_ffff87b6)[uVar3 * 0x10];
      if (((param_2 == '\0') ||
          ((param_2 == '\x01' &&
           ((&CAL_DTC_0300_Enable_Disable_1_1129)[(ushort)(&dtc_master_table_21_ffff87b0)[uVar3 * 8]] == '\x01'))))
         || ((param_2 == '\x02' && ((&DAT_0007e704)[(ushort)(&dtc_master_table_21_ffff87b0)[uVar3 * 8]] == '\x01')))
         ) {
        if (param_1 == '\0') {
          if (bVar1 == 0) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (param_1 == '`') {
          if ((bVar1 != 0) && (bVar1 < 0x40)) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (param_1 == -0x80) {
          if ((bVar1 & 0x80) == 0x80) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (param_1 == -0x40) {
          if (bVar1 == 0xc0) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (param_1 == -0x3f) {
          if (bVar1 == 0xc1) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (param_1 == 'P') {
          if (bVar1 == 0x50) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (param_1 == -0x10) {
          if (((bVar1 != 0) && (bVar1 < 0x40)) || ((bVar1 & 0x80) == 0x80)) {
            iVar2 = iVar2 + 1;
          }
        }
        else if (((param_1 == 'p') && (0x80 < bVar1)) && (bVar1 < 0xc0)) {
          iVar2 = iVar2 + 1;
        }
      }
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x15);
  return iVar2;
}


/* ROM address: 0x000615c6; body bytes: 366; decompiled */

uint FUN_000615c6(char param_1,char param_2,int param_3)

{
  ushort uVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  
  uVar3 = dtc_master_current_index_ffff8900._0_2_;
  uVar4 = 0;
  uVar5 = 0;
  do {
    if (uVar5 != uVar3) {
      bVar2 = (&DAT_ffff87b6)[uVar5 * 0x10];
      uVar1 = (&dtc_master_table_21_ffff87b0)[uVar5 * 8];
      if (((param_2 == '\0') ||
          ((param_2 == '\x01' && ((&CAL_DTC_0300_Enable_Disable_1_1129)[uVar1] == '\x01')))) ||
         ((param_2 == '\x02' && ((&DAT_0007e704)[uVar1] == '\x01')))) {
        puVar6 = (ushort *)((uVar4 & 0xffff) * 2 + param_3);
        if (param_1 == '\0') {
          if (bVar2 == 0) {
            *puVar6 = uVar1;
            uVar4 = uVar4 + 1;
          }
        }
        else if (param_1 == '`') {
          if ((bVar2 != 0) && (bVar2 < 0x40)) {
            *puVar6 = uVar1;
            uVar4 = uVar4 + 1;
          }
        }
        else if (param_1 == -0x80) {
          if ((bVar2 & 0x80) == 0x80) {
            *puVar6 = uVar1;
            uVar4 = uVar4 + 1;
          }
        }
        else if (param_1 == -0x40) {
          if (bVar2 == 0xc0) {
            *puVar6 = uVar1;
            uVar4 = uVar4 + 1;
          }
        }
        else if (param_1 == -0x3f) {
          if (bVar2 == 0xc1) {
            *puVar6 = uVar1;
            uVar4 = uVar4 + 1;
          }
        }
        else if (param_1 == 'P') {
          if (bVar2 == 0x50) {
            *puVar6 = uVar1;
            uVar4 = uVar4 + 1;
          }
        }
        else if (param_1 == -0x10) {
          if (((bVar2 != 0) && (bVar2 < 0x40)) || ((bVar2 & 0x80) == 0x80)) {
            *puVar6 = uVar1;
            uVar4 = uVar4 + 1;
          }
        }
        else if (((param_1 == 'p') && (0x80 < bVar2)) && (bVar2 < 0xc0)) {
          *puVar6 = uVar1;
          uVar4 = uVar4 + 1;
        }
      }
    }
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 0x15);
  return uVar4;
}


/* ROM address: 0x00061800; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000600f0 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00061800(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00062df8();
  uVar2 = uVar1 & 0xff;
  if ((uVar2 == 0) || (0x3f < uVar2)) {
    if ((0x80 < uVar2) && (uVar2 < 0xc0)) {
      uVar1 = 0x70;
    }
  }
  else {
    uVar1 = 0x60;
  }
  return uVar1;
}


/* ROM address: 0x000618b4; body bytes: 6; decompiled */

int FUN_000618b4(void)

{
  return (int)DAT_ffff8784._0_2_;
}


/* ROM address: 0x000618ba; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000601aa (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000618ba(void)

{
  int iVar1;
  
  iVar1 = (int)DAT_ffff8784._0_2_;
  if (DAT_ffff8784._0_2_ != -1) {
    iVar1 = iVar1 + 1;
  }
  DAT_ffff8784 = rx8_pack_u16_with_complement(iVar1);
  return;
}


/* [RX8DEFS 2026-09-30 000618f8]
 * Suggested interpretation: inferred_apply_diagnostic_index_policy.
 * Confidence: indexed byte-policy use verified; individual DTC mapping unresolved.
 * Reads bytes from 0x7e704 indexed by param_1 and branches on values zero/one. Related reads occur in 6071e, 61450, 615c6 and 61d28. This supports diagnostic policy bytes but does not independently map the upstream #1 bank at 7e678/7e679 to SAE DTC identities.
 */
/* ROM address: 0x000618f8; body bytes: 194; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000601e8 (194 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000618f8(uint param_1,byte param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 8;
  param_1 = param_1 & 0xffff;
  cVar1 = (&DAT_0007e32a)[param_1];
  if (cVar1 == '\0') {
    if ((param_2 == 0) || (0x3f < param_2)) {
      if ((param_2 & 0x80) == 0x80) {
        if ((&DAT_0007e704)[param_1] == '\0') {
          uVar2 = 5;
        }
        else if ((&DAT_0007e704)[param_1] == '\x01') {
          if ((&CAL_DTC_0300_Enable_Disable_1_1129)[param_1] == '\0') {
            uVar2 = 4;
          }
          else if ((&CAL_DTC_0300_Enable_Disable_1_1129)[param_1] == '\x01') {
            uVar2 = 3;
          }
        }
      }
    }
    else {
      uVar2 = 6;
    }
  }
  else if (((cVar1 == '\x03') || (cVar1 == '\x01')) || (cVar1 == '\x02')) {
    if ((param_2 == 0) || (0x3f < param_2)) {
      if ((param_2 & 0x80) == 0x80) {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 2;
    }
  }
  return uVar2;
}


/* ROM address: 0x000619ba; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000602aa (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000619ba(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_000615c6();
  uVar1 = FUN_0006694a(&DAT_ffffd766,uVar1,&DAT_ffffd73e);
  return uVar1;
}


/* ROM address: 0x00061ae6; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000603d6 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00061ae6(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_000606f6();
  return uVar1;
}


/* ROM address: 0x00061af4; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000603e4 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00061af4(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0006071e();
  return uVar1;
}


/* ROM address: 0x00061b02; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000603f2 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00061b02(uint param_1)

{
  undefined4 uVar1;
  undefined4 local_c;
  uint uStack_8;
  
  uStack_8 = param_1 & 0xffff;
  local_c = 0x14;
  uVar1 = os_schedule_task_event(2,3,&local_c);
  return uVar1;
}


/* ROM address: 0x00061b28; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060418 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00061b28(uint param_1)

{
  undefined4 uVar1;
  uint local_8 [2];
  
  local_8[0] = param_1 & 0xffff;
  uVar1 = os_schedule_task_event(2,5,local_8);
  return uVar1;
}


/* ROM address: 0x00061b8c; body bytes: 392; decompiled */

/* Function candidate recovered from ROM pointer at 67d2c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00061b8c(uint *param_1)

{
  char cVar2;
  undefined4 uVar1;
  char cVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = *param_1;
  FUN_000623a0(uVar4);
  FUN_000623b0();
  FUN_00063e78(0);
  FUN_00063ecc(0);
  FUN_0006289a();
  cVar2 = FUN_00062df8(uVar4);
  uVar5 = uVar4 & 0xffff;
  if ((cVar2 != '\0') && (cVar2 != 'P')) {
    FUN_00062420(8);
    FUN_00062dd8(0);
    FUN_0006310a(8);
    FUN_00062e4a(0);
    FUN_00063026(0);
    FUN_00063098(0);
    FUN_00062ebc((int)(char)(&DAT_0007e442)[uVar5]);
    FUN_00062f2e((int)(char)(&DAT_0007e4ce)[uVar5]);
    FUN_00062fa0(0x50);
    FUN_000628b8();
  }
  uVar1 = FUN_00063998(uVar4);
  cVar3 = FUN_00063920(uVar1);
  if ((cVar3 != '\0') && (cVar3 != '\x01')) {
    FUN_00062570(8);
    FUN_0006381c();
    FUN_000628d6();
  }
  cVar3 = (&DAT_0007e32a)[uVar5];
  if (((cVar3 == '\x01') || (cVar3 == '\x02')) || (cVar3 == '\x03')) {
    FUN_00062668();
    FUN_00067760();
    FUN_0006763c(0);
    FUN_000676c8(0);
    FUN_0006789e(0);
    FUN_000628f4();
  }
  if (((&DAT_0007e32a)[uVar5] == '\x01') || ((&DAT_0007e32a)[uVar5] == '\x02')) {
    if ((&DAT_0007e32a)[uVar5] == '\x01') {
      cVar2 = FUN_00062df8(1);
      uVar5 = FUN_000630b8(1);
    }
    else if ((&DAT_0007e32a)[uVar5] == '\x02') {
      cVar2 = FUN_00062df8(0);
      uVar5 = FUN_000630b8(0);
    }
    FUN_000626d4(0);
    if ((cVar2 == '\0') || (cVar2 == 'P')) {
      FUN_00067b88(0);
      FUN_00067c64(0);
    }
    if ((uVar5 & 0xff) == 0) {
      FUN_00067c06(0);
    }
    FUN_00062918(0);
  }
  FUN_000627a0();
  FUN_00060a96();
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffff8788 inferred_ram_8788_ffff8788 (uint16): PID 0x30 via 0x61d14
 */
/* ROM address: 0x00061d14; body bytes: 6; decompiled */

int FUN_00061d14(void)

{
  return (int)inferred_ram_8788_ffff8788_ffff8788._0_2_;
}


/* ROM address: 0x00061d1a; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006060a (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00061d1a(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_000630b8();
  return uVar1;
}


/* ROM address: 0x00061d28; body bytes: 214; decompiled */

uint FUN_00061d28(char param_1,char param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  
  uVar2 = dtc_master_current_index_ffff8900._0_2_;
  uVar3 = 0;
  uVar5 = 0;
  do {
    uVar1 = (&dtc_master_table_21_ffff87b0)[uVar3 * 8];
    if ((uVar3 != uVar2) && (uVar1 != 0xffff)) {
      if (((param_2 == '\0') ||
          ((param_2 == '\x01' && ((&CAL_DTC_0300_Enable_Disable_1_1129)[uVar1] == '\x01')))) ||
         ((param_2 == '\x02' && ((&DAT_0007e704)[uVar1] == '\x01')))) {
        puVar4 = (ushort *)((uVar5 & 0xffff) * 2 + param_3);
        if (param_1 == '\0') {
          if ((&DAT_ffff87bc)[uVar3 * 0x10] == '\0') {
            *puVar4 = uVar1;
            uVar5 = uVar5 + 1;
          }
        }
        else if ((param_1 == '\x01') && ((&DAT_ffff87bc)[uVar3 * 0x10] == '\x01')) {
          *puVar4 = uVar1;
          uVar5 = uVar5 + 1;
        }
      }
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x15);
  return uVar5;
}


/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00061eb0; body bytes: 258; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000607a0 (258 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00061eb0(uint param_1,char param_2,undefined2 param_3)

{
  byte snapshot_DAT_ffffd6c3;
  byte bVar2;
  char cVar3;
  
  bVar2 = FUN_00062df8(param_1);
  snapshot_DAT_ffffd6c3 = DAT_ffffd6c3;
  cVar3 = FUN_00063046(param_1);
  if ((bVar2 == 0) || (bVar2 == 0x50)) {
    if ((snapshot_DAT_ffffd6c3 == 0) || (0x3f < snapshot_DAT_ffffd6c3)) {
      if ((snapshot_DAT_ffffd6c3 & 0x80) == 0x80) {
        DAT_ffffd6be = param_3;
        DAT_ffffd6c2 = 2;
        return;
      }
      if (param_2 == '\x01') goto LAB_00061f7a;
      if (param_2 != '\x02') {
        if (((param_1 & 0xffff) != 0) && ((param_1 & 0xffff) != 1)) {
          DAT_ffffd6be = param_3;
          DAT_ffffd6c2 = 8;
          return;
        }
        DAT_ffffd6be = param_3;
        DAT_ffffd6c2 = 9;
        return;
      }
      if (cVar3 != '\0') {
        DAT_ffffd6be = param_3;
        DAT_ffffd6c2 = 4;
        return;
      }
    }
    DAT_ffffd6c2 = 1;
  }
  else {
    if ((bVar2 == 0) || (0x3f < bVar2)) {
      if ((bVar2 & 0x80) != 0x80) {
        DAT_ffffd6be = param_3;
        DAT_ffffd6c2 = 8;
        return;
      }
      DAT_ffffd6be = param_3;
      DAT_ffffd6c2 = 5;
      return;
    }
    if ((snapshot_DAT_ffffd6c3 & 0x80) == 0x80) {
      DAT_ffffd6be = param_3;
      DAT_ffffd6c2 = 3;
      return;
    }
    if ((snapshot_DAT_ffffd6c3 != 0) && (snapshot_DAT_ffffd6c3 != 0x50)) {
      if (snapshot_DAT_ffffd6c3 == 0) {
        DAT_ffffd6be = param_3;
        DAT_ffffd6c2 = 8;
        return;
      }
      if (0x3f < snapshot_DAT_ffffd6c3) {
        DAT_ffffd6be = param_3;
        DAT_ffffd6c2 = 8;
        return;
      }
      DAT_ffffd6be = param_3;
      DAT_ffffd6c2 = 4;
      return;
    }
LAB_00061f7a:
    DAT_ffffd6c2 = 7;
  }
  DAT_ffffd6be = param_3;
  return;
}


/* ROM address: 0x00061fc0; body bytes: 128; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000608b0 (128 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00061fc0(undefined4 param_1,char param_2)

{
  byte bVar1;
  undefined1 uVar2;
  
  uVar2 = 8;
  bVar1 = FUN_00062df8();
  if (((bVar1 == 0) || (bVar1 == 0x50)) || ((bVar1 != 0 && (bVar1 < 0x40)))) {
    if (param_2 == '\x03') {
      if ((DAT_ffffd6c3 & 0x80) == 0x80) {
        uVar2 = 6;
      }
      else {
        uVar2 = 8;
      }
    }
    else if (param_2 == '\x01') {
      uVar2 = 7;
    }
  }
  else if ((bVar1 & 0x80) == 0x80) {
    uVar2 = 8;
  }
  DAT_ffffd6c2 = uVar2;
  return;
}


/* ROM address: 0x00062040; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060930 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00062040(uint param_1)

{
  bool bVar1;
  int iVar2;
  
  param_1 = param_1 & 0xff;
  if ((param_1 == 1) && (iVar2 = (int)inferred_ram_8788_ffff8788_ffff8788._0_2_, bVar1 = inferred_ram_8788_ffff8788_ffff8788._0_2_ != -1, bVar1))
  {
    param_1 = rx8_pack_u16_with_complement(iVar2 + 1);
    inferred_ram_8788_ffff8788_ffff8788 = param_1;
  }
  return param_1;
}


/* ROM address: 0x00062080; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060970 (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00062080(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)(byte)(&DAT_ffff8d54)[(param_1 & 0xffff) * 2];
  uVar2 = param_2 & 0xff;
  if (uVar1 == 0) {
    uVar1 = FUN_00063e78(param_2);
  }
  else if (uVar1 == 0x10) {
    if ((uVar2 == 0x20) || (uVar1 = uVar2, uVar2 == 0x11)) {
      uVar1 = FUN_00063e78(param_2);
    }
  }
  else if ((uVar1 == 0x11) && (uVar1 = uVar2, uVar2 == 0x20)) {
    uVar1 = FUN_00063e78(param_2);
  }
  return uVar1;
}


/* ROM address: 0x000620e8; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000609d8 (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000620e8(uint param_1,byte param_2,char param_3)

{
  uint uVar1;
  
  uVar1 = (uint)param_2;
  if ((uVar1 == 0x10) || (uVar1 == 0x11)) {
    uVar1 = FUN_00063ecc((int)(char)(&DAT_ffff8d55)[(param_1 & 0xffff) * 2] | 1);
    return uVar1;
  }
  if ((uVar1 == 0x20) && ((param_3 == -0x40 || (param_3 == -0x3f)))) {
    uVar1 = FUN_00063ecc((int)(char)(&DAT_ffff8d55)[(param_1 & 0xffff) * 2] | 2);
    return uVar1;
  }
  return uVar1;
}


/* ROM address: 0x00062138; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060a28 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00062138(void)

{
  undefined1 *puVar1;
  
  if ((&DAT_ffff87b6)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10] == -0x40) {
    puVar1 = (undefined1 *)FUN_00062f2e(0);
    return puVar1;
  }
  return &DAT_ffff87b6;
}


/* ROM address: 0x0006217c; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060a6c (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined * FUN_0006217c(ushort *param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2];
  if (((puVar1 != &UNK_00000020) &&
      (puVar1 = (undefined *)(uint)DAT_ffff8e7e,
      puVar1 == (undefined *)((int)&vector_Poweron_Reset + 1))) &&
     (puVar1 = &DAT_0007e442, (byte)(&DAT_0007e442)[*param_1] <= *(byte *)((int)param_1 + 9))) {
    puVar1 = &DAT_0007e4ce;
    if (*(byte *)(param_1 + 4) < (byte)(&DAT_0007e4ce)[*param_1]) {
      puVar1 = (undefined *)FUN_00062f2e((char)*(byte *)(param_1 + 4) + 1);
      return puVar1;
    }
  }
  return puVar1;
}


/* ROM address: 0x000621d8; body bytes: 150; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060ac8 (150 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000621d8(byte param_1,byte param_2)

{
  undefined4 uVar1;
  
  if (param_1 != param_2) {
    if (param_2 == 1) {
      if ((param_1 == 0) || (param_1 == 0x50)) {
        FUN_000618ba();
        uVar1 = FUN_000618b4();
        FUN_0006317c(uVar1);
        FUN_000631fc(0xffff);
        return;
      }
    }
    else if (((param_2 == 0xc0) || (param_2 == 0xc1)) && ((param_1 & 0x80) != 0x80)) {
      FUN_000618ba();
      uVar1 = FUN_000618b4();
      FUN_000631fc(uVar1);
      if ((param_1 == 0) || (param_1 == 0x50)) {
        FUN_0006317c(uVar1);
        return;
      }
    }
  }
  return;
}


/* ROM address: 0x0006229c; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060b8c (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0006229c(void)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  cVar1 = FUN_0006293c();
  if ((((cVar1 != '\0') || (cVar1 = FUN_00061014(), cVar1 != '\0')) ||
      (cVar1 = FUN_00060560(), cVar1 != '\0')) || (cVar1 = FUN_00060a68(), cVar1 != '\0')) {
    uVar2 = 1;
  }
  return uVar2;
}


/* ROM address: 0x000622e0; body bytes: 124; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00060bd0 (124 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000622e0(void)

{
  _DAT_ffff879c = rx8_pack_u16_with_complement(0xffff);
  DAT_ffff87a0 = rx8_pack_u16_with_complement(0xffff);
  DAT_ffff8790 = rx8_pack_u16_with_complement(0xffff);
  DAT_ffff8794 = rx8_pack_u16_with_complement(0xffff);
  DAT_ffff8798 = rx8_pack_u8_with_complement(1);
  DAT_ffff87a4 = rx8_pack_u8_with_complement(2);
  DAT_ffff87a6 = rx8_pack_u8_with_complement(2);
  DAT_ffff87a8 = rx8_pack_u8_with_complement(2);
  _DAT_ffff87aa = rx8_pack_u8_with_complement(2);
  DAT_ffff87ac = rx8_pack_u8_with_complement(2);
  FUN_00063e24();
  FUN_00062ca0();
  FUN_000635ee();
  FUN_00067476();
  FUN_00067a24();
  return;
}


/* ROM address: 0x0006235c; body bytes: 68; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00060c4c (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006235c(void)

{
  if (DAT_ffff8798._0_1_ == '\0') {
    FUN_00062aa8();
    return;
  }
  DAT_ffff87a4 = rx8_pack_u8_with_complement(2);
  DAT_ffff87a6 = rx8_pack_u8_with_complement(2);
  DAT_ffff87a8 = rx8_pack_u8_with_complement(2);
  _DAT_ffff87aa = rx8_pack_u8_with_complement(2);
  DAT_ffff87ac = rx8_pack_u8_with_complement(2);
  return;
}


/* ROM address: 0x000623a0; body bytes: 16; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00060c90 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000623a0(void)

{
  _DAT_ffff879c = rx8_pack_u16_with_complement();
  return;
}


/* ROM address: 0x000623b0; body bytes: 112; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00060ca0 (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000623b0(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (DAT_ffff87a4._0_1_ == '\x02') {
    uVar1 = (uint)DAT_ffff879c;
    _DAT_ffff8e72 = rx8_pack_u8_with_complement((int)(char)(&DAT_ffff8d54)[uVar1 * 2]);
    _DAT_ffff8e74 = rx8_pack_u8_with_complement((int)(char)(&DAT_ffff8d55)[uVar1 * 2]);
    _DAT_ffff8e70 = rx8_pack_u8_with_complement((int)DAT_ffff8e6c._0_1_);
    DAT_ffff87a4 = rx8_pack_u8_with_complement(1);
  }
  else if (DAT_ffff87a4._0_1_ == '\x01') {
    uVar2 = 0;
  }
  else {
    DAT_ffff87a4 = rx8_pack_u8_with_complement(1);
  }
  return uVar2;
}


/* ROM address: 0x00062420; body bytes: 198; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060d10 (198 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00062420(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  short local_18 [2];
  char cStack_14;
  
  local_18[0] = -1;
  uVar2 = 1;
  cStack_14 = param_1;
  if (DAT_ffff87a6._0_1_ == '\x02') {
    iVar3 = (int)DAT_ffff879c;
    DAT_ffff87a6 = rx8_pack_u8_with_complement(1);
    cVar1 = FUN_00062d2c(iVar3);
    if (cVar1 == '\0') {
      sh_copy_bytes_forward_r0_r1_r2(&dtc_master_table_21_ffff87b0);
      FUN_00062dae(iVar3);
    }
    else if (cVar1 == '\x01') {
      FUN_000634b8(iVar3);
    }
    else {
      cVar1 = FUN_00063396(iVar3,(int)cStack_14,local_18);
      if (cVar1 == '\x02') {
        FUN_000634b8(iVar3);
      }
      else {
        uVar2 = 0;
      }
    }
  }
  else if (DAT_ffff87a6._0_1_ == '\x01') {
    uVar2 = 0;
  }
  else {
    DAT_ffff87a6 = rx8_pack_u8_with_complement(1);
  }
  DAT_ffff8790 = rx8_pack_u16_with_complement((int)local_18[0]);
  return uVar2;
}


/* ROM address: 0x00062570; body bytes: 248; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060e60 (248 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00062570(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  short local_24 [2];
  char cStack_20;
  
  uVar2 = 1;
  local_24[0] = -1;
  cStack_20 = param_1;
  if (DAT_ffff87a8._0_1_ == '\x02') {
    iVar3 = (int)DAT_ffff879c;
    DAT_ffff87a8 = rx8_pack_u8_with_complement(1);
    cVar1 = FUN_00063680(iVar3);
    if (cVar1 == '\0') {
      sh_copy_bytes_forward_r0_r1_r2();
    }
    else if (cVar1 == '\x01') {
      iVar4 = (uint)DAT_ffff8d4c._0_2_ * 0x34;
      (&DAT_ffff893a)[iVar4] = (&DAT_ffff893a)[iVar4] + (&DAT_ffff890f)[iVar4];
      (&DAT_ffff890f)[iVar4] = 0;
    }
    else {
      cVar1 = FUN_00063706(iVar3,(int)cStack_20,local_24);
      if (cVar1 != '\x02') {
        uVar2 = 0;
        goto LAB_0006264a;
      }
      iVar4 = (uint)DAT_ffff8d4c._0_2_ * 0x34;
      (&DAT_ffff893a)[iVar4] = (&DAT_ffff893a)[iVar4] + (&DAT_ffff890f)[iVar4];
      (&DAT_ffff890f)[iVar4] = 0;
    }
    FUN_00063862(iVar3);
  }
  else if (DAT_ffff87a8._0_1_ == '\x01') {
    uVar2 = 0;
  }
  else {
    DAT_ffff87a8 = rx8_pack_u8_with_complement(1);
  }
LAB_0006264a:
  DAT_ffff8794 = rx8_pack_u16_with_complement((int)local_24[0]);
  return uVar2;
}


/* ROM address: 0x00062668; body bytes: 108; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00060f58 (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00062668(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 1;
  if (DAT_ffff87aa == '\x02') {
    iVar3 = (int)DAT_ffff879c;
    _DAT_ffff87aa = rx8_pack_u8_with_complement(1);
    cVar1 = FUN_00067518(iVar3);
    if (cVar1 == '\0') {
      FUN_000675c2(iVar3);
    }
    else if (cVar1 == '\x01') {
      FUN_0006791c(iVar3);
    }
  }
  else if (DAT_ffff87aa == '\x01') {
    uVar2 = 0;
  }
  else {
    _DAT_ffff87aa = rx8_pack_u8_with_complement(1);
  }
  return uVar2;
}


/* ROM address: 0x000626d4; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060fc4 (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000626d4(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (DAT_ffff87ac._0_1_ == '\x02') {
    DAT_ffff87a0 = rx8_pack_u16_with_complement(param_1);
    DAT_ffff87ac = rx8_pack_u8_with_complement(1);
    cVar1 = FUN_00067a88(param_1);
    if (cVar1 == '\0') {
      FUN_00067b28(param_1);
    }
    else if (cVar1 == '\x01') {
      FUN_00067cc2(param_1);
    }
  }
  else if (DAT_ffff87ac._0_1_ == '\x01') {
    uVar2 = 0;
  }
  else {
    DAT_ffff87ac = rx8_pack_u8_with_complement(1);
  }
  return uVar2;
}


/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000627a0; body bytes: 250; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00061090 (250 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000627a0(void)

{
  ushort snapshot_DAT_ffff879c;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  undefined4 uVar6;
  
  snapshot_DAT_ffff879c = DAT_ffff879c;
  cVar2 = DAT_ffff87a4._0_1_;
  cVar3 = DAT_ffff87a6._0_1_;
  cVar4 = DAT_ffff87a8._0_1_;
  cVar5 = DAT_ffff87ac._0_1_;
  DAT_ffff8798 = rx8_pack_u8_with_complement(0);
  uVar6 = sh_raise_interrupt_mask_return_previous(0x10);
  if (cVar2 == '\0') {
    DAT_ffff8e6c = rx8_pack_u8_with_complement((int)DAT_ffff8e70);
    *(ushort *)(&DAT_ffff8d54 + (uint)snapshot_DAT_ffff879c * 2) =
         (ushort)DAT_ffff8e72 * 0x100 + (ushort)DAT_ffff8e74;
    DAT_ffff8e6e = rx8_pack_u8_with_complement((int)DAT_ffff8e70);
  }
  if (cVar3 == '\0') {
    dtc_master_current_index_ffff8900 = rx8_pack_u16_with_complement((int)DAT_ffff8904);
  }
  if (cVar4 == '\0') {
    DAT_ffff8d4c = rx8_pack_u16_with_complement((int)DAT_ffff8d50);
  }
  if (DAT_ffff87aa == '\0') {
    FUN_000675b0();
  }
  if (cVar5 == '\0') {
    FUN_00067b16();
  }
  ref_setSR(uVar6);
  DAT_ffff8798 = rx8_pack_u8_with_complement(1);
  DAT_ffff87a4 = rx8_pack_u8_with_complement(2);
  DAT_ffff87a6 = rx8_pack_u8_with_complement(2);
  DAT_ffff87a8 = rx8_pack_u8_with_complement(2);
  _DAT_ffff87aa = rx8_pack_u8_with_complement(2);
  DAT_ffff87ac = rx8_pack_u8_with_complement(2);
  return;
}


/* ROM address: 0x0006289a; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006118a (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0006289a(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff87a4._0_1_;
  if (uVar1 == 1) {
    uVar1 = rx8_pack_u8_with_complement(0);
    DAT_ffff87a4 = (undefined2)uVar1;
  }
  return uVar1;
}


/* ROM address: 0x000628b8; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000611a8 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000628b8(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff87a6._0_1_;
  if (uVar1 == 1) {
    uVar1 = rx8_pack_u8_with_complement(0);
    DAT_ffff87a6 = (undefined2)uVar1;
  }
  return uVar1;
}


/* ROM address: 0x000628d6; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000611c6 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000628d6(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff87a8._0_1_;
  if (uVar1 == 1) {
    uVar1 = rx8_pack_u8_with_complement(0);
    DAT_ffff87a8 = (undefined2)uVar1;
  }
  return uVar1;
}


/* ROM address: 0x000628f4; body bytes: 36; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 000611e4 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000628f4(void)

{
  uint uVar1;
  
  FUN_000675f4();
  uVar1 = (uint)DAT_ffff87aa;
  if (uVar1 == 1) {
    uVar1 = rx8_pack_u8_with_complement(0);
    _DAT_ffff87aa = (undefined2)uVar1;
  }
  return uVar1;
}


/* ROM address: 0x00062918; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061208 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00062918(void)

{
  uint uVar1;
  
  FUN_00067b58();
  uVar1 = (uint)DAT_ffff87ac._0_1_;
  if (uVar1 == 1) {
    uVar1 = rx8_pack_u8_with_complement(0);
    DAT_ffff87ac = (undefined2)uVar1;
  }
  return uVar1;
}


/* ROM address: 0x0006293c; body bytes: 242; decompiled */

uint FUN_0006293c(void)

{
  short sVar1;
  char cVar2;
  uint uVar3;
  
  sVar1 = FUN_00002034(&DAT_ffff879c);
  if (((((sVar1 == 0) && (sVar1 = FUN_00002034(&DAT_ffff87a0), sVar1 == 0)) &&
       (sVar1 = FUN_00002034(&DAT_ffff8790), sVar1 == 0)) &&
      (((sVar1 = FUN_00002034(&DAT_ffff8794), sVar1 == 0 &&
        (cVar2 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8798), cVar2 == '\0')) &&
       ((cVar2 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff87a4), cVar2 == '\0' &&
        ((cVar2 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff87a6), cVar2 == '\0' &&
         (cVar2 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff87aa), cVar2 == '\0')))))))) &&
     ((cVar2 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff87a8), cVar2 == '\0' &&
      (cVar2 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff87ac), cVar2 == '\0')))) {
    uVar3 = FUN_00063d8c();
    if (((((uVar3 & 0xff) == 0) && (uVar3 = FUN_00062c10(), (uVar3 & 0xff) == 0)) &&
        (uVar3 = FUN_00063540(), (uVar3 & 0xff) == 0)) &&
       (uVar3 = FUN_000673e0(), (uVar3 & 0xff) == 0)) {
      uVar3 = FUN_00067990();
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


/* ROM address: 0x00062aa8; body bytes: 192; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00061398 (192 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00062aa8(void)

{
  if (DAT_ffff87a4._0_1_ == '\0') {
    DAT_ffff8e6c = rx8_pack_u8_with_complement((int)DAT_ffff8e70);
    *(ushort *)(&DAT_ffff8d54 + (uint)DAT_ffff879c * 2) =
         (ushort)DAT_ffff8e72 * 0x100 + (ushort)DAT_ffff8e74;
    DAT_ffff8e6e = rx8_pack_u8_with_complement((int)DAT_ffff8e70);
  }
  if (DAT_ffff87a6._0_1_ == '\0') {
    dtc_master_current_index_ffff8900 = rx8_pack_u16_with_complement((int)DAT_ffff8904);
  }
  if (DAT_ffff87a8._0_1_ == '\0') {
    DAT_ffff8d4c = rx8_pack_u16_with_complement((int)DAT_ffff8d50);
  }
  if (DAT_ffff87aa == '\0') {
    FUN_000675b0();
  }
  if (DAT_ffff87ac._0_1_ == '\0') {
    FUN_00067b16();
  }
  DAT_ffff8798 = rx8_pack_u8_with_complement(1);
  DAT_ffff87a4 = rx8_pack_u8_with_complement(2);
  DAT_ffff87a6 = rx8_pack_u8_with_complement(2);
  DAT_ffff87a8 = rx8_pack_u8_with_complement(2);
  _DAT_ffff87aa = rx8_pack_u8_with_complement(2);
  DAT_ffff87ac = rx8_pack_u8_with_complement(2);
  return;
}


/* ROM address: 0x00062b68; body bytes: 2; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061458 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00062b68(void)

{
  DAT_ffff8e6c = rx8_pack_u8_with_complement((int)DAT_ffff8e70);
  *(ushort *)(&DAT_ffff8d54 + (uint)DAT_ffff879c * 2) =
       (ushort)DAT_ffff8e72 * 0x100 + (ushort)DAT_ffff8e74;
  DAT_ffff8e6e = rx8_pack_u8_with_complement((int)DAT_ffff8e70);
  return;
}


/* ROM address: 0x00062c10; body bytes: 144; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061500 (144 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00062c10(void)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  sVar2 = FUN_00002034(&dtc_master_current_index_ffff8900);
  if ((sVar2 == 0) && (sVar2 = FUN_00002034(&DAT_ffff8904), sVar2 == 0)) {
    uVar6 = 0;
    for (uVar3 = 0; cVar4 = '\0', (int)uVar3 < 0x15; uVar3 = uVar3 + 1) {
      pcVar5 = (char *)(&dtc_master_table_21_ffff87b0 + uVar3 * 8);
      if ((DAT_ffff8798._0_1_ == '\0') || (uVar3 != dtc_master_current_index_ffff8900._0_2_)) {
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          cVar4 = cVar4 + cVar1;
        } while (pcVar5 < (char *)(uVar3 * 0x10 + -0x7841));
        if (cVar4 != -0x5b) goto LAB_00062c80;
      }
    }
  }
  else {
LAB_00062c80:
    uVar6 = 1;
  }
  return uVar6;
}


/* ROM address: 0x00062ca0; body bytes: 108; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00061590 (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00062ca0(void)

{
  undefined4 *puVar1;
  
  dtc_master_current_index_ffff8900 = rx8_pack_u16_with_complement(0);
  _DAT_ffff8904 = rx8_pack_u16_with_complement(1);
  puVar1 = (undefined4 *)&dtc_master_table_21_ffff87b0;
  do {
    *(undefined2 *)puVar1 = 0xffff;
    *(undefined2 *)((int)puVar1 + 2) = 0xffff;
    *(undefined2 *)(puVar1 + 1) = 0xffff;
    *(undefined1 *)((int)puVar1 + 6) = 0;
    *(undefined1 *)((int)puVar1 + 7) = 0;
    *(undefined1 *)(puVar1 + 2) = 3;
    *(undefined1 *)((int)puVar1 + 9) = 0x28;
    *(undefined1 *)((int)puVar1 + 10) = 0x50;
    *(undefined1 *)((int)puVar1 + 0xb) = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
    *(undefined1 *)((int)puVar1 + 0xd) = 8;
    *(undefined1 *)((int)puVar1 + 0xe) = 0x28;
    puVar1 = puVar1 + 4;
  } while (puVar1 < &dtc_master_current_index_ffff8900);
  return 0x28;
}


/* ROM address: 0x00062d2c; body bytes: 130; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 0006161c (130 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00062d2c(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (((&dtc_master_table_21_ffff87b0)[uVar1 * 8] == param_1) && (uVar1 != dtc_master_current_index_ffff8900._0_2_)) {
      _DAT_ffff8904 = rx8_pack_u16_with_complement(uVar1);
      return 0;
    }
    if (((&dtc_master_table_21_ffff87b0)[uVar1 * 8] == -1) && (uVar1 != dtc_master_current_index_ffff8900._0_2_)) break;
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 3;
    }
  }
  _DAT_ffff8904 = rx8_pack_u16_with_complement(uVar1);
  return 1;
}


/* ROM address: 0x00062dae; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006169e (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00062dae(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)dtc_master_current_index_ffff8900._0_2_;
  iVar3 = uVar2 * 0x10;
  uVar1 = (&dtc_master_table_21_ffff87b0)[uVar2 * 8];
  (&DAT_ffff87be)[iVar3] =
       (&DAT_ffff87be)[iVar3] +
       (((char)uVar1 + (char)((ushort)uVar1 >> 8)) - ((char)((uint)param_1 >> 8) + (char)param_1));
  (&dtc_master_table_21_ffff87b0)[uVar2 * 8] = (short)param_1;
  return;
}


/* ROM address: 0x00062dd8; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000616c8 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00062dd8(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)dtc_master_current_index_ffff8900._0_2_ * 0x10;
  (&DAT_ffff87be)[iVar1] = (&DAT_ffff87be)[iVar1] + ((&DAT_ffff87b6)[iVar1] - param_1);
  (&DAT_ffff87b6)[iVar1] = param_1;
  return;
}


/* ROM address: 0x00062df8; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000616e8 (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00062df8(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&dtc_master_table_21_ffff87b0)[uVar1 * 8] != param_1 || (dtc_master_current_index_ffff8900._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff87b6)[uVar1 * 0x10];
}


/* ROM address: 0x00062e4a; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006173a (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00062e4a(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)dtc_master_current_index_ffff8900._0_2_ * 0x10;
  (&DAT_ffff87be)[iVar1] = (&DAT_ffff87be)[iVar1] + ((&DAT_ffff87b7)[iVar1] - param_1);
  (&DAT_ffff87b7)[iVar1] = param_1;
  return;
}


/* ROM address: 0x00062e6a; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006175a (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00062e6a(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&dtc_master_table_21_ffff87b0)[uVar1 * 8] != param_1 || (dtc_master_current_index_ffff8900._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff87b7)[uVar1 * 0x10];
}


/* ROM address: 0x00062ebc; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000617ac (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00062ebc(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)dtc_master_current_index_ffff8900._0_2_ * 0x10;
  (&DAT_ffff87be)[iVar1] = (&DAT_ffff87be)[iVar1] + ((&DAT_ffff87b8)[iVar1] - param_1);
  (&DAT_ffff87b8)[iVar1] = param_1;
  return;
}


/* ROM address: 0x00062f2e; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006181e (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00062f2e(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)dtc_master_current_index_ffff8900._0_2_ * 0x10;
  (&DAT_ffff87be)[iVar1] = (&DAT_ffff87be)[iVar1] + ((&DAT_ffff87b9)[iVar1] - param_1);
  (&DAT_ffff87b9)[iVar1] = param_1;
  return;
}


/* ROM address: 0x00062fa0; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061890 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00062fa0(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)dtc_master_current_index_ffff8900._0_2_ * 0x10;
  (&DAT_ffff87be)[iVar1] = (&DAT_ffff87be)[iVar1] + ((&DAT_ffff87ba)[iVar1] - param_1);
  (&DAT_ffff87ba)[iVar1] = param_1;
  return;
}


/* ROM address: 0x00063026; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061916 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063026(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)dtc_master_current_index_ffff8900._0_2_ * 0x10;
  (&DAT_ffff87be)[iVar1] = (&DAT_ffff87be)[iVar1] + ((&DAT_ffff87bb)[iVar1] - param_1);
  (&DAT_ffff87bb)[iVar1] = param_1;
  return;
}


/* ROM address: 0x00063046; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061936 (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00063046(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&dtc_master_table_21_ffff87b0)[uVar1 * 8] != param_1 || (dtc_master_current_index_ffff8900._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff87bb)[uVar1 * 0x10];
}


/* ROM address: 0x00063098; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061988 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063098(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)dtc_master_current_index_ffff8900._0_2_ * 0x10;
  (&DAT_ffff87be)[iVar1] = (&DAT_ffff87be)[iVar1] + ((&DAT_ffff87bc)[iVar1] - param_1);
  (&DAT_ffff87bc)[iVar1] = param_1;
  return;
}


/* ROM address: 0x000630b8; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000619a8 (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000630b8(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&dtc_master_table_21_ffff87b0)[uVar1 * 8] != param_1 || (dtc_master_current_index_ffff8900._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff87bc)[uVar1 * 0x10];
}


/* ROM address: 0x0006310a; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000619fa (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006310a(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)dtc_master_current_index_ffff8900._0_2_ * 0x10;
  (&DAT_ffff87be)[iVar1] = (&DAT_ffff87be)[iVar1] + ((&DAT_ffff87bd)[iVar1] - param_1);
  (&DAT_ffff87bd)[iVar1] = param_1;
  return;
}


/* ROM address: 0x0006317c; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061a6c (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006317c(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)dtc_master_current_index_ffff8900._0_2_;
  (&DAT_ffff87be)[uVar1 * 0x10] =
       (&DAT_ffff87be)[uVar1 * 0x10] +
       (((char)(&DAT_ffff87b2)[uVar1 * 8] + (char)((ushort)(&DAT_ffff87b2)[uVar1 * 8] >> 8)) -
       ((char)((uint)param_1 >> 8) + (char)param_1));
  (&DAT_ffff87b2)[uVar1 * 8] = (short)param_1;
  return;
}


/* ROM address: 0x000631aa; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061a9a (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000631aa(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&dtc_master_table_21_ffff87b0)[uVar1 * 8] != param_1 || (dtc_master_current_index_ffff8900._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0xffff;
    }
  }
  return (int)(short)(&DAT_ffff87b2)[uVar1 * 8];
}


/* ROM address: 0x000631fc; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061aec (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000631fc(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)dtc_master_current_index_ffff8900._0_2_;
  (&DAT_ffff87be)[uVar1 * 0x10] =
       (&DAT_ffff87be)[uVar1 * 0x10] +
       (((char)(&DAT_ffff87b4)[uVar1 * 8] + (char)((ushort)(&DAT_ffff87b4)[uVar1 * 8] >> 8)) -
       ((char)((uint)param_1 >> 8) + (char)param_1));
  (&DAT_ffff87b4)[uVar1 * 8] = (short)param_1;
  return;
}


/* ROM address: 0x0006322a; body bytes: 82; decompiled */

int FUN_0006322a(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&dtc_master_table_21_ffff87b0)[uVar1 * 8] != param_1 || (dtc_master_current_index_ffff8900._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0xffff;
    }
  }
  return (int)(short)(&DAT_ffff87b4)[uVar1 * 8];
}


/* ROM address: 0x0006328a; body bytes: 268; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061b7a (268 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0006328a(char param_1)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    DAT_ffffd79e = 0;
    DAT_ffffd7a0 = dtc_master_current_index_ffff8900._0_2_;
  }
  else if (param_1 == '\x01') {
    DAT_ffffd79e = DAT_ffffd79e + 1;
  }
  if ((DAT_ffffd79e == dtc_master_current_index_ffff8900._0_2_) || (DAT_ffffd79e == DAT_ffffd7a0)) {
    DAT_ffffd79e = DAT_ffffd79e + 1;
  }
  if (DAT_ffffd79e < 0x15) {
    if ((&dtc_master_table_21_ffff87b0)[(uint)DAT_ffffd79e * 8] == -1) {
      uVar1 = 0;
    }
    else {
      DAT_ffffd790 = (&dtc_master_table_21_ffff87b0)[(uint)DAT_ffffd79e * 8];
      DAT_ffffd792 = (&DAT_ffff87b2)[(uint)DAT_ffffd79e * 8];
      DAT_ffffd794 = (&DAT_ffff87b4)[(uint)DAT_ffffd79e * 8];
      DAT_ffffd796 = (&DAT_ffff87b6)[(uint)DAT_ffffd79e * 0x10];
      DAT_ffffd797 = (&DAT_ffff87b7)[(uint)DAT_ffffd79e * 0x10];
      DAT_ffffd798 = (&DAT_ffff87b9)[(uint)DAT_ffffd79e * 0x10];
      DAT_ffffd799 = (&DAT_ffff87b8)[(uint)DAT_ffffd79e * 0x10];
      DAT_ffffd79a = (&DAT_ffff87ba)[(uint)DAT_ffffd79e * 0x10];
      DAT_ffffd79b = (&DAT_ffff87bb)[(uint)DAT_ffffd79e * 0x10];
      DAT_ffffd79c = (&DAT_ffff87bc)[(uint)DAT_ffffd79e * 0x10];
      DAT_ffffd79d = (&DAT_ffff87bd)[(uint)DAT_ffffd79e * 0x10];
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* ROM address: 0x00063396; body bytes: 290; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00061c86 (290 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 FUN_00063396(undefined4 param_1,byte param_2,undefined2 *param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  undefined1 local_20;
  
  local_20 = 3;
  uVar2 = (uint)dtc_master_current_index_ffff8900._0_2_;
  bVar3 = DAT_ffff87bd;
  if (uVar2 == 0) {
    bVar3 = DAT_ffff87cd;
  }
  uVar4 = (uint)(uVar2 == 0);
  uVar1 = 0;
  do {
    if (uVar1 != uVar2) {
      if (bVar3 < (&DAT_ffff87bd)[uVar1 * 0x10]) {
        bVar3 = (&DAT_ffff87bd)[uVar1 * 0x10];
        uVar4 = uVar1;
      }
      else if (bVar3 == (&DAT_ffff87bd)[uVar1 * 0x10]) {
        if (((&DAT_ffff87b6)[uVar1 * 0x10] == 0) || (0x3f < (byte)(&DAT_ffff87b6)[uVar1 * 0x10])) {
          if ((((&DAT_ffff87b6)[uVar1 * 0x10] & 0x80) == 0x80) &&
             ((ushort)(&DAT_ffff87b4)[(uVar4 & 0xffff) * 8] < (ushort)(&DAT_ffff87b4)[uVar1 * 8])) {
            uVar4 = uVar1;
          }
        }
        else if ((ushort)(&DAT_ffff87b2)[(uVar4 & 0xffff) * 8] < (ushort)(&DAT_ffff87b2)[uVar1 * 8])
        {
          uVar4 = uVar1;
        }
      }
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x15);
  if (param_2 < bVar3) {
    *param_3 = (&dtc_master_table_21_ffff87b0)[(uVar4 & 0xffff) * 8];
    _DAT_ffff8904 = rx8_pack_u16_with_complement(uVar4);
    local_20 = 2;
  }
  return local_20;
}


/* ROM address: 0x000634b8; body bytes: 94; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061da8 (94 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000634b8(ushort param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)dtc_master_current_index_ffff8900._0_2_;
  iVar2 = uVar1 * 0x10;
  (&dtc_master_table_21_ffff87b0)[uVar1 * 8] = 0xffff;
  (&DAT_ffff87b2)[uVar1 * 8] = 0xffff;
  (&DAT_ffff87b4)[uVar1 * 8] = 0xffff;
  (&DAT_ffff87b6)[iVar2] = 0;
  (&DAT_ffff87b7)[iVar2] = 0;
  (&DAT_ffff87b8)[iVar2] = 3;
  (&DAT_ffff87b9)[iVar2] = 0x28;
  (&DAT_ffff87ba)[iVar2] = 0x50;
  (&DAT_ffff87bb)[iVar2] = 0;
  (&DAT_ffff87bc)[iVar2] = 0;
  (&DAT_ffff87bd)[iVar2] = 8;
  (&DAT_ffff87be)[iVar2] = 0x28;
  FUN_00062dae((int)(short)param_1);
  FUN_00062ebc((int)(char)(&DAT_0007e442)[param_1]);
  FUN_00062f2e((int)(char)(&DAT_0007e4ce)[param_1]);
  return;
}


/* ROM address: 0x00063540; body bytes: 174; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061e30 (174 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00063540(void)

{
  char cVar1;
  short sVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  
  sVar2 = FUN_00002034(&DAT_ffff8d4c);
  if ((sVar2 == 0) && (sVar2 = FUN_00002034(&DAT_ffff8d50), sVar2 == 0)) {
    uVar6 = 0;
    for (uVar4 = 0; cVar3 = '\0', (int)uVar4 < 0x15; uVar4 = uVar4 + 1) {
      iVar8 = uVar4 * 0x34;
      pcVar5 = (char *)(&DAT_ffff8908 + uVar4 * 0x1a);
      pcVar7 = &DAT_ffff8912 + iVar8;
      if ((DAT_ffff8798._0_1_ == '\0') || (uVar4 != DAT_ffff8d4c._0_2_)) {
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          cVar3 = cVar3 + cVar1;
        } while (pcVar5 < (char *)(iVar8 + -0x76ef));
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          cVar3 = cVar3 + cVar1;
        } while (pcVar7 < &DAT_ffff893a + iVar8);
        if ((char)(cVar3 + (&DAT_ffff893a)[iVar8]) != -0x5b) goto LAB_000635cc;
      }
    }
  }
  else {
LAB_000635cc:
    uVar6 = 1;
  }
  return uVar6;
}


/* ROM address: 0x000635ee; body bytes: 112; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00061ede (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000635ee(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  DAT_ffff8d4c = rx8_pack_u16_with_complement(0);
  _DAT_ffff8d50 = rx8_pack_u16_with_complement(1);
  puVar2 = (undefined4 *)&DAT_ffff8908;
  puVar4 = puVar2;
  puVar5 = puVar2;
  do {
    *(undefined2 *)puVar2 = 0xffff;
    *(undefined2 *)((int)puVar2 + 2) = 0xffff;
    puVar3 = (undefined2 *)((int)puVar5 + 10);
    *(undefined2 *)(puVar2 + 1) = 0xffff;
    *(undefined1 *)((int)puVar2 + 6) = 0;
    *(undefined1 *)((int)puVar2 + 7) = 0;
    *(undefined1 *)(puVar2 + 2) = 8;
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined2 *)((int)puVar3 + 1);
    } while (iVar1 < 0x28);
    puVar2 = puVar2 + 0xd;
    *(undefined1 *)((int)puVar4 + 0x32) = 0xa3;
    puVar4 = puVar4 + 0xd;
    puVar5 = puVar5 + 0xd;
  } while (puVar2 < &DAT_ffff8d4c);
  return;
}


/* ROM address: 0x00063680; body bytes: 134; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00061f70 (134 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00063680(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (((&DAT_ffff8908)[uVar1 * 0x1a] == param_1) && (uVar1 != DAT_ffff8d4c._0_2_)) {
      _DAT_ffff8d50 = rx8_pack_u16_with_complement(uVar1);
      return 0;
    }
    if (((&DAT_ffff890f)[uVar1 * 0x34] == '\0') && (uVar1 != DAT_ffff8d4c._0_2_)) break;
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 3;
    }
  }
  _DAT_ffff8d50 = rx8_pack_u16_with_complement(uVar1);
  return 1;
}


/* ROM address: 0x00063706; body bytes: 258; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00063706(undefined4 param_1,byte param_2,undefined2 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  
  uVar3 = (uint)DAT_ffff8d4c._0_2_;
  uVar2 = 3;
  bVar4 = DAT_ffff8910;
  if (uVar3 == 0) {
    bVar4 = DAT_ffff8944;
  }
  uVar5 = (uint)(uVar3 == 0);
  uVar1 = 0;
  do {
    if (uVar1 != uVar3) {
      if (bVar4 < (&DAT_ffff8910)[uVar1 * 0x34]) {
        bVar4 = (&DAT_ffff8910)[uVar1 * 0x34];
        uVar5 = uVar1;
      }
      else if (bVar4 == (&DAT_ffff8910)[uVar1 * 0x34]) {
        if ((&DAT_ffff890f)[uVar1 * 0x34] == '\x10') {
          if ((ushort)(&DAT_ffff890a)[(uVar5 & 0xffff) * 0x1a] <
              (ushort)(&DAT_ffff890a)[uVar1 * 0x1a]) {
            uVar5 = uVar1;
          }
        }
        else if (((&DAT_ffff890f)[uVar1 * 0x34] == -0x40) &&
                ((ushort)(&DAT_ffff890c)[(uVar5 & 0xffff) * 0x1a] <
                 (ushort)(&DAT_ffff890c)[uVar1 * 0x1a])) {
          uVar5 = uVar1;
        }
      }
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x15);
  if (param_2 < bVar4) {
    *param_3 = (&DAT_ffff8908)[(uVar5 & 0xffff) * 0x1a];
    _DAT_ffff8d50 = rx8_pack_u16_with_complement(uVar5);
    uVar2 = 2;
  }
  return uVar2;
}


/* ROM address: 0x0006381c; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006210c (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006381c(void)

{
  int iVar1;
  
  iVar1 = (uint)DAT_ffff8d4c._0_2_ * 0x34;
  (&DAT_ffff893a)[iVar1] = (&DAT_ffff893a)[iVar1] + (&DAT_ffff890f)[iVar1] + -1;
  (&DAT_ffff890f)[iVar1] = 1;
  iVar1 = (uint)DAT_ffff8d4c._0_2_ * 0x34;
  (&DAT_ffff893a)[iVar1] = (&DAT_ffff893a)[iVar1] + (&DAT_ffff8910)[iVar1] + -7;
  (&DAT_ffff8910)[iVar1] = 7;
  return;
}


/* ROM address: 0x00063862; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062152 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063862(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)DAT_ffff8d4c._0_2_;
  iVar3 = uVar2 * 0x34;
  uVar1 = (&DAT_ffff8908)[uVar2 * 0x1a];
  (&DAT_ffff893a)[iVar3] =
       (&DAT_ffff893a)[iVar3] +
       (((char)uVar1 + (char)((ushort)uVar1 >> 8)) - ((char)((uint)param_1 >> 8) + (char)param_1));
  (&DAT_ffff8908)[uVar2 * 0x1a] = (short)param_1;
  return;
}


/* ROM address: 0x000638e2; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000621d2 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000638e2(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)DAT_ffff8d4c._0_2_ * 0x34;
  (&DAT_ffff893a)[iVar1] = (&DAT_ffff893a)[iVar1] + ((&DAT_ffff890f)[iVar1] - param_1);
  (&DAT_ffff890f)[iVar1] = param_1;
  return;
}


/* ROM address: 0x00063920; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062210 (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00063920(char param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff890e)[uVar1 * 0x34] != param_1 || (DAT_ffff8d4c._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff890f)[uVar1 * 0x34];
}


/* ROM address: 0x00063972; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062262 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063972(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)DAT_ffff8d4c._0_2_ * 0x34;
  (&DAT_ffff893a)[iVar1] = (&DAT_ffff893a)[iVar1] + ((&DAT_ffff890e)[iVar1] - param_1);
  (&DAT_ffff890e)[iVar1] = param_1;
  return;
}


/* ROM address: 0x00063998; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062288 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00063998(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8908)[uVar1 * 0x1a] != param_1 || (DAT_ffff8d4c._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff890e)[uVar1 * 0x34];
}


/* ROM address: 0x000639dc; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000622cc (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000639dc(char param_1)

{
  int iVar1;
  
  iVar1 = (uint)DAT_ffff8d4c._0_2_ * 0x34;
  (&DAT_ffff893a)[iVar1] = (&DAT_ffff893a)[iVar1] + ((&DAT_ffff8910)[iVar1] - param_1);
  (&DAT_ffff8910)[iVar1] = param_1;
  return;
}


/* ROM address: 0x00063a54; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062344 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063a54(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8d4c._0_2_;
  (&DAT_ffff893a)[uVar1 * 0x34] =
       (&DAT_ffff893a)[uVar1 * 0x34] +
       (((char)(&DAT_ffff890a)[uVar1 * 0x1a] + (char)((ushort)(&DAT_ffff890a)[uVar1 * 0x1a] >> 8)) -
       ((char)((uint)param_1 >> 8) + (char)param_1));
  (&DAT_ffff890a)[uVar1 * 0x1a] = (short)param_1;
  return;
}


/* ROM address: 0x00063ada; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000623ca (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063ada(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8d4c._0_2_;
  (&DAT_ffff893a)[uVar1 * 0x34] =
       (&DAT_ffff893a)[uVar1 * 0x34] +
       (((char)(&DAT_ffff890c)[uVar1 * 0x1a] + (char)((ushort)(&DAT_ffff890c)[uVar1 * 0x1a] >> 8)) -
       ((char)((uint)param_1 >> 8) + (char)param_1));
  (&DAT_ffff890c)[uVar1 * 0x1a] = (short)param_1;
  return;
}


/* ROM address: 0x00063b60; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062450 (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00063b60(char param_1,undefined2 *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while (((&DAT_ffff890e)[uVar1 * 0x34] != param_1 || (DAT_ffff8d4c._0_2_ == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  iVar2 = uVar1 * 0x34;
  *param_2 = (&DAT_ffff8908)[uVar1 * 0x1a];
  param_2[1] = (&DAT_ffff890a)[uVar1 * 0x1a];
  param_2[2] = (&DAT_ffff890c)[uVar1 * 0x1a];
  *(undefined1 *)(param_2 + 3) = (&DAT_ffff890e)[iVar2];
  *(undefined1 *)((int)param_2 + 7) = (&DAT_ffff890f)[iVar2];
  *(undefined1 *)(param_2 + 4) = (&DAT_ffff8910)[iVar2];
  return 1;
}


/* ROM address: 0x00063bd4; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000624c4 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063bd4(int param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  char cVar6;
  
  uVar4 = DAT_ffff8d4c._0_2_;
  uVar2 = (uint)DAT_ffff8d4c._0_2_;
  cVar6 = (&DAT_ffff893a)[uVar2 * 0x34];
  iVar5 = 0;
  do {
    pcVar1 = (char *)(param_1 + iVar5);
    iVar3 = iVar5 + uVar2 * 0x34;
    iVar5 = iVar5 + 1;
    cVar6 = cVar6 + ((&DAT_ffff8912)[iVar3] - *pcVar1);
    (&DAT_ffff8912)[iVar3] = *pcVar1;
  } while (iVar5 < 0x28);
  (&DAT_ffff893a)[(uint)uVar4 * 0x34] = cVar6;
  return;
}


/* ROM address: 0x00063c1c; body bytes: 124; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006250c (124 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00063c1c(char param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  
  iVar5 = 1;
  uVar3 = 0;
  puVar6 = param_2 + 0x28;
  while( true ) {
    if (0x14 < (int)uVar3) goto LAB_00063c76;
    if (((&DAT_ffff890e)[uVar3 * 0x34] == param_1) && (DAT_ffff8d4c._0_2_ != uVar3)) break;
    uVar3 = uVar3 + 1;
  }
  puVar4 = &DAT_ffff8912 + uVar3 * 0x34;
  puVar2 = param_2;
  do {
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while (puVar2 < puVar6);
  iVar5 = 0;
LAB_00063c76:
  if (iVar5 == 1) {
    do {
      *param_2 = 0;
      param_2 = param_2 + 1;
    } while (param_2 < puVar6);
  }
  return iVar5;
}


/* ROM address: 0x00063cea; body bytes: 150; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000625da (150 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00063cea(char param_1,uint param_2,uint param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  iVar5 = 1;
  param_3 = param_3 & 0xff;
  while( true ) {
    if (0x14 < (int)uVar6) goto LAB_00063d54;
    if (((&DAT_ffff890e)[uVar6 * 0x34] == param_1) && (DAT_ffff8d4c._0_2_ != uVar6)) break;
    uVar6 = uVar6 + 1;
  }
  iVar5 = 0;
  puVar3 = &DAT_ffff8912 + (param_2 & 0xff) + uVar6 * 0x34;
  puVar2 = param_4;
  if (param_3 != 0) {
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      iVar5 = iVar5 + 1;
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
    } while (iVar5 < (int)param_3);
  }
  iVar5 = 0;
LAB_00063d54:
  if ((iVar5 == 1) && (iVar4 = 0, param_3 != 0)) {
    do {
      *param_4 = 0;
      iVar4 = iVar4 + 1;
      param_4 = param_4 + 1;
    } while (iVar4 < (int)param_3);
  }
  return iVar5;
}


/* ROM address: 0x00063d8c; body bytes: 152; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006267c (152 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00063d8c(void)

{
  char cVar1;
  char cVar3;
  undefined2 uVar2;
  undefined2 *puVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  
  uVar8 = 0;
  cVar3 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8e72);
  if (((cVar3 != '\0') || (cVar3 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8e74), cVar3 != '\0')) ||
     (cVar3 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8e70), cVar3 != '\0')) {
    uVar8 = 1;
  }
  cVar3 = '\0';
  pcVar6 = &DAT_ffff8d54;
  iVar7 = 0x8c;
  do {
    pcVar5 = pcVar6;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      cVar3 = cVar3 + cVar1;
    } while (pcVar5 < pcVar6 + 2);
    iVar7 = iVar7 + -1;
    pcVar6 = pcVar6 + 2;
  } while (iVar7 != 0);
  if ((char)(cVar3 + DAT_ffff8e6c._0_1_) == -0x5b) {
    uVar2 = rx8_pack_u8_with_complement();
    puVar4 = &DAT_ffff8e6e;
  }
  else {
    if ((char)(cVar3 + DAT_ffff8e6e._0_1_) != -0x5b) {
      return 1;
    }
    uVar2 = rx8_pack_u8_with_complement((int)DAT_ffff8e6e._0_1_);
    puVar4 = &DAT_ffff8e6c;
  }
  *puVar4 = uVar2;
  return uVar8;
}


/* ROM address: 0x00063e24; body bytes: 84; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00062714 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063e24(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)&DAT_ffff8d54;
  do {
    *(undefined1 *)puVar1 = 0;
    *(undefined1 *)((int)puVar1 + 1) = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 < &DAT_ffff8e6c);
  DAT_ffff8e6c = rx8_pack_u8_with_complement(0xa5);
  DAT_ffff8e6e = rx8_pack_u8_with_complement(0xa5);
  _DAT_ffff8e70 = rx8_pack_u8_with_complement(0xa5);
  _DAT_ffff8e72 = rx8_pack_u8_with_complement(0);
  _DAT_ffff8e74 = rx8_pack_u8_with_complement(0);
  return;
}


/* ROM address: 0x00063e78; body bytes: 48; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00062768 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00063e78(char param_1)

{
  undefined4 uVar1;
  
  _DAT_ffff8e70 = rx8_pack_u8_with_complement(((int)DAT_ffff8e72 - (int)param_1) + (int)DAT_ffff8e70);
  uVar1 = rx8_pack_u8_with_complement((int)param_1);
  _DAT_ffff8e72 = (short)uVar1;
  return uVar1;
}


/* ROM address: 0x00063ecc; body bytes: 48; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 000627bc (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00063ecc(char param_1)

{
  undefined4 uVar1;
  
  _DAT_ffff8e70 = rx8_pack_u8_with_complement(((int)DAT_ffff8e74 - (int)param_1) + (int)DAT_ffff8e70);
  uVar1 = rx8_pack_u8_with_complement((int)param_1);
  _DAT_ffff8e74 = (short)uVar1;
  return uVar1;
}


/* ROM address: 0x00063efc; body bytes: 76; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000627ec (76 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063efc(void)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = (int)DAT_ffff8e6c._0_1_;
  pcVar1 = &DAT_ffff8d54;
  do {
    iVar2 = iVar2 + *pcVar1;
    DAT_ffff8e6c = rx8_pack_u8_with_complement(iVar2);
    *pcVar1 = '\0';
    DAT_ffff8e6e = rx8_pack_u8_with_complement(iVar2);
    pcVar1 = pcVar1 + 2;
  } while (pcVar1 < &DAT_ffff8e6c);
  return;
}


/* ROM address: 0x00063f64; body bytes: 160; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062854 (160 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063f64(undefined4 param_1,uint param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = 8;
  uVar3 = 0;
  if ((param_2 & 0xff) == 3) {
    uVar3 = FUN_00064088(param_1);
    uVar2 = FUN_000618f8(param_1,uVar3,param_2);
    cVar1 = FUN_00062420(uVar2);
    if (cVar1 == '\x01') {
      FUN_00064122(param_1,uVar3);
      FUN_000642b8();
      FUN_00062138(param_1);
      FUN_00064234(param_1,0x20);
      FUN_00064312();
      FUN_0006310a(uVar2);
      FUN_00063026(param_2);
      FUN_00063098(1);
      FUN_00064418(param_1,uVar3);
    }
    FUN_000628b8();
  }
  DAT_ffffd6c0 = (undefined1)uVar2;
  DAT_ffffd6c3 = (undefined1)uVar3;
  FUN_000623b0();
  FUN_00062080(param_1,0x20);
  FUN_000620e8(param_1,0x20,uVar3);
  FUN_0006289a();
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00060c7a [high]: 6-byte body: word 0xd31c = `mov.l @(0x64078,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x64078 = 0x00060c7a (ROM-verified, big-endian) (ROM-verified at 0x00064004). Direct tail-jump to `FUN_00060c7a` 0x00060c7a; callers in callgraph: 0x00061092. Upstream name `thunk_FUN_00060c7a` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00064004; body bytes: 6; decompiled */

void jump_to_FUN_00060c7a(void)

{
  FUN_00060c7a();
  return;
}


/* ROM address: 0x0006400a; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000628fa (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006400a(undefined4 param_1)

{
  FUN_00062668();
  FUN_00062420(8);
  FUN_000642da(param_1);
  FUN_0006217c(param_1);
  FUN_0006435a(param_1);
  FUN_000643b8(param_1);
  FUN_00064174(param_1);
  FUN_00064268(param_1);
  FUN_0006447e();
  FUN_000628b8();
  FUN_000628f4();
  return;
}


/* ROM address: 0x00064088; body bytes: 108; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062978 (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00064088(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_00062df8();
  uVar3 = uVar1 & 0xff;
  if (((uVar3 == 0) || ((uVar3 != 0 && (uVar3 < 0x40)))) || ((0x80 < uVar3 && (uVar3 < 0xc0)))) {
    uVar2 = FUN_000640f4(param_1);
  }
  else {
    uVar2 = uVar1;
    if (((uVar3 != 0xc0) && (uVar2 = 0xc0, uVar3 != 0xc1)) && (uVar2 = uVar1, uVar3 == 0x50)) {
      uVar2 = FUN_000640f4(param_1,0);
    }
  }
  return uVar2;
}


/* ROM address: 0x000640f4; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000629e4 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000640f4(uint param_1,uint param_2)

{
  if (((&DAT_ffff8d54)[(param_1 & 0xffff) * 2] != ' ') &&
     (param_2 = param_2 + 1, (uint)(byte)(&DAT_0007e3b6)[param_1 & 0xffff] <= (param_2 & 0x7f))) {
    param_2 = 0xc0;
  }
  return param_2;
}


/* ROM address: 0x00064122; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062a12 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00064122(undefined4 param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00062df8();
  if ((param_2 & 0xff) != (uVar1 & 0xff)) {
    FUN_00062dd8(param_2);
    uVar1 = FUN_000621d8(uVar1,param_2);
    return uVar1;
  }
  return uVar1;
}


/* ROM address: 0x00064174; body bytes: 192; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062a64 (192 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00064174(ushort *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 3);
  iVar3 = (uint)dtc_master_current_index_ffff8900._0_2_ * 0x10;
  if ((bVar1 == 0) || (0x3f < bVar1)) {
    if (bVar1 == 0xc0) {
      uVar2 = (uint)(byte)(&DAT_ffff87b8)[iVar3];
      if ((byte)(&DAT_0007e442)[*param_1] <= uVar2) {
        uVar2 = FUN_00062dd8(0xc1);
      }
    }
    else {
      uVar2 = 1;
      if ((bVar1 == 0xc1) &&
         (uVar2 = (uint)(byte)(&DAT_ffff87b9)[iVar3], (byte)(&DAT_0007e4ce)[*param_1] <= uVar2)) {
        FUN_00062dd8(0);
        uVar2 = FUN_0006310a(8);
        return uVar2;
      }
    }
  }
  else if ((0x4f < (byte)(&DAT_ffff87ba)[iVar3]) ||
          (uVar2 = (uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2], uVar2 == 0x11)) {
    FUN_00062dd8(0);
    uVar2 = FUN_0006310a(8);
    return uVar2;
  }
  return uVar2;
}


/* ROM address: 0x00064234; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062b24 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00064234(uint param_1)

{
  if (((&DAT_ffff87b6)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10] == -0x40) &&
     ((&CAL_DTC_0300_Enable_Disable_1_1129)[param_1 & 0xffff] == '\x01')) {
    FUN_00062e4a(0xc0);
    return;
  }
  return;
}


/* ROM address: 0x00064268; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062b58 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00064268(void)

{
  undefined1 *puVar1;
  
  if ((&DAT_ffff87b6)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10] == -0x3f) {
    puVar1 = (undefined1 *)FUN_00062e4a(0);
    return puVar1;
  }
  return &DAT_ffff87b6;
}


/* ROM address: 0x000642b8; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062ba8 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_000642b8(void)

{
  undefined1 *puVar1;
  
  if ((&DAT_ffff87b6)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10] == -0x40) {
    puVar1 = (undefined1 *)FUN_00062ebc(0);
    return puVar1;
  }
  return &DAT_ffff87b6;
}


/* ROM address: 0x000642da; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062bca (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined * FUN_000642da(ushort *param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2];
  if (puVar1 == (undefined *)((int)&vector_Illegal_instr + 1)) {
    puVar1 = &DAT_0007e442;
    if (*(byte *)((int)param_1 + 9) < (byte)(&DAT_0007e442)[*param_1]) {
      puVar1 = (undefined *)FUN_00062ebc((char)*(byte *)((int)param_1 + 9) + 1);
      return puVar1;
    }
  }
  return puVar1;
}


/* ROM address: 0x00064312; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062c02 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00064312(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_ffff87b6)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10];
  if (((uVar1 == 0) || (0x3f < uVar1)) && ((uVar1 < 0x81 || (0xbf < uVar1)))) {
    if (uVar1 == 0xc0) {
      uVar1 = FUN_00062fa0(0x50);
      return uVar1;
    }
    return uVar1;
  }
  uVar1 = FUN_00062fa0(0);
  return uVar1;
}


/* ROM address: 0x0006435a; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062c4a (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0006435a(ushort *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2];
  if (uVar1 == 0x11) {
    uVar1 = FUN_00062fa0(0x50);
    return uVar1;
  }
  if (((uVar1 == 0x10) || (uVar1 == 0)) &&
     (uVar1 = (uint)(char)*(byte *)(param_1 + 5), *(byte *)(param_1 + 5) < 0x50)) {
    uVar1 = FUN_00062fa0(uVar1 + 1);
    return uVar1;
  }
  return uVar1;
}


/* ROM address: 0x000643b8; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062ca8 (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000643b8(ushort *param_1)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *(byte *)(param_1 + 3);
  uVar2 = (uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2];
  if ((uVar2 != 0x11) &&
     ((((bVar1 == 0 || (uVar2 = (uint)bVar1, 0x3f < uVar2)) && ((bVar1 < 0x81 || (0xbf < bVar1))))
      || ((byte)(&DAT_ffff87ba)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10] < 0x50)))) {
    return uVar2;
  }
  uVar2 = FUN_00063098(0);
  return uVar2;
}


/* ROM address: 0x00064418; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062d08 (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00064418(undefined4 param_1,byte param_2)

{
  uint uVar1;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 local_8;
  
  uVar1 = FUN_00062df8();
  uVar1 = uVar1 & 0xff;
  if (((uVar1 == 0) || (uVar1 == 0x50)) && (uVar1 = (uint)param_2, uVar1 == 1)) {
    FUN_00062668();
    uStack_14 = FUN_0005fcf8();
    uStack_10 = FUN_0005fcf2();
    uStack_c = FUN_0005fcfe();
    local_8 = ref_returnCoolantTempGreaterThan71();
    FUN_00067732(&uStack_14);
    uVar1 = FUN_000628f4();
  }
  return uVar1;
}


/* ROM address: 0x0006447e; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062d6e (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0006447e(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_ffff87b6)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10];
  if ((uVar1 != 0) && (uVar1 != 0x50)) {
    return uVar1;
  }
  uVar1 = FUN_00067760();
  return uVar1;
}


/* ROM address: 0x000644e4; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062dd4 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000644e4(void)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  cVar1 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8e78);
  if ((cVar1 != '\0') || (cVar1 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8e7a), cVar1 != '\0')) {
    uVar2 = 1;
  }
  return uVar2;
}


/* ROM address: 0x00064512; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062e02 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00064512(void)

{
  DAT_ffff8e78 = rx8_pack_u8_with_complement(0);
  DAT_ffff8e7a = rx8_pack_u8_with_complement(0);
  return;
}


/* ROM address: 0x0006452c; body bytes: 4; decompiled */

void FUN_0006452c(void)

{
  return;
}


/* ROM address: 0x00064530; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062e20 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00064530(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8e7c;
  if (uVar1 == 1) {
    DAT_ffff8e78 = rx8_pack_u8_with_complement((int)DAT_ffff8d54);
    uVar1 = rx8_pack_u8_with_complement((int)DAT_ffff8d56);
    DAT_ffff8e7a = (undefined2)uVar1;
  }
  return uVar1;
}


/* ROM address: 0x0006455c; body bytes: 126; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062e4c (126 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0006455c(void)

{
  uint uVar1;
  char cVar2;
  
  DAT_ffffd7b2 = FUN_000630b8(1);
  uVar1 = (uint)DAT_ffff8e7c;
  if (uVar1 == 1) {
    cVar2 = FUN_000678b4(0);
    if (cVar2 != '\0') {
      FUN_000623a0(0);
      FUN_00062668();
      FUN_0006789e(0);
      FUN_000628f4();
      FUN_000627a0();
    }
    uVar1 = FUN_000678b4(1);
    if ((uVar1 & 0xff) != 0) {
      FUN_000623a0(1);
      FUN_00062668();
      FUN_0006789e(0);
      FUN_000628f4();
      uVar1 = FUN_000627a0();
    }
  }
  DAT_ffffd7b3 = 0;
  DAT_ffffd7b4 = 0;
  return uVar1;
}


/* ROM address: 0x00064620; body bytes: 274; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062f10 (274 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00064620(undefined4 param_1,char param_2,short param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  char cVar6;
  
  FUN_00062668();
  uVar1 = FUN_00062df8(param_1);
  uVar2 = FUN_00065206(param_1,uVar1);
  uVar3 = FUN_00064b30(param_1,uVar1,uVar2);
  uVar4 = FUN_000618f8(param_1,uVar3,(int)param_2);
  cVar5 = FUN_00062420(uVar4);
  if (cVar5 == '\x01') {
    FUN_00062ebc(0);
    FUN_00062f2e(0);
    if (((uVar2 & 0xff) == 0) || ((uVar2 & 0xff) == 1)) {
      FUN_00064d74(uVar1,uVar3);
      FUN_00062e4a(0x80);
      FUN_0006508c(uVar3);
      FUN_0006310a(uVar4);
      FUN_00063026((int)param_2);
      FUN_00063098(1);
      FUN_000653e0(param_1,(int)param_3,uVar3);
      FUN_000623b0();
      FUN_00062080(param_1,0x20);
      FUN_000620e8(param_1,0x20,uVar3);
      FUN_0006289a();
      cVar5 = FUN_0006559c(uVar3);
      cVar6 = FUN_0006559c(uVar1);
      if (((cVar6 != '`') && (cVar5 == '`')) || ((cVar6 != 'p' && (cVar5 == 'p')))) {
        DAT_ffffd7b3 = 1;
      }
    }
  }
  FUN_000628b8();
  FUN_000628f4();
  DAT_ffffd6c0 = (char)uVar4;
  DAT_ffffd6c3 = (char)uVar3;
  return;
}


/* ROM address: 0x0006477c; body bytes: 268; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006306c (268 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006477c(undefined4 param_1,char param_2,short param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  char cVar6;
  
  FUN_00062668();
  uVar1 = FUN_00062df8(param_1);
  uVar2 = FUN_00065270(param_1);
  uVar3 = FUN_00064c74(param_1,uVar1,uVar2);
  uVar4 = FUN_000618f8(param_1,uVar3,(int)param_2);
  cVar5 = FUN_00062420(uVar4);
  if (cVar5 == '\x01') {
    FUN_00062ebc(0);
    FUN_00062f2e(0);
    if (((uVar2 & 0xff) == 0) || ((uVar2 & 0xff) == 1)) {
      FUN_00064d74(uVar1,uVar3);
      FUN_00064ed0(uVar3);
      FUN_0006508c(uVar3);
      FUN_0006310a(uVar4);
      FUN_00063026((int)param_2);
      FUN_00063098(1);
      FUN_000653e0(param_1,(int)param_3,uVar3);
      FUN_000623b0();
      FUN_00062080(param_1,0x20);
      FUN_000620e8(param_1,0x20,uVar3);
      FUN_0006289a();
      cVar5 = FUN_0006559c(uVar3);
      cVar6 = FUN_0006559c(uVar1);
      if (((cVar6 != '`') && (cVar5 == '`')) || ((cVar6 != 'p' && (cVar5 == 'p')))) {
        DAT_ffffd7b4 = 1;
      }
    }
  }
  FUN_000628b8();
  FUN_000628f4();
  DAT_ffffd6c0 = (char)uVar4;
  DAT_ffffd6c3 = (char)uVar3;
  return;
}


/* ROM address: 0x000648cc; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000631bc (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000648cc(undefined4 param_1,char param_2)

{
  char cVar1;
  char cVar2;
  
  cVar1 = FUN_00062e6a(param_1);
  cVar2 = FUN_00062df8(param_1);
  if (cVar1 == -0x80) {
    FUN_00062420(8);
    FUN_00064eba((int)cVar2);
    FUN_000628b8();
  }
  FUN_00060c7a(param_1,(int)param_2);
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00060c7a [high]: 6-byte body: word 0xd333 = `mov.l @(0x649e0,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x649e0 = 0x00060c7a (ROM-verified, big-endian) (ROM-verified at 0x00064912). Direct tail-jump to `FUN_00060c7a` 0x00060c7a; callers in callgraph: 0x00061092. Upstream name `thunk_FUN_00060c7a` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00064912; body bytes: 6; decompiled */

void jump_to_FUN_00060c7a(void)

{
  FUN_00060c7a();
  return;
}


/* ROM address: 0x00064918; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063208 (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00064918(undefined2 *param_1)

{
  FUN_00062668();
  FUN_00062420(8);
  DAT_ffffd7a4 = *param_1;
  FUN_00064f94(param_1,&DAT_ffffd7a4);
  FUN_0006500a(param_1,&DAT_ffffd7a4);
  FUN_000650ea(param_1,&DAT_ffffd7a4);
  FUN_00065158(param_1,&DAT_ffffd7a4);
  FUN_00064da6(param_1,&DAT_ffffd7a4);
  FUN_00065480(&DAT_ffffd7a4);
  FUN_00064ee4(param_1,&DAT_ffffd7a4);
  FUN_00065344(&DAT_ffffd7a4);
  FUN_0006789e(0);
  FUN_000628b8();
  FUN_000628f4();
  return;
}


/* ROM address: 0x00064972; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063262 (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00064972(undefined2 *param_1)

{
  FUN_00062668();
  FUN_00062420(8);
  DAT_ffffd7a4 = *param_1;
  FUN_00064f94(param_1,&DAT_ffffd7a4);
  FUN_0006500a(param_1,&DAT_ffffd7a4);
  FUN_000650ea(param_1,&DAT_ffffd7a4);
  FUN_00065158(param_1,&DAT_ffffd7a4);
  FUN_00064da6(param_1,&DAT_ffffd7a4);
  FUN_00065480(&DAT_ffffd7a4);
  FUN_00064f44(param_1,&DAT_ffffd7a4);
  FUN_00065344(&DAT_ffffd7a4);
  FUN_0006789e(0);
  FUN_000628b8();
  FUN_000628f4();
  return;
}


/* ROM address: 0x000649f4; body bytes: 230; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000632e4 (230 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000649f4(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_00062df8(1);
  uVar2 = FUN_0006559c(uVar1);
  uVar2 = uVar2 & 0xff;
  if (uVar2 == 0x60) {
    FUN_000623a0(1);
    FUN_00062420(8);
    FUN_00062dd8(0x50);
    FUN_0006310a(7);
    FUN_00062e4a(0);
    FUN_00062ebc(3);
    FUN_00062f2e(0x28);
    FUN_00062fa0(0x50);
    FUN_00063026(0);
    FUN_00063098(0);
    FUN_000628b8();
    FUN_00062668();
    FUN_00067760();
    FUN_0006763c(0);
    FUN_000676c8(0);
    FUN_000628f4();
    FUN_000606be();
    uVar2 = FUN_000627a0();
    return uVar2;
  }
  if (uVar2 == 0x70) {
    FUN_000623a0(1);
    FUN_00062420(8);
    FUN_00062dd8(0xc1);
    FUN_00062e4a(0);
    FUN_00062ebc(3);
    FUN_00062fa0(0x50);
    FUN_00063026(0);
    FUN_00063098(0);
    FUN_000628b8();
    FUN_00062668();
    FUN_00067760();
    FUN_000628f4();
    uVar2 = FUN_000627a0();
    return uVar2;
  }
  return uVar2;
}


/* ROM address: 0x00064b30; body bytes: 292; decompiled */

uint FUN_00064b30(ushort param_1,char param_2,char param_3)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  
  cVar1 = (&DAT_ffff8d54)[(uint)param_1 * 2];
  uVar3 = (uint)param_2;
  cVar2 = FUN_0006559c((int)param_2);
  if ((cVar2 == '\0') || (cVar2 == 'P')) {
    if (DAT_ffffd7b2 != '\x01') {
      if ((param_3 != '\0') && (param_3 != '\x01')) {
        return uVar3;
      }
      FUN_00065314();
      FUN_000652b4();
      return 1;
    }
    FUN_00065314();
  }
  else {
    if ((cVar2 == '`') || (cVar2 == 'p')) {
      if ((DAT_ffffd7b3 == '\0') &&
         (((cVar2 = ref_driveCycleDetectMAYBE_((int)(short)param_1), DAT_ffff8e78._0_1_ == ' ' ||
           (cVar2 == '\0')) || (DAT_ffffd7b2 == '\x01')))) {
        uVar3 = 0xc0;
      }
      if (cVar1 == ' ') {
        return uVar3;
      }
      if ((uVar3 & 0xff) == 0xc0) {
        return uVar3;
      }
      if ((param_3 != '\0') && (param_3 != '\x01')) {
        return uVar3;
      }
      FUN_000652b4();
      return uVar3;
    }
    if (cVar2 == -0x40) {
      return uVar3;
    }
    if (cVar2 != -0x3f) {
      return uVar3;
    }
    if (DAT_ffffd7b2 != '\x01') {
      if ((param_3 != '\0') && (param_3 != '\x01')) {
        return uVar3;
      }
      FUN_00065314();
      FUN_000652b4();
      return 0x81;
    }
    FUN_00065314();
  }
  FUN_000652b4();
  return 0xc0;
}


/* ROM address: 0x00064c74; body bytes: 234; decompiled */

int FUN_00064c74(ushort param_1,char param_2,char param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  cVar1 = (&DAT_ffff8d54)[(uint)param_1 * 2];
  iVar3 = (int)param_2;
  cVar2 = FUN_0006559c((int)param_2);
  if ((cVar2 == '\0') || (cVar2 == 'P')) {
    if ((param_3 == '\0') || (param_3 == '\x01')) {
      iVar3 = 1;
      FUN_00065314();
      FUN_000652b4();
    }
  }
  else if ((cVar2 == '`') || (cVar2 == 'p')) {
    if (DAT_ffffd7b4 == '\0') {
      if (param_3 == '\x01') {
        cVar2 = ref_driveCycleDetectMAYBE_((int)(short)param_1);
        if ((DAT_ffff8e7a._0_1_ == ' ') || (cVar2 == '\0')) {
          iVar3 = 0xc0;
        }
        else if (cVar1 != ' ') {
          FUN_000652b4();
        }
      }
      else if (param_3 == '\0') {
        iVar3 = 0xc0;
      }
    }
  }
  else if (((cVar2 != -0x40) && (cVar2 == -0x3f)) && ((param_3 == '\0' || (param_3 == '\x01')))) {
    iVar3 = 0x81;
    FUN_00065314();
    FUN_000652b4();
  }
  return iVar3;
}


/* ROM address: 0x00064d74; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063664 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00064d74(byte param_1,uint param_2)

{
  if ((uint)param_1 != (param_2 & 0xff)) {
    FUN_00062dd8(param_2);
    FUN_000621d8((int)(char)param_1,param_2);
    return;
  }
  return;
}


/* ROM address: 0x00064da6; body bytes: 252; decompiled */

void FUN_00064da6(ushort *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  
  cVar1 = (&DAT_ffff8d54)[(uint)*param_1 * 2];
  iVar2 = (int)*(char *)(param_1 + 3);
  iVar3 = (int)*(char *)((int)param_1 + 0xd);
  if (*param_1 == 0) {
    cVar4 = '\0';
  }
  else {
    cVar4 = FUN_000678b4((int)(short)*param_1);
  }
  cVar5 = FUN_0006559c((int)*(char *)(param_1 + 3));
  if (cVar5 == '`') {
    if ((0x4f < *(byte *)(param_2 + 10)) || ((cVar1 == '\x11' && (cVar4 == '\0')))) {
      iVar2 = 0;
      iVar3 = 8;
    }
  }
  else if (cVar5 == 'p') {
    if ((0x4f < *(byte *)(param_2 + 10)) || ((cVar1 == '\x11' && (cVar4 == '\0')))) {
      iVar2 = 0xc1;
    }
  }
  else if (cVar5 == -0x40) {
    if ((byte)(&DAT_0007e442)[*param_1] <= *(byte *)(param_2 + 9)) {
      iVar2 = 0xc1;
    }
  }
  else if ((cVar5 == -0x3f) && ((byte)(&DAT_0007e4ce)[*param_1] <= *(byte *)(param_2 + 8))) {
    iVar3 = 8;
    iVar2 = 0;
  }
  FUN_00062dd8(iVar2);
  FUN_0006310a(iVar3);
  *(char *)(param_2 + 6) = (char)iVar2;
  *(char *)(param_2 + 0xd) = (char)iVar3;
  return;
}


/* ROM address: 0x00064eba; body bytes: 22; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000637aa (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00064eba(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xc0;
  if (param_1 != -0x40) {
    uVar1 = 0;
  }
  FUN_00062e4a(uVar1);
  return;
}


/* ROM address: 0x00064ed0; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000637c0 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00064ed0(char param_1)

{
  if (param_1 == -0x40) {
    FUN_00062e4a(0xc0);
    return;
  }
  return;
}


/* ROM address: 0x00064ee4; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000637d4 (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00064ee4(ushort *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)((int)param_1 + 7);
  iVar2 = (int)cVar1;
  if (cVar1 == -0x80) {
    iVar2 = 0xc0;
    if (*(char *)(param_2 + 6) != -0x40) {
      iVar2 = 0;
    }
  }
  else if ((cVar1 == -0x40) && ((byte)(&DAT_0007e442)[*param_1] <= *(byte *)(param_2 + 9))) {
    iVar2 = 0;
  }
  FUN_00062e4a(iVar2);
  *(char *)(param_2 + 7) = (char)iVar2;
  return;
}


/* ROM address: 0x00064f44; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063834 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00064f44(ushort *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)*(char *)((int)param_1 + 7);
  if ((byte)(&DAT_0007e442)[*param_1] <= *(byte *)(param_2 + 9)) {
    iVar1 = 0;
  }
  FUN_00062e4a(iVar1);
  *(char *)(param_2 + 7) = (char)iVar1;
  return;
}


/* ROM address: 0x00064f94; body bytes: 118; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063884 (118 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00064f94(ushort *param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  char cVar4;
  
  cVar2 = (&DAT_ffff8d54)[(uint)*param_1 * 2];
  bVar1 = *(byte *)((int)param_1 + 9);
  iVar3 = (int)(char)bVar1;
  if (*param_1 == 0) {
    cVar4 = '\0';
  }
  else {
    cVar4 = FUN_000678b4((int)(short)*param_1);
  }
  if ((((cVar2 == '\x11') && (*(char *)(param_1 + 3) == -0x40)) && (cVar4 == '\0')) &&
     (bVar1 < (byte)(&DAT_0007e442)[*param_1])) {
    iVar3 = iVar3 + 1;
  }
  FUN_00062ebc(iVar3);
  *(char *)(param_2 + 9) = (char)iVar3;
  return;
}


/* ROM address: 0x0006500a; body bytes: 130; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000638fa (130 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006500a(ushort *param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  char cVar4;
  
  cVar2 = (&DAT_ffff8d54)[(uint)*param_1 * 2];
  bVar1 = *(byte *)(param_1 + 4);
  iVar3 = (int)(char)bVar1;
  if (*param_1 == 0) {
    cVar4 = '\0';
  }
  else {
    cVar4 = FUN_000678b4((int)(short)*param_1);
  }
  if ((((cVar2 != ' ') && (*(char *)(param_1 + 3) == -0x3f)) && (cVar4 == '\0')) &&
     ((DAT_ffff8e7e == '\x01' && (bVar1 < (byte)(&DAT_0007e4ce)[*param_1])))) {
    iVar3 = iVar3 + 1;
  }
  FUN_00062f2e(iVar3);
  *(char *)(param_2 + 8) = (char)iVar3;
  return;
}


/* ROM address: 0x0006508c; body bytes: 56; decompiled */

uint FUN_0006508c(void)

{
  uint uVar1;
  
  uVar1 = FUN_0006559c();
  uVar1 = uVar1 & 0xff;
  if ((uVar1 != 0x60) && (uVar1 != 0x70)) {
    if (uVar1 == 0xc0) {
      uVar1 = FUN_00062fa0(0x50);
      return uVar1;
    }
    return uVar1;
  }
  uVar1 = FUN_00062fa0(0);
  return uVar1;
}


/* ROM address: 0x000650ea; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000639da (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000650ea(ushort *param_1,int param_2)

{
  char cVar1;
  char cVar3;
  int iVar2;
  
  if (*param_1 == 0) {
    cVar3 = '\0';
  }
  else {
    cVar3 = FUN_000678b4((int)(short)*param_1);
  }
  cVar1 = (&DAT_ffff8d54)[(uint)*param_1 * 2];
  iVar2 = (int)(char)*(byte *)(param_1 + 5);
  if ((cVar1 == '\x11') && (cVar3 == '\0')) {
    iVar2 = 0x50;
  }
  else if (((cVar1 == '\x10') || (cVar1 == '\0')) && (*(byte *)(param_1 + 5) < 0x50)) {
    iVar2 = iVar2 + 1;
  }
  FUN_00062fa0(iVar2);
  *(char *)(param_2 + 10) = (char)iVar2;
  return;
}


/* ROM address: 0x00065158; body bytes: 158; decompiled */

void FUN_00065158(ushort *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  
  cVar1 = (&DAT_ffff8d54)[(uint)*param_1 * 2];
  iVar2 = (int)*(char *)(param_1 + 6);
  if (*param_1 == 0) {
    cVar3 = '\0';
  }
  else {
    cVar3 = FUN_000678b4((int)(short)*param_1);
  }
  cVar4 = FUN_0006559c((int)*(char *)(param_1 + 3));
  if ((cVar4 == '`') || (cVar4 == 'p')) {
    if ((0x4f < *(byte *)(param_2 + 10)) || ((cVar1 == '\x11' && (cVar3 == '\0')))) {
      iVar2 = 0;
    }
  }
  else if ((cVar1 == '\x11') && (cVar3 == '\0')) {
    iVar2 = 0;
  }
  FUN_00063098(iVar2);
  *(char *)(param_2 + 0xc) = (char)iVar2;
  return;
}


/* ROM address: 0x00065206; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063af6 (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065206(short param_1,char param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if ((((param_2 == '\0') || (param_2 == 'P')) || (param_2 == -0x3f)) && (DAT_ffffd7b2 != '\x01')) {
    cVar1 = FUN_0005fcae();
    if (cVar1 == '\0') {
      uVar2 = 0;
    }
    else {
      cVar1 = FUN_000678b4((int)param_1);
      if ((byte)(cVar1 + 1U) < 3) {
        FUN_0006789e();
        uVar2 = 2;
      }
      else {
        FUN_0006789e(3);
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}


/* ROM address: 0x00065270; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063b60 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065270(short param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_0005fc98();
  if (cVar1 == '\0') {
    uVar2 = 0;
  }
  else {
    cVar1 = FUN_000678b4((int)param_1);
    if ((byte)(cVar1 + 1U) < 4) {
      FUN_0006789e();
      uVar2 = 2;
    }
    else {
      FUN_0006789e(4);
      uVar2 = 1;
    }
  }
  return uVar2;
}


/* ROM address: 0x000652b4; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063ba4 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000652b4(void)

{
  undefined4 uVar1;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  
  local_14 = FUN_0005fcf8();
  uStack_10 = FUN_0005fcf2();
  uStack_c = FUN_0005fcfe();
  uStack_8 = ref_returnCoolantTempGreaterThan71();
  uVar1 = FUN_000677f2(&local_14);
  return uVar1;
}


/* ROM address: 0x00065314; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063c04 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065314(void)

{
  undefined4 uVar1;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  
  local_14 = FUN_0005fcf8();
  uStack_10 = FUN_0005fcf2();
  uStack_c = FUN_0005fcfe();
  uStack_8 = ref_returnCoolantTempGreaterThan71();
  uVar1 = FUN_00067732(&local_14);
  return uVar1;
}


/* ROM address: 0x00065344; body bytes: 122; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063c34 (122 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00065344(ushort *param_1)

{
  char cVar1;
  byte bVar3;
  uint uVar2;
  undefined1 auStack_18 [20];
  
  cVar1 = (&DAT_ffff8d54)[(uint)*param_1 * 2];
  bVar3 = FUN_0006559c((int)*(char *)(param_1 + 3));
  if ((cVar1 == ' ') && ((bVar3 == 0x60 || (bVar3 == 0x70)))) {
    uVar2 = FUN_00067826((int)(short)*param_1,auStack_18);
    if ((uVar2 & 0xff) == 0) {
      uVar2 = FUN_00067732(auStack_18);
    }
  }
  else {
    uVar2 = (uint)bVar3;
    if ((uVar2 == 0) || ((uVar2 == 0x50 || (uVar2 == 0xc1)))) {
      uVar2 = FUN_00067760();
    }
  }
  return uVar2;
}


/* ROM address: 0x000653e0; body bytes: 160; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063cd0 (160 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000653e0(short param_1,uint param_2,char param_3)

{
  char cVar4;
  uint uVar1;
  uint uVar2;
  short sVar3;
  
  FUN_000626d4(0);
  cVar4 = FUN_0006559c((int)param_3);
  uVar1 = FUN_00067c78(0);
  FUN_00067c64(uVar1 | param_2);
  uVar2 = FUN_000676de((int)param_1);
  FUN_000676c8(uVar2 | param_2);
  sVar3 = FUN_00067c1a(0);
  if (sVar3 == 0) {
    FUN_00067c06(param_2);
  }
  if (((cVar4 == 'p') || (cVar4 == -0x40)) || (cVar4 == -0x3f)) {
    uVar2 = FUN_00067674((int)param_1);
    FUN_0006763c(uVar2 | param_2);
    sVar3 = FUN_00067bbc(0);
    if (sVar3 == 0) {
      FUN_00067b88(uVar1 | param_2);
    }
  }
  FUN_00062918(0);
  return;
}


/* ROM address: 0x00065480; body bytes: 224; decompiled */

void FUN_00065480(short *param_1)

{
  char cVar1;
  char cVar2;
  
  FUN_000626d4(0);
  if ((*(char *)(param_1 + 3) == '\0') || (*(char *)(param_1 + 3) == 'P')) {
    FUN_0006763c(0);
    FUN_000676c8(0);
  }
  else if (*(char *)(param_1 + 6) == '\0') {
    FUN_000676c8(0);
  }
  if (*param_1 == 1) {
    cVar1 = FUN_00061800(0);
    cVar2 = FUN_00061d1a(0);
  }
  else {
    cVar1 = FUN_00061800(1);
    cVar2 = FUN_00061d1a(1);
  }
  if (((*(char *)(param_1 + 3) == '\0') || (*(char *)(param_1 + 3) == 'P')) &&
     ((cVar1 == '\0' || (cVar1 == 'P')))) {
    FUN_00067b88(0);
  }
  if ((*(char *)(param_1 + 6) == '\0') && (cVar2 == '\0')) {
    FUN_00067c06(0);
  }
  if (((*(char *)(param_1 + 3) == '\0') || (*(char *)(param_1 + 3) == 'P')) &&
     ((cVar1 == '\0' || (cVar1 == 'P')))) {
    FUN_00067c64(0);
  }
  FUN_00062918(0);
  return;
}


/* ROM address: 0x0006559c; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063e8c (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0006559c(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xff;
  if ((uVar1 == 0) || (0x3f < uVar1)) {
    if ((0x80 < uVar1) && (uVar1 < 0xc0)) {
      param_1 = 0x70;
    }
  }
  else {
    param_1 = 0x60;
  }
  return param_1;
}


/* ROM address: 0x000655e4; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063ed4 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000655e4(void)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  cVar1 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8e7c);
  if ((cVar1 != '\0') || (cVar1 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8e7e), cVar1 != '\0')) {
    uVar2 = 1;
  }
  return uVar2;
}


/* ROM address: 0x00065616; body bytes: 26; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00063f06 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00065616(void)

{
  _DAT_ffff8e7c = rx8_pack_u8_with_complement(0);
  _DAT_ffff8e7e = rx8_pack_u8_with_complement(0);
  return;
}


/* ROM address: 0x00065630; body bytes: 40; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00063f20 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065630(void)

{
  undefined4 uVar1;
  float fVar2;
  float extraout_fr0;
  
  fVar2 = (float)FUN_0005fc72();
  uVar1 = FUN_0005fc6c();
  if (extraout_fr0 <= fVar2) {
    uVar1 = rx8_pack_u8_with_complement(1);
    _DAT_ffff8e7c = (undefined2)uVar1;
  }
  return uVar1;
}


/* ROM address: 0x00065658; body bytes: 56; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00063f48 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_coolantTempPlausibilityCheck___(void)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)FUN_0005fc78();
  fVar3 = (float)FUN_0005fc7e();
  puVar1 = &DAT_00065754;
  if ((71.0 <= fVar2) && (puVar1 = &DAT_00065758, 22.0 <= fVar2 - fVar3)) {
    puVar1 = (undefined4 *)rx8_pack_u8_with_complement(1);
    _DAT_ffff8e7e = SUB42(puVar1,0);
  }
  return puVar1;
}


/* ROM address: 0x00065690; body bytes: 164; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063f80 (164 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_driveCycleDetectMAYBE_(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  
  uVar2 = 1;
  cVar1 = FUN_00067778(param_1,&fStack_20);
  if (cVar1 == '\0') {
    fVar3 = (float)FUN_0005fcf8();
    fVar4 = (float)FUN_0005fcf2();
    cVar1 = ref_returnCoolantTempGreaterThan71();
    fVar4 = rx8_absolute_difference(fVar4,fStack_1c);
    fVar3 = rx8_absolute_difference(fVar3,fStack_20);
    if (fStack_18 < 71.0) {
      if (((cVar1 == '\0') && (fVar4 <= 0.2)) && (fVar3 <= 375.0)) {
        uVar2 = 0;
      }
    }
    else if (((cVar1 == '\x01') && (fVar4 <= 0.2)) && (fVar3 <= 375.0)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}


/* ROM address: 0x00065778; body bytes: 8; decompiled */

void FUN_00065778(void)

{
  DAT_ffffd958 = 0;
  return;
}


/* ROM address: 0x00065780; body bytes: 76; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00064070 (76 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00065780(undefined4 param_1)

{
  FUN_000657cc();
  FUN_000622e0();
  FUN_0006106e();
  _DAT_ffff8e7e = rx8_pack_u8_with_complement(0);
  FUN_00064512();
  FUN_0006057e();
  FUN_00060518();
  FUN_00060a86();
  FUN_00064530();
  FUN_0006455c();
  os_schedule_task_event(2,4,param_1);
  return;
}


/* ROM address: 0x000657cc; body bytes: 14; decompiled */

void FUN_000657cc(void)

{
  FUN_0006051c();
  FUN_0006058e();
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * obd_mode01_current_data [high]: service table record 0x5eb40 (service 0x01) -> handler; ROM bytes verified; OBD Mode 01 handler (caseD_27)
 */
/* ROM address: 0x0006581c; body bytes: 282; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006410c (282 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint obd_mode01_current_data(uint param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  char local_3c [4];
  undefined1 auStack_38 [4];
  char cStack_34;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  param_1 = param_1 & 0xffff;
  bVar1 = false;
  if ((param_1 == 0) || (6 < param_1)) {
    bVar1 = true;
  }
  cStack_34 = param_2;
  if (!bVar1) {
    DAT_ffffd816 = 1;
    auStack_38[0] = 0x41;
    ref_setupForUdsResponse_(1,auStack_38);
    iVar5 = 0;
    if (param_1 != 0) {
      do {
        ref_udsServiceResponse(1,local_3c);
        cVar2 = FUN_00066678(1,(int)local_3c[0]);
        if (cVar2 == '\0') {
          cVar2 = FUN_00066718((int)local_3c[0]);
          if (cVar2 == '\0') {
            FUN_00065936((int)local_3c[0]);
          }
          else {
            FUN_00065980((int)local_3c[0]);
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)param_1);
    }
    if (DAT_ffffd816 == 1) {
      bVar1 = false;
    }
  }
  uVar3 = (uint)bVar1;
  if (uVar3 == 0) {
    local_30 = 1;
    uStack_2c = (uint)DAT_ffffd816;
    uStack_28 = 8;
    uStack_24 = 0;
    uVar3 = FUN_00068d56();
  }
  else if (uVar3 == 1) {
    if (cStack_34 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar3 = FUN_0006672a(1,0x12,uVar4);
  }
  else if (uVar3 == 2) {
    if (cStack_34 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar3 = FUN_0006672a(1,0x12,uVar4);
  }
  return uVar3;
}


/* ROM address: 0x00065936; body bytes: 74; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064226 (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065936(char param_1)

{
  undefined4 uVar1;
  char local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  
  uVar1 = FUN_000666aa(1,(int)param_1);
  uStack_b = (undefined1)((uint)uVar1 >> 0x18);
  uStack_a = (undefined1)((uint)uVar1 >> 0x10);
  uStack_9 = (undefined1)((uint)uVar1 >> 8);
  uStack_8 = (undefined1)uVar1;
  local_c = param_1;
  uVar1 = ref_setupForUdsResponse_(1,&local_c,5);
  DAT_ffffd816 = DAT_ffffd816 + 5;
  return uVar1;
}


/* ROM address: 0x00065980; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064270 (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00065980(char param_1)

{
  uint uVar1;
  short sVar2;
  undefined1 auStack_14 [7];
  char local_d [5];
  
  local_d[0] = param_1;
  uVar1 = jump_to_FUN_00054d90((int)param_1);
  if ((uVar1 & 0xff) != 0) {
    ref_setupForUdsResponse_(1,local_d);
    DAT_ffffd816 = DAT_ffffd816 + 1;
    sVar2 = (short)(uVar1 & 0xff);
    ref_setupForUdsResponse_(1,auStack_14,uVar1 & 0xff);
    uVar1 = (uint)sVar2;
    DAT_ffffd816 = DAT_ffffd816 + sVar2;
  }
  return uVar1;
}


/* ROM address: 0x00065bc4; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000644b4 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065bc4(short *param_1,ushort param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      cVar1 = FUN_00062e6a((int)*param_1);
      iVar3 = iVar3 + 1;
      if (cVar1 != '\0') {
        uVar2 = 0xc0;
      }
      param_1 = param_1 + 1;
    } while (iVar3 < (int)(uint)param_2);
  }
  return uVar2;
}


/* ROM address: 0x00065c0c; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000644fc (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065c0c(ushort *param_1)

{
  ushort *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = param_1;
  while( true ) {
    if (param_1[iVar2] == 0xffff) {
      return 0;
    }
    if ((((&DAT_ffff8d55)[(uint)*puVar1 * 2] & 1) != 1) &&
       (((&DAT_ffff8d55)[(uint)*puVar1 * 2] & 2) != 2)) break;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  }
  return 1;
}


/* [ADDITIONAL SOURCE REVIEW]
 * obd_mode02_freeze_frame [high]: service table record 0x5eb4c (service 0x02) -> handler; ROM bytes verified; OBD Mode 02
 */
/* ROM address: 0x00065c88; body bytes: 462; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064578 (462 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint obd_mode02_freeze_frame(uint param_1,char param_2)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  char local_48 [4];
  char acStack_44 [4];
  undefined1 auStack_40 [4];
  uint uStack_3c;
  uint uStack_38;
  char cStack_34;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uVar6 = param_1 & 0xffff;
  bVar1 = false;
  bVar2 = false;
  if (((uVar6 == 0) || (6 < uVar6)) || ((param_1 & 1) == 1)) {
    bVar1 = true;
  }
  cStack_34 = param_2;
  if (!bVar1) {
    DAT_ffffd818 = 1;
    auStack_40[0] = 0x42;
    ref_setupForUdsResponse_(2,auStack_40,1);
    cVar3 = FUN_0006071e(&DAT_ffffd81a);
    iVar5 = 0;
    uStack_38 = (uint)(cVar3 == '\0');
    uStack_3c = (uint)(cVar3 == '\0');
    if (uVar6 != 0) {
      do {
        ref_udsServiceResponse(2,local_48,1);
        ref_udsServiceResponse(2,acStack_44,1);
        cVar3 = FUN_00066678(2,(int)local_48[0]);
        if (cVar3 == '\0') {
          cVar3 = FUN_00066718((int)local_48[0]);
          if (cVar3 == '\0') {
            FUN_00065e56((int)local_48[0],(int)acStack_44[0]);
          }
          else if (local_48[0] == '\x02') {
            if ((uStack_38 == 0) || (acStack_44[0] != '\0')) {
              FUN_00065f96(2,(int)acStack_44[0]);
            }
            else {
              FUN_00065ed0(2,0);
            }
          }
          else if ((uStack_3c != 0) && (acStack_44[0] == '\0')) {
            FUN_00065ed0((int)local_48[0],0);
          }
          bVar2 = true;
        }
        iVar5 = iVar5 + 2;
      } while (iVar5 < (int)uVar6);
    }
    if (DAT_ffffd818 == 1) {
      if (bVar2) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
  }
  uVar6 = (uint)bVar1;
  if (uVar6 == 0) {
    local_30 = 2;
    uStack_2c = (uint)DAT_ffffd818;
    uStack_28 = 8;
    uStack_24 = 0;
    uVar6 = FUN_00068d56();
  }
  else if (uVar6 == 1) {
    if (cStack_34 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar6 = FUN_0006672a(2,0x12,uVar4);
  }
  else if (uVar6 == 2) {
    if (cStack_34 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar6 = FUN_0006672a(2,0x12,uVar4);
  }
  else if (uVar6 == 3) {
    if (cStack_34 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar6 = FUN_0006672a(2,0x22,uVar4);
  }
  return uVar6;
}


/* ROM address: 0x00065e56; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064746 (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065e56(char param_1,undefined1 param_2)

{
  undefined4 uVar1;
  char local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  uVar1 = FUN_000666aa(2,(int)param_1);
  uStack_a = (undefined1)((uint)uVar1 >> 0x18);
  uStack_9 = (undefined1)((uint)uVar1 >> 0x10);
  uStack_8 = (undefined1)((uint)uVar1 >> 8);
  uStack_7 = (undefined1)uVar1;
  local_c = param_1;
  uStack_b = param_2;
  uVar1 = ref_setupForUdsResponse_(2,&local_c,6);
  DAT_ffffd818 = DAT_ffffd818 + 6;
  return uVar1;
}


/* ROM address: 0x00065ed0; body bytes: 198; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000647c0 (198 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00065ed0(char param_1,undefined1 param_2)

{
  undefined1 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  byte bVar4;
  int iVar5;
  undefined *puVar6;
  byte bVar7;
  undefined1 local_20 [6];
  undefined1 local_1a;
  char local_19 [5];
  
  bVar4 = 0;
  uVar2 = 0;
  while( true ) {
    local_1a = param_2;
    local_19[0] = param_1;
    bVar7 = 0;
    if (((&DAT_0005edbc)[(uVar2 & 0xff) * 2] == -1) || (0x27 < bVar4)) goto LAB_00065f4e;
    iVar5 = (uVar2 & 0xff) * 2;
    bVar7 = (&DAT_0005edbd)[iVar5];
    if ((&DAT_0005edbc)[iVar5] == param_1) break;
    bVar4 = bVar4 + bVar7;
    uVar2 = uVar2 + 1;
  }
  iVar5 = 0;
  puVar6 = &DAT_ffffd81a + bVar4;
  puVar3 = local_20;
  if (bVar7 != 0) {
    do {
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      iVar5 = iVar5 + 1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
    } while (iVar5 < (int)(uint)bVar7);
  }
LAB_00065f4e:
  if (bVar7 != 0) {
    ref_setupForUdsResponse_(2,local_19,1);
    ref_setupForUdsResponse_(2,&local_1a,1);
    DAT_ffffd818 = DAT_ffffd818 + 2;
    ref_setupForUdsResponse_(2,local_20);
    DAT_ffffd818 = DAT_ffffd818 + (ushort)bVar7;
  }
  return;
}


/* ROM address: 0x00065f96; body bytes: 78; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064886 (78 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00065f96(undefined1 param_1,undefined1 param_2)

{
  undefined2 local_14 [3];
  undefined1 local_e;
  undefined1 local_d [5];
  
  local_14[0] = 0;
  local_e = param_2;
  local_d[0] = param_1;
  ref_setupForUdsResponse_(2,local_d,1);
  ref_setupForUdsResponse_(2,&local_e,1);
  DAT_ffffd818 = DAT_ffffd818 + 2;
  ref_setupForUdsResponse_(2,local_14);
  DAT_ffffd818 = DAT_ffffd818 + 2;
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * obd_mode03_stored_dtc [high]: service table record 0x5eb58 (service 0x03) -> handler; ROM bytes verified; OBD Mode 03
 */
/* ROM address: 0x00065ff8; body bytes: 180; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000648e8 (180 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint obd_mode03_stored_dtc(short param_1,char param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 local_30 [4];
  undefined *puStack_2c;
  undefined *puStack_28;
  undefined4 local_24;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  DAT_ffffd8a0 = 0;
  uVar2 = (uint)(param_1 != 0);
  if (uVar2 == 0) {
    puStack_2c = &DAT_ffffd844;
    uVar1 = FUN_000615c6(0x80,2);
    local_30[0] = (undefined1)uVar1;
    puStack_28 = &DAT_ffffd86c;
    DAT_ffffd8a0 = FUN_000667c8(3,&DAT_ffffd86c,puStack_2c,uVar1);
    local_30[0] = 0x43;
    ref_setupForUdsResponse_(3,local_30,1);
    ref_setupForUdsResponse_(3,&DAT_ffffd8a0,1);
    ref_setupForUdsResponse_(3,puStack_28,(uint)DAT_ffffd8a0 << 1);
    iStack_20 = (uint)DAT_ffffd8a0 * 2 + 2;
    local_24 = 3;
    uStack_1c = 8;
    uStack_18 = 0;
    uVar2 = FUN_00068d56();
  }
  else if (uVar2 == 1) {
    if (param_2 == '\x01') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    uVar2 = FUN_0006672a(3,0x12,uVar1);
  }
  return uVar2;
}


/* [ADDITIONAL SOURCE REVIEW]
 * obd_mode04_clear_dtc [high]: service table record 0x5eb64 (service 0x04) -> handler; ROM bytes verified; OBD Mode 04 (also ref_ClearFaults_ at 0x558ac for service 0x14)
 */
/* ROM address: 0x000660d0; body bytes: 162; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000649c0 (162 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint obd_mode04_clear_dtc(short param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 local_2c [4];
  char cStack_28;
  undefined4 local_24;
  undefined **ppuStack_20;
  
  bVar1 = param_1 != 0;
  cStack_28 = (char)param_2;
  if (!bVar1) {
    param_2 = FUN_0006619a();
    if ((param_2 & 0xff) == 0) {
      DAT_ffffd958 = 1;
      local_24 = 4;
      ppuStack_20 = &PTR_ref_LongFunc_0000ff00;
      os_schedule_task_event(2,3);
      local_2c[0] = 0x44;
      param_2 = ref_setupForUdsResponse_(4,local_2c,1);
    }
    else {
      bVar1 = false;
    }
  }
  uVar2 = (uint)bVar1;
  if (uVar2 != 0) {
    if (uVar2 == 1) {
      if (cStack_28 == '\x01') {
        uVar3 = 2;
      }
      else {
        uVar3 = 1;
      }
      param_2 = FUN_0006672a(4,0x12,uVar3);
    }
    else {
      param_2 = uVar2;
      if (uVar2 == 2) {
        param_2 = FUN_0006672a(4,0x22,1);
      }
    }
  }
  return param_2;
}


/* ROM address: 0x00066172; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064a62 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066172(void)

{
  undefined4 uVar1;
  
  DAT_ffffd958 = 0;
  uVar1 = FUN_00068d56();
  return uVar1;
}


/* ROM address: 0x0006619a; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064a8a (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0006619a(void)

{
  FUN_0005fc72();
  FUN_0005fc84();
  return 0;
}


/* [ADDITIONAL SOURCE REVIEW]
 * obd_mode07_pending_dtc [high]: service table record 0x5eb7c (service 0x07) -> handler; ROM bytes verified; OBD Mode 07
 */
/* ROM address: 0x000661ec; body bytes: 180; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064adc (180 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint obd_mode07_pending_dtc(short param_1,char param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 local_30 [4];
  undefined *puStack_2c;
  undefined *puStack_28;
  undefined4 local_24;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  DAT_ffffd900 = 0;
  uVar2 = (uint)(param_1 != 0);
  if (uVar2 == 0) {
    puStack_2c = &DAT_ffffd8a4;
    uVar1 = FUN_00061d28(1,2);
    local_30[0] = (undefined1)uVar1;
    puStack_28 = &DAT_ffffd8cc;
    DAT_ffffd900 = FUN_000667c8(7,&DAT_ffffd8cc,puStack_2c,uVar1);
    local_30[0] = 0x47;
    ref_setupForUdsResponse_(7,local_30,1);
    ref_setupForUdsResponse_(7,&DAT_ffffd900,1);
    ref_setupForUdsResponse_(7,puStack_28,(uint)DAT_ffffd900 << 1);
    iStack_20 = (uint)DAT_ffffd900 * 2 + 2;
    local_24 = 7;
    uStack_1c = 8;
    uStack_18 = 0;
    uVar2 = FUN_00068d56();
  }
  else if (uVar2 == 1) {
    if (param_2 == '\x01') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    uVar2 = FUN_0006672a(7,0x12,uVar1);
  }
  return uVar2;
}


/* [ADDITIONAL SOURCE REVIEW]
 * obd_mode09_vehicle_info [high]: service table record 0x5eb88 (service 0x09) -> handler; ROM bytes verified; OBD Mode 09 (ref_OBDMode9Fuction)
 */
/* ROM address: 0x000662c0; body bytes: 444; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064bb0 (444 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint obd_mode09_vehicle_info(undefined4 param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  uint unaff_r9;
  undefined1 local_34 [4];
  char cStack_30;
  undefined4 local_2c;
  uint uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  bVar1 = false;
  cStack_30 = param_2;
  cVar2 = FUN_000664c4(param_1);
  if (cVar2 == '\0') {
    ref_udsServiceResponse(9,&DAT_ffffd927,param_1);
    unaff_r9 = FUN_00066718((int)(char)DAT_ffffd927);
    cVar2 = FUN_00066500(unaff_r9,&DAT_ffffd927,param_1);
    if (cVar2 != '\0') {
      bVar1 = true;
    }
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    DAT_ffffd904 = 1;
    local_34[0] = 0x49;
    ref_setupForUdsResponse_(9,local_34,1);
    if ((unaff_r9 & 0xff) == 0) {
      FUN_00066526(&DAT_ffffd927,param_1);
    }
    else {
      cVar2 = FUN_00066678(9,(int)(char)DAT_ffffd927);
      if (cVar2 == '\0') {
        if (DAT_ffffd927 == 6) {
          cVar2 = FUN_00066620();
          if (cVar2 == '\0') {
            FUN_000665cc((int)(char)DAT_ffffd927);
            if (DAT_ffffd904 == 1) {
              bVar1 = false;
            }
          }
          else {
            bVar1 = true;
          }
        }
        else if (DAT_ffffd927 == 2) {
          FUN_000665cc(2);
          if (DAT_ffffd904 == 1) {
            bVar1 = false;
          }
        }
        else if (DAT_ffffd927 < 9) {
          FUN_000665cc((int)(char)DAT_ffffd927);
        }
      }
    }
    if ((bVar1 == false) && (DAT_ffffd904 == 1)) {
      bVar1 = false;
    }
  }
  uVar3 = (uint)bVar1;
  if (uVar3 == 0) {
    local_2c = 9;
    uStack_28 = (uint)DAT_ffffd904;
    uStack_24 = 8;
    uStack_20 = 0;
    uVar3 = FUN_00068d56();
  }
  else if (uVar3 == 1) {
    if (cStack_30 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar3 = FUN_0006672a(9,0x12,uVar4);
  }
  else if (uVar3 == 2) {
    if (cStack_30 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar3 = FUN_0006672a(9,0x12,uVar4);
  }
  else if (uVar3 == 3) {
    uVar3 = FUN_0006672a(9,0x22,1);
  }
  else if (uVar3 == 4) {
    uVar3 = FUN_0006672a(9,0x22,3);
  }
  else if (uVar3 == 6) {
    if (cStack_30 == '\x01') {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar3 = FUN_0006672a(9,0x10,uVar4);
  }
  return uVar3;
}


/* ROM address: 0x0006647c; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064d6c (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0006647c(void)

{
  undefined4 uVar1;
  undefined1 local_18 [4];
  undefined4 local_14;
  uint uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  ref_unknownMode22Func(9);
  DAT_ffffd904 = 1;
  local_18[0] = 0x49;
  ref_setupForUdsResponse_(9,local_18,1);
  FUN_000665cc(6);
  local_14 = 9;
  uStack_10 = (uint)DAT_ffffd904;
  uStack_c = 8;
  uStack_8 = 0;
  uVar1 = FUN_00068d56();
  return uVar1;
}


/* ROM address: 0x000664c4; body bytes: 22; decompiled */

undefined4 FUN_000664c4(ushort param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == 0) || (6 < param_1)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* ROM address: 0x00066500; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064df0 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066500(char param_1,undefined4 param_2,ushort param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 == '\0') {
    uVar1 = FUN_000666c8();
  }
  else if (1 < param_3) {
    uVar1 = 1;
  }
  return uVar1;
}


/* ROM address: 0x00066526; body bytes: 166; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064e16 (166 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00066526(char *param_1,uint param_2)

{
  char cVar2;
  undefined4 uVar1;
  int iVar3;
  char *pcVar4;
  char local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  
  iVar3 = 0;
  pcVar4 = param_1;
  if ((param_2 & 0xffff) != 0) {
    do {
      cVar2 = FUN_00066678(9,(int)*param_1);
      if (cVar2 == '\0') {
        uVar1 = FUN_000666aa(9,(int)*pcVar4);
        local_28 = *pcVar4;
        local_27 = (undefined1)((uint)uVar1 >> 0x18);
        local_26 = (undefined1)((uint)uVar1 >> 0x10);
        local_25 = (undefined1)((uint)uVar1 >> 8);
        local_24 = (undefined1)uVar1;
        ref_setupForUdsResponse_(9,&local_28,5);
        DAT_ffffd904 = DAT_ffffd904 + 5;
      }
      iVar3 = iVar3 + 1;
      pcVar4 = pcVar4 + 1;
      param_1 = param_1 + 1;
    } while (iVar3 < (int)(param_2 & 0xffff));
  }
  return;
}


/* ROM address: 0x000665cc; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064ebc (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000665cc(char param_1)

{
  ushort uVar1;
  uint uVar2;
  char local_d [5];
  
  local_d[0] = param_1;
  uVar2 = ref_OBDModeFunc_Unsure((int)param_1,&DAT_ffffd906);
  if ((uVar2 & 0xff) != 0) {
    ref_setupForUdsResponse_(9,local_d,1);
    uVar1 = (ushort)uVar2;
    DAT_ffffd904 = DAT_ffffd904 + 1;
    uVar2 = ref_setupForUdsResponse_(9,&DAT_ffffd906);
    DAT_ffffd904 = DAT_ffffd904 + (uVar1 & 0xff);
  }
  return uVar2;
}


/* ROM address: 0x00066620; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064f10 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066620(void)

{
  FUN_0005fc72();
  FUN_0005fc84();
  return 0;
}


/* ROM address: 0x00066678; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064f68 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066678(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_2 & 0xff) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_000666aa(param_1,param_2 + 0xff & 0xe0);
    uVar1 = FUN_000669be(param_2,uVar1);
  }
  return uVar1;
}


/* ROM address: 0x000666aa; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064f9a (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000666aa(byte param_1,uint param_2)

{
  return (&DAT_0005ec9c)[(param_1 - 1) * 8 + ((param_2 & 0xff) >> 5)];
}


/* ROM address: 0x000666c8; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064fb8 (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000666c8(char param_1,char *param_2,ushort param_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_3 != 0) {
    do {
      cVar1 = FUN_00066718((int)*param_2);
      if (cVar1 != param_1) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      param_2 = param_2 + 1;
    } while (iVar2 < (int)(uint)param_3);
  }
  return 0;
}


/* ROM address: 0x00066718; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065008 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_00066718(uint param_1)

{
  return (param_1 & 0x1f) != 0;
}


/* ROM address: 0x0006672a; body bytes: 138; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006501a (138 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0006672a(uint param_1,undefined1 param_2,uint param_3)

{
  undefined1 local_2c [4];
  undefined1 uStack_28;
  uint local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  param_3 = param_3 & 0xff;
  local_24 = param_1 & 0xff;
  uStack_28 = param_2;
  if (param_3 == 2) {
    ref_unknownMode22Func(param_1);
    local_2c[0] = 0x7f;
    ref_setupForUdsResponse_(param_1,local_2c,1);
    local_2c[0] = (undefined1)param_1;
    ref_setupForUdsResponse_(param_1,local_2c,1);
    local_2c[0] = uStack_28;
    ref_setupForUdsResponse_(param_1,local_2c,1);
    uStack_20 = 3;
    uStack_1c = 8;
    uStack_18 = 0;
    param_3 = FUN_00068d56();
  }
  else if (param_3 == 1) {
    uStack_20 = 3;
    uStack_1c = 8;
    uStack_18 = 1;
    param_3 = FUN_00068d56();
  }
  return param_3;
}


/* ROM address: 0x000667c8; body bytes: 210; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000650b8 (210 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000667c8(char param_1,undefined2 *param_2,ushort *param_3,byte param_4)

{
  ushort uVar2;
  uint uVar1;
  undefined2 *puVar3;
  int iVar4;
  ushort uVar6;
  ushort *puVar5;
  uint uVar7;
  
  uVar6 = 1;
  uVar2 = 0;
  uVar7 = 0;
  if ((param_1 == '\x01') || (param_1 == '\x03')) {
    uVar2 = FUN_00067bbc(0);
  }
  else if (param_1 == '\a') {
    uVar2 = FUN_00067c1a(0);
  }
  puVar3 = &DAT_0007e55c;
  do {
    if ((uVar6 & uVar2) != 0) {
      uVar1 = uVar7 & 0xff;
      uVar7 = uVar7 + 1;
      param_2[uVar1] = *puVar3;
    }
    uVar6 = uVar6 << 1;
    puVar3 = puVar3 + 1;
  } while (puVar3 < &UNK_0007e567);
  iVar4 = 0;
  if (1 < (uVar7 & 0xff)) {
    uVar7 = 1;
    *param_2 = 0x300;
  }
  puVar5 = param_3;
  if (param_4 != 0) {
    do {
      uVar2 = *puVar5;
      puVar5 = puVar5 + 1;
      if ((uVar2 != 0) && (uVar2 != 1)) {
        uVar1 = uVar7 & 0xff;
        uVar7 = uVar7 + 1;
        param_2[uVar1] = (&DAT_0007e560)[*param_3];
      }
      iVar4 = iVar4 + 1;
      param_3 = param_3 + 1;
    } while (iVar4 < (int)(uint)param_4);
  }
  return uVar7;
}


/* [MATH AND UNITS REVIEW]
 * rx8_insertion_sort_u16_key_u8_payload: Sorts records at stride 4 by ascending uint16 key, carrying a byte at offset 2. Strict-less comparison preserves equal-key order. Padding byte is not copied by the visible routine. Specialized insertion sort, not a proven qsort implementation.
 */
/* ROM address: 0x0006689e; body bytes: 172; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006518e (172 bytes). Names prefixed ref_
   are inherited hypotheses. */

/* [SORT RECORD RECONSTRUCTION] Typed equivalent for ordinary RAM records.
 * Four-byte stride, strict key comparison, low-16-bit count and untouched padding.
 * Volatile memory/interruption behavior is outside this reconstruction. */
void rx8_insertion_sort_u16_key_u8_payload(Rx8KeyPayloadRecord *records, uint32_t count)
{
  count &= 0xffffu;
  for (uint32_t insertion_index = 1; insertion_index < count; ++insertion_index) {
    uint16_t pending_key = records[insertion_index].key;
    uint8_t pending_payload = records[insertion_index].payload;
    uint32_t destination_index = insertion_index;
    while (destination_index != 0 && pending_key < records[destination_index - 1].key) {
      records[destination_index].key = records[destination_index - 1].key;
      records[destination_index].payload = records[destination_index - 1].payload;
      --destination_index;
    }
    records[destination_index].key = pending_key;
    records[destination_index].payload = pending_payload;
  }
  /* Padding bytes stay at their original locations, matching the ROM stores. */
}


/* ROM address: 0x0006694a; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006523a (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_0006694a(ushort *param_1,ushort param_2,short *param_3)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  iVar5 = 0;
  do {
    if ((int)(uint)param_2 <= iVar6) {
      return iVar5;
    }
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    bVar2 = false;
    if ((iVar5 != 0) && (iVar3 = 0, psVar4 = param_3, 0 < iVar5)) {
      do {
        if (*psVar4 == (&DAT_0007e560)[uVar1]) {
          bVar2 = true;
          break;
        }
        iVar3 = iVar3 + 1;
        psVar4 = psVar4 + 1;
      } while (iVar3 < iVar5);
    }
    iVar6 = iVar6 + 1;
    if (!bVar2) {
      param_3[iVar5] = (&DAT_0007e560)[uVar1];
      iVar5 = iVar5 + 1;
    }
  } while( true );
}


/* ROM address: 0x000669be; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000652ae (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000669be(uint param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  param_1 = param_1 & 0x1f;
  uVar2 = 1;
  if (param_1 == 0) {
    param_1 = 0x20;
  }
  uVar1 = FUN_000044e0(param_1,param_2,param_3,1);
  if ((uVar1 & param_2) != 0) {
    uVar2 = 0;
  }
  return uVar2;
}


/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffd930 dtc_status_bits (uint32): Status bits ANDed with low16 of ROM mask table 0x7e934 in ref_getFaultStatus__ (0x66a00).
 */
/* ROM address: 0x00066a00; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000652f0 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool ref_getFaultStatus__(uint param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = (param_1 & 0xffff) * 4;
  bVar3 = (*(uint *)(&DAT_0007e934 + iVar2) & dtc_status_bits_ffffd930 & 0xffff) != 0;
  if ((!bVar3) &&
     (uVar1 = FUN_00066a58(), (*(uint *)(&DAT_0007e934 + iVar2) & uVar1 & 0xffff0000) != 0)) {
    bVar3 = true;
  }
  return bVar3;
}


/* ROM address: 0x00066a46; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065336 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getFaultEvalState(void)

{
  uint uVar1;
  
  uVar1 = ref_setFaultEvalState_();
  dtc_status_bits_ffffd930 = uVar1 & 0xffff;
  return;
}


/* ROM address: 0x00066a58; body bytes: 160; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065348 (160 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00066a58(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  cVar1 = FUN_00066af8();
  if (cVar1 != '\0') {
    uVar2 = 0x80000000;
  }
  cVar1 = FUN_00066afc(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x40000000;
  }
  cVar1 = FUN_00066af8(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x20000000;
  }
  cVar1 = FUN_00066b70(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x10000000;
  }
  cVar1 = FUN_00066b8e(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x8000000;
  }
  cVar1 = FUN_00066af8(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x4000000;
  }
  cVar1 = FUN_00066af8(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x2000000;
  }
  cVar1 = FUN_00066af8(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x1000000;
  }
  cVar1 = FUN_00066baa(param_1);
  if (cVar1 != '\0') {
    uVar2 = uVar2 | 0x800000;
  }
  return uVar2;
}


/* ROM address: 0x00066af8; body bytes: 4; decompiled */

undefined4 FUN_00066af8(void)

{
  return 0;
}


/* ROM address: 0x00066afc; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000653ec (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066afc(uint param_1)

{
  char cVar1;
  ushort uVar2;
  short *psVar3;
  
  cVar1 = '\0';
  uVar2 = 0;
  psVar3 = (short *)(&PTR_PTR_0007f128)[param_1 & 0xffff];
  while( true ) {
    if (*psVar3 == -1) {
      return 0;
    }
    if (0x32 < uVar2) break;
    if (*psVar3 != -2) {
      cVar1 = FUN_00060478((int)*psVar3);
    }
    if (cVar1 == '\x01') {
      return 1;
    }
    psVar3 = psVar3 + 1;
    uVar2 = uVar2 + 1;
  }
  return 0;
}


/* ROM address: 0x00066b70; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065460 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_00066b70(uint param_1)

{
  return (&DAT_ffff8d54)[(uint)*(ushort *)(&DAT_0007df42 + (param_1 & 0xffff) * 2) * 2] != '\0';
}


/* ROM address: 0x00066b8e; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006547e (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_00066b8e(void)

{
  char cVar1;
  
  cVar1 = FUN_000603b2();
  return cVar1 == '\0';
}


/* ROM address: 0x00066baa; body bytes: 78; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006549a (78 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066baa(uint param_1)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar3 = 1;
  do {
    bVar2 = FUN_000604c2(iVar4);
    iVar1 = iVar4 + (param_1 & 0xffff) * 2;
    iVar4 = iVar4 + 1;
    if (((&DAT_0007eb8c)[iVar1] & bVar2) != 0) {
      uVar3 = 0;
    }
  } while (iVar4 < 2);
  return uVar3;
}


/* ROM address: 0x00066c4c; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006553c (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066c4c(char param_1,undefined4 param_2,short param_3,char param_4)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    uVar1 = FUN_00066cb4(param_2,(int)param_3);
  }
  else {
    uVar1 = FUN_00066d90(param_2,(int)param_3,(int)param_4);
  }
  return uVar1;
}


/* ROM address: 0x00066c80; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065570 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00066c80(char param_1,undefined1 *param_2,uint param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (param_1 == '\0') {
    puVar2 = &DAT_ffffd935;
    iVar3 = 0;
    if ((param_3 & 0xffff) != 0) {
      do {
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        iVar3 = iVar3 + 1;
        *puVar2 = uVar1;
        puVar2 = puVar2 + 1;
      } while (iVar3 < (int)(param_3 & 0xffff));
    }
    param_2 = &DAT_ffffd934;
    param_3 = param_3 + 1;
  }
  FUN_00067160(param_1,param_2,param_3);
  return;
}


/* ROM address: 0x00066cb4; body bytes: 194; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000655a4 (194 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00066cb4(char *param_1,uint param_2)

{
  char cVar2;
  undefined4 uVar1;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined1 auStack_38 [4];
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 local_24;
  
  puStack_34 = &DAT_ffffd935;
  iVar3 = 1;
  iVar4 = 0;
  auStack_38[0] = 0;
  puStack_30 = &DAT_ffffd936;
  puStack_28 = &DAT_ffffd938;
  puStack_2c = &DAT_ffffd937;
  pcVar5 = param_1;
  if ((param_2 & 0xffff) != 0) {
    do {
      cVar2 = FUN_00066678(8,(int)*param_1);
      if (cVar2 == '\0') {
        DAT_ffffd934 = *pcVar5;
        uVar1 = FUN_000666aa(8,(int)*pcVar5);
        local_24._0_1_ = (undefined1)((uint)uVar1 >> 0x18);
        *puStack_34 = local_24._0_1_;
        local_24._1_1_ = (undefined1)((uint)uVar1 >> 0x10);
        *puStack_30 = local_24._1_1_;
        local_24._2_1_ = (undefined1)((uint)uVar1 >> 8);
        *puStack_2c = local_24._2_1_;
        local_24._3_1_ = (undefined1)uVar1;
        *puStack_28 = (undefined1)local_24;
        local_24 = uVar1;
        FUN_0006713c(&DAT_ffffd934,5);
        iVar3 = 0;
      }
      iVar4 = iVar4 + 1;
      pcVar5 = pcVar5 + 1;
      param_1 = param_1 + 1;
    } while (iVar4 < (int)(param_2 & 0xffff));
  }
  if (iVar3 == 0) {
    FUN_00067160(0,auStack_38);
  }
  return iVar3;
}


/* ROM address: 0x00066d90; body bytes: 140; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065680 (140 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066d90(char *param_1,short param_2,char param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  cVar1 = FUN_00066678(8,(int)*param_1);
  if (cVar1 == '\0') {
    pcVar3 = "\x01";
    pcVar4 = pcVar3;
    for (iVar2 = 0; (&DAT_0005f014)[iVar2 * 8] != -1; iVar2 = iVar2 + 1) {
      if (*pcVar3 == *param_1) {
        DAT_ffffd934 = *param_1;
        (**(code **)(pcVar4 + 4))(param_1 + 1,param_2 + 0xffff,(int)param_3);
        return 0;
      }
      pcVar4 = pcVar4 + 8;
      pcVar3 = pcVar3 + 8;
    }
  }
  return 1;
}


/* ROM address: 0x00066e30; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065720 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066e30(char param_1,char *param_2,short param_3)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    uVar1 = FUN_00066e5a(param_2,(int)param_3);
  }
  else {
    uVar1 = FUN_00066f06((int)*param_2);
  }
  return uVar1;
}


/* ROM address: 0x00066e5a; body bytes: 172; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006574a (172 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 FUN_00066e5a(char *param_1,uint param_2)

{
  char cVar2;
  undefined4 uVar1;
  int iVar3;
  char *pcVar4;
  undefined1 uStack_28;
  undefined1 local_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  iVar3 = 0;
  uStack_28 = 1;
  pcVar4 = param_1;
  if ((param_2 & 0xffff) != 0) {
    do {
      cVar2 = FUN_00066678(6,(int)*param_1);
      if (cVar2 == '\0') {
        DAT_ffffd93c = *pcVar4;
        uVar1 = FUN_000666aa(6,(int)*pcVar4);
        local_24 = (undefined1)((uint)uVar1 >> 0x18);
        DAT_ffffd93d = local_24;
        uStack_23 = (undefined1)((uint)uVar1 >> 0x10);
        DAT_ffffd93e = uStack_23;
        uStack_22 = (undefined1)((uint)uVar1 >> 8);
        DAT_ffffd93f = uStack_22;
        uStack_21 = (undefined1)uVar1;
        DAT_ffffd940 = uStack_21;
        FUN_000672ec(&DAT_ffffd93c,5);
        uStack_28 = 0;
      }
      iVar3 = iVar3 + 1;
      pcVar4 = pcVar4 + 1;
      param_1 = param_1 + 1;
    } while (iVar3 < (int)(param_2 & 0xffff));
  }
  return uStack_28;
}


/* ROM address: 0x00066f06; body bytes: 112; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000657f6 (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066f06(uint param_1)

{
  char cVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  cVar1 = FUN_00066678(6,param_1);
  if (cVar1 == '\0') {
    pbVar3 = &DAT_0005efc4;
    pbVar4 = pbVar3;
    for (iVar2 = 0; (&DAT_0005efc4)[iVar2 * 8] != -1; iVar2 = iVar2 + 1) {
      if ((uint)*pbVar3 == (param_1 & 0xff)) {
        FUN_00066f8c(param_1,*(undefined4 *)(pbVar4 + 4),0xff,&DAT_0005efc4,&DAT_0005efc4);
        return 0;
      }
      pbVar4 = pbVar4 + 8;
      pbVar3 = pbVar3 + 8;
    }
  }
  return 1;
}


/* ROM address: 0x00066f8c; body bytes: 264; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006587c (264 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066f8c(undefined1 param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  char cVar3;
  undefined2 uVar2;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 local_24;
  undefined1 uStack_23;
  
  uVar1 = 0x1c;
  puVar5 = param_2;
  puVar6 = param_2;
  for (iVar4 = 0; param_2[iVar4 * 0x14] != -1; iVar4 = iVar4 + 1) {
    DAT_ffffd93d = *puVar5;
    DAT_ffffd93e = puVar5[1];
    DAT_ffffd93c = param_1;
    cVar3 = (**(code **)(puVar5 + 4))();
    if (cVar3 == '\0') {
      uVar2 = (**(code **)(puVar6 + 8))();
      local_24 = (undefined1)((ushort)uVar2 >> 8);
      DAT_ffffd93f = local_24;
      uStack_23 = (undefined1)uVar2;
      DAT_ffffd940 = uStack_23;
      uVar2 = (**(code **)(puVar6 + 0xc))();
      local_24 = (undefined1)((ushort)uVar2 >> 8);
      DAT_ffffd941 = local_24;
      uStack_23 = (undefined1)uVar2;
      DAT_ffffd942 = uStack_23;
      uVar2 = (**(code **)(puVar6 + 0x10))();
      local_24 = (undefined1)((ushort)uVar2 >> 8);
      DAT_ffffd943 = local_24;
      uStack_23 = (undefined1)uVar2;
      DAT_ffffd944 = uStack_23;
    }
    else {
      DAT_ffffd93f = 0;
      DAT_ffffd940 = 0;
      DAT_ffffd941 = 0;
      DAT_ffffd942 = 0;
      DAT_ffffd943 = 0;
      DAT_ffffd944 = 0;
    }
    uVar1 = FUN_000672ec(&DAT_ffffd93c,9);
    puVar6 = puVar6 + 0x14;
    puVar5 = puVar5 + 0x14;
  }
  return uVar1;
}


/* ROM address: 0x000670a0; body bytes: 156; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065990 (156 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000670a0(undefined4 param_1,char param_2)

{
  uint uVar1;
  undefined4 unaff_r11;
  int iVar2;
  undefined1 local_1c [4];
  char cStack_18;
  
  iVar2 = 0;
  local_1c[0] = 0x48;
  cStack_18 = param_2;
  uVar1 = FUN_000671c2(param_1);
  if ((uVar1 & 0xff) == 0) {
    ref_udsServiceResponse(8,&DAT_ffffd94a,param_1);
    unaff_r11 = FUN_00066718((int)DAT_ffffd94a);
    uVar1 = FUN_000671d8(unaff_r11,&DAT_ffffd94a,param_1);
    if ((uVar1 & 0xff) != 0) {
      iVar2 = 1;
    }
  }
  else {
    iVar2 = 1;
  }
  if (iVar2 == 0) {
    ref_setupForUdsResponse_(8,local_1c,1);
    DAT_ffffd948 = 1;
    uVar1 = FUN_00066c4c(unaff_r11,&DAT_ffffd94a,param_1,(int)cStack_18);
    if ((uVar1 & 0xff) != 0) {
      iVar2 = 2;
    }
  }
  if (iVar2 != 0) {
    uVar1 = FUN_000671f0(iVar2,(int)cStack_18);
  }
  return uVar1;
}


/* ROM address: 0x0006713c; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065a2c (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0006713c(undefined4 param_1,short param_2)

{
  undefined4 uVar1;
  
  uVar1 = ref_setupForUdsResponse_(8,param_1,(int)param_2);
  DAT_ffffd948 = DAT_ffffd948 + param_2;
  return uVar1;
}


/* ROM address: 0x00067160; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065a50 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067160(char param_1,char *param_2,short param_3)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    ref_setupForUdsResponse_(8,param_2,(int)param_3);
    DAT_ffffd948 = DAT_ffffd948 + param_3;
    uVar1 = FUN_00068d56();
  }
  else {
    if (param_1 == '\x02') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    uVar1 = FUN_0006672a(8,(int)*param_2,uVar1);
  }
  return uVar1;
}


/* ROM address: 0x000671c2; body bytes: 22; decompiled */

undefined4 FUN_000671c2(ushort param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == 0) || (6 < param_1)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* ROM address: 0x000671d8; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065ac8 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000671d8(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 == '\0') {
    uVar1 = FUN_000666c8();
  }
  return uVar1;
}


/* ROM address: 0x000671f0; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065ae0 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000671f0(uint param_1,char param_2)

{
  undefined4 uVar1;
  
  param_1 = param_1 & 0xff;
  if (param_1 == 1) {
    if (param_2 == '\x01') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    param_1 = FUN_0006672a(8,0x12,uVar1);
  }
  else if (param_1 == 2) {
    if (param_2 == '\x01') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    param_1 = FUN_0006672a(8,0x12,uVar1);
  }
  return param_1;
}


/* [ADDITIONAL SOURCE REVIEW]
 * obd_mode06_test_results [high]: service table record 0x5eb70 (service 0x06) -> handler; ROM bytes verified; OBD Mode 06
 */
/* ROM address: 0x0006725c; body bytes: 144; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065b4c (144 bytes). Names prefixed ref_
   are inherited hypotheses. */

void obd_mode06_test_results(undefined4 param_1,char param_2)

{
  char cVar1;
  undefined4 unaff_r12;
  int iVar2;
  undefined1 local_1c [4];
  char cStack_18;
  
  iVar2 = 0;
  local_1c[0] = 0x46;
  cStack_18 = param_2;
  cVar1 = FUN_00067310(param_1);
  if (cVar1 == '\0') {
    ref_udsServiceResponse(6,&DAT_ffffd952,param_1);
    unaff_r12 = FUN_00066718((int)DAT_ffffd952);
    cVar1 = FUN_00067326(unaff_r12,&DAT_ffffd952,param_1);
    if (cVar1 != '\0') {
      iVar2 = 1;
    }
  }
  else {
    iVar2 = 1;
  }
  if (iVar2 == 0) {
    ref_setupForUdsResponse_(6,local_1c,1);
    DAT_ffffd950 = 1;
    cVar1 = FUN_00066e30(unaff_r12,&DAT_ffffd952,param_1);
    if (cVar1 != '\0') {
      iVar2 = 2;
    }
  }
  FUN_0006734c(iVar2,(int)cStack_18);
  return;
}


/* ROM address: 0x000672ec; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065bdc (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000672ec(undefined4 param_1,short param_2)

{
  undefined4 uVar1;
  
  uVar1 = ref_setupForUdsResponse_(6,param_1,(int)param_2);
  DAT_ffffd950 = DAT_ffffd950 + param_2;
  return uVar1;
}


/* ROM address: 0x00067310; body bytes: 22; decompiled */

undefined4 FUN_00067310(ushort param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == 0) || (6 < param_1)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* ROM address: 0x00067326; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065c16 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067326(char param_1,undefined4 param_2,ushort param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 == '\0') {
    uVar1 = FUN_000666c8();
  }
  else if (1 < param_3) {
    uVar1 = 1;
  }
  return uVar1;
}


/* ROM address: 0x0006734c; body bytes: 112; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065c3c (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0006734c(uint param_1,char param_2)

{
  undefined4 uVar1;
  
  param_1 = param_1 & 0xff;
  if (param_1 == 0) {
    param_1 = FUN_00068d56();
  }
  else if (param_1 == 1) {
    if (param_2 == '\x01') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    param_1 = FUN_0006672a(6,0x12,uVar1);
  }
  else if (param_1 == 2) {
    if (param_2 == '\x01') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    param_1 = FUN_0006672a(6,0x12,uVar1);
  }
  return param_1;
}


/* ROM address: 0x000673e0; body bytes: 150; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065cd0 (150 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000673e0(void)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  sVar2 = FUN_00002034(&DAT_ffff8f98);
  if ((sVar2 == 0) && (sVar2 = FUN_00002034(&DAT_ffff8f9c), sVar2 == 0)) {
    uVar6 = 0;
    for (uVar3 = 0; cVar4 = '\0', (int)uVar3 < 7; uVar3 = uVar3 + 1) {
      pcVar5 = (char *)(&DAT_ffff8e80 + uVar3 * 10);
      if ((DAT_ffff8798._0_1_ == '\0') || (uVar3 != DAT_ffff8f98)) {
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          cVar4 = cVar4 + cVar1;
        } while (pcVar5 < &DAT_ffff8ea8 + uVar3 * 10);
        if (cVar4 != -0x5b) goto LAB_00067456;
      }
    }
  }
  else {
LAB_00067456:
    uVar6 = 1;
  }
  return uVar6;
}


/* ROM address: 0x00067476; body bytes: 126; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00065d66 (126 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067476(void)

{
  undefined4 *puVar1;
  
  _DAT_ffff8f98 = rx8_pack_u16_with_complement(0);
  _DAT_ffff8f9c = rx8_pack_u16_with_complement(1);
  puVar1 = &DAT_ffff8e80;
  do {
    *(undefined2 *)(puVar1 + 8) = 0xffff;
    *(undefined2 *)((int)puVar1 + 0x22) = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
    *(undefined1 *)((int)puVar1 + 0xd) = 0;
    *(undefined1 *)((int)puVar1 + 0xe) = 0;
    *(undefined1 *)((int)puVar1 + 0xf) = 0;
    *(undefined2 *)(puVar1 + 9) = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    *(undefined1 *)(puVar1 + 7) = 0;
    *(undefined1 *)((int)puVar1 + 0x1d) = 0;
    *(undefined1 *)((int)puVar1 + 0x1e) = 0;
    *(undefined1 *)((int)puVar1 + 0x1f) = 0;
    *(undefined1 *)((int)puVar1 + 0x26) = 0;
    *(undefined1 *)((int)puVar1 + 0x27) = 0xa7;
    puVar1 = puVar1 + 10;
  } while (puVar1 < &DAT_ffff8f98);
  return 0x27;
}


/* ROM address: 0x00067518; body bytes: 152; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00065e08 (152 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067518(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (((&DAT_ffff8ea0)[uVar1 * 0x14] == param_1) && (uVar1 != DAT_ffff8f98)) {
      _DAT_ffff8f9c = rx8_pack_u16_with_complement(uVar1);
      return 0;
    }
    if (((&DAT_ffff8ea0)[uVar1 * 0x14] == -1) && (uVar1 != DAT_ffff8f98)) break;
    uVar1 = uVar1 + 1;
    if (6 < (int)uVar1) {
      return 3;
    }
  }
  _DAT_ffff8f9c = rx8_pack_u16_with_complement(uVar1);
  return 1;
}


/* ROM address: 0x000675b0; body bytes: 18; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00065ea0 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000675b0(void)

{
  _DAT_ffff8f98 = rx8_pack_u16_with_complement((int)DAT_ffff8f9c);
  return;
}


/* ROM address: 0x000675c2; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065eb2 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000675c2(undefined4 param_1)

{
  FUN_0000420c(param_1,&DAT_ffff8e80);
  FUN_00067626();
  return;
}


/* ROM address: 0x000675f4; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065ee4 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000675f4(void)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  
  cVar3 = -0x5b;
  iVar4 = (uint)DAT_ffff8f98 * 0x28;
  pcVar2 = (char *)(&DAT_ffff8e80 + (uint)DAT_ffff8f98 * 10);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    cVar3 = cVar3 - cVar1;
  } while (pcVar2 < &DAT_ffff8ea7 + iVar4);
  (&DAT_ffff8ea7)[iVar4] = cVar3;
  return;
}


/* ROM address: 0x00067626; body bytes: 22; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065f16 (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067626(undefined2 param_1)

{
  (&DAT_ffff8ea0)[(uint)DAT_ffff8f98 * 0x14] = param_1;
  return;
}


/* ROM address: 0x0006763c; body bytes: 22; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065f2c (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006763c(undefined2 param_1)

{
  (&DAT_ffff8ea2)[(uint)DAT_ffff8f98 * 0x14] = param_1;
  return;
}


/* ROM address: 0x00067674; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065f64 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00067674(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8ea0)[uVar1 * 0x14] != param_1 || (DAT_ffff8f98 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (6 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(short)(&DAT_ffff8ea2)[uVar1 * 0x14];
}


/* ROM address: 0x000676c8; body bytes: 22; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065fb8 (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000676c8(undefined2 param_1)

{
  (&DAT_ffff8ea4)[(uint)DAT_ffff8f98 * 0x14] = param_1;
  return;
}


/* ROM address: 0x000676de; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065fce (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000676de(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8ea0)[uVar1 * 0x14] != param_1 || (DAT_ffff8f98 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (6 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(short)(&DAT_ffff8ea4)[uVar1 * 0x14];
}


/* ROM address: 0x00067732; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066022 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067732(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8f98;
  (&DAT_ffff8e8d)[uVar1 * 0x28] = 1;
  (&DAT_ffff8e80)[uVar1 * 10] = *param_1;
  (&DAT_ffff8e84)[uVar1 * 10] = param_1[1];
  (&DAT_ffff8e88)[uVar1 * 10] = param_1[2];
  (&DAT_ffff8e8c)[uVar1 * 0x28] = *(undefined1 *)(param_1 + 3);
  return;
}


/* ROM address: 0x00067760; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066050 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067760(void)

{
  (&DAT_ffff8e8d)[(uint)DAT_ffff8f98 * 0x28] = 0;
  return;
}


/* ROM address: 0x00067778; body bytes: 122; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066068 (122 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067778(short param_1,undefined4 *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  while ((((&DAT_ffff8ea0)[uVar1 * 0x14] != param_1 || (DAT_ffff8f98 == uVar1)) ||
         ((&DAT_ffff8e8d)[uVar1 * 0x28] != '\x01'))) {
    uVar1 = uVar1 + 1;
    if (6 < (int)uVar1) {
      return 1;
    }
  }
  *param_2 = (&DAT_ffff8e80)[uVar1 * 10];
  param_2[1] = (&DAT_ffff8e84)[uVar1 * 10];
  param_2[2] = (&DAT_ffff8e88)[uVar1 * 10];
  *(undefined1 *)(param_2 + 3) = (&DAT_ffff8e8c)[uVar1 * 0x28];
  return 0;
}


/* ROM address: 0x000677f2; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000660e2 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000677f2(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8f98;
  (&DAT_ffff8e90)[uVar1 * 10] = *param_1;
  (&DAT_ffff8e94)[uVar1 * 10] = param_1[1];
  (&DAT_ffff8e98)[uVar1 * 10] = param_1[2];
  (&DAT_ffff8e9c)[uVar1 * 0x28] = *(undefined1 *)(param_1 + 3);
  return;
}


/* ROM address: 0x00067826; body bytes: 120; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066116 (120 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067826(short param_1,undefined4 *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8ea0)[uVar1 * 0x14] != param_1 || (DAT_ffff8f98 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (6 < (int)uVar1) {
      return 1;
    }
  }
  *param_2 = (&DAT_ffff8e90)[uVar1 * 10];
  param_2[1] = (&DAT_ffff8e94)[uVar1 * 10];
  param_2[2] = (&DAT_ffff8e98)[uVar1 * 10];
  *(undefined1 *)(param_2 + 3) = (&DAT_ffff8e9c)[uVar1 * 0x28];
  return 0;
}


/* ROM address: 0x0006789e; body bytes: 22; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006618e (22 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006789e(undefined1 param_1)

{
  (&DAT_ffff8ea6)[(uint)DAT_ffff8f98 * 0x28] = param_1;
  return;
}


/* ROM address: 0x000678b4; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000661a4 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_000678b4(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8ea0)[uVar1 * 0x14] != param_1 || (DAT_ffff8f98 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (6 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff8ea6)[uVar1 * 0x28];
}


/* ROM address: 0x0006791c; body bytes: 100; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006620c (100 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006791c(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)DAT_ffff8f98;
  iVar2 = uVar1 * 0x28;
  (&DAT_ffff8ea0)[uVar1 * 0x14] = 0xffff;
  (&DAT_ffff8ea2)[uVar1 * 0x14] = 0;
  (&DAT_ffff8e80)[uVar1 * 10] = 0;
  (&DAT_ffff8e84)[uVar1 * 10] = 0;
  (&DAT_ffff8e88)[uVar1 * 10] = 0;
  (&DAT_ffff8e8c)[iVar2] = 0;
  (&DAT_ffff8e8d)[iVar2] = 0;
  (&DAT_ffff8e8e)[iVar2] = 0;
  (&DAT_ffff8e8f)[iVar2] = 0;
  (&DAT_ffff8ea4)[uVar1 * 0x14] = 0;
  (&DAT_ffff8e90)[uVar1 * 10] = 0;
  (&DAT_ffff8e94)[uVar1 * 10] = 0;
  (&DAT_ffff8e98)[uVar1 * 10] = 0;
  (&DAT_ffff8e9c)[iVar2] = 0;
  (&DAT_ffff8e9d)[iVar2] = 0;
  (&DAT_ffff8e9e)[iVar2] = 0;
  (&DAT_ffff8e9f)[iVar2] = 0;
  (&DAT_ffff8ea6)[iVar2] = 0;
  (&DAT_ffff8ea7)[iVar2] = 0xa7;
  FUN_00067626();
  return;
}


/* ROM address: 0x00067990; body bytes: 148; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066280 (148 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067990(void)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  sVar2 = FUN_00002034(&DAT_ffff8fb4);
  if ((sVar2 == 0) && (sVar2 = FUN_00002034(&DAT_ffff8fb8), sVar2 == 0)) {
    uVar6 = 0;
    for (uVar3 = 0; cVar4 = '\0', (int)uVar3 < 2; uVar3 = uVar3 + 1) {
      pcVar5 = (char *)(&DAT_ffff8fa0 + uVar3 * 5);
      if ((DAT_ffff8798._0_1_ == '\0') || (uVar3 != DAT_ffff8fb4)) {
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          cVar4 = cVar4 + cVar1;
        } while (pcVar5 < (char *)(uVar3 * 10 + -0x7057));
        if (cVar4 != -0x5b) goto LAB_00067a04;
      }
    }
  }
  else {
LAB_00067a04:
    uVar6 = 1;
  }
  return uVar6;
}


/* ROM address: 0x00067a24; body bytes: 68; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00066314 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067a24(void)

{
  undefined2 *puVar1;
  
  _DAT_ffff8fb4 = rx8_pack_u16_with_complement(0);
  _DAT_ffff8fb8 = rx8_pack_u16_with_complement(1);
  puVar1 = &DAT_ffff8fa0;
  do {
    *puVar1 = 0xffff;
    puVar1[2] = 0;
    puVar1[1] = 0;
    puVar1[3] = 0;
    *(undefined1 *)(puVar1 + 4) = 0xa7;
    puVar1 = puVar1 + 5;
  } while (puVar1 < &DAT_ffff8fb4);
  return 0xa7;
}


/* ROM address: 0x00067a88; body bytes: 142; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00066378 (142 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067a88(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (((&DAT_ffff8fa0)[uVar1 * 5] == param_1) && (uVar1 != DAT_ffff8fb4)) {
      _DAT_ffff8fb8 = rx8_pack_u16_with_complement(uVar1);
      return 0;
    }
    if (((&DAT_ffff8fa0)[uVar1 * 5] == -1) && (uVar1 != DAT_ffff8fb4)) break;
    uVar1 = uVar1 + 1;
    if (1 < (int)uVar1) {
      return 3;
    }
  }
  _DAT_ffff8fb8 = rx8_pack_u16_with_complement(uVar1);
  return 1;
}


/* ROM address: 0x00067b16; body bytes: 18; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 00066406 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067b16(void)

{
  _DAT_ffff8fb4 = rx8_pack_u16_with_complement((int)DAT_ffff8fb8);
  return;
}


/* ROM address: 0x00067b28; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066418 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067b28(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_copy_bytes_forward_r0_r1_r2(&DAT_ffff8fa0);
  return uVar1;
}


/* ROM address: 0x00067b58; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066448 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067b58(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  
  cVar4 = -0x5b;
  iVar2 = (uint)DAT_ffff8fb4 * 10;
  pcVar3 = (char *)(&DAT_ffff8fa0 + (uint)DAT_ffff8fb4 * 5);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    cVar4 = cVar4 - cVar1;
  } while (pcVar3 < &DAT_ffff8fa8 + iVar2);
  (&DAT_ffff8fa8)[iVar2] = cVar4;
  return;
}


/* ROM address: 0x00067b88; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066478 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067b88(undefined2 param_1)

{
  (&DAT_ffff8fa2)[(uint)DAT_ffff8fb4 * 5] = param_1;
  return;
}


/* ROM address: 0x00067bbc; body bytes: 74; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000664ac (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00067bbc(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8fa0)[uVar1 * 5] != param_1 || (DAT_ffff8fb4 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (1 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(short)(&DAT_ffff8fa2)[uVar1 * 5];
}


/* ROM address: 0x00067c06; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000664f6 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067c06(undefined2 param_1)

{
  (&DAT_ffff8fa4)[(uint)DAT_ffff8fb4 * 5] = param_1;
  return;
}


/* ROM address: 0x00067c1a; body bytes: 74; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006650a (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00067c1a(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8fa0)[uVar1 * 5] != param_1 || (DAT_ffff8fb4 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (1 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(short)(&DAT_ffff8fa4)[uVar1 * 5];
}


/* ROM address: 0x00067c64; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066554 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067c64(undefined2 param_1)

{
  (&DAT_ffff8fa6)[(uint)DAT_ffff8fb4 * 5] = param_1;
  return;
}


/* ROM address: 0x00067c78; body bytes: 74; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066568 (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00067c78(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8fa0)[uVar1 * 5] != param_1 || (DAT_ffff8fb4 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (1 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(short)(&DAT_ffff8fa6)[uVar1 * 5];
}


/* ROM address: 0x00067cc2; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000665b2 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067cc2(undefined2 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffff8fb4;
  (&DAT_ffff8fa0)[uVar1 * 5] = param_1;
  (&DAT_ffff8fa4)[uVar1 * 5] = 0;
  (&DAT_ffff8fa2)[uVar1 * 5] = 0;
  (&DAT_ffff8fa6)[uVar1 * 5] = 0;
  (&DAT_ffff8fa8)[uVar1 * 10] = 0xa7;
  return;
}


/* ROM address: 0x00067d38; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066628 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067d38(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00067d44(0);
  return uVar1;
}


/* ROM address: 0x00067d44; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066634 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067d44(byte param_1)

{
  int iVar1;
  
  iVar1 = (uint)param_1 * 0x46c;
  *(undefined2 *)(&DAT_ffffd95c + iVar1) = 0;
  *(undefined2 *)(&DAT_ffffd95e + iVar1) = 0;
  *(undefined2 *)(&DAT_ffffd960 + iVar1) = 0;
  return;
}


/* ROM address: 0x00067d60; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066650 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067d60(byte param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = (uint)param_1 * 0x46c;
  if (*(ushort *)(&DAT_ffffd960 + iVar2) < 0x464) {
    sVar1 = *(short *)(&DAT_ffffd960 + iVar2) + 1;
  }
  else {
    sVar1 = 0;
  }
  *(short *)(&DAT_ffffd95c + iVar2) = sVar1;
  return;
}


/* ROM address: 0x00067d8c; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006667c (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067d8c(byte param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = (uint)param_1 * 0x46c;
  if (*(ushort *)(&DAT_ffffd960 + iVar2) < 0x464) {
    sVar1 = *(short *)(&DAT_ffffd960 + iVar2) + 1;
  }
  else {
    sVar1 = 0;
  }
  *(short *)(&DAT_ffffd95c + iVar2) = sVar1;
  return;
}


/* ROM address: 0x00067db8; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000666a8 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067db8(byte param_1)

{
  short sVar1;
  
  if (*(short *)(&DAT_ffffd95c + (uint)param_1 * 0x46c) == 0) {
    sVar1 = 0x464;
  }
  else {
    sVar1 = *(short *)(&DAT_ffffd95c + (uint)param_1 * 0x46c) + -1;
  }
  *(short *)(&DAT_ffffd960 + (uint)param_1 * 0x46c) = sVar1;
  return;
}


/* ROM address: 0x00067de4; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000666d4 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067de4(byte param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = (uint)param_1 * 0x46c;
  if (*(ushort *)(&DAT_ffffd960 + iVar2) < 0x464) {
    sVar1 = *(short *)(&DAT_ffffd960 + iVar2) + 1;
  }
  else {
    sVar1 = 0;
  }
  *(short *)(&DAT_ffffd95e + iVar2) = sVar1;
  return;
}


/* ROM address: 0x00067e1c; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006670c (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_pack_for_OBD_response_(uint param_1,undefined1 *param_2,ushort param_3)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = (param_1 & 0xff) * 0x46c;
  puVar2 = (ushort *)(&DAT_ffffd95c + iVar3);
  if (param_3 != 0) {
    do {
      if (*(ushort *)(&DAT_ffffd960 + iVar3) != *puVar2) {
        *(undefined1 *)((uint)*puVar2 + iVar3 + -0x269e) = *param_2;
        *puVar2 = *puVar2 + 1;
        if (0x464 < *puVar2) {
          *puVar2 = 0;
        }
      }
      iVar1 = iVar1 + 1;
      param_2 = param_2 + 1;
    } while (iVar1 < (int)(uint)param_3);
  }
  return;
}


/* ROM address: 0x00067e78; body bytes: 140; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066768 (140 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067e78(uint param_1,undefined1 *param_2,uint param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = (param_1 & 0xff) * 0x46c;
  puVar2 = param_2;
  if ((param_3 & 0xffff) != 0) {
    do {
      if ((*(ushort *)(&DAT_ffffd960 + iVar3) + 1 == (uint)*(ushort *)(&DAT_ffffd95e + iVar3)) ||
         ((0x463 < *(ushort *)(&DAT_ffffd960 + iVar3) && (*(ushort *)(&DAT_ffffd95e + iVar3) == 0)))
         ) {
        *param_2 = 0;
      }
      else {
        *puVar2 = *(undefined1 *)(iVar3 + -0x269e + (uint)*(ushort *)(&DAT_ffffd95e + iVar3));
        *(short *)(&DAT_ffffd95e + iVar3) = *(short *)(&DAT_ffffd95e + iVar3) + 1;
        if (0x464 < *(ushort *)(&DAT_ffffd95e + iVar3)) {
          *(undefined2 *)(&DAT_ffffd95e + iVar3) = 0;
        }
      }
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    } while (iVar1 < (int)(param_3 & 0xffff));
  }
  return;
}


/* ROM address: 0x00067f10; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066800 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067f10(void)

{
  DAT_ffffddf6 = 0;
  DAT_ffffddf7 = 0;
  DAT_ffffddf9 = 0xff;
  FUN_00068398();
  FUN_000683b4();
  DAT_ffffddf3 = 0xff;
  DAT_ffffddf4 = 0;
  DAT_ffffddda = 0xff;
  FUN_00068c58(2);
  FUN_00068c58(3);
  FUN_00068c58(4);
  FUN_00068c58(5);
  FUN_00068c58(1);
  FUN_00068c58(0);
  FUN_00068c58(6);
  DAT_ffffddf5 = 0;
  return;
}


/* ROM address: 0x00067f64; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066854 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00067f64(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffddf7;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffddf5, (DAT_ffffddf5 & 0x10) == 0)) {
    DAT_ffffddf7 = 0;
    DAT_ffffddda = 0xff;
    uVar1 = FUN_00067faa();
  }
  return uVar1;
}


/* ROM address: 0x00067faa; body bytes: 208; decompiled */

uint FUN_00067faa(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined2 uVar5;
  uint uVar6;
  
  uVar6 = *param_1;
  uVar4 = param_1[1];
  uVar2 = param_1[3];
  uVar1 = FUN_00068ae8(uVar6);
  if ((char)uVar1 != -1) {
    uVar5 = (undefined2)uVar4;
    if ((DAT_ffffddf5 & 0x10) == 0) {
      if ((char)uVar2 == '\0') {
        DAT_ffffddf5 = DAT_ffffddf5 & 0xbf | 0x10;
        FUN_00068398();
        FUN_00068b46(uVar1);
        uVar4 = uVar4 & 0xffff;
        DAT_ffffdddc = uVar5;
        if (0xfff < uVar4) {
          DAT_ffffdddc = 0xfff;
        }
        DAT_ffffddf6 = 0;
        if (uVar4 < 8) {
          uVar3 = 0;
        }
        else {
          uVar3 = 0x10;
        }
        DAT_ffffdde0 = (char)uVar6;
        DAT_ffffdde2 = (char)uVar1;
        FUN_00068776(uVar3);
        jump_to_FUN_00054a00((int)DAT_ffffdde0);
      }
      else {
        FUN_00068b98(uVar1);
        DAT_ffffddf5 = DAT_ffffddf5 & 0xbf;
      }
      FUN_00068c58(1);
      uVar1 = FUN_00068c58(0);
      return uVar1;
    }
    uVar1 = (uint)DAT_ffffddf6;
    if (DAT_ffffddf6 == 1) {
      DAT_ffffddf7 = 1;
      uVar1 = uVar6;
      DAT_ffffddd8 = uVar5;
      DAT_ffffddda = (char)uVar6;
    }
  }
  return uVar1;
}


/* [ADDITIONAL SOURCE REVIEW]
 * uds_service_entry [high]: Emulator dynamic: harness.call(0x680a0, r4=0x7e0) after buffer fill -> PCI byte check via 0x683d4, service dispatch 0x6842c, then 0x684b4(0x7e0) schedules the UDS service task via ref_osTaskScheduler(2,0,&local).
 */
/* ROM address: 0x000680a0; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066990 (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

void uds_service_entry(int param_1)

{
  char cVar1;
  
  if ((((param_1 == 0x7e0) || (param_1 == 0x7df)) && (cVar1 = isotp_pci_type_extract(), cVar1 != '@')) &&
     (cVar1 = isotp_frame_type_dispatch(), cVar1 == '\0')) {
    uds_request_schedule_service_task(param_1);
    return;
  }
  return;
}


/* ROM address: 0x000680de; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000669ce (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000680de(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffdde1;
  if (uVar1 == 6) {
    uVar1 = FUN_0006896c();
    return uVar1;
  }
  if (uVar1 == 10) {
    uVar1 = FUN_00068996();
    return uVar1;
  }
  if (uVar1 == 0) {
    uVar1 = (uint)DAT_ffffddeb;
    if (uVar1 == 0) {
      uVar1 = FUN_0006892a();
      return uVar1;
    }
    if (uVar1 == 3) {
      uVar1 = FUN_00068a44();
      return uVar1;
    }
  }
  return uVar1;
}


/* ROM address: 0x00068124; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066a14 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * ref_setupForUdsResponse_(char param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if ((&DAT_ffffddf3)[iVar2 * 2] == param_1) {
      puVar1 = (undefined1 *)ref_pack_for_OBD_response_(iVar2);
      return puVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  return &DAT_ffffddf3;
}


/* ROM address: 0x00068184; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066a74 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * ref_udsServiceResponse(char param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if ((&DAT_ffffddf3)[iVar2 * 2] == param_1) {
      puVar1 = (undefined1 *)FUN_00067e78(iVar2);
      return puVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  return &DAT_ffffddf3;
}


/* ROM address: 0x000681ba; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066aaa (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_unknownMode22Func(char param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_ffffddf3)[iVar1 * 2] == param_1) {
      FUN_00067d60(iVar1);
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 1);
  return;
}


/* ROM address: 0x00068246; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066b36 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068246(void)

{
  FUN_00067d38();
  FUN_00067f10();
  return;
}


/* ROM address: 0x00068398; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066c88 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068398(void)

{
  DAT_ffffdddc = 0;
  DAT_ffffddde = 0;
  DAT_ffffdde0 = 0xff;
  DAT_ffffdde1 = 0;
  DAT_ffffdde2 = 0;
  DAT_ffffdde3 = 0;
  DAT_ffffdde4 = 0;
  DAT_ffffdde5 = 0;
  return;
}


/* ROM address: 0x000683b4; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066ca4 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000683b4(void)

{
  DAT_ffffddf8 = 0;
  DAT_ffffdde6 = 0;
  DAT_ffffdde8 = 0;
  DAT_ffffddea = 0xff;
  DAT_ffffddeb = 0;
  DAT_ffffddec = 0;
  DAT_ffffdded = 0;
  DAT_ffffddee = 0;
  DAT_ffffddef = 0;
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * isotp_pci_type_extract [high]: reads RX buffer byte0, and 0xf0 -> frame type 0x00/0x10/0x20/0x30, clamp 0x40
 */
/* ROM address: 0x000683d4; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066cc4 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint isotp_pci_type_extract(void)

{
  uint uVar1;
  
  uVar1 = (int)uds_rx_buffer_ffffddc8 & 0xf0;
  if (0x3f < uVar1) {
    uVar1 = 0x40;
  }
  return uVar1;
}


/* [ADDITIONAL SOURCE REVIEW]
 * isotp_frame_type_dispatch [high]: switch on frame type: SF->0x68548, FF->0x6859e, CF->0x6872c, FC->0x68764
 */
/* ROM address: 0x0006842c; body bytes: 136; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066d1c (136 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 isotp_frame_type_dispatch(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_1 == '\0') {
    cVar1 = FUN_000686f8();
    if (cVar1 == '\0') {
      uVar2 = isotp_single_frame_accept();
    }
  }
  else if (param_1 == '\x10') {
    cVar1 = FUN_00068712();
    if (cVar1 == '\0') {
      isotp_first_frame_accept();
    }
  }
  else if (param_1 == ' ') {
    cVar1 = isotp_consecutive_frame_check();
    if ((cVar1 == '\0') && (FUN_00068620(), DAT_ffffdde6 <= DAT_ffffdde8)) {
      FUN_00068c58(5);
      uVar2 = 0;
    }
  }
  else if (param_1 == '0') {
    cVar1 = isotp_flow_control_check();
    if (cVar1 == '\0') {
      FUN_00068688();
    }
  }
  return uVar2;
}


/* [ADDITIONAL SOURCE REVIEW]
 * uds_request_schedule_service_task [high]: Calls 0x68b22(DAT_ffffddec), 0x68bc6(1,0x28), thunk 0x54b2c, ref_osTaskScheduler(2,0,&local_14). Executed in emulator while serving 10 03.
 */
/* ROM address: 0x000684b4; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066da4 (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

void uds_request_schedule_service_task(int param_1)

{
  uint local_14;
  uint uStack_10;
  uint local_c;
  
  FUN_00068b22((int)DAT_ffffddec);
  FUN_00068bc6(1,0x28);
  local_14 = (uint)DAT_ffffddea;
  uStack_10 = (uint)DAT_ffffdde6;
  local_c = (uint)(param_1 != 0x7df);
  DAT_ffffddf9 = DAT_ffffddea;
  DAT_ffffddeb = 0;
  DAT_ffffddf5 = DAT_ffffddf5 & 0xfb | 0x40;
  jump_to_FUN_00054b2c((int)(char)DAT_ffffddea);
  os_schedule_task_event(2,0,&local_14);
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * isotp_single_frame_accept [high]: SF: service=buf[1], channel=0x68a86(service), pack_for_OBD_response
 */
/* ROM address: 0x00068548; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066e38 (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 isotp_single_frame_accept(void)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = (ushort)uds_rx_buffer_ffffddc8;
  uVar2 = 1;
  if (((uVar1 & 0xf) < 8) && ((uds_rx_buffer_ffffddc8 & 0xf) != 0)) {
    DAT_ffffddf5 = DAT_ffffddf5 | 4;
    FUN_000683b4();
    DAT_ffffddec = uds_rx_channel_alloc((int)DAT_ffffddc9);
    DAT_ffffddea = DAT_ffffddc9;
    DAT_ffffdde6 = uVar1 & 0xf;
    ref_pack_for_OBD_response_((int)DAT_ffffddec,&DAT_ffffddc9,7);
    uVar2 = 0;
  }
  return uVar2;
}


/* [ADDITIONAL SOURCE REVIEW]
 * isotp_first_frame_accept [high]: FF: total len=(pci&0xf)*256+buf[2], service=buf[3], starts reassembly
 */
/* ROM address: 0x0006859e; body bytes: 130; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066e8e (130 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint isotp_first_frame_accept(void)

{
  uint uVar1;
  
  uVar1 = (uds_rx_buffer_ffffddc8 & 0xf) * 0x100 + (uint)DAT_ffffddc9;
  if ((uVar1 < 0x1000) && (7 < uVar1)) {
    DAT_ffffddf5 = DAT_ffffddf5 | 4;
    FUN_000683b4();
    DAT_ffffddec = uds_rx_channel_alloc((int)DAT_ffffddca);
    DAT_ffffddeb = 2;
    DAT_ffffdde6 = (undefined2)uVar1;
    DAT_ffffddea = DAT_ffffddca;
    DAT_ffffdde8 = 6;
    DAT_ffffdded = 1;
    ref_pack_for_OBD_response_((int)DAT_ffffddec,&DAT_ffffddca,6);
    FUN_00068bc6(6,5);
    uVar1 = jump_to_FUN_00054b62((int)DAT_ffffddea);
    return uVar1;
  }
  return (uint)DAT_ffffddc9;
}


/* ROM address: 0x00068620; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066f10 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068620(void)

{
  FUN_00068c58(5);
  DAT_ffffdde8 = DAT_ffffdde8 + 7;
  DAT_ffffddee = rx8_add_u8_saturate((int)DAT_ffffddee,1);
  DAT_ffffddeb = 4;
  FUN_00068bc6(5,0x96);
  ref_pack_for_OBD_response_((int)DAT_ffffddec,&DAT_ffffddc9,7);
  return;
}


/* ROM address: 0x00068688; body bytes: 112; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066f78 (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00068688(void)

{
  uint uVar1;
  
  uVar1 = (int)uds_rx_buffer_ffffddc8 & 0xf;
  DAT_ffffddf0 = (undefined1)uVar1;
  if (uVar1 == 0) {
    FUN_00068c58(4);
    DAT_ffffdde4 = 0;
    DAT_ffffddf1 = DAT_ffffddc9;
    DAT_ffffddf2 = DAT_ffffddca;
    DAT_ffffdde1 = 9;
    uVar1 = FUN_00068bc6(2,DAT_ffffddca);
    return uVar1;
  }
  if (uVar1 == 1) {
    FUN_00068c58(4);
    DAT_ffffdde1 = 7;
    uVar1 = FUN_00068bc6(4,0x4b);
    return uVar1;
  }
  return uVar1;
}


/* ROM address: 0x000686f8; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066fe8 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000686f8(void)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((DAT_ffffddf5 == 0) || ((DAT_ffffddf5 & 4) != 0)) {
    uVar1 = 0;
  }
  return uVar1;
}


/* ROM address: 0x00068712; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067002 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00068712(void)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((DAT_ffffddf5 == 0) || ((DAT_ffffddf5 & 4) != 0)) {
    uVar1 = 0;
  }
  return uVar1;
}


/* [ADDITIONAL SOURCE REVIEW]
 * isotp_consecutive_frame_check [high]: CF: checks DAT_ffffddeb==4 and seq == expected
 */
/* ROM address: 0x0006872c; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006701c (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 isotp_consecutive_frame_check(void)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((DAT_ffffddeb == '\x04') && (DAT_ffffdded == (uds_rx_buffer_ffffddc8 & 0xf))) {
    if ((uds_rx_buffer_ffffddc8 & 0xf) < 0xf) {
      DAT_ffffdded = DAT_ffffdded + 1;
    }
    else {
      DAT_ffffdded = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


/* [ADDITIONAL SOURCE REVIEW]
 * isotp_flow_control_check [high]: FC: DAT_ffffdde1 != 7
 */
/* ROM address: 0x00068764; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067054 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool isotp_flow_control_check(void)

{
  return DAT_ffffdde1 != '\a';
}


/* ROM address: 0x00068776; body bytes: 78; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067066 (78 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068776(char param_1)

{
  if (param_1 == '\0') {
    uds_tx_buffer_ffffddd0 = 0;
    FUN_000687c4();
  }
  else if (param_1 == '\x10') {
    uds_tx_buffer_ffffddd0 = 0x10;
    FUN_000687e8();
  }
  else if (param_1 == ' ') {
    uds_tx_buffer_ffffddd0 = 0x20;
    FUN_00068826();
  }
  else if (param_1 == '0') {
    uds_tx_buffer_ffffddd0 = 0x30;
    FUN_00068868();
  }
  ref_txCAN_EventBased(&DAT_0004e00c);
  return;
}


/* ROM address: 0x000687c4; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000670b4 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000687c4(void)

{
  uds_tx_buffer_ffffddd0 = uds_tx_buffer_ffffddd0 | (byte)DAT_ffffdddc;
  FUN_00067e78((int)DAT_ffffdde2,&DAT_ffffddd1,7);
  FUN_00068bc6(3,0x30);
  return;
}


/* ROM address: 0x000687e8; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000670d8 (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000687e8(void)

{
  uds_tx_buffer_ffffddd0 = uds_tx_buffer_ffffddd0 | (byte)((ushort)DAT_ffffdddc >> 8);
  DAT_ffffddd1 = (undefined1)DAT_ffffdddc;
  FUN_00067e78((int)DAT_ffffdde2,&DAT_ffffddd2,6);
  DAT_ffffdde3 = 1;
  DAT_ffffdde1 = 6;
  FUN_00068bc6(4,0x30);
  return;
}


/* ROM address: 0x00068826; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067116 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068826(void)

{
  uds_tx_buffer_ffffddd0 = uds_tx_buffer_ffffddd0 | DAT_ffffdde3;
  FUN_00067e78((int)DAT_ffffdde2,&DAT_ffffddd1,7);
  if (DAT_ffffdde3 < 0xf) {
    DAT_ffffdde3 = DAT_ffffdde3 + 1;
  }
  else {
    DAT_ffffdde3 = '\0';
  }
  DAT_ffffdde1 = 10;
  FUN_00068bc6(4,0x30);
  return;
}


/* ROM address: 0x00068868; body bytes: 168; decompiled */

void FUN_00068868(void)

{
  undefined4 uVar1;
  byte bVar2;
  
  bVar2 = FUN_000688c4();
  if (bVar2 == 1) {
    DAT_ffffddf8 = 1;
    uVar1 = sh_raise_interrupt_mask_return_previous(0x90);
    if ((DAT_ffffddf5 & 4) != 0) {
      DAT_ffffddf8 = 0;
      (&DAT_ffffddf4)[(uint)DAT_ffffddec * 2] = 0;
      DAT_ffffddeb = 0;
      DAT_ffffddf5 = DAT_ffffddf5 & 0xfb;
      jump_to_FUN_00054b98((int)DAT_ffffddea);
    }
    ref_setSR(uVar1);
    return;
  }
  DAT_ffffddf8 = 0;
  uds_tx_buffer_ffffddd0 = uds_tx_buffer_ffffddd0 | bVar2;
  DAT_ffffddd1 = 0;
  DAT_ffffddd2 = 0;
  DAT_ffffddd3 = 0;
  DAT_ffffddd4 = 0;
  DAT_ffffddd5 = 0;
  DAT_ffffddd6 = 0;
  DAT_ffffddd7 = 0;
  DAT_ffffddeb = 3;
  FUN_00068bc6(5,0x12);
  return;
}


/* ROM address: 0x000688c4; body bytes: 4; decompiled */

undefined4 FUN_000688c4(void)

{
  return 0;
}


/* ROM address: 0x00068910; body bytes: 26; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067200 (26 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068910(void)

{
  FUN_00068b98((int)DAT_ffffdde2);
  DAT_ffffdde1 = 0;
  DAT_ffffddf5 = DAT_ffffddf5 & 0xef;
  return;
}


/* ROM address: 0x0006892a; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006721a (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006892a(void)

{
  int iVar1;
  
  FUN_00068c58(3);
  if (DAT_ffffddf6 == '\x01') {
    FUN_00068bc6(1,0xf96);
    DAT_ffffddf5 = DAT_ffffddf5 & 0xef;
    iVar1 = 0x7f;
  }
  else {
    FUN_00068c58(1);
    FUN_00068c58(0);
    FUN_00068910();
    iVar1 = (int)DAT_ffffdde0;
  }
  jump_to_FUN_00054a36(iVar1);
  return;
}


/* ROM address: 0x0006896c; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006725c (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0006896c(void)

{
  FUN_00068c58(4);
  FUN_00068c58(1);
  FUN_00068c58(0);
  DAT_ffffddde = DAT_ffffddde + 6;
  DAT_ffffdde1 = 7;
  FUN_00068bc6(4,0x4b);
  return;
}


/* ROM address: 0x00068996; body bytes: 120; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067286 (120 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068996(void)

{
  FUN_00068c58(4);
  DAT_ffffdde4 = rx8_add_u8_saturate((int)(char)DAT_ffffdde4,1);
  DAT_ffffddde = DAT_ffffddde + 7;
  if (DAT_ffffdddc <= DAT_ffffddde) {
    FUN_00068910();
    jump_to_FUN_00054a36((int)DAT_ffffdde0);
    return;
  }
  if ((DAT_ffffddf1 != 0) && (DAT_ffffddf1 <= DAT_ffffdde4)) {
    DAT_ffffdde4 = 0;
    DAT_ffffdde1 = 7;
    FUN_00068bc6(4,0x4b);
    return;
  }
  DAT_ffffdde1 = 9;
  FUN_00068bc6(2,DAT_ffffddf2);
  return;
}


/* ROM address: 0x00068a44; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067334 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068a44(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_00068c58(5);
  DAT_ffffddef = rx8_add_u8_saturate((int)DAT_ffffddef,1);
  if (DAT_ffffddf8 == '\x01') {
    uVar2 = 5;
    DAT_ffffddeb = 2;
    uVar1 = 6;
  }
  else {
    uVar2 = 0x96;
    uVar1 = 5;
    DAT_ffffddef = 0;
    DAT_ffffddeb = 4;
  }
  FUN_00068bc6(uVar1,uVar2);
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * uds_rx_channel_alloc [high]: finds free/busy channel slot in DAT_ffffddf4, binds service via 0x68b10 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x00068a86; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067376 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

int uds_rx_channel_alloc(char param_1)

{
  bool bVar1;
  int iVar2;
  int unaff_r14;
  
  bVar1 = true;
  iVar2 = 0;
  do {
    if ((&DAT_ffffddf4)[iVar2 * 2] == '\x04') {
      bVar1 = false;
      unaff_r14 = iVar2;
      break;
    }
    if (((&DAT_ffffddf4)[iVar2 * 2] == '\0') && (bVar1)) {
      bVar1 = false;
      unaff_r14 = iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  if (!bVar1) {
    uds_rx_channel_set_service(unaff_r14,(int)param_1);
  }
  return unaff_r14;
}


/* ROM address: 0x00068ae8; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000673d8 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00068ae8(char param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_ffffddf3)[iVar1 * 2] == param_1) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 1);
  return 0xff;
}


/* [ADDITIONAL SOURCE REVIEW]
 * uds_rx_channel_set_service [high]: DAT_ffffddf3[ch*2]=service, state=4, calls 0x67d8c timer | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x00068b10; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067400 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void uds_rx_channel_set_service(byte param_1,undefined1 param_2)

{
  (&DAT_ffffddf3)[(uint)param_1 * 2] = param_2;
  (&DAT_ffffddf4)[(uint)param_1 * 2] = 4;
  FUN_00067d8c();
  return;
}


/* ROM address: 0x00068b22; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067412 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068b22(char param_1)

{
  (&DAT_ffffddf4)[(uint)DAT_ffffddec * 2] = 0x40;
  FUN_00067de4((int)param_1);
  FUN_00067db8((int)param_1);
  return;
}


/* ROM address: 0x00068b46; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067436 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068b46(uint param_1)

{
  (&DAT_ffffddf4)[(param_1 & 0xff) * 2] = 0x10;
  FUN_00067de4(param_1);
  FUN_00067db8(param_1);
  return;
}


/* ROM address: 0x00068b98; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067488 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068b98(uint param_1)

{
  (&DAT_ffffddf4)[(param_1 & 0xff) * 2] = 0;
  return;
}


/* ROM address: 0x00068ba8; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067498 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068ba8(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = &DAT_ffffddfc;
  puVar1 = &DAT_ffffde04;
  do {
    *puVar1 = 0;
    *puVar2 = 0;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (puVar1 < &DAT_ffffde20);
  return;
}


/* ROM address: 0x00068bc6; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000674b6 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068bc6(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = ATUII_TCNT0H_W;
  (&DAT_ffffde04)[param_1 & 0xff] = param_2 * 4000 + iVar1;
  (&DAT_ffffddfc)[param_1 & 0xff] = 1;
  return;
}


/* ROM address: 0x00068be8; body bytes: 112; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000674d8 (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068be8(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  puVar3 = &DAT_ffffddfc;
  iVar6 = 0;
  piVar5 = &DAT_ffffde04;
  iVar4 = 0;
  do {
    uVar2 = sh_raise_interrupt_mask_return_previous(0x90);
    if (((&DAT_ffffddfc)[iVar6] == '\x01') &&
       (iVar1 = ATUII_TCNT0H_W, 0x7fffffff < (uint)(*piVar5 - iVar1))) {
      *puVar3 = 0;
      (**(code **)((int)&PTR_FUN_00068edc + iVar4))();
    }
    ref_setSR(uVar2);
    iVar6 = iVar6 + 1;
    iVar4 = iVar4 + 4;
    puVar3 = puVar3 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar6 < 7);
  return;
}


/* ROM address: 0x00068c58; body bytes: 10; decompiled */

void FUN_00068c58(uint param_1)

{
  (&DAT_ffffddfc)[param_1 & 0xff] = 0;
  return;
}


/* ROM address: 0x00068c98; body bytes: 8; decompiled */

void FUN_00068c98(void)

{
  DAT_ffffde20 = 0;
  return;
}


/* ROM address: 0x00068ca0; body bytes: 182; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067590 (182 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_udsSomething_(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 auStack_18 [8];
  
  uVar5 = *param_1;
  uVar3 = param_1[1];
  uVar2 = param_1[2];
  uVar4 = uVar2 & 0xff;
  if ((uVar3 & 0xffff) == 0) {
    if (uVar4 != 0) {
      if (uVar4 != 1) {
        return uVar4;
      }
      uVar2 = ref_udsResponseRelated2(uVar5,0x12,1);
      return uVar2;
    }
    uVar1 = 0x12;
  }
  else {
    ref_udsServiceResponse(uVar5,auStack_18,1);
    uVar2 = uds_service_dispatch_table_scan(uVar5,uVar3 - 1,uVar2);
    uVar2 = uVar2 & 0xff;
    if (uVar2 == 1) {
      if (uVar4 == 0) {
        uVar2 = ref_udsResponseRelated2(uVar5,0x11,1);
        return uVar2;
      }
      if (uVar4 != 1) {
        return uVar4;
      }
      uVar2 = ref_udsResponseRelated2(uVar5,0x11,2);
      return uVar2;
    }
    if (uVar2 != 2) {
      return uVar2;
    }
    if (uVar4 != 0) {
      if (uVar4 != 1) {
        return uVar4;
      }
      uVar2 = ref_udsResponseRelated2(uVar5,0x22,2);
      return uVar2;
    }
    uVar1 = 0x22;
  }
  uVar2 = ref_udsResponseRelated2(uVar5,uVar1,1);
  return uVar2;
}


/* ROM address: 0x00068d56; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067646 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00068d56(undefined4 param_1)

{
  os_schedule_task_event(2,1,param_1);
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00054a00 [high]: 6-byte body: word 0xd30b = `mov.l @(0x68d94,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x68d94 = 0x00054a00 (ROM-verified, big-endian) (ROM-verified at 0x00068d64). Direct tail-jump to `FUN_00054a00` 0x00054a00; callers in callgraph: 0x00067faa. Upstream name `thunk_FUN_00054a00` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00068d64; body bytes: 6; decompiled */

void jump_to_FUN_00054a00(void)

{
  FUN_00054a00();
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00054b2c [high]: 6-byte body: word 0xd30b = `mov.l @(0x68d98,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x68d98 = 0x00054b2c (ROM-verified, big-endian) (ROM-verified at 0x00068d6a). Direct tail-jump to `FUN_00054b2c` 0x00054b2c; callers in callgraph: 0x000684b4. Upstream name `thunk_FUN_00054b2c` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00068d6a; body bytes: 6; decompiled */

void jump_to_FUN_00054b2c(void)

{
  FUN_00054b2c();
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00054a36 [high]: 6-byte body: word 0xd30a = `mov.l @(0x68d9c,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x68d9c = 0x00054a36 (ROM-verified, big-endian) (ROM-verified at 0x00068d70). Direct tail-jump to `FUN_00054a36` 0x00054a36; callers in callgraph: 0x0006892a, 0x00068996. Upstream name `thunk_FUN_00054a36` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00068d70; body bytes: 6; decompiled */

void jump_to_FUN_00054a36(void)

{
  FUN_00054a36();
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00054aa0 [high]: 6-byte body: word 0xd30a = `mov.l @(0x68da0,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x68da0 = 0x00054aa0 (ROM-verified, big-endian) (ROM-verified at 0x00068d76). Direct tail-jump to `FUN_00054aa0` 0x00054aa0; no callgraph callers (vector/dispatch-table entry only). Upstream name `thunk_FUN_00054aa0` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00068d76; body bytes: 6; decompiled */

void jump_to_FUN_00054aa0(void)

{
  FUN_00054aa0();
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00054b62 [high]: 6-byte body: word 0xd309 = `mov.l @(0x68da4,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x68da4 = 0x00054b62 (ROM-verified, big-endian) (ROM-verified at 0x00068d7c). Direct tail-jump to `FUN_00054b62` 0x00054b62; callers in callgraph: 0x0006859e. Upstream name `thunk_FUN_00054b62` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00068d7c; body bytes: 6; decompiled */

void jump_to_FUN_00054b62(void)

{
  FUN_00054b62();
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * jump_to_FUN_00054b98 [high]: 6-byte body: word 0xd309 = `mov.l @(0x68da8,pc),r3`, 0x432b = `jmp @r3`, 0x0009 nop; pool 0x68da8 = 0x00054b98 (ROM-verified, big-endian) (ROM-verified at 0x00068d82). Direct tail-jump to `FUN_00054b98` 0x00054b98; callers in callgraph: 0x00068868. Upstream name `thunk_FUN_00054b98` is Ghidra's mechanical thunk auto-name (single-jump function), not a semantic label and not an uncertainty marker - the target is proven from the bra displacement resp. the PC-relative literal pool, so renamed per the label ladder (rule 6).
 */
/* ROM address: 0x00068d82; body bytes: 6; decompiled */

void jump_to_FUN_00054b98(void)

{
  FUN_00054b98();
  return;
}


/* [ADDITIONAL SOURCE REVIEW]
 * uds_service_dispatch_table_scan [high]: scans 12-byte records at 0x5eb40 (literal @0x68ed0): byte0==service, checks record[8] & session mask, jsr record[4]; disasm 0x68dd0-0x68e02
 */
/* ROM address: 0x00068dac; body bytes: 146; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006769c (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 uds_service_dispatch_table_scan(uint param_1,short param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  byte bVar4;
  
  uVar3 = 1;
  uVar2 = FUN_00004308(param_1,1);
  bVar4 = 0;
  while( true ) {
    if ((&tbl_uds_service_dispatch_0005eb40)[(uint)bVar4 * 0xc] == -1) {
      return uVar3;
    }
    iVar1 = (uint)bVar4 * 0xc;
    if ((uint)(byte)(&tbl_uds_service_dispatch_0005eb40)[iVar1] == (param_1 & 0xff)) break;
    bVar4 = bVar4 + 1;
    if (0xfe < bVar4) {
      return uVar3;
    }
  }
  if ((*(uint *)(&DAT_0005eb48 + iVar1) & uVar2) != 0) {
    (*(code *)(&switchD_00055ab6::switchdataD_0005eb44)[(uint)bVar4 * 3])((int)param_2,(int)param_3)
    ;
    return 0;
  }
  return 2;
}


/* ROM address: 0x00068e3e; body bytes: 134; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006772e (134 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_udsResponseRelated2(uint param_1,undefined1 param_2,uint param_3)

{
  undefined1 local_2c [4];
  undefined1 uStack_28;
  uint local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  param_3 = param_3 & 0xff;
  local_24 = param_1 & 0xff;
  uStack_28 = param_2;
  if (param_3 == 2) {
    ref_unknownMode22Func(param_1);
    local_2c[0] = 0x7f;
    ref_setupForUdsResponse_(param_1,local_2c,1);
    local_2c[0] = (undefined1)param_1;
    ref_setupForUdsResponse_(param_1,local_2c,1);
    local_2c[0] = uStack_28;
    ref_setupForUdsResponse_(param_1,local_2c,1);
    uStack_20 = 3;
    uStack_1c = 8;
    uStack_18 = 0;
    param_3 = FUN_00068d56();
  }
  else if (param_3 == 1) {
    uStack_20 = 3;
    uStack_1c = 8;
    uStack_18 = 1;
    param_3 = FUN_00068d56();
  }
  return param_3;
}


