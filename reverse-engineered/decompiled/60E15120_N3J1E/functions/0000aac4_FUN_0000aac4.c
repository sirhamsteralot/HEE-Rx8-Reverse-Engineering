/* [ADDITIONAL SOURCE REVIEW]
 * apv_drive_status_sample [high]: Reads PHDR_W 0xfffff72c bits 0x1000/0x2000 (PH12 pkg pin 79 / PH13 pkg pin 80) when a drive-active flag is set; emits remapped 0..3 state at a1bc. | promoted to high (data/labels/60E15120_N3J1E/intake_labels.json/function_aliases)
 * RAM 0xffffa1bc apv_drive_status (uint8): Remapped 0..3 state from PH12/PH13 (PHDR 0x1000/0x2000).
 */
/* ROM address: 0x0000aac4; body bytes: 126; decompiled */

/* 
   
   [WIRING REVIEW 2026-09-08]
   Candidate APV drive-status sampler. Firmware fact: reads PHDR_W 0x1000/0x2000 (PH12/PH13, pkg pins 79/80). pinout v3: APV opening-angle signal at PCM 3B (wire R/G, HP ³) and position-sensor power at PCM 1S (B/W *); external meaning of the two PH inputs not established. */

void apv_drive_status_sample(void)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((DAT_ffffa1c8 == '\x01') || (DAT_ffffa1c9 == '\x01')) {
    uVar1 = PHDR_W;
    uVar2 = PHDR_W;
    if ((uVar1 & 0x1000) == 0) {
      iVar3 = 2;
    }
    if ((uVar2 & 0x2000) == 0) {
      iVar3 = iVar3 + 1;
    }
  }
  else {
    iVar3 = 3;
  }
  if (iVar3 == 0) {
    apv_drive_status_ffffa1bc = 0;
  }
  else if (iVar3 == 1) {
    apv_drive_status_ffffa1bc = 2;
  }
  else if (iVar3 == 2) {
    apv_drive_status_ffffa1bc = 1;
  }
  else if (iVar3 == 3) {
    apv_drive_status_ffffa1bc = 3;
  }
  FUN_0000a16e(0);
  return;
}


