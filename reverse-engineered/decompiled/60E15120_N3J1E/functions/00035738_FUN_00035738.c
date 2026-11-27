/* [ADDITIONAL SOURCE REVIEW]
 * immo_tx_frame_build [high]: 220 B. Builds the 8-byte TX frame at 0xffffc1c8..c1cf and sets c1d1=1, c21f=0, c226=0, c229=1. param 7 -> [07][c208 BE]; param 9 -> [09][c220][key word c1dc/c1e0/c1e4/c1e8 BE per c220 1..4; c220=0xff -> zeros]; param 1 or 0x81 -> [cmd][c224 (0x7f OK / 0x80 / 0x81 NG)][0...]; param 0xc6/0xc8 -> zeros; other -> zero tail. Byte order verified dynamically: TX buffer c4a8..c4af = 09 01 77 b2 76 00 00 00 after cmd 9 with c220=1.
 * RAM 0xffffc224 immo_status_code (u8): 0x7f authorized, 0x80 battery/timeout reject, 0x81 challenge/key reject
 */
/* ROM address: 0x00035738; body bytes: 220; decompiled */

void immo_tx_frame_build(char param_1)

{
  undefined4 *puVar1;
  
  immo_tx_frame_ffffc1c8 = param_1;
  if (param_1 == '\t') {
    if (immo_key_word_index_ffffc220 == '\x01') {
      DAT_ffffc1c9 = immo_key_word_index_ffffc220;
      puVar1 = &immo_computed_key_words_ffffc1dc;
    }
    else if (immo_key_word_index_ffffc220 == '\x02') {
      DAT_ffffc1c9 = immo_key_word_index_ffffc220;
      puVar1 = &DAT_ffffc1e0;
    }
    else if (immo_key_word_index_ffffc220 == '\x03') {
      DAT_ffffc1c9 = immo_key_word_index_ffffc220;
      puVar1 = &DAT_ffffc1e4;
    }
    else {
      if (immo_key_word_index_ffffc220 != '\x04') {
        if (immo_key_word_index_ffffc220 != -1) {
          DAT_ffffc1cd = 0;
          DAT_ffffc1ce = 0;
          DAT_ffffc1cf = 0;
          immo_tx_frame_valid_ffffc1d1 = 1;
          immo_fail_counter_ffffc21f = 0;
          immo_authorized_latch_flag_ffffc226 = 0;
          DAT_ffffc229 = 1;
          return;
        }
        DAT_ffffc1c9 = immo_key_word_index_ffffc220;
        DAT_ffffc1ca = 0;
        DAT_ffffc1cb = 0;
        DAT_ffffc1cc = 0;
        DAT_ffffc1cd = 0;
        DAT_ffffc1ce = 0;
        DAT_ffffc1cf = 0;
        immo_tx_frame_valid_ffffc1d1 = 1;
        immo_fail_counter_ffffc21f = 0;
        immo_authorized_latch_flag_ffffc226 = 0;
        DAT_ffffc229 = 1;
        return;
      }
      DAT_ffffc1c9 = immo_key_word_index_ffffc220;
      puVar1 = &DAT_ffffc1e8;
    }
  }
  else {
    if (param_1 != '\a') {
      if ((param_1 == '\x01') || (param_1 == -0x7f)) {
        DAT_ffffc1c9 = immo_status_code_ffffc224;
        DAT_ffffc1ca = 0;
        DAT_ffffc1cb = 0;
        DAT_ffffc1cc = 0;
        DAT_ffffc1cd = 0;
        DAT_ffffc1ce = 0;
        DAT_ffffc1cf = 0;
        immo_tx_frame_valid_ffffc1d1 = 1;
        immo_fail_counter_ffffc21f = 0;
        immo_authorized_latch_flag_ffffc226 = 0;
        DAT_ffffc229 = 1;
        return;
      }
      if ((param_1 != -0x3a) && (param_1 != -0x38)) {
        DAT_ffffc1cd = 0;
        DAT_ffffc1ce = 0;
        DAT_ffffc1cf = 0;
        immo_tx_frame_valid_ffffc1d1 = 1;
        immo_fail_counter_ffffc21f = 0;
        immo_authorized_latch_flag_ffffc226 = 0;
        DAT_ffffc229 = 1;
        return;
      }
      DAT_ffffc1c9 = 0;
      DAT_ffffc1ca = 0;
      DAT_ffffc1cb = 0;
      DAT_ffffc1cc = 0;
      DAT_ffffc1cd = 0;
      DAT_ffffc1ce = 0;
      DAT_ffffc1cf = 0;
      immo_tx_frame_valid_ffffc1d1 = 1;
      immo_fail_counter_ffffc21f = 0;
      immo_authorized_latch_flag_ffffc226 = 0;
      DAT_ffffc229 = 1;
      return;
    }
    puVar1 = &immo_random_seed_ffffc208;
    DAT_ffffc1c9 = (char)((uint)immo_random_seed_ffffc208 >> 0x18);
  }
  DAT_ffffc1cc = *(undefined1 *)((int)puVar1 + 3);
  DAT_ffffc1cb = (char)((uint)*puVar1 >> 8);
  DAT_ffffc1ca = (char)((uint)*puVar1 >> 0x10);
  DAT_ffffc1cd = 0;
  DAT_ffffc1ce = 0;
  DAT_ffffc1cf = 0;
  immo_tx_frame_valid_ffffc1d1 = 1;
  immo_authorized_latch_flag_ffffc226 = 0;
  immo_fail_counter_ffffc21f = 0;
  DAT_ffffc229 = 1;
  return;
}


