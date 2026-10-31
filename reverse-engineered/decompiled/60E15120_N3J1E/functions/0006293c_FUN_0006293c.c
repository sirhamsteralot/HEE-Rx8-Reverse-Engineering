/* ROM address: 0x0006293c; body bytes: 242; decompiled */

uint FUN_0006293c(void)

{
  short sVar1;
  char cVar2;
  uint uVar3;
  
  sVar1 = FUN_00002034(&DAT_ffff879c);
  if (((((sVar1 == 0) && (sVar1 = FUN_00002034(&DAT_ffff87a0), sVar1 == 0)) &&
       (sVar1 = FUN_00002034(&DAT_ffff8790), sVar1 == 0)) &&
      (((sVar1 = FUN_00002034(&DAT_ffff8794), sVar1 == 0 &&
        (cVar2 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff8798), cVar2 == '\0')) &&
       ((cVar2 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff87a4), cVar2 == '\0' &&
        ((cVar2 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff87a6), cVar2 == '\0' &&
         (cVar2 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff87aa), cVar2 == '\0')))))))) &&
     ((cVar2 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff87a8), cVar2 == '\0' &&
      (cVar2 = ref_invertAndReturn_8bit_ADDR(&DAT_ffff87ac), cVar2 == '\0')))) {
    uVar3 = FUN_00063d8c();
    if (((((uVar3 & 0xff) == 0) && (uVar3 = FUN_00062c10(), (uVar3 & 0xff) == 0)) &&
        (uVar3 = FUN_00063540(), (uVar3 & 0xff) == 0)) &&
       (uVar3 = FUN_000673e0(), (uVar3 & 0xff) == 0)) {
      uVar3 = FUN_00067990();
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


