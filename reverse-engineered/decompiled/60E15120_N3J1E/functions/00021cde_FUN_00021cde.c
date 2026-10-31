/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffa426 engine_on_time_counter (uint16): Engine on-time counter (0x21cde).
 */
/* ROM address: 0x00021cde; body bytes: 96; decompiled */

undefined2 * FUN_00021cde(void)

{
  undefined2 *puVar1;
  
  if (inferred_coolant_temperature_ffffa98c < 65.0) {
    if (inferred_coolant_temperature_ffffa98c < 62.5) {
      DAT_ffffb32c = 0;
    }
  }
  else {
    DAT_ffffb32c = 1;
  }
  puVar1 = &DAT_00072ee8;
  if ((((engine_on_time_counter_ffffa426 < 0x2d) ||
       (puVar1 = (undefined2 *)(uint)DAT_ffffb32c,
       puVar1 != (undefined2 *)((int)&vector_Poweron_Reset + 1))) ||
      (puVar1 = (undefined2 *)(int)DAT_ffffc590, puVar1 != (undefined2 *)0x0)) ||
     (puVar1 = (undefined2 *)&DAT_ffffcd74, DAT_ffffcd74 != '\0')) {
    DAT_ffffb318 = 0;
  }
  else {
    DAT_ffffb318 = 1;
  }
  return puVar1;
}


