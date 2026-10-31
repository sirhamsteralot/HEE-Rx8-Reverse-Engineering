/* ROM address: 0x00026aa0; body bytes: 100; decompiled */

undefined2 * FUN_00026aa0(void)

{
  undefined2 *puVar1;
  undefined2 *extraout_r0;
  float fVar2;
  
  if (DAT_ffffba9c == 400) {
    fVar2 = rx8_max_float((float)DAT_ffffcb78,(float)DAT_ffffcb7c);
    DAT_ffffb690 = (undefined2)(int)fVar2;
  }
  puVar1 = &DAT_ffffba9e;
  if (DAT_ffffba9e == 2000) {
    fVar2 = rx8_max_float((float)DAT_ffffcb7a,(float)DAT_ffffcb7e);
    DAT_ffffb692 = (undefined2)(int)fVar2;
    puVar1 = extraout_r0;
  }
  return puVar1;
}


