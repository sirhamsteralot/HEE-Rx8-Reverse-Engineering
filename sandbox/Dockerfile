# syntax=docker/dockerfile:1
# Toolchain sandbox for this repo. The build context is this `sandbox/`
# directory (see compose.yaml), so the ~500 MB repo is bind-mounted at run time
# instead of being copied into the image.
#
# What the repo needs at run time — README.md "Quick start" plus AGENTS.md
# "Verification":
#   python3 (+ pytest) - tests/, utilities/scripts/; every other import in the
#                        tree is standard library
#   git + git-lfs      - submodules and the LFS-backed ROMs/PDFs/backups
#   gcc / make         - reverse-engineered/reimplementation host tests
#   JDK 21+            - utilities/README.md:18-19, docs/investigations/
#                        60E15120_N3J1E/README.md:476 (Ghidra 12.1.3 needs it)
#   Ghidra 12.1.3      - optional, staged from ghidra-dist/ (see below)
FROM python:3.13-slim-trixie

ARG DEBIAN_FRONTEND=noninteractive
# Match the host account so files written into the bind-mounted repo keep host
# ownership: SANDBOX_UID=$(id -u) SANDBOX_GID=$(id -g) docker compose build
ARG USER_UID=1000
ARG USER_GID=1000

RUN apt-get update && apt-get install -y --no-install-recommends \
      build-essential \
      ca-certificates \
      curl \
      git \
      git-lfs \
      less \
      openjdk-21-jdk-headless \
      unzip \
      vim-tiny \
    && rm -rf /var/lib/apt/lists/*

# pytest is the only non-stdlib import in tests/ and utilities/; pin it to the
# version the suite is verified against.
RUN python -m pip install --no-cache-dir "pytest==9.2.0"

# LFS materialization for clones made inside the sandbox, and git's ownership
# check for the bind-mounted working tree.
RUN git lfs install --system \
 && git config --system --add safe.directory '*'

# Optional Ghidra layer. fetch-ghidra.sh stages the official distribution zip
# plus its SHA256SUMS here; with nothing staged the image just lacks Ghidra and
# everything except rebuild.sh runs as usual.
COPY ghidra-dist/ /tmp/ghidra-dist/
RUN set -eux; \
    if ls /tmp/ghidra-dist/*.zip >/dev/null 2>&1; then \
      cd /tmp/ghidra-dist; \
      if [ -f SHA256SUMS ]; then sha256sum -c SHA256SUMS; fi; \
      unzip -q ./*.zip -d /opt; \
      set -- /opt/ghidra_*_PUBLIC; \
      mv "$1" /opt/ghidra; \
    fi; \
    rm -rf /tmp/ghidra-dist
ENV GHIDRA_HOME=/opt/ghidra

RUN groupadd --gid "${USER_GID}" dev \
 && useradd --uid "${USER_UID}" --gid "${USER_GID}" --create-home \
      --shell /bin/bash dev \
 && mkdir -p /home/dev/.cache/pip /home/dev/.config/ghidra \
 && chown -R dev:dev /home/dev \
 && if [ -d /opt/ghidra ]; then chown -R dev:dev /opt/ghidra; fi

ENV HOME=/home/dev \
    PYTHONUNBUFFERED=1 \
    PIP_DISABLE_PIP_VERSION_CHECK=1

# rebuild.sh writes the SH-2E processor config into $GHIDRA_HOME
# (utilities/scripts/rx8-pcm-pipeline/rebuild.sh), hence the dev-owned install.
USER dev
WORKDIR /work/repo
CMD ["bash"]
