#!/bin/bash

#Scott Martin
#HW3
#CS-270
#04/15/20
#Backup.sh

# Creates directory named '.backup'
mkdir .backup

# Moves all files in current working directory to '.backup'
ls | grep -v .backup | xargs cp -t .backup

