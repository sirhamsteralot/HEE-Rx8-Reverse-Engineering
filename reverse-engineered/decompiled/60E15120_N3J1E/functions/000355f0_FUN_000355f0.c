/* [ADDITIONAL SOURCE REVIEW]
 * immo_can_command_decode [high]: Pool words at 0x356b6-0x356d2 re-read from ROM: 0xc4bf (pending flag), 0xc4b9 (cmd), 0xc4ba/0xc4bb (data/sub), 0xc4bc/0xc4bd, compare consts 0x0090/0x00c9/0x00ff, store longs 0xffffc21e/0xffffc221/0xffffc204. Semantics (decompiled + disasm + emulator): c4bf must be 1; cmd 0 -> c21e=0; cmd 6 -> sub c4ba: (0,0xff)->c21e=1,c221=1, (1,0xff)->c21e=1,c221=3, 0x7f->c21e=1,c221=2 (seed request), else c21e=6; cmd 8 -> c21e=2, c204=BE32(c4ba..c4bd) (challenge word); cmd 0x90 -> c4ba in 1..4 -> c21e=4, c1ec=BE32(c4ba..c4bd) (key word incl. tag byte), else c21e=6; cmd 0xc9 -> c21e=3; no/other -> c21e=5; clears c4bf. Dynamically verified: cmd 6/0x7f, 8, 0xc9, 0x90 all decoded as above in the emulator.
 * RAM 0xffffc1ec immo_received_key_word (u32): emulator: c1ec echoed the sent word
 * RAM 0xffffc204 immo_challenge_received (u32): emulator: c204=0xdeadbeef after wrong challenge -> bad state
 * RAM 0xffffc21e immo_command_substate (u8): 0 idle, 1 wait-key, 2 challenge, 3 key-exchange, 4 key-word, 5 no-command, 6 error
 * RAM 0xffffc221 immo_request_subtype (u8): 2 = seed request (triggers seed TX + c21d=2)
 */
/* ROM address: 0x000355f0; body bytes: 298; decompiled */

undefined ** immo_can_command_decode(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = (undefined **)(uint)immo_rx_command_pending_ffffc4bf;
  if (ppuVar1 == (undefined **)((int)&vector_Poweron_Reset + 1)) {
    ppuVar1 = (undefined **)(uint)immo_rx_command_ffffc4b9;
    if (ppuVar1 == (undefined **)0x0) {
      immo_command_substate_ffffc21e = 0;
    }
    else if (ppuVar1 == (undefined **)&UNK_00000006) {
      immo_command_substate_ffffc21e = 1;
      if ((immo_rx_data_ffffc4ba == 0) && (DAT_ffffc4bb == 0xff)) {
        immo_request_subtype_ffffc221 = 1;
        ppuVar1 = (undefined **)0xff;
      }
      else if ((immo_rx_data_ffffc4ba == 1) && (DAT_ffffc4bb == 0xff)) {
        immo_request_subtype_ffffc221 = 3;
        ppuVar1 = (undefined **)((int)&vector_Poweron_Reset + 1);
      }
      else {
        ppuVar1 = (undefined **)(uint)immo_rx_data_ffffc4ba;
        if (ppuVar1 == (undefined **)0x7f) {
          immo_request_subtype_ffffc221 = 2;
        }
        else {
          immo_command_substate_ffffc21e = 6;
        }
      }
    }
    else if (ppuVar1 == &vector_Manual_Reset) {
      immo_command_substate_ffffc21e = 2;
      immo_challenge_received_ffffc204 = (uint)immo_rx_data_ffffc4ba * 0x1000000 + (uint)DAT_ffffc4bb * 0x10000 +
                     (uint)DAT_ffffc4bc * 0x100 + (uint)DAT_ffffc4bd;
      ppuVar1 = (undefined **)&immo_challenge_received_ffffc204;
    }
    else if (ppuVar1 == (undefined **)0x90) {
      ppuVar1 = (undefined **)(uint)immo_rx_data_ffffc4ba;
      if ((((ppuVar1 == (undefined **)((int)&vector_Poweron_Reset + 1)) ||
           (ppuVar1 == (undefined **)((int)&vector_Poweron_Reset + 2))) ||
          (ppuVar1 == (undefined **)((int)&vector_Poweron_Reset + 3))) ||
         (ppuVar1 == (undefined **)&UNK_00000004)) {
        immo_command_substate_ffffc21e = 4;
        immo_received_key_word_ffffc1ec = (uint)immo_rx_data_ffffc4ba * 0x1000000 + (uint)DAT_ffffc4bb * 0x10000 +
                       (uint)DAT_ffffc4bc * 0x100 + (uint)DAT_ffffc4bd;
        ppuVar1 = (undefined **)&immo_received_key_word_ffffc1ec;
      }
      else {
        immo_command_substate_ffffc21e = 6;
      }
    }
    else if (ppuVar1 == (undefined **)0xc9) {
      immo_command_substate_ffffc21e = 3;
    }
    else {
      immo_command_substate_ffffc21e = 6;
    }
  }
  else {
    immo_command_substate_ffffc21e = 5;
  }
  immo_rx_command_pending_ffffc4bf = 0;
  return ppuVar1;
}


