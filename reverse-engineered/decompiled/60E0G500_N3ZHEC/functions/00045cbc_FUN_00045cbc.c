/* ROM address: 0x00045cbc; body bytes: 72; decompiled */

uint FUN_00045cbc(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_0003eaa4(&DAT_ffff8788,1);
  if (cVar2 == '\x01') {
    FUN_0003ebc0(&DAT_ffff8750,0);
  }
  DAT_ffffcc16 = DAT_ffffadd4;
  DAT_ffffcc24 = DAT_ffffadd4;
  DAT_ffffcc26 = DAT_ffffadd4;
  uVar1 = (uint)DAT_ffffb53c;
  DAT_ffffcc2a = (uint)(int)DAT_ffffadd4 < uVar1;
  if ((bool)DAT_ffffcc2a) {
    uVar1 = 1;
  }
  return uVar1;
}


