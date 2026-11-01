/* ROM address: 0x000684e8; body bytes: 28; decompiled */

void FUN_000684e8(byte param_1)

{
  int iVar1;
  
  iVar1 = (uint)param_1 * 0x46c;
  *(undefined2 *)(&DAT_ffffd998 + iVar1) = 0;
  *(undefined2 *)(&DAT_ffffd99a + iVar1) = 0;
  *(undefined2 *)(&DAT_ffffd99c + iVar1) = 0;
  return;
}


