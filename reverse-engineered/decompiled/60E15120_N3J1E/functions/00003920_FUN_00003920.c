/* [CROSS-ECU / RX8DEFS REVIEW]
 * sh_raise_interrupt_mask_return_previous [assembly_verified]: 0x3922 reads SR; saves SR&0xf0; if requested mask is greater, delay-slot instruction 0x392c loads argument into SR. Raw C omits this side effect. This is not a pure function despite the exported C body.
 */
/* ROM address: 0x00003920; body bytes: 18; decompiled */

uint sh_raise_interrupt_mask_return_previous(uint param_1)

{
  uint uVar1;
  uint in_sr;
  
  uVar1 = in_sr & 0xf0;
  if (uVar1 < param_1) {
    return uVar1;
  }
  return uVar1;
}


