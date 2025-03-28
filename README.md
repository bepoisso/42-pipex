<div align="center">
  <img height="200" src="https://raw.githubusercontent.com/Benjamin-poisson/My_image_bank/refs/heads/main/pipex.png"  />
</div>

# Pipex - Process Management and Piping

Pipex is a project that introduces you to inter-process communication using pipes in Unix systems. It simulates the behavior of shell pipelines, deepening your understanding of file descriptors, processes, and system calls in C.

## Status
<div align="center">
  <img height="200" src="https://raw.githubusercontent.com/Benjamin-poisson/My_image_bank/refs/heads/main/pipex_success.png"  />
</div>

## Exemple
<div align="center">
  <img src="https://raw.githubusercontent.com/Benjamin-poisson/My_image_bank/refs/heads/main/pipex_exp.png"  />
</div>

## Objectives

The objective of Pipex is to recreate the behavior of the shell command:  
`< file1 cmd1 | cmd2 > file2`  
By understanding and implementing pipes, process creation (`fork`), and file descriptor manipulation, you'll develop a strong foundation in Unix programming.

## Great Resources

<li><a href="https://reactive.so/post/42-a-comprehensive-guide-to-pipex/">Pipex Guide</a></li>

## Mandatory

<table>
  <tr>
    <th>Program name</th>
    <td>pipex</td>
  </tr>
  <tr>
    <th>Turn in files</th>
    <td>All necessary files to compile the program</td>
  </tr>
  <tr>
    <th>Makefile</th>
    <td>Yes</td>
  </tr>
  <tr>
    <th>External functions</th>
    <td>open, close, read, write, malloc, free, pipe, dup, dup2, execve, fork, perror, strerror, exit</td>
  </tr>
  <tr>
    <th>Libft authorized</th>
    <td>Yes</td>
  </tr>
  <tr>
    <th>Description</th>
    <td>Simulate the shell's pipeline behavior with two commands and file redirections.</td>
  </tr>
</table>

- The project must be written in C.
- Code must adhere to the Norm.
- No memory leaks are tolerated; all allocated memory must be freed.
- Provide a Makefile to compile the program with flags `-Wall -Wextra -Werror`.
- The Makefile must include rules for `all`, `clean`, `fclean`, and `re`.

## Functionality

The program must:

- Reproduce the behavior of the following shell command:
  ```bash
  < file1 cmd1 | cmd2 > file2
  ```

    Handle the following:
        Open and read from file1.
        Execute cmd1 and cmd2 using execve.
        Write the output of cmd2 to file2.
        Create a pipe to redirect the output of cmd1 to the input of cmd2.
    Handle errors appropriately (invalid files, commands, or permissions).
    Use only the allowed functions.

Example Usage

```bash
$ ./pipex infile "ls -l" "wc -l" outfile
```
This command will execute ls -l with input from infile, pipe the result to wc -l, and save the output to outfile.

```bash
$ cat outfile
10
```
Edge Cases to Handle

    Invalid file paths or permissions.
    Invalid or missing commands.
    Empty or non-readable files.

Bonus

If the mandatory part is completed perfectly, consider the following bonus features:

    Handle multiple commands (e.g., cmd1 | cmd2 | cmd3 | ...).
    Support here-doc functionality:

    << LIMITER cmd1 | cmd2 >> file

    This will read from standard input until the LIMITER is reached, then execute the commands.

Bonus files should be named with the _bonus suffix.
Example Usage with Bonus

```bash
$ ./pipex infile "grep a" "sort" "uniq" "wc -l" outfile

$ ./pipex here_doc LIMITER "cat" "wc -l" outfile
> Hello world
> LIMITER
```

Key Concepts to Master

    File descriptors and their redirection using dup and dup2.
    Creating pipes and managing inter-process communication.
    Using fork to create child processes.
    Executing commands with execve.
    Error handling and resource management.
