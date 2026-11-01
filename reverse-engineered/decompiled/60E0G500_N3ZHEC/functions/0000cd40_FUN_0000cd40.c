/* ROM address: 0x0000cd40; body bytes: 34; decompiled */

byte can_mailbox_dlc(byte param_1)

{
  int iVar1;
  
  iVar1 = can_mailbox_reg_addr((int)(char)param_1,&DAT_ffffe420);
  return *(byte *)(iVar1 + (param_1 & 0xf) * 8) & 0xf;
}


