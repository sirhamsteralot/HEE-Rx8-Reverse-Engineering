/* ROM address: 0x00045426; body bytes: 68; decompiled */

void FUN_00045426(byte param_1)

{
  if (param_1 < 4) {
    if ((&DAT_ffffcbba)[param_1] == '\x01') {
      dtc_set_fault_x0((int)*(short *)(&DAT_0004e34c + (uint)param_1 * 2),1);
      return;
    }
    if ((&DAT_ffffcbb6)[param_1] == '\x01') {
      dtc_set_fault_x0((int)*(short *)(&DAT_0004e34c + (uint)param_1 * 2),2);
      return;
    }
  }
  return;
}


