# ASUX
ASUX (Advanced Shell User Experience) is a lightweight C++ reactive framework for building terminal-based applications. The name "ASUX" reflects the main purpose of providing an advanced user experience in a shell environment, and incorporates the initials of its creator, Andrea Sorrentino.

ASUX is a reactive framework. The term "reactive" in ASUX refers to the framework's ability to automatically reflect changes in component states on the user interface, without requiring the developer to write additional code. The framework provides built-in components specifically designed for text-based user interfaces (TUI), along with mechanisms for navigating the application and intercepting input events from the terminal. It uses a declarative approach to define user interfaces directly in C++ relying on method chaining and macros to reduce verbosity.

## Project structure
An ASUX application follows this project structure:

```
asux-app/
├── components/
│   ├── my_component.h
│   ├── ...
│
├── views/
│   ├── main_view.h
│   ├── ...
│
├── main.cpp
└── makefile
```

- :file_folder: **components**: Contains your custom components, the building blocks for the UI.
- :file_folder: **views**: Contains the views, which represent the pages of your applications.
- :page_facing_up: **main.cpp**: The entry point of the C++ program where an ASUX app instance is created.
- :page_facing_up: **makefile**: To build the app.

## Install ASUX
Download and install the `asux` tool:
```sh
curl -o asux https://raw.githubusercontent.com/andreasorrentino1998/ASUX/refs/heads/main/tools/asux.sh
mv asux /usr/local/bin && chmod +x /usr/local/bin/asux
```

Reload your shell configuration:
```sh
source ~/.bashrc    # For bash shell
source ~/.zshrc     # For zshrc shell
```

Once you have the ```asux``` tool installed, you can install the framework API:
```sh
asux install
```

## Compile the framework API
If you want to compile the framework from source code, follow these steps.
Clone this repository using `git`:
```sh
git clone https://github.com/andreasorrentino1998/ASUX
```

Move to the `asux-api` folder and build it with `make`:
```sh
cd asux-api
make
```

## Setup a new ASUX project
You can use the ```asux``` tool to setup a new project. It helps you to configure, build and run your projects easily.

Create a new project:
```sh
asux create my-project
cd my-project
```

Build the project:
```sh
asux build
```

Run the app:
```sh
asux run
```
