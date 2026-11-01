/* ROM address: 0x0002a4d2; body bytes: 228; decompiled */

undefined1 * FUN_0002a4d2(void)

{
  char cVar2;
  char cVar3;
  undefined1 *puVar1;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  
  fVar4 = (float)FUN_00002068(DAT_ffffae54,&DAT_0006b1c8);
  fVar5 = (float)FUN_00002068(DAT_ffffad8c,&DAT_0006b1dc);
  uVar6 = 0x3727c5ac;
  fVar4 = fVar4 * fVar5;
  fVar5 = 0.0;
  cVar2 = FUN_00002440(fVar4,0,0x3727c5ac);
  cVar3 = FUN_00002440(DAT_ffffbb88,fVar5,uVar6);
  if (DAT_ffffbb8c == '\x01') {
    DAT_ffffbb85 = 0xff;
    puVar1 = (undefined1 *)0x1;
  }
  else if (DAT_ffffa428 == '\0') {
    DAT_ffffbb85 = 0;
    puVar1 = (undefined1 *)0x0;
  }
  else {
    if ((DAT_ffffbc33 == '\0') && (DAT_ffffbc34 == '\0')) {
      puVar1 = (undefined1 *)(int)DAT_ffffbb80;
    }
    else {
      if ((cVar2 == '\0') || (cVar3 == '\0')) {
        DAT_ffffbb85 = 0xfe;
        return &DAT_ffffbc33;
      }
      fVar4 = rx8_clamp_float((((DAT_ffffb338 + DAT_ffffbd24 + DAT_ffffbd28) * 100.0) / DAT_ffffbb88
                              ) / fVar4,fVar5,100.0);
      puVar1 = (undefined1 *)FUN_000024d0(fVar4,0x3ec99326,fVar5);
    }
    DAT_ffffbb85 = SUB41(puVar1,0);
  }
  return puVar1;
}


