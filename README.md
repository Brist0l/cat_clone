# Cat's clone 

Cat's clone is a the `cat` command at a very basic level.

## Installation

There are 2 ways of installing it.
The first one involves compiling from source and the other is just moving the binary to the desired location that is in most cases[/usr/bin/]

To download the repo use git or download it as a zip

downloading using git:
```bash 
git clone https://github.com/mrHola21/cat_clone.git

cd cat_clone/

```
To compile from source use your preffered compiler. In this case I will be using gcc

```bash
gcc src/main.c -o bin/catt

```

To move the bin to the desired location in this case [/usr/bin/]

```bash
# mv bin/catt usr/bin/
```

## Usage

This will print the contents of the file

```
catt {file}

```
You can also print the contents of multiple files using 
```
catt {file} {file1} {file2}
```
You can also add the clear flag by using -c 

```
catt {file} -c 
```

## Integrating it with other tools 

*Would need exteral tools

This will print coloured text

```
catt {file} | lolcat
```
This will ease your viewing with big files
```
catt {file} | less
```
This is for filtering contents 

```
catt {file} | grep lol
```

## Diffrence 

cat does not tell the number of words but this does :) 

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

GPL[https://www.gnu.org/licenses/gpl-3.0.html]
