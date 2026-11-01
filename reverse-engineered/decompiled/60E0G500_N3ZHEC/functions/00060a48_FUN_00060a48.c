/* ROM address: 0x00060a48; body bytes: 36; decompiled */

void FUN_00060a48(uint param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  
  uVar1 = *(ushort *)(&DAT_0007daea + (param_1 & 0xffff) * 2);
  uVar2 = FUN_00061fa4((int)(short)uVar1);
  (&DAT_ffffd638)[uVar1] = uVar2;
  return;
}


