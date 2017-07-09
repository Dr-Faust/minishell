# minishell

As the name suggest, this project aim to produce a functional miniature version of a shell like bash, zsh and so on.  
***The project must not leak in any manner. Memory management is crucial.***

Authorized functions are restricted to these for the core functions:
 - *malloc, free*
 - *access*
 - *open, close, read, write*
 - *opendir, readdir, closedir*
 - *getcwd, chdir*
 - *stat, lstat, fstat*
 - *fork, execve*
 - *wait, waitpid, wait3, wait4*
 - *signal, kill*
 - *exit*

<p align="center">CORE FUNCTIONS STATUS</p>
|Functions|Implemented|Leaks|Arguments|Comments
|:-:|:-:|:-:|:-:|:-:|:--|:--
|exit|Done|No|[exit]|Exit minishell
|cd|Done|No|[cd]<br>[cd -]<br>[cd folder]<br>[cd ../../folder]<br>[cd ~/folder]|Return to the home folder<br>Go to previous folder<br>Go to folder from current<br>Complex dots solved<br>Retrieve home path
|pwd|Done|No|[pwd]|Give the current directory
|echo|Done|No|[echo Hello]<br>[echo "World"]<br>[echo $var]|Echo standard<br>Echo foo as it's writed<br>Echo the var from env
|env|Done|No|[env]|Show env info
|setenv|Done|No|[setenv FOO bar]|Add the var to the env
|unsetenv|Done|No|[unsetenv FOO]|Remove the var from env

<p align="center">EXTRA FEATURE</p>
|Functions|Status|Comments
|:--|:-:|:--
|Chain commands with ;|Done|Chained as [cd ; ls ; cd / ; ls -l]
|Execution rights in path|Done|Check if the file is a binary and if the user can access it
|Tilde support|Done|Solve a path input in the command with tilde or dots support
|Simple quote handling|**TBD**|-
|Double quote handling|**TBD**|-
