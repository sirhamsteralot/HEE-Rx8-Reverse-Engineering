/* ROM address: 0x0003b0a2; body bytes: 86; decompiled */

uint FUN_0003b0a2(void)

{
  char cVar1;
  uint uVar2;
  undefined4 local_10 [2];
  
  cVar1 = DAT_ffffd000;
  if ((DAT_ffffc598 == 0) && (DAT_ffffd000 == '\x01')) {
    local_10[0] = 0;
    FUN_00009630(0,2,local_10);
  }
  uVar2 = (uint)DAT_ffffc598;
  if ((uVar2 == 1) && (cVar1 == '\0')) {
    local_10[0] = 0;
    uVar2 = FUN_00009630(0,3,local_10);
  }
  DAT_ffffc598 = cVar1;
  return uVar2;
}


