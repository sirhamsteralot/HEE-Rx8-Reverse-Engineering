/* ROM address: 0x0005b13a; body bytes: 246; decompiled */

void FUN_0005b13a(void)

{
  short sVar4;
  uint uVar1;
  char cVar8;
  ushort uVar5;
  ushort uVar6;
  undefined4 uVar2;
  short sVar7;
  int iVar3;
  uint uVar9;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined1 auStack_48 [44];
  
  if (DAT_ffffd2e4 == '\0') {
    return;
  }
  sVar4 = ref_lookupCodeTypeMisfire((int)DAT_ffffd2e6);
  if (sVar4 == 3) {
    uVar1 = ref_lookupCodeTypeAll((int)DAT_ffffd2e6);
  }
  else {
    uVar1 = 0;
  }
  uVar9 = 0x8c;
  if ((uVar1 & 0xffff) == 0x8c) goto code_r0x0005b266;
  if ((uVar1 & 0xffff) != 0) {
    cVar8 = FUN_00061800(uVar1);
    uVar9 = uVar1;
    if ((cVar8 != -0x40) && (cVar8 != -0x3f)) {
      FUN_0005b266();
      return;
    }
    goto code_r0x0005b266;
  }
  cVar8 = FUN_00061800(0);
  if (((cVar8 == -0x40) || (cVar8 == -0x3f)) || (cVar8 == 'p')) {
    uVar9 = 0;
  }
  cVar8 = FUN_00061800(1);
  if (((cVar8 == -0x40) || (cVar8 == -0x3f)) || (cVar8 == 'p')) {
    if (uVar9 != 0x8c) {
      uVar5 = FUN_0006322a(1);
      uVar6 = FUN_0006322a(0);
      if (uVar6 <= uVar5) goto LAB_0005b214;
    }
    uVar9 = 1;
  }
LAB_0005b214:
  if (uVar9 != 0x8c) {
    uVar2 = FUN_00067bbc(0);
    sVar7 = FUN_0005f8cc(uVar2);
    if (sVar4 != sVar7) {
      FUN_0005b266();
      return;
    }
  }
code_r0x0005b266:
  if (((uVar9 & 0xffff) == 0x8c) || (cVar8 = FUN_00061ae6(uVar9,auStack_48), cVar8 != '\0')) {
    iVar3 = ref_udsErrorResponse(0x12,0x31);
  }
  else {
    uStack_4c = 0x52;
    uStack_4b = 0;
    ref_setupForUdsResponse_(0x12,&uStack_4c,2);
    iVar3 = FUN_0005b33a(auStack_48);
    uStack_4c = 4;
    uStack_4b = (undefined1)((ushort)DAT_ffffd2e6 >> 8);
    uStack_4a = (undefined1)DAT_ffffd2e6;
    ref_setupForUdsResponse_(0x12,&uStack_4c,3);
    iVar3 = iVar3 + 5;
  }
  ref_udsResponseRelated__(0x12,iVar3);
  ref_dtcCodeTypeInit();
  return;
}


