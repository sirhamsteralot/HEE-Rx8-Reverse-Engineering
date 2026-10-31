/* ROM address: 0x0000d46c; body bytes: 126; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000d46c (126 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0000d46c(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  uVar1 = (uint)DAT_ffffa3fa;
  iVar3 = 0;
  if (uVar1 == 2) {
    piVar4 = (int *)(&PTR_firmware_id_0007fb80)[(uint)DAT_ffffa3f8 * 3];
    piVar2 = *(int **)(&DAT_0007fb84 + (uint)DAT_ffffa3f8 * 0xc);
    uVar1 = FUN_0000d674(piVar4,piVar2);
    if ((uVar1 & 0xff) == 0) {
      for (; piVar4 < piVar2; piVar4 = piVar4 + 1) {
        iVar3 = iVar3 + *piVar4;
      }
      uVar1 = *(uint *)(&DAT_0007fb88 + (uint)DAT_ffffa3f8 * 0xc);
      if (iVar3 + uVar1 == 0x5aa5a55a) {
        uVar1 = 0;
        DAT_ffffa3fa = 0;
      }
      else {
        DAT_ffffa3fa = 1;
      }
    }
    else {
      DAT_ffffa3fa = 1;
    }
  }
  return uVar1;
}


