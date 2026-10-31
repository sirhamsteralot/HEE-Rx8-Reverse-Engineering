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
  
  FUN_000011c4();
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
          FUN_000011c4();
        }
      }
      else if (bVar1 == 1) {
        iVar4 = FUN_000015a6();
        if (iVar4 == 0) {
          bVar2 = true;
          FUN_00001624();
          FUN_000011c4();
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
        FUN_000011c4();
      }
    }
LAB_00001414:
    uVar5 = service_wdt_overflow_toggle_pb15_and_count();
    if (bVar2) {
      if (0x2d < uVar5) {
        bVar2 = false;
        FUN_000011c4();
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
      FUN_000011c4();
      unaff_r10 = '\0';
    }
  } while( true );
}


