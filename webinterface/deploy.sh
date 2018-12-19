#!/bin/bash

echo Building frontend...
npm run build
echo Done!

echo deploying build...
rm -r /var/www/posicontrol/build
cp -r build/ /var/www/posicontrol/
echo Done!
