/* ROM address: 0x00032208; body bytes: 172; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00032238) */
/* WARNING: Removing unreachable block (ram,0x00032240) */
/* WARNING: Removing unreachable block (ram,0x0003224e) */
/* WARNING: Removing unreachable block (ram,0x00032256) */
/* WARNING: Removing unreachable block (ram,0x00032262) */

void FUN_00032208(void)

{
  float arg1;
  
  if (((DAT_ffffa6b7 == '\x01') || (DAT_ffffa6b8 == '\x01')) || (DAT_ffffa6b9 == '\x01')) {
    DAT_ffffbfcc = DAT_ffffbfb0;
  }
  else {
    DAT_ffffbfcc = 0.0;
  }
  if (DAT_ffffa9e4 == '\0') {
    DAT_ffffbfa8 = 0.0;
  }
  else {
    arg1 = (float)FUN_00002068(DAT_ffffaa10,&DAT_0006b180);
    DAT_ffffbfa8 = rx8_min_float(DAT_ffffbfcc,arg1);
  }
  return;
}


