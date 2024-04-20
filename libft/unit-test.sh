#!/bin/bash

current_dir=$(pwd)
target_dir="$HOME/Desktop/42/42assignment/libft"

if [ "$current_dir" != "$target_dir" ]; then
    echo "Current directory is not $target_dir"
    exit 1
fi

make -C ../libft-unit-test f
make -C ../libft-unit-test fclean
make clean
