/* ROM address: 0x0006004a; body bytes: 24; decompiled */

void FUN_0006004a(void)

{
  undefined1 *puVar1;
  ushort uVar2;
  
  uVar2 = 0;
  puVar1 = &dtc_transition_state_array_ffffd4e4;
  do {
    uVar2 = uVar2 + 1;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x8c);
  return;
}


