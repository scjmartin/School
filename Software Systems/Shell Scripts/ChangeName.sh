#!/bin/bash

#Scott Martin
#HW3
#CS-270
#4/15/20
#ChangeName.sh

# Removes all underscores from every file in current working directory.
rename '_' '' *

# Moves all suffixes of files in current working directory to their respective names,
# but in lowercase.

find . -name '*.*' -exec sh -c '
  a=$(echo "$0" | sed -r "s/([^.]*)\$/\L\1/");
  [ "$a" != "$0" ] && mv "$0" "$a" ' {} \;

