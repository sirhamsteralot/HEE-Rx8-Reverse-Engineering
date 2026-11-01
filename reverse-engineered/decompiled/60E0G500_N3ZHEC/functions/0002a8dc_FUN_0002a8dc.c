/* ROM address: 0x0002a8dc; body bytes: 232; decompiled */

undefined4 FUN_0002a8dc(void)

{
  char cVar2;
  undefined4 uVar1;
  undefined *puVar3;
  float arg0;
  float arg1;
  
  if (DAT_ffffbb57 == '\0') {
    DAT_ffffbbb8 = DAT_ffffb5b8;
  }
  if (DAT_ffffb33c == '\x01') {
    puVar3 = &DAT_0006a9c8;
  }
  else {
    if (DAT_ffffb33d != '\x01') {
      if (DAT_ffffb33e == '\x01') {
        puVar3 = &DAT_0006aa00;
      }
      else {
        puVar3 = &DAT_0006aa1c;
      }
      arg0 = (float)FUN_000020dc(DAT_ffffbbb8,DAT_ffffaa40,puVar3);
      goto LAB_0002a984;
    }
    puVar3 = &DAT_0006a9e4;
  }
  arg0 = (float)FUN_000020dc(DAT_ffffbbb8,puVar3);
LAB_0002a984:
  arg1 = 0.0;
  DAT_ffffbbb4 = rx8_clamp_float(arg0,0.0,84.0);
  DAT_ffffbbac = rx8_clamp_float(((DAT_ffffb314 + DAT_ffffbbb4) * 100.0) / 84.0,arg1,100.0);
  cVar2 = FUN_0003eaa4(&DAT_ffff876c,0);
  if (((cVar2 != '\x01') && (cVar2 = FUN_0003eaa4(&DAT_ffff8750,0), cVar2 != '\x01')) &&
     (DAT_ffffccd5 != '\x01')) {
    uVar1 = FUN_000024d0(DAT_ffffbbac,0x3f000000,arg1);
    DAT_ffffbbc2 = (char)uVar1;
    return uVar1;
  }
  DAT_ffffbbc2 = 0xff;
  return 1;
}


