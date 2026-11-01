/* ROM address: 0x00010ea8; body bytes: 38; decompiled */

int FUN_00010ea8(void)

{
  ushort uVar1;
  
  uVar1 = DAT_ffffa5d8;
  if (DAT_ffffa578 == '\0') {
    uVar1 = DAT_ffffa5d8 | DAT_ffffa5da;
  }
  if (DAT_ffffa5a4 == '\0') {
    uVar1 = uVar1 | DAT_ffffa5dc;
  }
  return (int)(short)uVar1;
}


