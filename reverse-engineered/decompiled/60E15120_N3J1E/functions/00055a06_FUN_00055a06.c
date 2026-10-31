/* ROM address: 0x00055a06; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00053d22 (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined * FUN_00055a06(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = (undefined *)(uint)DAT_ffffd1c9;
  if ((puVar2 != (undefined *)0x0) && (DAT_ffffd1c4 != '\0')) {
    DAT_ffffd1c4 = DAT_ffffd1c4 + -1;
  }
  puVar1 = &DAT_ffffd1c9;
  if (DAT_ffffd1c4 == '\0') {
    if (puVar2 == &UNK_00000004) {
      puVar2 = (undefined *)FUN_00066172();
    }
    else if (puVar2 == &UNK_00000014) {
      puVar2 = (undefined *)FUN_00055942();
    }
    DAT_ffffd1c5 = 0;
    DAT_ffffd1c9 = 0;
    puVar1 = puVar2;
  }
  return puVar1;
}


