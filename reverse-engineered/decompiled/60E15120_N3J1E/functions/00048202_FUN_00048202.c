/* ROM address: 0x00048202; body bytes: 562; decompiled */

undefined2 * FUN_00048202(void)

{
  char cVar2;
  undefined2 *puVar1;
  undefined2 *puVar3;
  
  if (DAT_ffffcca4 == '\x01') {
    DAT_ffffcc8c = rx8_add_u16_saturate((int)(short)DAT_ffffcc8c,1);
  }
  else {
    DAT_ffffcc8c = 0;
  }
  if ((((((((((DAT_ffffcc1c == '\x01') && (DAT_ffffb4f4 == '\x01')) && (DAT_ffffb4f6 == '\x01')) &&
           ((DAT_ffffb4f8 == '\x01' && (DAT_ffffb4fa == '\x01')))) &&
          ((DAT_ffffb4fe == '\x01' && ((DAT_ffffb4fc == '\x01' && (DAT_ffffcc5d == '\x01')))))) &&
         (DAT_ffffcbf4 == '\x01')) &&
        (((DAT_ffffcbf5 == '\x01' && (DAT_ffffcc00 == '\x01')) && (DAT_ffffcc01 == '\x01')))) &&
       (((DAT_ffffcbec == '\x01' && (DAT_ffffcbd4 == '\x01')) &&
        ((DAT_ffffb50d == '\x01' && ((DAT_ffffcc6d == '\x01' && (DAT_ffffcc14 == '\x01')))))))) &&
      (((DAT_ffffb4f1 == '\x01' &&
        (((DAT_ffffb519 == '\x01' && (DAT_ffffb501 == '\x01')) && (DAT_ffffb504 == '\x01')))) &&
       (((DAT_ffffb506 == '\x01' && (DAT_ffffb508 == '\x01')) &&
        (((DAT_ffffb50b == '\x01' && ((DAT_ffffb515 == '\x01' && (DAT_ffffb517 == '\x01')))) &&
         (DAT_ffffb50f == '\x01')))))))) &&
     (((((DAT_ffffb511 == '\x01' && (DAT_ffffb513 == '\x01')) && (DAT_ffffcc64 == '\x01')) &&
       ((DAT_ffffcc68 == '\x01' && (DAT_ffffcc4a == '\x01')))) && (DAT_ffffcc4b == '\x01')))) {
    puVar3 = (undefined2 *)((int)&vector_Poweron_Reset + 1);
  }
  else {
    puVar3 = (undefined2 *)0x0;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff875c,0);
  puVar1 = (undefined2 *)((int)&vector_Poweron_Reset + 1);
  if (((cVar2 == '\x01') || (puVar1 = &DAT_0007c6a0, 0x270 < DAT_ffffcc8c)) ||
     (puVar1 = puVar3, puVar3 == (undefined2 *)((int)&vector_Poweron_Reset + 1))) {
    DAT_ffffcca4 = '\0';
  }
  return puVar1;
}


