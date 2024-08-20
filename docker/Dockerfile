# Use an official Ubuntu as a base image
FROM ubuntu:22.04

# Set environment variables to non-interactive to avoid prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Update and install necessary packages
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    ninja-build \
    git \
    && rm -rf /var/lib/apt/lists/*

# Create a directory for the build
WORKDIR /workspace

# Set up a default command to run when the container starts
CMD ["bash"]
