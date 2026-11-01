/* ROM address: 0x0000cc46; body bytes: 94; decompiled */

void FUN_0000cc46(char param_1,uint param_2)

{
  ushort uVar1;
  short *psVar2;
  
  psVar2 = (short *)FUN_0000cefe((int)param_1,&DAT_ffffe41e);
  uVar1 = (ushort)(param_2 >> 0x10);
  *psVar2 = (short)((param_2 >> 0x12 & 7) << 0xd) + (uVar1 & 3) * 0x100 + (uVar1 >> 5 & 0xff);
  psVar2 = (short *)FUN_0000cefe((int)param_1,&DAT_ffffe41c);
  *psVar2 = (short)param_2 * 0x100 + ((ushort)(param_2 >> 8) & 0xff);
  return;
}


