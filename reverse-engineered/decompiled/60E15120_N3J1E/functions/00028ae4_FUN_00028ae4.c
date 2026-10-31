/* ROM address: 0x00028ae4; body bytes: 44; decompiled */

undefined1 * FUN_00028ae4(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(uint)DAT_ffffd1c5;
  if ((puVar1 == (undefined1 *)0x1) &&
     (puVar1 = (undefined1 *)(uint)engine_stopped_latch_ffffa41c, puVar1 == (undefined1 *)0x1)) {
    puVar1 = &DAT_ffffbaa0;
    DAT_ffffba9c = 0;
    DAT_ffffba9e = 0;
    DAT_ffffbaa0 = 1;
  }
  return puVar1;
}


