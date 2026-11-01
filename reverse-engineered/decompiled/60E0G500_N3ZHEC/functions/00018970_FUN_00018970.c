/* ROM address: 0x00018970; body bytes: 84; decompiled */

undefined1 * FUN_00018970(void)

{
  undefined1 *puVar1;
  undefined4 local_c [2];
  
  if (DAT_ffffa980 == '\x01') {
    FUN_0003ebc0(&DAT_ffff807c,1);
    local_c[0] = 0;
    FUN_00009630(0,3,local_c);
    DAT_ffffa980 = '\x02';
  }
  puVar1 = &DAT_ffffa8f1;
  if (DAT_ffffa974 == DAT_ffffa8f1) {
    DAT_ffffa97b = 0x30;
    DAT_ffffa980 = '\x01';
  }
  else {
    puVar1 = (undefined1 *)FUN_00018756((int)DAT_ffffa984);
  }
  return puVar1;
}


