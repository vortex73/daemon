# Experimental Conclusions

## Forking 
- There are 2 processes spawned on running a _fork()_. The one with ID = 0 is the child process and the other one is the parent process.
- On running multiple(n) fork calls, the number of resulting processes is given by 2<sup>n</sup>.
- Parent processes will always have a _set_ ID. Child processes will always have one of the IDs equal to _zero_.
- On forking a process the process ID of _that_ process will become the _parent process_ ID of the child process created by the fork.
- [Detailed Explaination in this video](https://www.youtube.com/watch?v=94URLRsjqMQ).

### The `wait()` function
- `pid_t wait(int* status)`.
- `status` stores the information about the child process that has terminated.
- `status` can be `NULL` if we don't need to retrieve the exit status of the child process.
- This function blocks the parent until the child terminates.
- When the child process terminates `wait()` returns the exit status of the child process.
