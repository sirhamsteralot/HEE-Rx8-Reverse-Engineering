/* ROM address: 0x0001bcac; body bytes: 142; decompiled */

void FUN_0001bcac(void)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_0003eaa4(&DAT_ffff8788,1);
  if (cVar1 == '\x01') {
    FUN_0003ebc0(&DAT_ffff80c4,0);
    FUN_0003ebc0(&DAT_ffff80ca,0);
    uVar2 = 0;
    DAT_ffffaddb = 0;
    FUN_0003ec20(0,&DAT_ffff80d4);
    FUN_0003ec20(uVar2,&DAT_ffff80dc);
  }
  DAT_ffffae45 = FUN_0003eaa4(&DAT_ffff80c4,0);
  DAT_ffffae46 = FUN_0003eaa4(&DAT_ffff80c6,0);
  DAT_ffffadd0 = FUN_0003eb72(0x41700000,&DAT_ffff80a4);
  DAT_ffffadf0 = FUN_0003eb72(0x41700000,&DAT_ffff80ac);
  DAT_ffffadd8 = 0;
  DAT_ffffadd4 = DAT_ffff9f08;
  DAT_ffffadd6 = DAT_ffff9f0a;
  return;
}


