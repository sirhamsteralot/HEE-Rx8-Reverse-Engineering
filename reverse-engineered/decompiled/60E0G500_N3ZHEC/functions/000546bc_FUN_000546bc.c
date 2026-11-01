/* ROM address: 0x000546bc; body bytes: 82; decompiled */

undefined4 FUN_000546bc(void)

{
  char cVar1;
  
  cVar1 = FUN_00060194(3,0);
  if ((((cVar1 != '\x01') && (cVar1 = FUN_00060194(4,0), cVar1 != '\x01')) &&
      (cVar1 = FUN_00060194(5,0), cVar1 != '\x01')) && (cVar1 = FUN_00060194(6,0), cVar1 != '\x01'))
  {
    DAT_ffffd1e4 = 0;
    return 0;
  }
  DAT_ffffd1e4 = 1;
  return 1;
}


