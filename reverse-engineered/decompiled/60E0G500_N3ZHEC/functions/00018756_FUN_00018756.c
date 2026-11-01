/* ROM address: 0x00018756; body bytes: 486; decompiled */

undefined * FUN_00018756(char param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  
  puVar4 = (undefined *)(uint)((DAT_ffffa97c & 1) != 0);
  bVar1 = false;
  uVar5 = (uint)DAT_ffffa8f1;
  if (param_1 == '\0') {
    if (DAT_ffffa974 < uVar5) {
      DAT_ffffa98b = 0;
    }
    else if (uVar5 < DAT_ffffa974) {
      DAT_ffffa98b = 1;
    }
    else {
      DAT_ffffa98b = 2;
      bVar1 = true;
    }
  }
  uVar6 = (uint)DAT_ffffa974;
  if (DAT_ffffa98b == 0) {
    if ((uVar6 <= uVar5) || (puVar4 != (undefined *)0x0)) {
      if ((uVar5 == uVar6) && (puVar4 == (undefined *)0x0)) {
        DAT_ffffa98b = 2;
        bVar1 = true;
      }
      goto LAB_000188ae;
    }
  }
  else {
    if (DAT_ffffa98b != 1) {
      if (DAT_ffffa98b == 2) {
        if (uVar5 <= uVar6) {
          if (uVar5 < uVar6) {
            DAT_ffffa98b = 1;
          }
          goto LAB_000188ae;
        }
      }
      else {
        if (DAT_ffffa98b != 3) {
          if ((DAT_ffffa98b == 4) && (puVar4 == (undefined *)0x0)) {
            if ((int)uVar6 <= (int)(uVar5 - 2)) {
              DAT_ffffa98b = 3;
            }
            if (uVar5 < 5) {
              bVar1 = true;
              DAT_ffffa98b = 2;
            }
          }
          goto LAB_000188ae;
        }
        if (uVar5 <= uVar6) {
          if (uVar5 < uVar6) {
            DAT_ffffa98b = 1;
          }
          else if (uVar5 == uVar6) {
            DAT_ffffa98b = 2;
            bVar1 = true;
          }
          goto LAB_000188ae;
        }
      }
      DAT_ffffa98b = 0;
      goto LAB_000188ae;
    }
    if ((uVar5 <= uVar6) || ((puVar4 != (undefined *)0x0 && (uVar6 != 0)))) {
      if ((uVar5 == uVar6) && ((puVar4 == (undefined *)0x0 || (uVar6 == 0)))) {
        if (uVar6 < 5) {
          DAT_ffffa98b = 2;
          bVar1 = true;
        }
        else {
          DAT_ffffa98b = 4;
        }
      }
      goto LAB_000188ae;
    }
  }
  DAT_ffffa98b = 3;
LAB_000188ae:
  puVar2 = (undefined *)(uint)DAT_ffffa98b;
  if (puVar2 == (undefined *)0x0) {
    puVar4 = (undefined *)FUN_000182ba(2);
  }
  else if (puVar2 == &UNK_00000001) {
    if (DAT_ffffa974 < 5) {
      FUN_000182ba(1);
      if (puVar4 == &UNK_00000001) {
        DAT_ffffa97b = 8;
        return puVar4;
      }
      DAT_ffffa97b = 0x30;
      return puVar4;
    }
    puVar4 = (undefined *)FUN_000182ba(3);
  }
  else {
    if (puVar2 == &UNK_00000002) {
      if ((bVar1) && (DAT_ffffa974 == 0)) {
        puVar3 = &DAT_ffffa97d;
        DAT_ffffa97d = DAT_ffffa97c;
      }
      else {
        puVar3 = (undefined1 *)FUN_000182ba(4);
      }
      DAT_ffffa97b = 4;
      return puVar3;
    }
    if (puVar2 == &UNK_00000003) {
      DAT_ffffa97b = 0x30;
      return puVar2;
    }
    if (puVar2 != &UNK_00000004) {
      return puVar2;
    }
    if (DAT_ffffa974 < 5) {
      FUN_000182ba(1);
      if (puVar4 == &UNK_00000001) {
        DAT_ffffa97b = 8;
        return puVar4;
      }
      DAT_ffffa97b = 0x30;
      return puVar4;
    }
    puVar4 = (undefined *)FUN_000182ba(3);
  }
  DAT_ffffa97b = 0x10;
  return puVar4;
}


