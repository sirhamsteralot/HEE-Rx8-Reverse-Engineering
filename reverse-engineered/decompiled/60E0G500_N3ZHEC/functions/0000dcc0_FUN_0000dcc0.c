/* ROM address: 0x0000dcc0; body bytes: 252; decompiled */

uint FUN_0000dcc0(void)

{
  char cVar2;
  uint uVar1;
  
  if (((DAT_ffffaae0 == 1) && (DAT_ffffb5e8 != '\x01')) &&
     ((cVar2 = FUN_00009b08(0), cVar2 == '\x01' || (cVar2 = FUN_00009b08(1), cVar2 == '\x01')))) {
    if (DAT_ffffa40f != 0xff) {
      DAT_ffffa40f = DAT_ffffa40f + 1;
    }
  }
  else {
    DAT_ffffa40f = 0;
  }
  if ((100 < DAT_ffffa40f) && (FUN_0000dddc(), DAT_ffffa40a == 0)) {
    DAT_ffffa40a = 1;
  }
  uVar1 = (uint)DAT_ffffaae0;
  if ((uVar1 == 1) && (uVar1 = 1, DAT_ffffb5e8 != '\x01')) {
    cVar2 = FUN_00009ac4(0);
    if ((cVar2 == '\x01') ||
       ((cVar2 = FUN_00009ac4(1), cVar2 == '\x01' || (uVar1 = (uint)DAT_ffffa40a, uVar1 == 1)))) {
      DAT_ffffa40a = 1;
      DAT_ffffa409 = 1;
      if (DAT_ffffa40c == 0) {
        FUN_0000dddc();
        FUN_0000d9f4();
      }
      FUN_0000dddc();
      uVar1 = FUN_00002460((int)(short)DAT_ffffa40c,1);
      DAT_ffffa40c = (ushort)uVar1;
    }
    else {
      DAT_ffffa40c = 0;
    }
    if (999 < DAT_ffffa40c) {
      uVar1 = FUN_0000dade();
      DAT_ffffa40a = 0;
      DAT_ffffa40c = 0;
    }
  }
  return uVar1;
}


