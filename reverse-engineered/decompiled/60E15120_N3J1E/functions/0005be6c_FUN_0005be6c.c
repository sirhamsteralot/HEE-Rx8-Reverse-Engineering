/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005be6c; body bytes: 228; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005a65c (228 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005be6c(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined2 snapshot_DAT_ffffd314;
  byte snapshot_DAT_ffffd319;
  byte snapshot_DAT_ffffd31a;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined1 local_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  char cStack_21;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  
  uVar7 = sh_raise_interrupt_mask_return_previous(0x10);
  snapshot_DAT_ffffd31a = DAT_ffffd31a;
  snapshot_DAT_ffffd319 = DAT_ffffd319;
  snapshot_DAT_ffffd314 = DAT_ffffd314;
  cVar1 = *(&PTR_DAT_0005f734)[(uint)DAT_ffffd31a * 4];
  uVar2 = (&DAT_ffffd335)[(uint)DAT_ffffd31a * 2];
  uVar3 = (&DAT_ffffd336)[(uint)DAT_ffffd31a * 2];
  ref_setSR(uVar7);
  uVar8 = (uint)snapshot_DAT_ffffd319;
  if (uVar8 == 1) {
    DAT_ffffd314 = 0;
    DAT_ffffd319 = 0;
    local_24 = 0x6f;
    uStack_23 = (undefined1)((ushort)snapshot_DAT_ffffd314 >> 8);
    uStack_22 = (undefined1)snapshot_DAT_ffffd314;
    if ((cVar1 == '\x05') || (cVar1 == '\a')) {
      iVar9 = (byte)(&DAT_0005f733)[(uint)snapshot_DAT_ffffd31a * 0x10] + 4;
    }
    else {
      iVar9 = 4;
    }
    cStack_21 = cVar1;
    uStack_20 = uVar2;
    uStack_1f = uVar3;
    ref_setupForUdsResponse_(0x2f,&local_24,iVar9);
    uVar8 = ref_udsResponseRelated__(0x2f,iVar9);
  }
  else if (uVar8 == 2) {
    DAT_ffffd314 = 0;
    DAT_ffffd319 = 0;
    uVar7 = ref_udsErrorResponse(0x2f,0x22);
    uVar8 = ref_udsResponseRelated__(0x2f,uVar7);
  }
  return uVar8;
}


