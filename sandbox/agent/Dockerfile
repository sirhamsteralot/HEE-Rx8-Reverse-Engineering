# syntax=docker/dockerfile:1
# Two images for running an AI coding agent against this repo behind a
# least-privilege boundary:
#
#   target `agent`  - the box the agent runs in: toolchain + agent CLI, non-root,
#                     no capabilities, read-only root, no host Docker socket,
#                     no network route except the egress proxy.
#   target `egress` - tinyproxy with a default-deny domain allowlist; the only
#                     container with a route off the machine.
#
# The repo's working tree is bind-mounted read-write at /work/repo, so the agent
# works in the checkout itself; nothing of the repo is baked into the image.
# See README.md for the threat model and what this does not protect.

# ---------------------------------------------------------------- egress proxy
FROM debian:trixie-slim AS egress

RUN apt-get update \
 && apt-get install -y --no-install-recommends tinyproxy \
 && rm -rf /var/lib/apt/lists/*

COPY tinyproxy.conf /etc/tinyproxy/tinyproxy.conf
COPY allowlist.txt /etc/tinyproxy/allowlist.txt
# tinyproxy runs unprivileged, so both files must be world-readable.
# A Windows checkout with core.autocrlf hands the build context CRLF files, and
# tinyproxy refuses a config with CR at the end of a directive ("Syntax error on
# line 3"), so normalize the copies instead of depending on how the tree was
# checked out.
RUN sed -i 's/\r$//' /etc/tinyproxy/tinyproxy.conf /etc/tinyproxy/allowlist.txt \
 && chmod 0644 /etc/tinyproxy/tinyproxy.conf /etc/tinyproxy/allowlist.txt

USER tinyproxy
EXPOSE 8888
ENTRYPOINT ["tinyproxy", "-d", "-c", "/etc/tinyproxy/tinyproxy.conf"]

# ------------------------------------------------------------------ agent box
FROM python:3.13-slim-trixie AS agent

ARG DEBIAN_FRONTEND=noninteractive
# Which agent CLI to install. `none` builds the same hardened box without one.
ARG AGENT=vibe
ARG VIBE_VERSION=3.1.4

RUN apt-get update && apt-get install -y --no-install-recommends \
      build-essential \
      ca-certificates \
      curl \
      git \
      git-lfs \
      gosu \
      jq \
      less \
      procps \
    && rm -rf /var/lib/apt/lists/*

# Agent CLI installed system-wide so the non-root agent user can run it; the
# tool dirs are build-scoped on purpose, so `uv tool install` run by the agent
# later writes to its own home volume instead of the read-only root filesystem.
RUN python -m pip install --no-cache-dir uv "pytest==9.2.0" \
 && if [ "$AGENT" = vibe ]; then \
      UV_TOOL_DIR=/opt/uv-tools UV_TOOL_BIN_DIR=/usr/local/bin \
        uv tool install "mistral-vibe==${VIBE_VERSION}"; \
    fi

RUN git lfs install --system \
 && git config --system --add safe.directory '*'

RUN groupadd --gid 1000 agent \
 && useradd --uid 1000 --gid 1000 --create-home --shell /bin/bash agent \
 && mkdir -p /work /home/agent/.cache \
 && chown -R agent:agent /work /home/agent

COPY entrypoint.sh /usr/local/bin/entrypoint.sh
# There is no browser in the box; this stub prints the URL for the human to open
# on the host instead of failing the opener, which is what makes the CLI's
# browser sign-in work here (see xdg-open.sh and README.md).
COPY xdg-open.sh /usr/local/bin/xdg-open
# Both scripts run from their shebang, so a CRLF checkout (Windows host with
# core.autocrlf) fails here with "env: 'bash\r': No such file or directory":
# normalize the copies instead of depending on the checkout's line endings.
RUN sed -i 's/\r$//' /usr/local/bin/entrypoint.sh /usr/local/bin/xdg-open \
 && chmod 0755 /usr/local/bin/entrypoint.sh /usr/local/bin/xdg-open

ENV HOME=/home/agent \
    PYTHONUNBUFFERED=1 \
    PIP_DISABLE_PIP_VERSION_CHECK=1

WORKDIR /work/repo
ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
CMD ["bash"]
