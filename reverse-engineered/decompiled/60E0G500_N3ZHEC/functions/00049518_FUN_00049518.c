/* ROM address: 0x00049518; body bytes: 166; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00049592) */
/* WARNING: Removing unreachable block (ram,0x0004959e) */
/* WARNING: Removing unreachable block (ram,0x000495b4) */

char FUN_00049518(void)

{
  char cVar1;
  
  if (DAT_ffffb600 < 6.0) {
    DAT_ffffcd02 = 0;
    DAT_ffffcd04 = 0;
  }
  else {
    DAT_ffffcd05 = 1;
    DAT_ffffcd02 = 1;
    if (DAT_ffffcd0a == 0) {
      DAT_ffffcd04 = 1;
    }
    else {
      DAT_ffffcd04 = 0;
    }
  }
  cVar1 = DAT_ffffaae0 == '\x01';
  if (((DAT_ffffaae0 == '\x01') && (cVar1 = DAT_ffffcd01, DAT_ffffcd01 == '\x01')) &&
     (cVar1 = DAT_ffffb55d, DAT_ffffb55d == '\x01')) {
    DAT_ffffcd03 = 1;
  }
  else {
    DAT_ffffcd03 = 0;
  }
  return cVar1;
}


