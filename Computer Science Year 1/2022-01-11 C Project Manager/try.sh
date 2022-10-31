#!/bin/bash
git add $1
git commit -m $2
git push --set-upstream origin master
