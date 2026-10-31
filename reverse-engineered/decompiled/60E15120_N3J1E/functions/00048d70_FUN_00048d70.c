/* ROM address: 0x00048d70; body bytes: 166; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00048dea) */
/* WARNING: Removing unreachable block (ram,0x00048df6) */
/* WARNING: Removing unreachable block (ram,0x00048e0c) */

char FUN_00048d70(void)

{
  char cVar1;
  
  if (inferred_battery_voltage_ffffb590 < 6.0) {
    DAT_ffffccc2 = 0;
    DAT_ffffccc4 = 0;
  }
  else {
    DAT_ffffccc5 = 1;
    DAT_ffffccc2 = 1;
    if (DAT_ffffccca == 0) {
      DAT_ffffccc4 = 1;
    }
    else {
      DAT_ffffccc4 = 0;
    }
  }
  cVar1 = DAT_ffffaa68 == '\x01';
  if (((DAT_ffffaa68 == '\x01') && (cVar1 = DAT_ffffccc1, DAT_ffffccc1 == '\x01')) &&
     (cVar1 = DAT_ffffb4ed, DAT_ffffb4ed == '\x01')) {
    DAT_ffffccc3 = 1;
  }
  else {
    DAT_ffffccc3 = 0;
  }
  return cVar1;
}


