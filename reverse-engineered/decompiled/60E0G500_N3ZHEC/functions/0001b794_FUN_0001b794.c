/* ROM address: 0x0001b794; body bytes: 288; decompiled */

uint FUN_0001b794(void)

{
  uint uVar1;
  uint extraout_r0;
  float fVar2;
  float arg2;
  undefined4 uVar3;
  float fVar4;
  float arg3;
  
  uVar1 = (uint)DAT_ffffad82;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffa428, uVar1 == 1)) {
    arg3 = 1e-05;
    if (DAT_ffffad82 == 0) {
      fVar4 = DAT_ffffab00 - DAT_ffffad74;
      uVar3 = DAT_ffffaa88;
      fVar2 = (float)FUN_00002068(DAT_ffffaa88,&DAT_00069e88);
      arg2 = (float)FUN_00002068(uVar3,&DAT_00069e94);
      if (0.0 <= fVar4) {
        fVar2 = DAT_ffffab00;
        if (0.0 < fVar4) {
          fVar2 = rx8_first_order_filter(DAT_ffffab00,DAT_ffffaae4,arg2,arg3);
        }
      }
      else {
        fVar2 = rx8_first_order_filter(DAT_ffffab00,DAT_ffffaae4,fVar2,arg3);
      }
    }
    else if (DAT_ffffad74 <= DAT_ffffab00) {
      fVar2 = DAT_ffffab00;
      if (DAT_ffffad7c != 0) {
        fVar2 = (float)FUN_000024c0(0x37800000,0);
        fVar2 = rx8_first_order_filter(DAT_ffffab00,DAT_ffffaae4,fVar2,arg3);
      }
    }
    else {
      fVar2 = DAT_ffffab00;
      if (DAT_ffffad7e != 0) {
        fVar2 = (float)FUN_000024c0(0x37800000,0);
        fVar2 = rx8_first_order_filter(DAT_ffffab00,DAT_ffffaae4,fVar2,arg3);
      }
    }
    DAT_ffffaae4 = fVar2;
    DAT_ffffaae8 = rx8_first_order_filter(DAT_ffffaae4,DAT_ffffaae8,1.0,arg3);
    DAT_ffffaaec = DAT_ffffaae4;
    uVar1 = extraout_r0;
  }
  DAT_ffffad74 = DAT_ffffaae4;
  return uVar1;
}


