#!/bin/bash
# set -e

export PATH=$PATH:/${PWD}/build/bin:${PWD}/tools
export LIBRARY_PATH=$LIBRARY_PATH:/${PWD}/build/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/${PWD}/build/lib

if [ -d "${PWD}/.git/" ]; then
  if [ -f "${PWD}/tools/commit-template" ]; then
    git config --local commit.template tools/commit-template
  else
    echo "tools/commit-template doesn't exist."
    exit 1
  fi

  if [ -f "${PWD}/.git/hooks/pre-commit" ]; then
    rm -f ${PWD}/.git/hooks/pre-commit
  fi
  ln -sf ${PWD}/tools/pre-commit ${PWD}/.git/hooks
fi
