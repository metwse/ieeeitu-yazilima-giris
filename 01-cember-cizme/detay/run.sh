#!/bin/bash

xwinwrap -un -b -- watch -n 0 -x $(dirname "$0")/run-compile.sh $1 WID
