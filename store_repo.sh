#!/bin/bash
git remote add local/$1 ../$1
git fetch local/$1
git checkout -b $1 local/$1/master
# git push origin repo_b