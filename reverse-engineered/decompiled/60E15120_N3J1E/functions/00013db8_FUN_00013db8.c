/* ROM address: 0x00013db8; body bytes: 134; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00013d1c (134 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * FUN_00013db8(void)

{
  undefined4 *puVar1;
  
  if (engine_speed_rpm_ffffb548 < 8000.0) {
    if (engine_speed_rpm_ffffb548 < 7800.0) {
      DAT_ffffa777 = 1;
    }
  }
  else {
    DAT_ffffa777 = 0;
  }
  puVar1 = (undefined4 *)(uint)DAT_ffffa764;
  if ((((puVar1 == (undefined4 *)((int)&vector_Poweron_Reset + 1)) && (DAT_ffffa762 != 0)) &&
      (puVar1 = (undefined4 *)(uint)DAT_ffffa777,
      puVar1 == (undefined4 *)((int)&vector_Poweron_Reset + 1))) &&
     (((DAT_ffffa768 < 0.5 && (puVar1 = &DAT_00072524, 0.1 <= engine_load_ffffc0b4)) &&
      ((puVar1 = (undefined4 *)(uint)DAT_ffffa758, puVar1 == (undefined4 *)&UNK_00000015 &&
       (puVar1 = (undefined4 *)(int)DAT_ffffa760, puVar1 == (undefined4 *)0x0)))))) {
    DAT_ffffa758 = 0;
  }
  DAT_ffffa768 = engine_load_ffffc0b4;
  return puVar1;
}


