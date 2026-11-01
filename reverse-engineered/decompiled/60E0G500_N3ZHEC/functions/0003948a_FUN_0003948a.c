/* ROM address: 0x0003948a; body bytes: 60; decompiled */

undefined4 * FUN_0003948a(void)

{
  undefined4 *puVar1;
  float fVar2;
  
  puVar1 = (undefined4 *)&DAT_0007a5bc;
  if (0x49 < DAT_ffffc568) {
    fVar2 = rx8_max_float(DAT_ffffc558 * 0.099999994,1.0);
    fVar2 = (float)FUN_0003ea74(DAT_ffffc55c,fVar2);
    puVar1 = &DAT_0003953c;
    DAT_ffffc554 = fVar2 * 100.0;
  }
  return puVar1;
}


