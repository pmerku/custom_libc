## Custom_libc
Reimplementation of some C/CPP standard functions and templates

##### Link to documentation: https://pmerku.github.io/custom_libc

### List of functions to add:
### ft_stdlib.h
- `ft_atoi_base`
- `ft_atol` | `ft_atoll`
- `ft_atol_base` | `ft_atoll_base`
### ft_unistd.h
- `ft_putnbr_fd_base`
### ft_libft.h
- `ft_ltoa` | `ft_lltoa`
- `ft_ltoa_base` | `ft_lltoa_base`

### Building the library
- Using Cmake:
```
cmake .
make
./bin/test
```

- Using Make:
```
make -f Makefile.mk
make -f Makefile.mk run
```

### Contribute
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.