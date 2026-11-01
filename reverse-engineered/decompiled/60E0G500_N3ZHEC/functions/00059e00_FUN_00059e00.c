/* ROM address: 0x00059e00; body bytes: 228; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00059e1c) */
/* WARNING: Removing unreachable block (ram,0x00059e28) */
/* WARNING: Removing unreachable block (ram,0x00059e30) */
/* WARNING: Removing unreachable block (ram,0x00059e4c) */
/* WARNING: Removing unreachable block (ram,0x00059e58) */
/* WARNING: Removing unreachable block (ram,0x00059e60) */
/* WARNING: Removing unreachable block (ram,0x00059e7c) */
/* WARNING: Removing unreachable block (ram,0x00059e88) */
/* WARNING: Removing unreachable block (ram,0x00059e90) */

undefined1 * FUN_00059e00(void)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)0x1;
  if (((DAT_ffffd290 == '\x01') || (puVar1 = (undefined1 *)0x1, DAT_ffffd291 == '\x01')) ||
     (puVar1 = (undefined1 *)(uint)DAT_ffffd292, puVar1 == (undefined1 *)0x1)) {
    DAT_ffffd298 = 1;
  }
  if (DAT_ffffd2b9 != '\0') {
    puVar1 = &DAT_ffffd293;
    DAT_ffffd293 = 1;
    DAT_ffffd294 = 1;
    DAT_ffffd295 = 1;
  }
  DAT_ffffd2b9 = 0;
  return puVar1;
}


