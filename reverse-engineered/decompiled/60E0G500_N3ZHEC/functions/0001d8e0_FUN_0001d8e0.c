/* ROM address: 0x0001d8e0; body bytes: 412; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001da52) */

void FUN_0001d8e0(void)

{
  char cVar1;
  char cVar2;
  undefined *puVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  cVar2 = DAT_ffffcb38;
  cVar1 = DAT_ffffae97;
  fVar6 = DAT_ffffb28c;
  fVar5 = DAT_ffffaae8;
  fVar4 = rx8_absolute_difference(DAT_ffffaae8,DAT_ffffae74);
  fVar7 = 0.0;
  if (cVar1 == '\x01') {
    if ((DAT_ffffb0da != '\0') || (fVar4 < 1.0)) {
      if (DAT_ffffaf98 < 0.02) {
        if (-0.02 <= DAT_ffffaf98) {
          DAT_ffffaf98 = 0.0;
        }
        else {
          DAT_ffffaf98 = DAT_ffffaf98 + 0.0005;
        }
      }
      else {
        DAT_ffffaf98 = DAT_ffffaf98 - 0.0005;
      }
    }
    else {
      DAT_ffffaf98 = fVar5 - DAT_ffffae74;
    }
  }
  else {
    DAT_ffffaf98 = 0.0;
  }
  if (cVar2 == '\0') {
    puVar3 = &DAT_0006a0c4;
  }
  else {
    puVar3 = &DAT_0006a0e0;
  }
  DAT_ffffae84 = (float)FUN_000020dc(DAT_ffffb5b8,DAT_ffffc12c,puVar3);
  fVar5 = fVar7;
  if (1.0 <= fVar6) {
    fVar5 = rx8_min_float(fVar6 * 0.0,0.015);
  }
  DAT_ffffaf9c = fVar5;
  DAT_ffffae7c = rx8_first_order_filter(DAT_ffffaf9c,DAT_ffffae7c,0.0,1e-05);
  if (cVar1 == '\x01') {
    fVar7 = (float)FUN_000020dc(DAT_ffffb5b8,DAT_ffffadbc,&DAT_0006a01c);
  }
  DAT_ffffae88 = fVar7;
  DAT_ffffae80 = ((DAT_ffffae84 - DAT_ffffae78) + DAT_ffffaf94 + DAT_ffffaf98) - DAT_ffffb078;
  fVar6 = rx8_max_float(DAT_ffffae88,DAT_ffffb084);
  DAT_ffffae74 = rx8_clamp_float((((((DAT_ffffae84 - DAT_ffffae78) - DAT_ffffae7c) + DAT_ffffb0e4 +
                                    0.0 + DAT_ffffaf94 + DAT_ffffaf98 + DAT_ffffb070) - DAT_ffffb078
                                  ) - fVar6) + 1.0,0.85,1.05);
  DAT_ffffb0da = cVar1;
  return;
}


