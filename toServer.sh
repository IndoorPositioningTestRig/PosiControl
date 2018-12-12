#!/bin/bash

# Create tar gz and send to pi
tar -czvf pyserver.tar.gz pyserver
scp pyserver.tar.gz pi@192.168.4.1:pyserver.tar.gz
rm pyserver.tar.gz
 
