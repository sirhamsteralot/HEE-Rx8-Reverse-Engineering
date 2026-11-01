/* ROM address: 0x000312c0; body bytes: 248; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000312f8) */

void FUN_000312c0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  DAT_ffffbf3c = DAT_ffffc12c * 0.07196;
  DAT_ffffbf40 = (float)FUN_000020dc(DAT_ffffb5b8,&DAT_0006b0b0);
  fVar3 = 1.0;
  fVar1 = rx8_max_float(DAT_ffffc178,DAT_ffffce20);
  DAT_ffffbf88 = (float)FUN_00002068(DAT_ffffaa10,&DAT_0006b074);
  fVar2 = rx8_min_float(DAT_ffffbf88,DAT_ffffc074 + DAT_ffffb190);
  fVar1 = rx8_max_float(DAT_ffffbfa8,
                        DAT_ffffc084 + DAT_ffffb134 + DAT_ffffbce0 + DAT_ffffce34 + DAT_ffffa5e0 +
                        fVar1 + fVar2);
  fVar2 = rx8_max_float(DAT_ffffae88,DAT_ffffb194);
  DAT_ffffbf80 = ((((DAT_ffffb140 - DAT_ffffc140) - DAT_ffffae80) - DAT_ffffb28c) + fVar1 + fVar2 +
                 fVar3) * DAT_ffffae64 * DAT_ffffbf40;
  DAT_ffffbf18 = (float)FUN_0005c7c8(DAT_ffffbf80);
  DAT_ffffbf1c = DAT_ffffbf18 * DAT_ffffbf3c;
  return;
}


