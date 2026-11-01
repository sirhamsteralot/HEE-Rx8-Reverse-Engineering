/* ROM address: 0x000521ac; body bytes: 228; decompiled */

uint FUN_000521ac(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar5;
  char cVar6;
  char cVar7;
  uint uVar3;
  undefined4 uVar4;
  
  bVar5 = FUN_0003eaa4(&DAT_ffff8704,4);
  cVar6 = FUN_0003eaa4(&DAT_ffff86ea,0);
  cVar7 = FUN_0003eaa4(&DAT_ffff86e8,0);
  bVar2 = DAT_ffffd131;
  bVar1 = DAT_ffffd130;
  if (((((bVar5 < DAT_ffffd13e) || ((DAT_ffffd144 == '\0' && (cVar6 == '\x01')))) ||
       ((DAT_ffffd143 == '\0' && (cVar7 == '\x01')))) &&
      ((DAT_ffffcfb4 == '\0' && (DAT_ffffcfc1 == '\0')))) ||
     (uVar3 = (uint)DAT_ffffd201, uVar3 == 1)) {
    uVar3 = FUN_0003ebc0(&DAT_ffff86ee,0);
  }
  else if (((DAT_ffffd140 == '\0') && (uVar3 = (uint)DAT_ffffd130, uVar3 == 1)) ||
          ((DAT_ffffd141 == '\0' && (uVar3 = (uint)DAT_ffffd131, uVar3 == 1)))) {
    uVar4 = FUN_0003eaa4(&DAT_ffff86c4,0);
    uVar3 = FUN_0003ebc0(&DAT_ffff86ee,uVar4);
  }
  DAT_ffffd13e = bVar5;
  DAT_ffffd143 = cVar7;
  DAT_ffffd144 = cVar6;
  DAT_ffffd140 = bVar1;
  DAT_ffffd141 = bVar2;
  return uVar3;
}


