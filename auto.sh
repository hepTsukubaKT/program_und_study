#!/bin/bash

while true
do
  git add .
  git commit -m 'auto commit'
  sleep 30
  git commit -m 'auto commit'
  git push ssh://git@github.com:hepTsukubaKT/program_und_study.git master:master
  sleep 30
done