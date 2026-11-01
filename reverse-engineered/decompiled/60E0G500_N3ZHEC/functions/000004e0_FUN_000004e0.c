/* ROM address: 0x000004e0; body bytes: 146; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00000550) */
/* WARNING: Removing unreachable block (ram,0x00000532) */
/* WARNING: Removing unreachable block (ram,0x0000053c) */

void FUN_000004e0(int param_1,undefined1 param_2)

{
  bool bVar1;
  int iVar2;
  undefined *unaff_r13;
  
  bVar1 = true;
  FUN_00000572();
  FUN_00000170();
  FUN_0000041c();
  FUN_000003d4();
  if (param_1 == 0) {
    if ((DAT_ffffdffc != 0x5aa5a55a) && (iVar2 = FUN_000005b0(7), iVar2 == 0)) {
      bVar1 = false;
      unaff_r13 = &DAT_000006c8;
    }
    if (bVar1) {
      unaff_r13 = &DAT_00001298;
    }
  }
  else {
    DAT_ffffdfa8 = param_2;
    FUN_000008f6();
    unaff_r13 = &DAT_000006c8;
  }
  DAT_ffffdffc = 0x5aa5a55a;
  FUN_00000040(unaff_r13);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


