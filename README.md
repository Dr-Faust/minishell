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

|Functions|Implemented|Arguments|Comments
|:-:|:-:|:-:|:--
|exit|Done|[exit]|Exit minishell
|cd|Done|[cd]<br>[cd -]<br>[cd folder]<br>[cd .././folder]<br>[cd ~/folder]|Return to the home folder<br>Go to previous folder<br>Go to folder from current<br>Complex dots solved<br>Retrieve home path
|pwd|Done|[pwd]|Give the current directory path
|echo|Done[echo foo]<br>[echo "foo"]<br>[echo $var]|Echo standard<br>Echo foo as it's writed<br>Echo the var from env
|env|Done|[env]|Shows environment info
|setenv|Done|[setenv foo bar]|Add the var to the env
|unsetenv|Done|[unsetenv foo]|Remove the var from env

<p align="center">EXTRA FEATURE</p>

|Functions|Comments
|:--|:--
|Chain commands with ;|Chained as [cd ; ls ; cd / ; ls -l]
|Execution rights in path|Check if the file is a binary and if the user can access it
|Tilde support|Solve a path input in the command with tilde or dots support
