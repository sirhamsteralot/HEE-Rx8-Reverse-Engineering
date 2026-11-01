/* ROM address: 0x00016a24; body bytes: 72; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00016a34) */

undefined4 FUN_00016a24(void)

{
  byte bVar1;
  byte bVar2;
  
  DAT_ffffdfa0 = 0;
  bVar1 = 0;
  do {
    bVar2 = bVar1 + 1;
    (&DAT_ffffdf70)[bVar1] = "N3ZHE_3W.Z05"[bVar1];
    bVar1 = bVar2;
  } while (bVar2 < 0x10);
  DAT_ffffdf90 = 0xc;
  return 0x20;
}


