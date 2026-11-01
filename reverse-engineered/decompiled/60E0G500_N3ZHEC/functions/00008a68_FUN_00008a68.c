/* ROM address: 0x00008a68; body bytes: 192; decompiled */

void injector_pulse_set_channel(uint param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_20;
  short sStack_1c;
  undefined *puStack_18;
  
  iVar3 = (param_1 & 0xff) * 0x18;
  puStack_18 = &DAT_ffffa004 + iVar3;
  sStack_1c = (short)((&DAT_ffffa094)[param_1 & 0xff] + *(int *)(&DAT_ffffa010 + iVar3) >> 4);
  FUN_00002054(&local_20,0xe0);
  sVar1 = DAT_fffff440;
  uVar4 = param_1 & 0xff;
  if (0x7fff < (ushort)(*(short *)(puStack_18 + 0x10) - (sVar1 + 3))) {
    *(short *)(&DAT_ffffa014 + (param_1 & 0xff) * 0x18) = sVar1 + 3;
  }
  iVar3 = (param_1 & 0xff) * 0x18;
  *(undefined2 *)(&PTR_DAT_0000d7d8)[uVar4 * 3] = *(undefined2 *)(&DAT_ffffa014 + iVar3);
  FUN_0000a8a4((&PTR_DAT_0000d7d4)[uVar4 * 3],(int)sStack_1c);
  (&DAT_ffffa016)[iVar3] = 0;
  uVar2 = DAT_fffff66c;
  DAT_fffff66c = ~*(ushort *)(&PTR_DAT_0000d7dc + uVar4 * 3) & uVar2;
  (&DAT_ffffa018)[iVar3] = 0;
  FUN_00002064(local_20);
  return;
}


