/* ROM address: 0x0004c0a8; body bytes: 256; decompiled */

char FUN_0004c0a8(void)

{
  char cVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffce9d = 0;
    DAT_ffffce9a = '\0';
    DAT_ffffce9b = '\0';
    DAT_ffffce9c = '\0';
    DAT_ffffce99 = 0;
    cVar1 = '\x01';
  }
  else {
    if ((((1 < DAT_ffffce93) && (cVar1 = ref_getFaultStatus__(0x54), cVar1 == '\0')) &&
        (cVar1 = ref_getFaultStatus__(0x55), cVar1 == '\0')) &&
       (cVar1 = ref_getFaultStatus__(0x56), cVar1 == '\0')) {
      DAT_ffffce9d = 1;
      DAT_ffffce9a = '\0';
      DAT_ffffce9b = '\0';
      DAT_ffffce9c = '\0';
      DAT_ffffce99 = 0;
    }
    if ((9 < DAT_ffffce90) && (cVar1 = ref_getFaultStatus__(0x55), cVar1 == '\0')) {
      DAT_ffffce9a = '\x01';
    }
    if ((9 < DAT_ffffce91) && (cVar1 = ref_getFaultStatus__(0x56), cVar1 == '\0')) {
      DAT_ffffce9b = '\x01';
    }
    if ((9 < DAT_ffffce92) && (cVar1 = ref_getFaultStatus__(0x54), cVar1 == '\0')) {
      DAT_ffffce9c = '\x01';
    }
    cVar1 = '\x01';
    if (((DAT_ffffce9a == '\x01') || (cVar1 = '\x01', DAT_ffffce9b == '\x01')) ||
       (cVar1 = DAT_ffffce9c, DAT_ffffce9c == '\x01')) {
      DAT_ffffce99 = 1;
      DAT_ffffce9d = 0;
    }
  }
  return cVar1;
}


