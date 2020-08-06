# Parfeen

Simulating particles with charges.
> Just some of that coulomb's law goodness amiright.
>
> -- This guy

### Building
```sh
# Navigate to the repo directory
cd /path/to/repo

# Compile code
# There is already a makefile so that should take care of everything
make
```

### Running
```sh
# While still in the repo run the binary by terminal
bin/output.out
```

There should be a prompt for you to enter in all the graphing configurations and particle data. High chance that your particles will fly off the screen after some time. Just press <kbd>return</kbd> to step forward by 1 second in the simulation. Press <kbd>q</kbd> to quit the simulation.

### Some small notes

- The order in coordinates and geometry is always `x y` or `width height`.
- Since there is no continuous computation, the accuracy is a bit off.
- The scale is in units of `chars / 1 unit`.
- No data is saved.
