/* ROM address: 0x000630e0; body bytes: 242; decompiled */

uint FUN_000630e0(void)

{
  short sVar1;
  char cVar2;
  uint uVar3;
  
  sVar1 = FUN_00002034(&DAT_ffff87c4);
  if (((((sVar1 == 0) && (sVar1 = FUN_00002034(&DAT_ffff87c8), sVar1 == 0)) &&
       (sVar1 = FUN_00002034(&DAT_ffff87b8), sVar1 == 0)) &&
      (((sVar1 = FUN_00002034(&DAT_ffff87bc), sVar1 == 0 &&
        (cVar2 = FUN_00002044(&DAT_ffff87c0), cVar2 == '\0')) &&
       ((cVar2 = FUN_00002044(&DAT_ffff87cc), cVar2 == '\0' &&
        ((cVar2 = FUN_00002044(&DAT_ffff87ce), cVar2 == '\0' &&
         (cVar2 = FUN_00002044(&DAT_ffff87d2), cVar2 == '\0')))))))) &&
     ((cVar2 = FUN_00002044(&DAT_ffff87d0), cVar2 == '\0' &&
      (cVar2 = FUN_00002044(&DAT_ffff87d4), cVar2 == '\0')))) {
    uVar3 = FUN_00064530();
    if (((((uVar3 & 0xff) == 0) && (uVar3 = FUN_000633b4(), (uVar3 & 0xff) == 0)) &&
        (uVar3 = FUN_00063ce4(), (uVar3 & 0xff) == 0)) &&
       (uVar3 = FUN_00067b84(), (uVar3 & 0xff) == 0)) {
      uVar3 = FUN_00068134();
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


