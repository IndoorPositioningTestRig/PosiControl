#!/bin/bash

echo building and starting...

# webinterface
cd ./webinterface
sh ./deploy.sh
cd ../

# pyserver
cd ./pyserver
sh ./start.sh


