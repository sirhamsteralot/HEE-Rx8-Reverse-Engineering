/* ROM address: 0x00003c68; body bytes: 16; decompiled */

void os_dispatch_next_task(int param_1)

{
  os_switch_to_task(param_1,(int)*(short *)(param_1 + 6));
  return;
}


