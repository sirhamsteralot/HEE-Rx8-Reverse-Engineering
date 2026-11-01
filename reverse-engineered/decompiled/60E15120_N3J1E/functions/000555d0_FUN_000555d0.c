/* ROM address: 0x000555d0; body bytes: 40; decompiled */

uint diag_read_runtime_s(void)

{
  uint uVar1;
  
  uVar1 = FUN_0000409c((int)engine_runtime_counter_ffffd284_ffffd284);
  if (0xffff < uVar1) {
    uVar1 = 0xffff;
  }
  return uVar1;
}


