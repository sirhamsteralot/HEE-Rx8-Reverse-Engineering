/* ROM address: 0x0004c598; body bytes: 216; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0004c600) */
/* WARNING: Removing unreachable block (ram,0x0004c60a) */
/* WARNING: Removing unreachable block (ram,0x0004c618) */
/* WARNING: Removing unreachable block (ram,0x0004c63e) */
/* WARNING: Removing unreachable block (ram,0x0004c64c) */

undefined1 * FUN_0004c598(void)

{
  undefined1 *puVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcea2 = '\'';
    puVar1 = (undefined1 *)((int)&vector_CPUaddr_error + 3);
    DAT_ffffcea3 = 0x27;
    DAT_ffffceaa = 0;
    DAT_ffffceab = 0;
  }
  else {
    puVar1 = (undefined1 *)(uint)apv_direction_flag_ffffbf8b;
    if (puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) {
      if (inferred_ram_cab4_ffffcab4_ffffcab4 == '\0') {
        if (DAT_ffffcea2 == '\0') {
          puVar1 = &UNK_ffffffff;
        }
        else {
          DAT_ffffcea2 = DAT_ffffcea2 + -1;
        }
        DAT_ffffcea3 = 0x27;
      }
      else {
        puVar1 = (undefined1 *)(uint)DAT_ffffcea3;
        if (puVar1 == (undefined1 *)0x0) {
          puVar1 = &DAT_0007ccbb;
        }
        else {
          DAT_ffffcea3 = DAT_ffffcea3 - 1;
        }
        DAT_ffffcea2 = '\'';
      }
    }
    else {
      DAT_ffffcea2 = '\'';
      DAT_ffffcea3 = 0x27;
    }
  }
  return puVar1;
}


