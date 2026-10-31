/* [CROSS-ECU / RX8DEFS REVIEW]
 * update_serial_command_bits_3_to_5_and_send [assembly_and_dataflow_verified]: Replaces command bits under mask 0x38, then calls 0x7188. Supersedes the inherited interpretation ignitionCoilPulse as a descriptive alias: this routine sends a serial command, not a direct coil pulse. Knock-front-end association is a hypothesis, not established chip identity.
 */
/* ROM address: 0x0000ca7e; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000ca7e (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void update_serial_command_bits_3_to_5_and_send(byte *param_1,byte param_2)

{
  *param_1 = *param_1 & 199 | param_2;
  sci0_configure_sync_and_exchange_command();
  return;
}


