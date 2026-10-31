/* ROM address: 0x00007c68; body bytes: 268; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007c68 (268 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined * ref_geteShaftAngle_(void)

{
  char cVar1;
  undefined *puVar2;
  byte bVar3;
  
  DAT_ffff9f97 = DAT_ffff9f97 + 1;
  if (0x17 < DAT_ffff9f97) {
    DAT_ffff9f97 = 0;
  }
  if (DAT_ffff9fca != 0xff) {
    if (DAT_ffff9f96 == 0) {
      DAT_ffff9f97 = DAT_ffff9fca;
      DAT_ffff9f96 = 1;
      FUN_00007668(1);
    }
    else if (DAT_ffff9fca != DAT_ffff9f97) {
      bVar3 = DAT_ffff9fca - DAT_ffff9f97;
      if (0x7f < bVar3) {
        bVar3 = bVar3 + 0x18;
      }
      if (bVar3 < 3) {
        while (bVar3 != 0) {
          ref_getCrankAngle((int)(char)DAT_ffff9f97);
          FUN_0000a092(DAT_ffff9f97);
          DAT_ffff9f97 = DAT_ffff9f97 + 1;
          bVar3 = bVar3 - 1;
          if (0x17 < DAT_ffff9f97) {
            DAT_ffff9f97 = 0;
          }
        }
      }
      else {
        FUN_0000a13e(0);
      }
      DAT_ffff9f97 = DAT_ffff9fca;
    }
    DAT_ffff9fca = 0xff;
  }
  puVar2 = (undefined *)(uint)DAT_ffff9f96;
  if (puVar2 == (undefined *)((int)&vector_Poweron_Reset + 1)) {
    ref_getCrankAngle((int)(char)DAT_ffff9f97);
    FUN_0000a092(DAT_ffff9f97);
    puVar2 = &DAT_0000d7bc;
    cVar1 = (&DAT_0000d7bc)[DAT_ffff9f97];
    if (cVar1 != -1) {
      FUN_00007b84();
      puVar2 = (undefined *)FUN_0000a0b8(cVar1);
      return puVar2;
    }
  }
  return puVar2;
}


