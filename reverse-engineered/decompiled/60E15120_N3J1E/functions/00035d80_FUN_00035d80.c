/* ROM address: 0x00035d80; body bytes: 276; decompiled */

void FUN_00035d80(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  cVar1 = '\x01';
  if (DAT_ffffc262 != '\0') {
    return;
  }
  if (param_1 == '\x01') {
    uVar3 = 2;
    uVar2 = 10;
  }
  else if (param_1 == '\x02') {
    uVar3 = 8;
    uVar2 = 2;
  }
  else if (param_1 == '\r') {
    uVar3 = 2;
    uVar2 = 0x1e;
  }
  else if (param_1 == '\x03') {
    uVar3 = 2;
    uVar2 = 0;
  }
  else if (param_1 == '\x04') {
    uVar3 = 6;
    uVar2 = 0xc;
  }
  else if (param_1 == '\x05') {
    uVar3 = 2;
    uVar2 = 0x12;
  }
  else if (param_1 == '\x06') {
    uVar3 = 2;
    uVar2 = 0xe;
  }
  else if (param_1 == '\a') {
    uVar3 = 4;
    uVar2 = 0x16;
  }
  else if (param_1 == '\b') {
    uVar3 = 2;
    uVar2 = 0x14;
  }
  else if (param_1 == '\f') {
    uVar3 = 0x14;
    uVar2 = 0xc;
  }
  else if (param_1 == '\t') {
    uVar3 = 8;
    uVar2 = 0xc;
  }
  else if (param_1 == '\n') {
    uVar3 = 4;
    uVar2 = 0x1a;
  }
  else if (param_1 == '\v') {
    uVar3 = 10;
    uVar2 = 2;
  }
  else if (param_1 == '\x0e') {
    uVar3 = 2;
    uVar2 = 0xc;
  }
  else if (param_1 == '\x0f') {
    uVar3 = 2;
    uVar2 = 0xe;
  }
  else {
    if (param_1 != -1) goto LAB_00035e8c;
    uVar3 = 0x20;
    uVar2 = 0;
  }
  cVar1 = e2ram_flush_request(uVar2,uVar3,1);
LAB_00035e8c:
  if (cVar1 == '\0') {
    DAT_ffffc262 = '\x01';
  }
  return;
}


