#!/bin/bash

npm run build
rm -r /var/www/posicontrol/build
mv build/ /var/www/posicontrol/
