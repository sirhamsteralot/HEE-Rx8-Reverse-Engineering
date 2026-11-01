/* ROM address: 0x0001791a; body bytes: 486; decompiled */

undefined * FUN_0001791a(char param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  
  puVar4 = (undefined *)(uint)((DAT_ffffa8fb & 1) != 0);
  bVar1 = false;
  uVar5 = (uint)DAT_ffffa8dd;
  if (param_1 == '\0') {
    if (inferred_ram_a8f4_ffffa8f4_ffffa8f4 < uVar5) {
      DAT_ffffa908 = 0;
    }
    else if (uVar5 < inferred_ram_a8f4_ffffa8f4_ffffa8f4) {
      DAT_ffffa908 = 1;
    }
    else {
      DAT_ffffa908 = 2;
      bVar1 = true;
    }
  }
  uVar6 = (uint)inferred_ram_a8f4_ffffa8f4_ffffa8f4;
  if (DAT_ffffa908 == 0) {
    if ((uVar6 <= uVar5) || (puVar4 != (undefined *)0x0)) {
      if ((uVar5 == uVar6) && (puVar4 == (undefined *)0x0)) {
        DAT_ffffa908 = 2;
        bVar1 = true;
      }
      goto LAB_00017a72;
    }
  }
  else {
    if (DAT_ffffa908 != 1) {
      if (DAT_ffffa908 == 2) {
        if (uVar5 <= uVar6) {
          if (uVar5 < uVar6) {
            DAT_ffffa908 = 1;
          }
          goto LAB_00017a72;
        }
      }
      else {
        if (DAT_ffffa908 != 3) {
          if ((DAT_ffffa908 == 4) && (puVar4 == (undefined *)0x0)) {
            if ((int)uVar6 <= (int)(uVar5 - 2)) {
              DAT_ffffa908 = 3;
            }
            if (uVar5 < 5) {
              bVar1 = true;
              DAT_ffffa908 = 2;
            }
          }
          goto LAB_00017a72;
        }
        if (uVar5 <= uVar6) {
          if (uVar5 < uVar6) {
            DAT_ffffa908 = 1;
          }
          else if (uVar5 == uVar6) {
            DAT_ffffa908 = 2;
            bVar1 = true;
          }
          goto LAB_00017a72;
        }
      }
      DAT_ffffa908 = 0;
      goto LAB_00017a72;
    }
    if ((uVar5 <= uVar6) || ((puVar4 != (undefined *)0x0 && (uVar6 != 0)))) {
      if ((uVar5 == uVar6) && ((puVar4 == (undefined *)0x0 || (uVar6 == 0)))) {
        if (uVar6 < 5) {
          DAT_ffffa908 = 2;
          bVar1 = true;
        }
        else {
          DAT_ffffa908 = 4;
        }
      }
      goto LAB_00017a72;
    }
  }
  DAT_ffffa908 = 3;
LAB_00017a72:
  puVar2 = (undefined *)(uint)DAT_ffffa908;
  if (puVar2 == (undefined *)0x0) {
    puVar4 = (undefined *)FUN_000174b4(2);
  }
  else if (puVar2 == (undefined *)((int)&vector_Poweron_Reset + 1)) {
    if (inferred_ram_a8f4_ffffa8f4_ffffa8f4 < 5) {
      FUN_000174b4(1);
      if (puVar4 == (undefined *)((int)&vector_Poweron_Reset + 1U)) {
        DAT_ffffa8fa = 8;
        return puVar4;
      }
      DAT_ffffa8fa = 0x30;
      return puVar4;
    }
    puVar4 = (undefined *)FUN_000174b4(3);
  }
  else {
    if (puVar2 == (undefined *)((int)&vector_Poweron_Reset + 2)) {
      if ((bVar1) && (inferred_ram_a8f4_ffffa8f4_ffffa8f4 == 0)) {
        puVar3 = &DAT_ffffa8fc;
        DAT_ffffa8fc = DAT_ffffa8fb;
      }
      else {
        puVar3 = (undefined1 *)FUN_000174b4(4);
      }
      DAT_ffffa8fa = 4;
      return puVar3;
    }
    if (puVar2 == (undefined *)((int)&vector_Poweron_Reset + 3)) {
      DAT_ffffa8fa = 0x30;
      return puVar2;
    }
    if (puVar2 != &UNK_00000004) {
      return puVar2;
    }
    if (inferred_ram_a8f4_ffffa8f4_ffffa8f4 < 5) {
      FUN_000174b4(1);
      if (puVar4 == (undefined *)((int)&vector_Poweron_Reset + 1U)) {
        DAT_ffffa8fa = 8;
        return puVar4;
      }
      DAT_ffffa8fa = 0x30;
      return puVar4;
    }
    puVar4 = (undefined *)FUN_000174b4(3);
  }
  DAT_ffffa8fa = 0x10;
  return puVar4;
}


