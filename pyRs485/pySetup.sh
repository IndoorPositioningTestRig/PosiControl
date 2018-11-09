#!/usr/bin/env bash

sudo apt-get update
sudo apt-get install build-essential tk-dev libncurses5-dev libncursesw5-dev libreadline6-dev libdb5.3-dev libgdbm-dev libsqlite3-dev libssl-dev libbz2-dev libexpat1-dev liblzma-dev zlib1g-dev

# Install the latest version of python
wget https://www.python.org/ftp/python/3.7.1/Python-3.7.1.tar.xz
tar xf Python-3.7.1.tar.xz
cd Python-3.7.1
./configure
make
sudo make altinstall
