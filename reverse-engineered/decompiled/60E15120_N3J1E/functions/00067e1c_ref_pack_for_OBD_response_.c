/* ROM address: 0x00067e1c; body bytes: 92; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006670c (92 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_pack_for_OBD_response_(uint param_1,undefined1 *param_2,ushort param_3)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = (param_1 & 0xff) * 0x46c;
  puVar2 = (ushort *)(&DAT_ffffd95c + iVar3);
  if (param_3 != 0) {
    do {
      if (*(ushort *)(&DAT_ffffd960 + iVar3) != *puVar2) {
        *(undefined1 *)((uint)*puVar2 + iVar3 + -0x269e) = *param_2;
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


