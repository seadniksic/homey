FROM nvidia/cuda:13.1.0-devel-ubuntu24.04 AS builder

RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    wget \
    git \
    && rm -rf /var/lib/apt/lists/*

ARG USERNAME=dev
ARG USER_UID=1000
ARG USER_GID=$USER_UID
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME
USER $USERNAME
