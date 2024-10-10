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

to_Uppercase(){
    uppercase=$(echo "$1" | tr '[:lower:]' '[:upper:]')
    echo $uppercase
}

to_Capitalized(){
    capitalized=$(echo "$1" | awk '{print toupper(substr($0, 1, 1)) tolower(substr($0, 2))}')
    echo $capitalized
}

# Install ASUX framework
install_ASUX(){
    git clone https://github.com/andreasorrentino1998/ASUX/
    working_dir=$(pwd)
    cd ASUX/asux-api
    make
    cd bin
    mkdir /usr/local/lib/ASUX-1.0/
    mv libASUX.a /usr/local/lib/ASUX-1.0/
    cd ..
    mkdir /usr/local/include/ASUX/
    mv *.h /usr/local/include/ASUX/
    cd $working_dir
    rm -rf ASUX
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

# Create ASUX app project template
create_project(){
    # Download the app project template
    git clone https://github.com/andreasorrentino1998/ASUX/ $1
    cd $1
    
    # Remove the useless file
    rm -rf asux-api
    rm -rf tools
    rm -rf README.md
    rm -rf .gitignore
    rm -rf .git

    # Move "app-template" content to the root directory
    cd asux-templates/app-template
    mv * ../..
    cd ../..
    rm -rf asux-templates
    rm -rf asux-examples
}

create_view(){
    cd views
    curl -o "${1}_view.h" https://raw.githubusercontent.com/andreasorrentino1998/ASUX/main/asux-templates/view.h
    
    uppercaseName=$(to_Uppercase "$1")
    capitalizedName=$(to_Capitalized "$1")

    sed -i '' "s/example/$1/g" "${1}_view.h"
    sed -i '' "s/Example/${capitalizedName}/g" "${1}_view.h"
    sed -i '' "s/EXAMPLE/${uppercaseName}/g" "${1}_view.h"

    cd ..
}

create_component(){
    curl -o $1".h" https://raw.githubusercontent.com/andreasorrentino1998/ASUX/main/asux-templates/component.h

    uppercaseName=$(to_Uppercase "$1")
    capitalizedName=$(to_Capitalized "$1")

    sed -i '' "s/example/${1}/g" "${1}.h"
    sed -i '' "s/Example/${capitalizedName}/g" "${1}.h"
    sed -i '' "s/EXAMPLE/${uppercaseName}/g" "${1}.h"
}


create_class(){
    curl -o $1".h" https://raw.githubusercontent.com/andreasorrentino1998/ASUX/main/asux-templates/class.h

    uppercaseName=$(to_Uppercase "$1")
    capitalizedName=$(to_Capitalized "$1")

    sed -i '' "s/example/${1}/g" "${1}.h"
    sed -i '' "s/Example/${capitalizedName}/g" "${1}.h"
    sed -i '' "s/EXAMPLE/${uppercaseName}/g" "${1}.h"
}


create_struct(){
    curl -o $1".h" https://raw.githubusercontent.com/andreasorrentino1998/ASUX/main/asux-templates/struct.h

    uppercaseName=$(to_Uppercase "$1")
    capitalizedName=$(to_Capitalized "$1")

    sed -i '' "s/example/${1}/g" "${1}.h"
    sed -i '' "s/Example/${capitalizedName}/g" "${1}.h"
    sed -i '' "s/EXAMPLE/${uppercaseName}/g" "${1}.h"
}

create_enum(){
    curl -o $1".h" https://raw.githubusercontent.com/andreasorrentino1998/ASUX/main/asux-templates/enum.h

    uppercaseName=$(to_Uppercase "$1")
    capitalizedName=$(to_Capitalized "$1")

    sed -i '' "s/example/${1}/g" "${1}.h"
    sed -i '' "s/Example/${capitalizedName}/g" "${1}.h"
    sed -i '' "s/EXAMPLE/${uppercaseName}/g" "${1}.h"
}

check_ASUX_version(){
    # TODO...
    echo -e "${YELLOW}ASUX-v1.0${NC}"
}

info(){
    # Print the available command list
    echo -e "${CYAN}List of available commands:${NC}"
    echo -e "${CYAN}- version${NC}${WHITE}: get the ASUX version installed.${NC}"
    echo -e "${CYAN}- install${NC}${WHITE}: install the ASUX framework.${NC}"
    echo -e "${CYAN}- uninstall${NC}${WHITE}: uninstall the ASUX framework.${NC}"
    echo -e "${CYAN}- update${NC}${WHITE}: update the ASUX framework.${NC}"
    echo -e "${CYAN}- info${NC}${WHITE}: info about asux command.${NC}"
    echo ""
    echo -e "${CYAN}- create <project-name>${NC}${WHITE}: create an ASUX project.${NC}"
    echo -e "${CYAN}- clean${NC}${WHITE}: clean the project build.${NC}"
    echo -e "${CYAN}- build${NC}${WHITE}: build the project.${NC}"
    echo -e "${CYAN}- rebuild${NC}${WHITE}: rebuild the project.${NC}"
    echo -e "${CYAN}- run${NC}${WHITE}: run the project.${NC}"
    echo ""
    echo -e "${CYAN}- create-view <name>${NC}${WHITE}: create a view.${NC}"
    echo -e "${CYAN}- create-component <name>${NC}${WHITE}: create a component.${NC}"
    echo -e "${CYAN}- create-class <name>${NC}${WHITE}: create a C++ class.${NC}"
    echo -e "${CYAN}- create-struct <name>${NC}${WHITE}: create a C struct.${NC}"
    echo -e "${CYAN}- create-enum <name>${NC}${WHITE}: create a C++ enum.${NC}"
}

# Parse command
case $command in
    install)
        echo "Installing ASUX framework..."
        install_ASUX
        ;;
    unistall)
        echo "Uninstalling ASUX framework..."
        unistall_ASUX
        ;;
    update)
        echo "Updating ASUX framework..."
        update_ASUX
        ;;
    create)
        # Create a new project template
        if [ -z "$2" ]; then
            echo "No option provided for '$1' command."
            echo "Usage: $0 <$1> <project-name>"
            exit 1
        fi

        create_project $2
        ;;
    clean)
        make clean
        ;;
    build)
        make
        ;;
    rebuild)
        make clean
        make
        ;;
    run)
        ./bin/main
        ;;
    create-view)
        create_view $2
        ;;
    create-component)
        create_component $2
        ;;
    create-class)
        create_class $2;
        ;;
    create-struct)
        create_struct $2;
        ;;
    create-enum)
        create_enum $2;
        ;;
    version)
        check_ASUX_version
        ;;
    info)
        info
        ;;
    *)
        echo -e "${RED}Invalid command '$command'.${NC}"
        echo -e "${YELLOW}For more information, type 'asux info'.${NC}"
        exit 1
    ;;
esac