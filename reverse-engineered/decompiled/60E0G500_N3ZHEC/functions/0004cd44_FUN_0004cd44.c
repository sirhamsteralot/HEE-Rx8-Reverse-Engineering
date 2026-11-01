/* ROM address: 0x0004cd44; body bytes: 216; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0004cdac) */
/* WARNING: Removing unreachable block (ram,0x0004cdb6) */
/* WARNING: Removing unreachable block (ram,0x0004cdc4) */
/* WARNING: Removing unreachable block (ram,0x0004cdea) */
/* WARNING: Removing unreachable block (ram,0x0004cdf8) */

undefined * FUN_0004cd44(void)

{
  undefined *puVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcede = '\'';
    puVar1 = &UNK_00000027;
    DAT_ffffcedf = 0x27;
    DAT_ffffcee6 = 0;
    DAT_ffffcee7 = 0;
  }
  else {
    puVar1 = (undefined *)(uint)DAT_ffffbff3;
    if (puVar1 == &UNK_00000001) {
      if (DAT_ffffcb24 == '\0') {
        if (DAT_ffffcede == '\0') {
          puVar1 = &UNK_ffffffff;
        }
        else {
          DAT_ffffcede = DAT_ffffcede + -1;
        }
        DAT_ffffcedf = 0x27;
      }
      else {
        puVar1 = (undefined *)(uint)DAT_ffffcedf;
        if (puVar1 == (undefined *)0x0) {
          puVar1 = &DAT_0007c883;
        }
        else {
          DAT_ffffcedf = DAT_ffffcedf - 1;
        }
        DAT_ffffcede = '\'';
      }
    }
    else {
      DAT_ffffcede = '\'';
      DAT_ffffcedf = 0x27;
    }
  }
  return puVar1;
}


