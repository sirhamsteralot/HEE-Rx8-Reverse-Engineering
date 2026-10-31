/* ROM address: 0x0005bc4c; body bytes: 464; decompiled */

/* Function candidate recovered from ROM pointer at 5ec34 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined * FUN_0005bc4c(ushort param_1,uint param_2)

{
  uint uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  short sVar7;
  undefined *puVar8;
  undefined *puVar9;
  int iVar10;
  byte local_24;
  byte bStack_23;
  byte bStack_22;
  
  puVar4 = (undefined *)(param_2 & 0xff);
  if (puVar4 == (undefined *)((int)&vector_Poweron_Reset + 1)) {
    iVar10 = 0x33;
    uVar1 = ref_securityNotUnlocked(1);
    puVar4 = (undefined *)(uVar1 & 0xff);
    if ((puVar4 == (undefined *)0x0) && (iVar10 = 0x12, 2 < param_1)) {
      ref_udsServiceResponse(0x2f,&local_24,3);
      sVar7 = (ushort)local_24 * 0x100 + (ushort)bStack_23;
      puVar2 = (undefined *)FUN_0005d6a2(sVar7);
      iVar10 = 0x31;
      puVar4 = puVar2;
      if ((char)puVar2 != -1) {
        if ((DAT_ffffd3b4 & *(ushort *)(&DAT_0005f72a + ((uint)puVar2 & 0xff) * 0x10)) == 0) {
          puVar4 = (undefined *)0x0;
        }
        else if ((((bStack_22 == 0) && (((&DAT_0005f731)[((uint)puVar2 & 0xff) * 0x10] & 0x80) != 0)
                  ) || ((bStack_22 == 5 &&
                        (((&DAT_0005f731)[((uint)puVar2 & 0xff) * 0x10] & 0x40) != 0)))) ||
                ((puVar4 = (undefined *)(uint)bStack_22,
                 (undefined *)(uint)bStack_22 == &UNK_00000007 &&
                 (puVar4 = (undefined *)(uint)(byte)(&DAT_0005f731)[((uint)puVar2 & 0xff) * 0x10],
                 ((&DAT_0005f731)[((uint)puVar2 & 0xff) * 0x10] & 0x20) != 0)))) {
          puVar8 = (undefined *)(uint)bStack_22;
          iVar10 = 0x12;
          if ((((puVar8 == (undefined *)0x0) || (puVar8 == &UNK_00000005)) && (param_1 == 3)) ||
             ((puVar4 = puVar8, puVar8 == &UNK_00000007 &&
              (puVar4 = &DAT_0005f733,
              (ushort)(param_1 - 3) == (ushort)(byte)(&DAT_0005f733)[((uint)puVar2 & 0xff) * 0x10]))
             )) {
            iVar10 = 0x31;
            puVar5 = (undefined *)0x0;
            puVar9 = puVar8;
            if (puVar8 == &UNK_00000007) {
              iVar6 = ((uint)puVar2 & 0xff) * 0x10;
              ref_udsServiceResponse(0x2f,&local_24,(&DAT_0005f733)[iVar6]);
              puVar9 = (undefined *)((uint)local_24 << 8);
              if ((&DAT_0005f733)[iVar6] == '\x02') {
                puVar9 = (undefined *)(uint)CONCAT11(local_24,bStack_23);
              }
              puVar8 = (undefined *)FUN_0005d6d8(puVar2,puVar9);
              puVar5 = puVar8;
            }
            puVar4 = puVar8;
            if (((uint)puVar5 & 0xff) != 0xff) {
              iVar10 = 0x22;
              puVar4 = (undefined *)0x0;
              if ((DAT_ffffd36c & (&DAT_0005f730)[((uint)puVar2 & 0xff) * 0x10]) != 0) {
                iVar10 = 0;
                DAT_ffffd318 = bStack_22;
                DAT_ffffd316 = SUB42(puVar9,0);
                puVar4 = &DAT_ffffd31a;
                DAT_ffffd314 = sVar7;
                DAT_ffffd31a = (char)puVar2;
              }
            }
          }
        }
      }
    }
    if (iVar10 != 0) {
      uVar3 = ref_udsErrorResponse(0x2f,iVar10);
      puVar4 = (undefined *)ref_udsResponseRelated__(0x2f,uVar3);
    }
  }
  else if (puVar4 == (undefined *)0x0) {
    puVar4 = (undefined *)FUN_0005494a(0x2f);
  }
  return puVar4;
}


