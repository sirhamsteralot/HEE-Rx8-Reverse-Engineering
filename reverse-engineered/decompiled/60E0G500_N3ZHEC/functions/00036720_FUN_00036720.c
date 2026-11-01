/* ROM address: 0x00036720; body bytes: 220; decompiled */

void FUN_00036720(char param_1)

{
  undefined4 *puVar1;
  
  DAT_ffffc238 = param_1;
  if (param_1 == '\t') {
    if (DAT_ffffc290 == '\x01') {
      DAT_ffffc239 = DAT_ffffc290;
      puVar1 = &DAT_ffffc24c;
    }
    else if (DAT_ffffc290 == '\x02') {
      DAT_ffffc239 = DAT_ffffc290;
      puVar1 = &DAT_ffffc250;
    }
    else if (DAT_ffffc290 == '\x03') {
      DAT_ffffc239 = DAT_ffffc290;
      puVar1 = &DAT_ffffc254;
    }
    else {
      if (DAT_ffffc290 != '\x04') {
        if (DAT_ffffc290 != -1) {
          DAT_ffffc23d = 0;
          DAT_ffffc23e = 0;
          DAT_ffffc23f = 0;
          DAT_ffffc241 = 1;
          DAT_ffffc28f = 0;
          DAT_ffffc296 = 0;
          DAT_ffffc299 = 1;
          return;
        }
        DAT_ffffc239 = DAT_ffffc290;
        DAT_ffffc23a = 0;
        DAT_ffffc23b = 0;
        DAT_ffffc23c = 0;
        DAT_ffffc23d = 0;
        DAT_ffffc23e = 0;
        DAT_ffffc23f = 0;
        DAT_ffffc241 = 1;
        DAT_ffffc28f = 0;
        DAT_ffffc296 = 0;
        DAT_ffffc299 = 1;
        return;
      }
      DAT_ffffc239 = DAT_ffffc290;
      puVar1 = &DAT_ffffc258;
    }
  }
  else {
    if (param_1 != '\a') {
      if ((param_1 == '\x01') || (param_1 == -0x7f)) {
        DAT_ffffc239 = DAT_ffffc294;
        DAT_ffffc23a = 0;
        DAT_ffffc23b = 0;
        DAT_ffffc23c = 0;
        DAT_ffffc23d = 0;
        DAT_ffffc23e = 0;
        DAT_ffffc23f = 0;
        DAT_ffffc241 = 1;
        DAT_ffffc28f = 0;
        DAT_ffffc296 = 0;
        DAT_ffffc299 = 1;
        return;
      }
      if ((param_1 != -0x3a) && (param_1 != -0x38)) {
        DAT_ffffc23d = 0;
        DAT_ffffc23e = 0;
        DAT_ffffc23f = 0;
        DAT_ffffc241 = 1;
        DAT_ffffc28f = 0;
        DAT_ffffc296 = 0;
        DAT_ffffc299 = 1;
        return;
      }
      DAT_ffffc239 = 0;
      DAT_ffffc23a = 0;
      DAT_ffffc23b = 0;
      DAT_ffffc23c = 0;
      DAT_ffffc23d = 0;
      DAT_ffffc23e = 0;
      DAT_ffffc23f = 0;
      DAT_ffffc241 = 1;
      DAT_ffffc28f = 0;
      DAT_ffffc296 = 0;
      DAT_ffffc299 = 1;
      return;
    }
    puVar1 = &DAT_ffffc278;
    DAT_ffffc239 = (char)((uint)DAT_ffffc278 >> 0x18);
  }
  DAT_ffffc23c = *(undefined1 *)((int)puVar1 + 3);
  DAT_ffffc23b = (char)((uint)*puVar1 >> 8);
  DAT_ffffc23a = (char)((uint)*puVar1 >> 0x10);
  DAT_ffffc23d = 0;
  DAT_ffffc23e = 0;
  DAT_ffffc23f = 0;
  DAT_ffffc241 = 1;
  DAT_ffffc296 = 0;
  DAT_ffffc28f = 0;
  DAT_ffffc299 = 1;
  return;
}


