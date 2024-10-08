#!/bin/bash

# ASUX: A lightweight C++ reactive framework for building terminal-based applications. 
#
# Authors:
# © 2024 - Andrea Sorrentino
# 
# ASUX is free software: you can redistribute it and/or modify it under the
# terms of the GNU General Public License as published by the Free Software Foundation,
# either version 3 of the License, or (at your option) any later version.
#  
# ASUX is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
# PURPOSE. See the GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License along with ASUX.
# If not, see <http://www.gnu.org/licenses/>.

# ANSI BOLD COLORS
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
CYAN='\033[1;36m'
WHITE='\033[1;37m'

NC='\033[0m'   # Reset

# Get args
command=$1
param1=$2

# Install ASUX framework
install_ASUX(){
    # Copy headers from root directory
    mkdir /usr/local/include/ASUX/
    cp *.h /usr/local/include/ASUX/

    # Find all the project subdirectories, excluding "./bin"
    directories=($(find . -type d -name bin -prune -o -type d -print))

    # Copy headers from subdirectories
    for dir in "${directories[@]}"; do        
        if [[ $dir != "." ]]; then  # Exclude "./" directory
            cleaned_dir="${dir//.\//}"
            mkdir "/usr/local/include/ASUX/${cleaned_dir}/"
            cp $cleaned_dir/*.h /usr/local/include/ASUX/$cleaned_dir/
        fi
    done

    # Copy the static library
    mkdir /usr/local/lib/ASUX-1.0/
    cp bin/libASUX.a /usr/local/lib/ASUX-1.0/
}

# Unistall ASUX framework
unistall_ASUX(){
    rm -rf /usr/local/lib/ASUX-1.0/
    rm -rf /usr/local/include/ASUX/
}

# Update ASUX framework
update_ASUX(){
    unistall_ASUX
    install_ASUX
}

# Parse command
case $command in
    install)
        echo "Install ASUX framework..."
        install_ASUX
        echo "Done."
        ;;
    unistall)
        echo "Uninstalling ASUX framework..."
        unistall_ASUX
        echo "Done."
        ;;
    update)
        echo "Updating ASUX framework..."
        update_ASUX
        echo "Done."
        ;;
    "")
        echo "Updating ASUX framework..."
        update_ASUX
        echo "Done."
        ;;
    *)
        echo -e "${RED}Invalid command '$command'.${NC}"
        exit 1
    ;;
esac