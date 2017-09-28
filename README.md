# Wordz-Solver

Fast command line Wordz Solver, build for fun :)
_______________

### Build

Configure the project build with the following command. It will create the
`build` directory with the configuration.

```shell
mkdir build; cd build  # Create a build directory.
cmake ..               # Configure the project.
cmake --build .        # Build all default targets.
```

### Example
> p l y o
>
> b u i b
>
> h s u o
>
> w o i k

```shell
cd build
./solver ../en_dict.txt plyobuibhsuowoik
```
