"""ISO-TP (ISO 15765-2) framing over CAN — pure functions, unit-tested.

Used by the virtual OBD port (obd_port.py) to carry UDS payloads on the
emulated CAN bus (diag IDs from the profile, default 0x7E0 req / 0x7E8 resp).
"""

SF = 0x0   # single frame
FF = 0x1   # first frame
CF = 0x2   # consecutive frame
FC = 0x3   # flow control


def encode(payload, can_id):
    """UDS payload bytes -> list of (can_id, data bytes) CAN frames."""
    n = len(payload)
    if n <= 7:
        return [(can_id, bytes([SF << 4 | n]) + payload + b"\x00" * (7 - n))]
    frames = [(can_id, bytes([FF << 4 | (n >> 8) & 0xF, n & 0xFF]) + payload[:6])]
    seq = 1
    i = 6
    while i < n:
        chunk = payload[i:i + 7]
        frames.append((can_id, bytes([CF << 4 | (seq & 0xF)]) + chunk + b"\x00" * (7 - len(chunk))))
        seq = (seq + 1) & 0xF
        i += 7
    return frames


class Reassembler:
    """Reassemble ISO-TP payloads from CAN frames (one per direction)."""

    def __init__(self):
        self.buf = bytearray()
        self.expected = 0
        self.next_seq = 1

    def feed(self, data):
        """Feed one CAN frame's 8 data bytes; return complete payload or None."""
        if not data:
            return None
        pci = data[0] >> 4
        if pci == SF:
            return bytes(data[1:1 + (data[0] & 0xF)])
        if pci == FF:
            self.expected = ((data[0] & 0xF) << 8) | data[1]
            self.buf = bytearray(data[2:8])
            self.next_seq = 1
            if len(self.buf) >= self.expected:
                return bytes(self.buf[:self.expected])
            return None
        if pci == CF:
            if (data[0] & 0xF) != self.next_seq:
                self.buf = bytearray()
                return None
            self.next_seq = (self.next_seq + 1) & 0xF
            self.buf += data[1:8]
            if len(self.buf) >= self.expected:
                return bytes(self.buf[:self.expected])
            return None
        return None  # flow control etc.
