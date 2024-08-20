#!/bin/bash
set -e
if [ $# -lt 1 ]
then
  #image-name should include version in ":" sep format
  echo "usage: $0  <image-name>"
  exit 1
fi


image_name=$1
echo "Image name: $image_name"
# Extract the version from the image name
image_version="${image_name##*:}"
if [ -z "$image_version" ]; then
  echo "Error: Image name must include a version (e.g., myapp:1.0)"
  exit 2
fi
echo "Version: $image_version"

docker build -t $image_name .
