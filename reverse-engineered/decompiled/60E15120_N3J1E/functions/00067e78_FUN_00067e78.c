/* ROM address: 0x00067e78; body bytes: 140; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066768 (140 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00067e78(uint param_1,undefined1 *param_2,uint param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = (param_1 & 0xff) * 0x46c;
  puVar2 = param_2;
  if ((param_3 & 0xffff) != 0) {
    do {
      if ((*(ushort *)(&DAT_ffffd960 + iVar3) + 1 == (uint)*(ushort *)(&DAT_ffffd95e + iVar3)) ||
         ((0x463 < *(ushort *)(&DAT_ffffd960 + iVar3) && (*(ushort *)(&DAT_ffffd95e + iVar3) == 0)))
         ) {
        *param_2 = 0;
      }
      else {
        *puVar2 = *(undefined1 *)(iVar3 + -0x269e + (uint)*(ushort *)(&DAT_ffffd95e + iVar3));
        *(short *)(&DAT_ffffd95e + iVar3) = *(short *)(&DAT_ffffd95e + iVar3) + 1;
        if (0x464 < *(ushort *)(&DAT_ffffd95e + iVar3)) {
          *(undefined2 *)(&DAT_ffffd95e + iVar3) = 0;
        }
      }
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    } while (iVar1 < (int)(param_3 & 0xffff));
  }
  return;
}


