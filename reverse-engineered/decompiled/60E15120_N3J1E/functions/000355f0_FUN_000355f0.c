/* ROM address: 0x000355f0; body bytes: 298; decompiled */

undefined ** FUN_000355f0(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = (undefined **)(uint)DAT_ffffc4bf;
  if (ppuVar1 == (undefined **)((int)&vector_Poweron_Reset + 1)) {
    ppuVar1 = (undefined **)(uint)DAT_ffffc4b9;
    if (ppuVar1 == (undefined **)0x0) {
      DAT_ffffc21e = 0;
    }
    else if (ppuVar1 == (undefined **)&UNK_00000006) {
      DAT_ffffc21e = 1;
      if ((DAT_ffffc4ba == 0) && (DAT_ffffc4bb == 0xff)) {
        DAT_ffffc221 = 1;
        ppuVar1 = (undefined **)0xff;
      }
      else if ((DAT_ffffc4ba == 1) && (DAT_ffffc4bb == 0xff)) {
        DAT_ffffc221 = 3;
        ppuVar1 = (undefined **)((int)&vector_Poweron_Reset + 1);
      }
      else {
        ppuVar1 = (undefined **)(uint)DAT_ffffc4ba;
        if (ppuVar1 == (undefined **)0x7f) {
          DAT_ffffc221 = 2;
        }
        else {
          DAT_ffffc21e = 6;
        }
      }
    }
    else if (ppuVar1 == &vector_Manual_Reset) {
      DAT_ffffc21e = 2;
      DAT_ffffc204 = (uint)DAT_ffffc4ba * 0x1000000 + (uint)DAT_ffffc4bb * 0x10000 +
                     (uint)DAT_ffffc4bc * 0x100 + (uint)DAT_ffffc4bd;
      ppuVar1 = (undefined **)&DAT_ffffc204;
    }
    else if (ppuVar1 == (undefined **)0x90) {
      ppuVar1 = (undefined **)(uint)DAT_ffffc4ba;
      if ((((ppuVar1 == (undefined **)((int)&vector_Poweron_Reset + 1)) ||
           (ppuVar1 == (undefined **)((int)&vector_Poweron_Reset + 2))) ||
          (ppuVar1 == (undefined **)((int)&vector_Poweron_Reset + 3))) ||
         (ppuVar1 == (undefined **)&UNK_00000004)) {
        DAT_ffffc21e = 4;
        DAT_ffffc1ec = (uint)DAT_ffffc4ba * 0x1000000 + (uint)DAT_ffffc4bb * 0x10000 +
                       (uint)DAT_ffffc4bc * 0x100 + (uint)DAT_ffffc4bd;
        ppuVar1 = (undefined **)&DAT_ffffc1ec;
      }
      else {
        DAT_ffffc21e = 6;
      }
    }
    else if (ppuVar1 == (undefined **)0xc9) {
      DAT_ffffc21e = 3;
    }
    else {
      DAT_ffffc21e = 6;
    }
  }
  else {
    DAT_ffffc21e = 5;
  }
  DAT_ffffc4bf = 0;
  return ppuVar1;
}


