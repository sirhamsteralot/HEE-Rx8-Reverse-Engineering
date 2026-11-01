/* ROM address: 0x0005ec56; body bytes: 110; decompiled */

undefined4 FUN_0005ec56(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar5;
  undefined4 uVar4;
  
  cVar5 = FUN_0003eaa4(&DAT_ffff9198,0xff);
  uVar4 = FUN_0003eaa4(&DAT_ffff919a,0xff);
  bVar3 = DAT_ffffd3c5;
  bVar2 = DAT_ffffd3c4;
  if (DAT_ffffd3ce == '\0') {
    bVar1 = DAT_ffffd3cd ^ DAT_ffffd3c5;
    FUN_0003ebc0(&DAT_ffff9198,~(int)(char)(DAT_ffffd3cc ^ DAT_ffffd3c4) & (int)cVar5);
    uVar4 = FUN_0003ebc0(&DAT_ffff919a,(int)(char)(~bVar1 & (byte)uVar4));
  }
  else {
    DAT_ffffd3ce = DAT_ffffd3ce + -1;
  }
  DAT_ffffd3cc = bVar2;
  DAT_ffffd3cd = bVar3;
  return uVar4;
}


