"""Emulator profiles: one JSON per ROM / market / model variant.

A profile selects the ROM image (path + SHA-256, verified at load), the memory
map, and which SH7055 peripherals exist with what configuration — so different
RX-8 markets/types/models (USDM/JDM/EU, 4-/6-port, MT/AT, DSC/RKE/immo options)
run the same emulator core against different bins with different peripherals.

Add a new variant by copying profiles/template.json — see profiles/README.md.
"""
import hashlib
import json
import os

REQUIRED = ["name", "rom", "memory", "peripherals"]


class ProfileError(Exception):
    pass


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def load_profile(path, repo_root):
    with open(path, encoding="utf-8") as f:
        prof = json.load(f)
    for key in REQUIRED:
        if key not in prof:
            raise ProfileError(f"{path}: missing required key '{key}'")
    rom = prof["rom"]
    rom_path = os.path.join(repo_root, rom["path"])
    if not os.path.isfile(rom_path):
        raise ProfileError(f"{path}: ROM not found: {rom_path} (fetch submodules: git submodule update --init --recursive)")
    digest = sha256_file(rom_path)
    if rom.get("sha256") and digest != rom["sha256"]:
        raise ProfileError(f"{path}: ROM SHA-256 mismatch: expected {rom['sha256']}, got {digest}")
    rom["_abs_path"] = rom_path
    rom["_size"] = os.path.getsize(rom_path)
    if rom.get("size") and rom["_size"] != rom["size"]:
        raise ProfileError(f"{path}: ROM size mismatch")
    for p in prof["peripherals"]:
        if "type" not in p or "base" not in p or "size" not in p:
            raise ProfileError(f"{path}: peripheral entries need type/base/size: {p}")
    return prof


def list_profiles(profiles_dir):
    out = []
    for fn in sorted(os.listdir(profiles_dir)):
        if fn.endswith(".json") and fn != "template.json":
            out.append(os.path.join(profiles_dir, fn))
    return out
