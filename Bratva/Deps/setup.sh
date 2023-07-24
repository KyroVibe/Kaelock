#!/bin/bash
rm -rf glfw/
rm -rf glew-2.2.0/

git clone https://github.com/glfw/glfw/
wget https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0.tgz
tar -xvf glew-2.2.0.tgz
rm glew-2.2.0.tgz