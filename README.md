# ShellNU
[![Version](https://img.shields.io/badge/Version-v0.0.3-darkorange?style=flat)]()
## _Basic shell to perform both linux/windows tasks_

ShellNU is a basic shell to perform basic linux/windows commands on your machine (windows/linux).

ShellNU is written in C and C++

## SOME BASIC COMMANDS

| Command |  |
| ------ | ------ |
| shellnu | displays the introduction of ShellNU |
| nw | starts a new ShellNU window |
| nt | starts a new ShellNU tab |
| ls | to list all the files |
| cd .. | to change the directory |
| pwd | returns the current working directory |
| touch | creates a file |
| rm | deletes a file or a folder |
| v | returns the version of ShellNU |
| cat | returns the content of a file |
| clear | clears the terminal screen |
| echo | returns a string on the terminal screen |
| whoami | returns the username |
| rename | renames a file |
| xt | to exit ShellNU |
| lscpu | returns the cpu specifications |
| credits | returns the creator of the ShellNU program |
| nano | to edit a file using nano text editor |
| vim | to edit a file using vim text editor |
| ffplay | to play a video file using ffplay |

## Installation

ShellNU requires g++ and gcc compiler run.

Follow the given steps to use ShellNU program.

```sh
git clone https://github.com/shujanislam/ShellNU.git
cd ShellNU
```

Making the ./main file and executing it

```sh
cmake .
make
./ShellNU
```

## Configuration File

ShellNU uses a configuration file (shellnu.config) for storing user-specific configurations. It allows for customizations such as the username and profile type.

### Configuration File Format

The configuration file (shellnu.config) can contain the following entries:

user: The username that will be displayed in the terminal prompt.

profile: Defines the user profile.

command_log: Logging all the commands in a 'log.txt' file.

### Example

```sh
user = shujan
profile = user
command_log = true
```

## License

MIT

**Created by: Shujan Islam**
