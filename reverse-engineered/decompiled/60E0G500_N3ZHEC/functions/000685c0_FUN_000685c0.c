/* ROM address: 0x000685c0; body bytes: 92; decompiled */

void FUN_000685c0(uint param_1,undefined1 *param_2,ushort param_3)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = (param_1 & 0xff) * 0x46c;
  puVar2 = (ushort *)(&DAT_ffffd998 + iVar3);
  if (param_3 != 0) {
    do {
      if (*(ushort *)(&DAT_ffffd99c + iVar3) != *puVar2) {
        *(undefined1 *)((uint)*puVar2 + iVar3 + -0x2662) = *param_2;
        *puVar2 = *puVar2 + 1;
        if (0x464 < *puVar2) {
          *puVar2 = 0;
        }
      }
      iVar1 = iVar1 + 1;
      param_2 = param_2 + 1;
    } while (iVar1 < (int)(uint)param_3);
  }
  return;
}


