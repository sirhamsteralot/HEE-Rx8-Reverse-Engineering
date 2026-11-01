/* ROM address: 0x000309a4; body bytes: 80; decompiled */

void FUN_000309a4(void)

{
  float fVar1;
  
  DAT_ffffbe84 = (float)FUN_000020dc(DAT_ffffb5b8,DAT_ffffc12c,&DAT_0006af1c);
  fVar1 = DAT_ffffbe6c;
  DAT_ffffbe6c = (float)FUN_0003ea74((DAT_ffffae54 + 273.0) * DAT_ffffbe84 * DAT_ffffbe88,0x43960000
                                    );
  DAT_ffffbe68 = DAT_ffffbe6c - fVar1;
  return;
}


