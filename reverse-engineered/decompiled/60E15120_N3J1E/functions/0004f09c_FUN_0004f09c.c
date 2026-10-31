/* ROM address: 0x0004f09c; body bytes: 310; decompiled */

char FUN_0004f09c(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  
  cVar4 = DAT_ffffcfc8;
  cVar3 = DAT_ffffcfc7;
  cVar2 = DAT_ffffcfc6;
  cVar1 = DAT_ffffcfc5;
  cVar6 = -((((int)(char)DAT_ffffcfb5 & 0x80U) == 0) + -1);
  if (((cVar6 == '\x01') &&
      ((((((DAT_ffffcfc5 == '\x01' || (DAT_ffffcfc6 == '\0')) ||
          (cVar5 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a4,0), cVar5 == '\x01')) ||
         ((cVar5 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a0,0), cVar5 == '\x01' ||
          ((DAT_ffffcfd5 == '\0' && (cVar4 == '\x01')))))) ||
        ((DAT_ffffcfd6 == '\0' && (cVar3 == '\x01')))) ||
       (cVar5 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86e2,0), cVar5 == '\x01')))) &&
     (((DAT_ffffd010 == '\0' && (DAT_ffffccc6 == '\0')) &&
      ((DAT_ffffa8ea == '\0' && (DAT_ffffbda0 == '\0')))))) {
    DAT_ffffcfc4 = 0;
    cVar5 = '\0';
  }
  else {
    cVar5 = '\x01';
    if (((((DAT_ffffcfb5 & 0x40) != 0) || (cVar5 = '\x01', (DAT_ffffcfb5 & 0x20) != 0)) ||
        (cVar5 = '\x01', DAT_ffffcfc9 == '\x01')) ||
       (((cVar5 = cVar6, cVar6 == '\x01' && (cVar1 == '\0')) && (cVar5 = cVar2, cVar2 == '\x01'))))
    {
      DAT_ffffcfc4 = 1;
    }
  }
  DAT_ffffcfd5 = cVar4;
  DAT_ffffcfd6 = cVar3;
  return cVar5;
}


